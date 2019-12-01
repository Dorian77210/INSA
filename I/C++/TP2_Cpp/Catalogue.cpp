/*************************************************************************
                        Catalogue  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) --

using namespace std;
// ----------- INCLUDES SYSTEME
#include <iostream>

//------------ Include personnel
#include "Catalogue.h"
#include "Arbre.h"
#include "Trajet.h"
#include "Collection.h"

// ------------ Méthodes publiques
void Catalogue::Afficher ( ) const 
{
    unsigned int i, tailleCollection;
    const Trajet* trajet;

    tailleCollection = collectionTrajets->GetTaille ( );

    if ( tailleCollection == 0 ) 
    {
        // aucun trajet
        cout << "Aucun trajet n'est disponible." << endl;
        return;
    }

    for ( i = 0; i < tailleCollection; i++ ) 
    {
        trajet = collectionTrajets->GetTrajet ( i );
        cout << "Trajet numero " << ( i + 1 ) << " : ";
        trajet->Afficher ( );
        cout << endl;
    }
} // Fin de Afficher

const Collection* Catalogue::GetCatalogue ( ) const 
{
    return collectionTrajets;
} // Fin de GetCatalogue

void Catalogue::Rechercher ( const char* depart, const char* arrivee ) const 
{
    const Trajet* trajet;
    unsigned int i, tailleCollection;
    bool trajetsTrouves = false;

    tailleCollection = collectionTrajets->GetTaille ( );

    for ( i = 0; i < tailleCollection; i++ ) 
    {
        trajet = collectionTrajets->GetTrajet ( i );
        if ( trajet->EstValide ( depart, arrivee ) ) 
        {
            if ( !trajetsTrouves ) trajetsTrouves = true;
            trajet->Afficher ( );
            cout << endl;
        }
    }

    if ( !trajetsTrouves ) 
    {
        cout << "Aucun trajet n'a été trouvé pour votre demande." << endl;
    }
} // Fin de Rechercher

void Catalogue::RechercheComplexe ( const char* depart, const char* arrivee ) const
{
    Arbre arbre;
    arbre.RechercherTrajetsPossibles ( this, depart, arrivee );
    
    if ( arbre.ContientPossibilites ( ) )
    {
        arbre.AfficherTrajetsPossibles ( );
    } else
    {
        cout << "Aucun trajet disponible." << endl;
    }
} // Fin de RecherComplexe

void Catalogue::Ajouter ( Trajet* trajet ) 
{
    collectionTrajets->Ajouter ( trajet );
} // Fin de Ajouter

// ----------------- Constructeurs - destructeur
Catalogue::Catalogue ( unsigned int _tailleMax ) 
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe <Catalogue>" << endl;
    #endif
    collectionTrajets = new Collection ( _tailleMax );
} // Fin de Catalogue ( constructeur par defaut )

Catalogue::~Catalogue ( ) 
{
    #ifdef MAP
        cout << "Appel au destructeur de la classe <Catalogue>" << endl;
    #endif

    delete collectionTrajets;
} // Fin de ~Catalogue (destructeur)