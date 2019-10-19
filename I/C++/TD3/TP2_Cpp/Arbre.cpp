/*************************************************************************
                        Arbre  -  Classe qui correspond a un arbre de trajets
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

// ---------- Réalisation de la classe <Arbre> (fichier Arbre.cpp) -------

// ------ INCLUDES SYSTEMES
#include <iostream>
#include <cstring>

using namespace std;

// ----- Includes personnel
#include "Arbre.h"
#include "Catalogue.h"
#include "Noeud.h"


// --------------- Methodes publiques
void Arbre::RechercherTrajetsPossibles ( const Catalogue* catalogue, const char* depart, const char* arrivee )
{
    const Collection* collectionTrajets = catalogue->GetCatalogue ( );
    unsigned int tailleCatalogue = collectionTrajets->GetTaille ( ), i;
    const Trajet* trajet;
    Noeud* voisin;

    bool* utilises = new bool [ tailleCatalogue ], estAjoute, fin;

    // chercher tous les trajets qui ont comme depart "depart"
    for ( i = 0; i < tailleCatalogue; i++ )
    {
        utilises [ i ] = false;
        trajet = collectionTrajets->GetTrajet ( i );
        if ( strcmp ( depart, trajet->GetVilleDepart ( ) ) == 0 )
        {
            if ( base == NOEUD_NULL ) 
            {
                base = new Noeud ( trajet );
                voisin = base;
            } else
            {
                voisin = base->AjouterVoisin ( trajet );
            }

            utilises [ i ] = true;
        }

        if ( strcmp ( arrivee, trajet->GetVilleArrivee ( ) ) == 0 && strcmp ( depart, trajet->GetVilleDepart ( ) ) == 0 ) 
        {
            // trajet qui correspond directement au trajet desire
            voisin->SetEstValide ( true );
            voisin->SetEstTrajetDirect ( true );
        }
    }

    // il n'y a aucun trajets de disponibles
    if ( base == NOEUD_NULL ) 
    {
        return;
    }

    fin = false;
    // ajout des autres trajets
    while ( !fin ) 
    {
        fin = true;
        for ( i = 0; i < tailleCatalogue; i++ ) 
        {
            trajet = collectionTrajets->GetTrajet ( i );
            if ( ! utilises [ i ] )
            {
                estAjoute = base->Ajouter ( trajet, arrivee );
                utilises [ i ] = estAjoute;
            }
        }
    }
    
    delete [] utilises;
} // ------------- Fin de RechercherTrajetsPossibles

void Arbre::AfficherTrajetsPossibles ( void ) const
{
    base->Afficher ( );
} // Fin de AfficherTrajetsPossibles

const bool Arbre::ContientPossibilites ( void ) const 
{
    if ( base == NOEUD_NULL ) return false;
    const Noeud* courant;

    for ( courant = base; courant != NULL; courant = courant->GetVoisin ( ) ) 
    {
        if ( courant->EstValide ( ) ) return true;
    }    

    return false;
} // Fin de ContientPossibilites

// ------------------ Constructeur et destructeur
Arbre::Arbre ( void )
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe <Arbre>" << endl;
    #endif

    base = NOEUD_NULL;    
} // Fin de Arbre (constructeur par defaut)

Arbre::~Arbre ( ) 
{   
    #ifdef MAP
        cout << "Appel au destructeur de la classe <Arbre>" << endl;
    #endif
    
    delete base;
} // Fin de ~Arbre (destructeur de Arbre)