/*************************************************************************
                        TrajetCompose  -  La classe <TrajetCompose> est une representation
                        d'un trajet composé de plusieurs autres trajets. Ces-derniers 
                        peuvet soit des trajets simples, soit des trajets composées.
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Alexandre DUFOUR
    e-mail               : alexandre.dufour@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Collection.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void    Afficher() const;
    // Mode d'emploi :
    //  Affiche les caractéristiques du voyage. Cette méthode est présente dans la classe 
    // mère <Trajet> mais elle a l'obligation d'etre redefinie.

    const char    *GetVilleDepart() const;
    // Mode d'emploi :
    //  Renvoie un pointeur sur la ville de départ du trajet (pas de copie).
    // Cette méthode est présente dans la classe 
    // mère <Trajet> mais elle a l'obligation d'etre redefinie.

    const char    *GetVilleArrivee() const;
    // Mode d'emploi :
    //  Renvoie un pointeur sur la ville d'arrivée du trajet (pas de copie).
    // Cette méthode est présente dans la classe 
    // mère <Trajet> mais elle a l'obligation d'etre redefinie.

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( Collection* uneListeTrajets );
    // Mode d'emploi :
    //  Construit un trajet composé en initialisant sa liste de trajets.
    // Le parametre "uneListeTrajets" est une collection de trajets

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //  Détruit en profondeur le trajet simple. (La liste des trajets)

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Collection*  listeTrajets;
};

//----------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

