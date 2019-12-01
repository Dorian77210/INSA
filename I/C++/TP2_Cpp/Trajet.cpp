/*************************************************************************
                        Trajet  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

// ---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) -------

// --------- INCLUDE SYSTEMES
#include <cstring>
#include <iostream>

using namespace std;
// --------- Include personnel
#include "Trajet.h"

// ---------------- Methodes publiques
bool Trajet::EstValide ( const char* _depart, const char* _arrivee ) const
{
    const char* depart = GetVilleDepart ( );
    const char* arrivee = GetVilleArrivee ( );

    return ( strcmp ( arrivee, _arrivee ) == 0 && strcmp ( depart, _depart ) == 0 );
} // Fin de EstValide

// ----------------- Constructeurs - destructeur
Trajet::Trajet ( ) 
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe <Trajet>" << endl;
    #endif
} // Fin de Trajet (constructeur par defaut de la classe Trajet)

Trajet::~Trajet ( ) 
{
    #ifdef MAP
        cout << "Appel au destructeur de la classe <Trajet>" << endl;
    #endif
} // Fin de ~Trajet (destructeur)