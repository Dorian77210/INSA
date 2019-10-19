/*************************************************************************
                        Collection  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <Collection> (fichier Collection.cpp) --

using namespace std;
#include <iostream>

// -------- Include personnel
#include "Collection.h"
#include "Trajet.h"

// -------- Partie publique

// ----------------- Constructeurs - destructeur
Collection::Collection ( unsigned int _tailleMax ) 
    : tailleMax ( _tailleMax ), tailleCourante ( 0 )
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe <Collection>" << endl;
    #endif
    
    trajets = new const Trajet* [ tailleMax ];
}

Collection::~Collection ( ) 
{  
    #ifdef MAP
        cout << "Appel au destructeur de la classe <Collection>" << endl;
    #endif
    
    unsigned int i;

    // supprime tous les trajets dans la collection
    for ( i = 0; i < tailleCourante; i++ ) 
    {
        delete trajets [ i ];
    }

    delete [] trajets;
}

// ---------------- Méthodes publiques
void Collection::Ajouter ( const Trajet* trajet )
{

    if ( tailleCourante == tailleMax ) 
    {
        reajuster ( );
    }

    trajets [ tailleCourante ] = trajet;
    tailleCourante++;
}

const Trajet* Collection::GetTrajet ( unsigned int index ) const
{
    return trajets [ index ];
}

unsigned int Collection::GetTaille ( ) const 
{ 
    return tailleCourante;
}

// -------------- Méthodes privées
void Collection::reajuster ( ) 
{
    unsigned int i;
    // reajustement de la taille
    tailleMax += FACTEUR_REDIMENSIONNEMENT;
    const Trajet** _trajets = new const Trajet* [ tailleMax ];

    for ( i = 0; i < tailleCourante; i++ )
    {
        _trajets [ i ] = trajets [ i ];
    }

    delete [] trajets;
    trajets = _trajets;
}

