/*************************************************************************
                        TrajetCompose  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Alexandre DUFOUR
    e-mail               : alexandre.dufour@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "Collection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher ( ) const
{
	unsigned int    taille;
    unsigned int    i;

    taille = listeTrajets->GetTaille();
    for (i = 0; i < taille; i++)
    {
        listeTrajets->GetTrajet(i)->Afficher();
        if (i != ( taille - 1 ) ) cout << " - ";
    }
} // Fin de Afficher


const char *TrajetCompose::GetVilleDepart ( ) const
{
	return (listeTrajets->GetTrajet(0)->GetVilleDepart());
} // Fin de GetVilleDepart

const char *TrajetCompose::GetVilleArrivee ( ) const
{
	return (listeTrajets->GetTrajet(listeTrajets->GetTaille() - 1)->GetVilleArrivee());
} // Fin de GetVilleArrivee


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( Collection* uneListeTrajets )
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose> : ";
    #endif
    listeTrajets = uneListeTrajets;
} //----- Fin de TrajetCompose (constructeur)


TrajetCompose::~TrajetCompose ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif

    delete listeTrajets;
} //----- Fin de ~TrajetCompose (destructeur)