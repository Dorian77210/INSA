/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : 04/12/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ----------------
#if ! defined ( GRAPH_H )
#define GRAPH_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
#include <unordered_map>

#include "./Referers.h"

using uint = unsigned int;

//------------------------------------------------------------- Constantes
const uint TOP_TEN = 10;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graph>
// Interface de la classe Graph.
// Cette classe fait le lien entre l'application, l'import/export de données
// et la gestion du graphe.
//------------------------------------------------------------------------

class Graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AddDocument ( string pageDestination, string pageReferer );
    // Mode d'emploi :
    // Cette méthode permet d'ajouter un lien entre une page destination et un referer.
    // La méthode va d'abords si les deux pages se trouvent dans les noeuds
    // déjà existants. Si ce n'est pas le cas, elle les ajoute.
    // Elle va ensuite ajouté un lien entre ces deux pages.

    string GetNBest ( uint n = TOP_TEN );
    // Mode d'emploi :
    // Cette méthode permet de récupérer le top N des des 
    // pages plus visitées. La valeur de N vaut 10 par défaut.


//------------------------------------------------- Surcharge d'opérateurs
    friend ostream & operator << ( ostream & out, const Graph & graph )
    {
        string buffer = "digraph {\n";
        
        // on récupère l'ensemble des noeuds
        unordered_map<string ,uint>::const_iterator nodesIt;

        for ( nodesIt = graph.nodes.begin ( ); nodesIt != graph.nodes.end ( ); ++nodesIt )
        {
            string pageName = nodesIt->first;
            uint pageId = nodesIt->second;

            buffer += "\tnode" + to_string ( pageId ) + " [label=\"" + pageName + "\"];\n";
        }

        // on recuperer les liens
        unordered_map<uint, Referers*>::const_iterator linksIt;

        for ( linksIt = graph.links.begin ( ); linksIt != graph.links.end ( ); ++linksIt )
        {
            uint pageDestinationId = linksIt->first;
            Referers *currentReferers = linksIt->second;

            unordered_map<uint, uint> occurences = currentReferers->GetOccurences ( );
            unordered_map<uint, uint>::iterator occurencesIt;

            for ( occurencesIt = occurences.begin ( ); occurencesIt != occurences.end ( ); ++occurencesIt )
            {
                uint hits = occurencesIt->second;
                uint refererId = occurencesIt->first;

                buffer += "\tnode" + to_string ( refererId ) 
                                 + " -> node" 
                                 + to_string ( pageDestinationId )
                                 + "[label=\"" + to_string ( hits ) + "\"];\n";
            }
        }

        buffer += "}";

        out << buffer;
        return out;
    }

    // Surcharge de l'opérateur <<
    // Cette surcharge va permettre de sérialiser le Graph dans un fichier par exemple.

//-------------------------------------------- Constructeurs - destructeur
    Graph ( );
    // Mode d'emploi :
    // Constructeur par défaut de la classe <Graph>

    virtual ~Graph ( );
    // Mode d'emploi :
    // Destructeur de la classe <Graph>

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    unordered_map<string, uint> nodes;
    unordered_map<uint, Referers*> links;
//----------------------------------------------------- Attributs protégés

private:
};

#endif // GRAPH_H
