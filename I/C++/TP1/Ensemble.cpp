// ------------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp)
// ------------- INCLUDE
// ------------- Include système
using namespace std;
#include <iostream>

#include "Ensemble.h"

//-------------- Constructeurs
Ensemble::Ensemble ( unsigned int _cardMax )
// permet de construire un ensemble avec un cardinal maximal fixé
{
    cardMax = _cardMax;
    elements = ( cardMax == 0 ) ? nullptr : new int [ cardMax ];
    currentCard = 0;
}

Ensemble::Ensemble ( int t [], unsigned int nbElements )
// permet de construire un ensemble avec les singletons de "t"
{
    unsigned int i;
    currentCard = 0;
    cardMax = nbElements;

    if ( t == nullptr ) {
        elements = ( cardMax == 0 ) ? nullptr : new int [ cardMax ];
    } else 
    {
        elements = new int [ cardMax ];
        for ( i = 0; i < nbElements; i++ ) 
        {
            // on verifie que l'element à rajouter n'est pas présent plusieurs fois dans le tableau
            if ( !isSingleton ( t [ i ] ) ) 
            {   
                elements [ currentCard ] = t [ i ];
                currentCard++;
            }
        }
    }
}

Ensemble::~Ensemble ( )
{
    delete [] elements;
}

void Ensemble::Afficher ( void )
{
    unsigned int i;
    
    cout << currentCard << "\r\n";
    cout << cardMax << "\r\n";

    if ( elements == nullptr || currentCard == 0 ) 
    {
        cout << "{}" << "\r\n";
    }
    else
    {
        // tri du tableau avant l'affichage
        sort ( );

        cout << "{";
        for ( i = 0; i < currentCard; i++ ) 
        {
            if ( i == ( currentCard - 1) )
            {
                cout << elements [ i ];
            }
            else 
            {
                cout << elements [ i ] << ",";
            }
        }

        cout << "}\r\n";
    }
}

crduAjouter Ensemble::Ajouter ( int toAdd ) 
{
    // verifie si l'element est deja dans l'ensemble
    if( isPresent ( toAdd ) ) return DEJA_PRESENT;

    // verifie si la taille maximum est deja atteinte
    if( currentCard == cardMax ) { 
        return PLEIN;
    }

    // sinon, on ajoute l'element dans l'ensemble
    elements [ currentCard ] = toAdd;
    currentCard++;

    return AJOUTE;
}

unsigned int Ensemble::Ajuster ( int delta ) 
{
    unsigned int min;
    if( delta > 0 ) 
    {
        cardMax += delta;
        resize ( );
    }
    else if ( delta < 0 ) 
    {
        unsigned int newDelta = delta * -1;
        min = ( newDelta < ( cardMax - currentCard ) ) ? newDelta : ( cardMax - currentCard );
        cardMax -= min;
    }

    return cardMax;
}

bool Ensemble::EstEgal ( const Ensemble & otherSet ) const
{   
    unsigned int i;
    if ( currentCard != otherSet.currentCard ) return false;

    for ( i = 0; i < currentCard; i++ ) 
    {
        if ( !isPresent ( otherSet.elements [ i ] )  ) return false;
    }

    return true;
}

crduEstInclus Ensemble::EstInclus ( const Ensemble & otherSet ) const 
{
    unsigned int i;

    if ( EstEgal ( otherSet ) ) 
    {
        return INCLUSION_LARGE;
    }

    if ( currentCard > otherSet.currentCard ) return NON_INCLUSION;

    // ici, currentCard < otherSet.currentCard
    for ( i = 0; i < currentCard; i++ ) 
    {   
        if ( !otherSet.isPresent ( elements [ i ] ) ) return NON_INCLUSION;
    }

    return INCLUSION_STRICTE;
}

unsigned int Ensemble::Intersection ( const Ensemble & set )
{
    Ensemble e ( currentCard );
    unsigned int i, deletedElements = 0;

    for ( i = 0; i < currentCard; i++ ) 
    {
        if ( !set.isPresent ( elements [ i ] ) )
        {
            deletedElements++;
            e.Ajouter ( elements [ i ] );
        }
    }

    Retirer ( e );

    Ajuster ( currentCard - cardMax );

    return deletedElements;
}

