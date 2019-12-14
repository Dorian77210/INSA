/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : 04/12/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <FileIO> (fichier FileIO.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "./../includes/Referers.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
uint Referers::GetTotal ( ) const
// Algorithme : aucun
{
    return hits;
} // ----- Fin de GetTotal

unordered_map<uint, uint> Referers::GetOccurences ( ) const
// Algorithme : aucun
{
    return occurences;
} // ------ Fin de GetOccurences

void Referers::AddReferer ( uint referer )
// Algorithme : aucun
{
    hits++;
    if ( occurences.find ( referer ) == occurences.end ( ) )
    {
        // on ajoute
        occurences [ referer ] = 1;
    } else
    {
        occurences [ referer ]++;
    }
} // ----- Fin de AddReferer

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Referers::Referers ( )
// Algorithme : aucun
    : hits ( 0 ),
    occurences ( )
{
} // ----- Fin du constructeur par défaut de Referers

Referers::Referers ( const Referers & copy )
// Algorithme : aucun
    : hits ( copy.hits ),
    occurences ( copy.occurences )
{
} // ------ Fin du constructeur par copie de Referers

Referers::~Referers ( )
// Algorithme : aucun
{
} // ---- Fin du destructeur de Referers

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
