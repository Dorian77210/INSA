/*************************************************************************
                           Arbre.h  -  Interface de la classe Arbre
                           La classe <Arbre> est une classe qui represente
                           l'ensemble des trajets disponibles pour un depart
                           et une arrivee donnée
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//------------------ Interface de la classe <Arbre> (fichier Arbre.h)----------
#if ! defined ( ARBRE_H )
#define ARBRE_H

// ------- Includes personnels
#include "Noeud.h"
#include "Catalogue.h"

// La classe a pour rôle de représenter un arbre de possibilites de trajets

class Arbre 
{
    // ------------------------------ PARTIE PUBLIQUE
    public:
        // --------------------- Constructeur et destructeur --------------
        Arbre ( void );
        // Mode d'emploi

    virtual ~Arbre ( );
    // Destructeur de la clase Arbre
    // Permet de detruire l'ensemble des noeuds qui constituent l'arbre

    // ----------------- Methodes publiques
    void RechercherTrajetsPossibles ( const Catalogue* catalogue, const char* depart, const char* arrivee );
    // La methode "RechercherTrajetsPossibles" permet de rechercher les trajets
    // disponibles en fonction d'un depart et d'une arrivee
    // Le parametre "catalogue" represente le catalogue de tous les trajets possibles
    // Le parametre "depart" represente le depart desire
    // Le parametre "arrivee" represente l'arrivee desire

    void AfficherTrajetsPossibles ( void ) const;
    // La methode "AfficherTrajetsPossibles" permet d'afficher les trajets disponibles
    // en fonction d'un depart et d'une arrivee

    const bool ContientPossibilites ( void ) const;
    // La methode "ContientPossibilites" permet de savoir si l'arbre contient
    // des trajets possibles en fonction d'une arrivee et d'un depart

    // ------------------------------ PARTIE PRIVEE
    private:
        Noeud* base;
};

#endif