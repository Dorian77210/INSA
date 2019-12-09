/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : 04/12/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Referers> (fichier Referers.h) ----------------
#if ! defined ( REFERERS_H )
#define REFERERS_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <unordered_map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
using uint = unsigned int;

//------------------------------------------------------------------------
// Rôle de la classe <Referers>
// Interface de la classe Referers.
// Cette classe permet de stocker les associations entre 
// des villes de départ et un nombre total de hits.
//------------------------------------------------------------------------

class Referers
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    uint GetTotal ( ) const;
    // Mode d'emploi :
    // Cette méthode permet de récupérer le nombre total de hits d'une page.

    unordered_map<uint, uint> GetOccurences ( ) const;
    // Mode d'emploi :
    // Permet de récupérer la map de correspondances entre un referer
    // et le nombre de fois qu'on est parti de ce referer.

    void AddReferer ( uint referer );
    // Mode d'emploi :
    // Permet d'ajouter un referer pour une page destination donnée.
    // La méthode a deux cas de figure :
    //      - Si le referer existe déjà, le nombre d'occurences incrémentera
    //      - Sinon, on ajoute une entrée dans la map avec un nombre d'occurence 
    // à 1. 

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Referers ( );
    // Mode d'emploi :
    // Constructeur par défaut de la classe <Referers>.

    Referers ( const Referers & copy );
    // Mode d'emploi :
    // Constructeur par copie de la classe <Referers>.

    virtual ~Referers ( );
    // Mode d'emploi :
    // Destructeur de la classe Referers.    
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    uint hits;
    unordered_map<uint, uint> occurences;
};

#endif // REFERERS_H
