/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : 04/12/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Graph> (fichier Graph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>

//------------------------------------------------------ Include personnel
#include "../includes/Graph.h"
#include "../includes/Referers.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Graph::AddDocument ( string pageDestination, string pageReferer )
// Algorithme : aucun
{
    uint pageDestinationId, pageRefererId;
    Referers *referers  = nullptr;

    // récupération ou création de l'id de la page destination
    if ( nodes.find ( pageDestination ) == nodes.end ( ) )
    {
        // la page n'est pas un noeud
        pageDestinationId = nodes.size ( );
        nodes.emplace ( pageDestination, pageDestinationId );
    } else
    {
        pageDestinationId = nodes [ pageDestination ];
    }

    // récupération ou création de l'id de la page referer
    if ( nodes.find ( pageReferer ) == nodes.end ( ) )
    {
        // la page n'est pas un noeud
        pageRefererId = nodes.size ( );
        nodes.emplace ( pageReferer, pageRefererId );
    } else
    {
        pageRefererId = nodes [ pageReferer ];
    }

    // récupèration du referers
    if ( links.find ( pageDestinationId ) == links.end ( ) )
    {
        referers = new Referers ( );
        links.emplace ( pageDestinationId, referers );
    } else
    {
        referers = links [ pageDestinationId ];
    }

    referers->AddReferer ( pageRefererId );
} // ----- Fin de AddDocument

string Graph::GetNBest ( uint n )
// Algorithme : manipulation de dictionnaires
{
    string buffer;
    multimap<uint, uint> ranking;
    uint i, pageDestinationId, hits;
    unordered_map<uint, Referers*>::iterator it;
    unordered_map<string, uint>::iterator nodesIt;
    string page;

    for ( it = links.begin ( ); it != links.end ( ); ++it )
    {
        const Referers *link = it->second;
        ranking.emplace ( link->GetTotal ( ), it->first );
    }

    // on affiche au maximum les dix pages les plus visitées
    map<uint, uint>::reverse_iterator rIt;

    i = 0;
    for ( rIt = ranking.rbegin ( ); rIt != ranking.rend ( ) && i < n; ++rIt, i++ )
    {
        hits = rIt->first;
        pageDestinationId = rIt->second;

        // on cherche le nom de la page
        for ( nodesIt = nodes.begin ( ); nodesIt != nodes.end ( ); ++nodesIt )
        {
            if ( nodesIt->second == pageDestinationId )
            {
                page = nodesIt->first;
                break;
            }
        }

        buffer += page + " (" + to_string ( hits ) + " hits)\n";
    }

    return buffer;

} // ----- Fin de PrintNBest

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Graph::Graph ( )
// Algorithme : aucun    
    : nodes ( ),
    links ( )
{

} // ----- Fin du constructeur par défaut de Graph

Graph::~Graph ( )
// Algorithme : aucun
{
    for ( unordered_map<uint, Referers*>::iterator it = links.begin ( ); it != links.end ( ); ++it )
    {
        delete it->second;
    }
} // ------ Fin du destructeur de Graph


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
