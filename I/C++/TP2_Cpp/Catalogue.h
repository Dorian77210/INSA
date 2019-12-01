/*************************************************************************
                           Catalogue.h  -  Interface de la classe Catalogue
                           La classe <Catalogue> permet de gérer l'ensemble
                           des trajets durant la vie de l'application. Elle 
                           fait le rôle d'interface entre l'utilisateur et les 
                           données de l'applicationhttp://servifa-algo.insa-lyon.fr/domjudge/team/
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//------------------ Interface de la classe <Catalogue> (fichier Catalogue.h)----------

#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

// ---------------- INTERFACE UTILISEES
#include "Trajet.h"
#include "Collection.h"

class Catalogue 
{
    //--------------------------- PARTIE PUBLIQUE
    public: 
        //-------- Constructeurs et destructeur ----------
        Catalogue ( unsigned int _tailleMax =  COLLECTION_TAILLE_PAR_DEFAUT );
        // Mode d'emploi 
            // La classe <Catalogue> permet de construire un catalogue de trajets
            // Le parametre "_tailleMax" permet de definir une taille maximale par defaut pour la liste de trajets

        // Destructeur de la classe
        virtual ~Catalogue ( );

        //------------------------------- Méthodes publiques
        void Afficher ( void ) const;
        // La methode "Afficher" permet d'afficher le catalogue

        const Collection* GetCatalogue ( ) const;
        //La méthode "GetCatalogue" permet de recuperer la liste 
        // des trajets disponibles dans le catalogue
        // La methode renvoit le parametre "collectionTrajets" de maniere
        // constante pour qu'il soit pas modifiable or de son contexte

        void Rechercher ( const char* depart, const char* arrivee ) const;
        // La methode "Rechercher" permet à l'utilisateur de rechercher un trajet
        // en fonction d'un depart et d'une arrivee.
        // Cette recherche est simple (c'est à dire qu'elle ne cherche pas 
        // de combinaisons de trajets).

        void RechercheComplexe ( const char* depart, const char* arrivee ) const;
        // La methode "RechercheComplexe" permet à l'utilisateur de rechercher un
        // trajet en fonction d'un depart et d'une arrivee. La methode utilisera
        // un arbre afin de pouvoir afficher les trajets simples et les trajets composes
        // de trajets simples et/ou composes

        void Ajouter ( Trajet* trajet );
        // La methode "Ajouter" permet d'ajouter un trajet à la collection de trajets 

    protected:
        Collection* collectionTrajets;
};

#endif // CATALOGUE_H