/*************************************************************************
                           Noeud.h  -  Interface de la classe Noeud
                            La classe <Noeud> est une classe qui servira
                            lors d'une recherche approfondi des trajets
                            disponibles. Cette classe est uniquement
                            utilisé dans le cadre de la recherche complexe
                            de trajets.
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//------------------ Interface de la classe <Noeud> (fichier Noeud.h)----------
#if ! defined ( NOEUD_H )
#define NOEUD_H

#define NOEUD_NULL 0

// ----- Includes personnels
#include "Trajet.h"

// La classe a pour rôle de représenter un noeud dans une arbre
// de trajets.

class Noeud 
{
    //--------------------------------- PARTIE PUBLIQUE
    public:
        // ------------ Constructeur et destructeur -----------
        Noeud ( const Trajet* _trajetAssocie, Noeud* _parent = NOEUD_NULL, bool _estTrajetDirect = false );
        // Mode d'emploi
            // Le parametre "_trajetAssocie" est le trajet que le noeud courant stockera
            // Le parametre "parent" represente le parent du noeud courant dans un arbre
        
        virtual ~Noeud ( );
        // Destructeur de la classe Noeur
        // Permettra de detruire le parent et les enfants associe au noeud courant

        // ---------- Methodes publiques
        bool Ajouter ( const Trajet* trajet, const char* arrivee );
        // La methode "Ajouter" permet de d'ajouter un trajet dans l'arborescence
        // Le parametre "trajet" represente le trajet a ajouter
        // le parametre "arrivee" permet de savoir si on a atteint la fin d'une branche ou non
        // Elle renvoit "true" si le trajet a ete ajoute à l'arbre des possibilites, false sinon

        Noeud* AjouterVoisin ( const Trajet* trajet );
        // La methode "AjouterNoeud" permet d'ajouter un noeud en fin de liste chainee (CF. voisin)
        // Le parametre "noeud" represente le nouveau noeud a ajouter
        // Cette methode renvoit le nouveau noeud ajouté.

        const Noeud* GetVoisin ( void ) const;
        // La methode "GetVosin" permet de recuperer le maillon suivant du noeud courant.
        // Cette méthode est utilisée pour savoir si un arbre de recherche contient ou non
        // des possibilités de trajets

        void Afficher ( void );
        // La methode "Afficher" permet d'afficher un trajet de maniere recursive

        const bool EstValide ( void ) const;
        // La methode "EstValide" permet de retourner l'attribut "estValide"

        void SetEstValide ( bool _estValide );
        // La methode "SetEstValide" permet de modifier l'attribut "estValide"
        // Le parametre "_estValide" correspond a la nouvelle valeur de l'attribut "estValide"

        void SetEstTrajetDirect ( bool _estTrajetDirect );
        // La methode "SetEstTrajetDirect" permet de modifier l'attribut "estTrajetDirect"
        // Le parametre "_estTrajetDirect" correspond a la nouvelle valeur de l'attribut "estTrajetDirect"

    // ------------------------------- PARTIE PROTEGEE
    private:
        // ------ Methodes privees
        void afficher ( void );
        // Methode qui permet d'afficher une branche d'un arbre en remontant de parent en parent.
        // Cette méthode utilise la récursivité.

        Noeud* parent;
        Noeud* enfant;
        Noeud* prochain;
        bool estValide;
        bool estTrajetDirect;
        const Trajet* trajetAssocie;
}; 

#endif // NOEUD_H