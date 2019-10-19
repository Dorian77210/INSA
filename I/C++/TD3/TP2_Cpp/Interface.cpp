/*************************************************************************
                        Interface  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <Interface> (fichier Interface.cpp) --

using namespace std;
// ----------- INCLUDES SYSTEMES
#include <iostream>
#include <cstring>

// ---------- Includes personnels
#include "Interface.h"
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

// -------------- Méthodes publiques
void Interface::Run ( void ) 
{
    bool loop = true;
    int choix;

    while ( loop ) 
    {
        afficherMenu ( );
        cin >> choix;

        if( choix == AFFICHAGE_CATALOGUE ) catalogue.Afficher ( );
        else if ( choix == AJOUTER_TRAJET ) ajouterTrajet ( );
        else if ( choix == RECHERCHER_PARCOURS ) rechercherTrajet ( );
        else if ( choix == QUITTER_APPLICATION ) loop = false;
        else 
        {
            cin.clear();
            cin.ignore(MAX_STREAM, '\n');
        }
    }
} // Fin de Run

// ------------- Méthodes protégées
void Interface::afficherMenu ( void ) const 
{
    cout << "Option 1 : Ajouter un trajet" << endl;
    cout << "Option 2 : Afficher le catalogue" << endl;
    cout << "Option 3 : Rechercher un parcours" << endl;
    cout << "Option 4 : Quitter application" << endl;
    cout << "Choisissez l'option qui vous convient : ";
} // Fin de afficherInterface

void Interface::rechercherTrajet ( void ) const
{
    unsigned int choix = 0;
    char* arrivee = new char [ MAX_TAILLE_STRING ], *depart = new char [ MAX_TAILLE_STRING ];
    cout << "Depart : ";
    cin >> depart;

    cout << "Arrivee : ";
    cin >> arrivee;

    while ( choix != RECHERCHE_BASIQUE && choix != RECHERCHE_COMPLEXE )
    {
        cout << "Quel type de recherche souhaitez-vous utiliser ? " << endl;
        cout << "1 : Recherche basique ? " << endl;
        cout << "2 : Recherche complexe ? " << endl;
        cout << "Choisisez la recherche que vous voulez : ";
        cin >> choix;
    }

    cout << "Voici la liste des trajets correspondants : " << endl;
    if ( choix == RECHERCHE_BASIQUE ) 
    {
        catalogue.Rechercher ( depart, arrivee );
    } else
    {
        // recherche de tous les trajets possibles
        catalogue.RechercheComplexe ( depart, arrivee );
    }

    delete [] arrivee;
    delete [] depart;
} // Fin de rechercherTrajet

void Interface::ajouterTrajet ( void ) 
{
    char* depart, *arrivee, *moyenTransport;
    Trajet* trajet;
    int choice = 0;

    // allocation des chaines de caracteres
    depart = new char [ MAX_TAILLE_STRING ];
    arrivee = new char [ MAX_TAILLE_STRING ];
    moyenTransport = new char [ MAX_TAILLE_STRING ];

    cout << "Option 1 : Création d'un trajet simple" << endl;
    cout << "Option 2 : Création d'un trajet composé" << endl;
    
    while ( ( choice != TRAJET_COMPOSE_OPTION ) && ( choice != TRAJET_SIMPLE_OPTION ) ) 
    {
        cout << "Choisissez l'option que vous souhaitez : ";
        cin >> choice;
    }

    if ( choice == TRAJET_SIMPLE_OPTION ) 
    {
        // edition du depart
        cout << "Départ : ";
        cin >> depart;

        // edition de l'arrivee 
        cout << "Arrivée : ";
        cin >> arrivee;

        // edition du moyen de transport
        cout << "Moyen de transport : ";
        cin >> moyenTransport;

        // creation du trajet simple, puis insertion dans le catalogue
        trajet = new TrajetSimple ( depart, arrivee, moyenTransport );
    } else 
    {
        // trajet composé
        unsigned int nbrTrajets, i;
        cout << "Combien de trajets voulez vous créer pour votre trajet composé : ";
        cin >> nbrTrajets;

        Collection* collectionTrajets  = new Collection ( nbrTrajets );

        for ( i = 0; i < nbrTrajets; i++ )
        {   
            // si ce n'est pas la premiere iteration, il faut voir que la ville de depart correspond a la
            // ville d'arrivee precedente

            cout << "Départ : ";
            if ( i != 0 ) 
            {
                while ( 1 ) 
                {
                    cin >> depart;
                    if ( strcmp ( depart, arrivee ) == 0 ) break;
                    cout << "Le nom de la ville de depart ne correspond pas a la ville d'arrivée précédente. Veuillez resaisir votre ville de départ." << endl;
                    cout << "Départ : ";
                }
            } else
            {
                // suppression et reallocation de arrivee
                delete [] arrivee;
                arrivee = new char [ MAX_TAILLE_STRING ];
                cin >> depart;
            }

            // edition de la ville d'arrivee
            cout << "Arrivée : ";
            cin >> arrivee;

            // edition du moyen de transport
            cout << "Moyen de transport : ";
            cin >> moyenTransport;

            trajet = new TrajetSimple ( depart, arrivee, moyenTransport );

            // ajout du trajet dans la collection
            collectionTrajets->Ajouter ( trajet );

            // suppression et reallocation des chaines de caracteres
            delete [] depart;
            delete [] moyenTransport;
            depart = new char [ MAX_TAILLE_STRING ];
            moyenTransport = new char [ MAX_TAILLE_STRING ];

        }

        // creation du trajet compose
        trajet = new TrajetCompose ( collectionTrajets );
    }

    // liberations des allocations
    delete [] depart;
    delete [] arrivee;
    delete [] moyenTransport;

    catalogue.Ajouter ( trajet );
} // fin de ajouterTrajet

void Interface::afficherCatalogue ( void ) const
{
    catalogue.Afficher ( );
} // fin de afficherCatalogue

// ---------------- Constructeurs - destructeur
Interface::Interface ( void ) 
    : catalogue ( )
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe <Interface>" << endl;
    #endif
} // fin de Interface (constructeur par defaut)

Interface::~Interface ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de la classe <Interface>" << endl;
    #endif
} // Fin de ~Interface