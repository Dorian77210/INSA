/*************************************************************************
                        TrajetSimple  -  La classe <TrajetSimple> est une représentation
                        d'un trajet qui dispose d'un départ et d'une arrivée
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Alexandre DUFOUR
    e-mail               : alexandre.dufour@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
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
    TrajetSimple ( const char * villeDepart, const char * villeArrivee, const char * moyTrans );
    // Mode d'emploi :
    //  Construit un trajet simple en initialisant ses attributs.
    // Le parametre "villeDepart" represente la source du trajet
    // Le parametre "villeArrivee" represente la destination du trajet
    // Le parametre "moyTran" represente le moyen de transport pour ce trajet

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //  Détruit en profondeur le trajet simple. (les chaines de caracteres)

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char    *depart;
    char    *arrivee;
    char    *moyenTransport;
};

//----------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