bool Ensemble::Retirer ( int element ) 
{
    bool isDeleted = false;
    unsigned int i;

    for ( i = 0; i < currentCard; i++ ) 
    {
        if ( elements [ i ] == element ) 
        {
            isDeleted = true;
            shift ( i );
            currentCard--;
            break;
        }
    }

    cardMax = currentCard;

    resize ( );
    return isDeleted;
}

unsigned int Ensemble::Retirer ( const Ensemble & set ) 
{
    unsigned int deletedElements = 0u, i = 0;

    while ( i < currentCard ) 
    {
        if ( set.isPresent ( elements [ i ] ) )
        {
            shift ( i );
            currentCard--;
            deletedElements++;
        } else 
        {   
            i++;
        }
    }

    // for ( i = 0; i < set.currentCard; i++ )
    // {
    //     index = getElementByIndex ( set.elements [ i ] );
    //     if ( index >= 0 ) 
    //     {
    //         // element found
    //         shift ( index );
    //         deletedElements++;
    //         currentCard--;
    //     }
    // }

    return deletedElements;
}

int Ensemble::Reunir ( const Ensemble & set ) 
{
    int maxCard = set.currentCard < currentCard ? currentCard : set.currentCard, delta, returnValue;
    unsigned int i;
    Ensemble e ( maxCard );
    if ( EstEgal ( set ) ) return 0;

    for ( i = 0; i < set.currentCard; i++ ) 
    {
        if ( !isPresent ( set.elements [ i ] ) )
        {
            e.Ajouter ( set.elements [ i ] );
        }
    }

    if( ( e.currentCard + currentCard ) > cardMax )
    {
        delta = ( e.currentCard + currentCard ) - cardMax;
        Ajuster ( delta );
        returnValue = -e.currentCard;
    } else 
    {
        returnValue = e.currentCard;
    }

    for ( i = 0; i < e.currentCard; i++ )
    {
        Ajouter ( e.elements [ i ] );
    }

    return returnValue;
}

//----------- Méthodes protégées
void Ensemble::resize ( void ) 
{
    int* tab = new int [ cardMax ];
    unsigned int i;

    for ( i = 0; i < currentCard; i++ ) 
    {
        tab [ i ] = elements [ i ];
    }

    delete [] elements;

    elements = tab;
}

int Ensemble::getElementByIndex ( int element ) const
{
    unsigned int i;

    for ( i = 0; i < currentCard; i++ ) 
    {
        if ( elements [ i ] == element ) return (int)i;
    }

    return -1;
}

bool Ensemble::isSingleton ( int value ) 
{
    unsigned int occurence = 0u, i;

    for ( i = 0; i < currentCard; i++ ) 
    {
        if ( elements [ i ] == value ) occurence++;
    }

    return occurence == 1;
}

bool Ensemble::isPresent( int value ) const
{
    unsigned int i;

    for ( i = 0; i < currentCard; i++ )
    {
        if ( elements [ i ] == value ) return true;
    }

    return false;
}

void Ensemble::sort ( void ) 
{
    // Algorithme 
    // utilisation de l'algorithme du tri à bulle 

    unsigned int i;
    int tmp;
    if ( currentCard == 1 || currentCard == 0 ) return;
    while ( !isSorted( ) ) {        
        for( i = 0; i < ( currentCard - 1 ); i++ )
        {   
            if ( elements[i] > elements [ i + 1 ] ) 
            {
                // swap des deux éléments
                tmp = elements[ i ];
                elements [ i ] = elements [ i + 1 ];
                elements [ i + 1 ] = tmp;
            }
        }
    }
}

bool Ensemble::isSorted( void ) const 
{
    unsigned int i;

    for ( i = 0; i + 1 < currentCard; i++ ) 
    {
        if ( elements [ i ] > elements [ i + 1 ] ) return false;
    }

    return true;
}

void Ensemble::shift ( unsigned int begin ) 
{
    unsigned int i;

    for ( i = ( begin + 1 ); i < currentCard; i++ ) 
    {
        elements [ i - 1 ] = elements [ i ];
    }
}