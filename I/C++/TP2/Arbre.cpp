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

Arbre::Arbre ( void )
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe <Arbre>" << endl;
    #endif

    base = NOEUD_NULL;    
}

Arbre::~Arbre ( ) 
{   
    #ifdef MAP
        cout << "Appel au destructeur de la classe <Arbre>" << endl;
    #endif
    
    delete base;
}

void Arbre::RechercherTrajetsPossibles ( const Catalogue* catalogue, const char* depart, const char* arrivee )
{
    const Collection* collectionTrajets = catalogue->GetCatalogue ( );
    unsigned int tailleCatalogue = collectionTrajets->GetTaille ( ), i;
    const Trajet* trajet;
    Noeud* voisin;

    // chercher tous les trajets qui ont comme depart "depart"
    for ( i = 0; i < tailleCatalogue; i++ )
    {
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

    // ajout des autres trajets
    for ( i = 0; i < tailleCatalogue; i++ ) 
    {
        trajet = collectionTrajets->GetTrajet ( i );
        if ( strcmp ( depart, trajet->GetVilleDepart ( ) ) != 0 )
        {
            base->Ajouter ( trajet, arrivee );
        }
    }
}

void Arbre::AfficherTrajetsPossibles ( void ) const
{
    base->Afficher ( );
}

const bool Arbre::ContientPossibilites ( void ) const 
{
    if ( base == NOEUD_NULL ) return false;
    const Noeud* courant;

    for ( courant = base; courant != NULL; courant = courant->GetVoisin ( ) ) 
    {
        if ( courant->EstValide ( ) ) return true;
    }    

    return false;
}