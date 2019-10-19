/*************************************************************************
                        TrajetCompose  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par  Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <Menu> (fichier Menu.h) ---
#if ! defined ( MENU_H )
#define MENU_H

// ---------------------- Interfaces utilisees
#include "Catalogue.h"

// ---------- CONSTANTES
// constantes pour le menu principal
const int AJOUTER_TRAJET  = 1;
const int AFFICHAGE_CATALOGUE = 2;
const int RECHERCHER_PARCOURS = 3;
const int QUITTER_APPLICATION = 4;

// constantes pour le choix entre trajet simple et trajet composé
const unsigned int TRAJET_SIMPLE_OPTION = 1;
const unsigned int TRAJET_COMPOSE_OPTION = 2;

const unsigned int MAX_TAILLE_STRING = 64;

class Menu 
{

    //------------------- PARTIE PUBLIQUE
    public:
        //--------- Constructeurs et destructeur
        Menu ( void );
        // Mode d'emploi
            // La classe <Menu> permet de gérer les inputs de l'utilisateur et
            // de faire le lien entre l'utilisateur et le catalogue des trajets

        virtual ~Menu ( );
        // Destructeur de la classe <Menu>

        void Run ( void );
        // La méthode "Run" permet de démarrer l'application

    // ---------- PARTIE PROTÉGÉE
    protected:
        // ---------- Méthodes protégées
        void afficherMenu ( void ) const;
        // La méthode "afficherMenu" permet d'afficher le menu des options possibles
        // de l'application

        void rechercherTrajet ( void ) const;
        // La méthode "rechercherTrajet" permet à l'utilisateur de rechercher un trajet

        void ajouterTrajet ( void );
        // La méthode "ajouterTrajet" permet à l'utilisateur d'ajouter un trajet

        void afficherCatalogue ( void ) const;
        // La méthode "afficherCatalogue" permet à l'utilisateur de voir le catalogue 
        // de trajets

    private:
        Catalogue* catalogue;
};

#endif