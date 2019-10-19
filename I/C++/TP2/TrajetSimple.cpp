/*************************************************************************
                        TrajetSimple  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Alexandre DUFOUR
    e-mail               : alexandre.dufour@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void    TrajetSimple::Afficher ( ) const
{
	cout << "de " << depart << " à " << arrivee << " en " << moyenTransport;
}


const char*     TrajetSimple::GetVilleDepart ( ) const
{
	return (depart);
}

const char*     TrajetSimple::GetVilleArrivee ( ) const
{
	return (arrivee);
}


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const char * villeDepart, const char * villeArrivee, const char * moyTrans )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple> : ";
    cout << villeDepart << " -> " << villeArrivee;
    cout << " par " << moyTrans << endl;
#endif
    int villeDepartLongueur, villeArriveeLongueur, moyenTransportLongueur;

    villeDepartLongueur = strlen ( villeDepart );
    villeArriveeLongueur = strlen ( villeArrivee );
    moyenTransportLongueur = strlen ( moyTrans );

    // alloue de la memoire pour les char*
    depart = new char [ villeDepartLongueur + 1 ];
    arrivee = new char [ villeArriveeLongueur + 1 ];
    moyenTransport = new char [ moyenTransportLongueur + 1 ];

    strncpy ( depart, villeDepart, villeDepartLongueur + 1 );
    strncpy ( arrivee, villeArrivee, villeArriveeLongueur + 1 );
    strncpy ( moyenTransport, moyTrans, moyenTransportLongueur + 1 );
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
    delete [] depart;
    delete [] arrivee;
    delete [] moyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

