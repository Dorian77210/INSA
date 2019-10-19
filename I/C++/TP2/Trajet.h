/*************************************************************************
                           Trajet.h  -  Interface de la classe Trajet
                            La classe <Trajet> est une classe qui represente un parcours
                            et qui sert de base pour les trajets simples et 
                            composés.                           
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//------------------ Interface de la classe <Trajet> (fichier Trajet.h)----------
#if ! defined ( TRAJET_H )
#define TRAJET_H

// La classe a pour rôle de représenter un trajet. Elle sert de classe mère pour les
// classes <TrajetSimple> et <TrajetCompose>

class Trajet 
{
    //--------------------------- PARTIE PUBLIQUE
    public: 
        //-------- Constructeurs et destructeur ----------
        Trajet ( );
        // Mode d'emploi 
            // La classe <Trajet> construit un trajet

        virtual ~Trajet ( );
        // Deconstructeur de la classe

        //------------------------------- Méthodes publiques
        virtual void Afficher ( ) const = 0;
        // La méthode "Afficher" permet d'afficher le trajet 
        // Cette methode a obligation d'etre redefinie dans les classes enfants

        virtual const char* GetVilleDepart ( ) const = 0;
        // La methode "GetVilleDepart" permet de recuperer la ville de depart du trajet
        // Cette methode a obligation d'etre redefinie dans les classes enfants
        
        virtual const char* GetVilleArrivee ( ) const = 0;
        // La methode "GetVilleArrivee"  permet de recuperer la ville d'arrivee du trajet
        // Cette methode a obligation d'etre redefinie dans les classes enfants

        bool EstValide ( const char* _depart, const char* arrive ) const;
        // La methode "EstValide" permet de verifier que le trajet courant est cohérent
        // avec un depart et une arrivee
        // Le parametre "_depart" represente le depart desiré
        // Le parametre "_arriveee" represente l'arrivee desirée
};

#endif