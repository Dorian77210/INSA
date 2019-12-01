/*************************************************************************
                        Interface  -  La classe <Interface> permet de gérer 
                        les inputs de l'utilisateur et
                        de faire le lien entre l'utilisateur et le catalogue des trajets
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par  Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <Interface> (fichier Interface.h) ---
#if ! defined ( INTERFACE_H )
#define INTERFACE_H

// ---------------------- Interfaces utilisees
#include "Catalogue.h"

// ---------- CONSTANTES
// constantes pour le Interface principal
const int AJOUTER_TRAJET  = 1;
const int AFFICHAGE_CATALOGUE = 2;
const int RECHERCHER_PARCOURS = 3;
const int QUITTER_APPLICATION = 4;

// constantes pour le choix entre trajet simple et trajet composé
const unsigned int TRAJET_SIMPLE_OPTION = 1;
const unsigned int TRAJET_COMPOSE_OPTION = 2;

// constantes pour choisir l'algorithme de recherche
const unsigned int RECHERCHE_BASIQUE = 1;
const unsigned int RECHERCHE_COMPLEXE = 2;

const unsigned int MAX_TAILLE_STRING = 64;
const unsigned int MAX_STREAM = 2147483647;

class Interface 
{

    //------------------- PARTIE PUBLIQUE
    public:
        //--------- Constructeurs et destructeur
        Interface ( void );
        // Constructeur de la classe <Interface>

        virtual ~Interface ( );
        // Destructeur de la classe <Interface>. 

        // ----------------------- Methodes publiques
        void Run ( void );
        // La méthode "Run" contient la logique principale de l'application. 
        // Elle créé une boucle infinie qui permet à l'utilisateur d'interagir
        // avec l'application. Cette boucle s'arrete si l'utilisateur décide de quitter
        // l'application

    // ---------- PARTIE PROTÉGÉE
    protected:
        // ---------- Méthodes protégées
        void afficherMenu ( void ) const;
        // La méthode "afficherMenu" permet d'afficher les actions utilisateurs
        // de l'application.

        void rechercherTrajet ( void ) const;
        // La méthode "rechercherTrajet" permet à l'utilisateur de rechercher un trajet


        void ajouterTrajet ( void );
        // La méthode "ajouterTrajet" permet à l'utilisateur d'ajouter un trajet

        void afficherCatalogue ( void ) const;
        // La méthode "afficherCatalogue" permet à l'utilisateur de voir le catalogue 
        // de trajets

    private:
        Catalogue catalogue;
};

#endif // INTERFACE_H