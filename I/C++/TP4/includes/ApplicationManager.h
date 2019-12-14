/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : 04/12/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ApplicationManager> (fichier ApplicationManager.h) ----------------
#if ! defined ( APPLICATION_MANAGER_H )
#define APPLICATION_MANAGER_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <utility>

#include "./Graph.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
using uint = unsigned int;

//------------------------------------------------------------------------
// Rôle de la classe <ApplicationManager>
// Interface de la classe ApplicationManager.
// Cette classe fait le lien entre l'application, l'import/export de données
// et la gestion du graphe.
//------------------------------------------------------------------------

class ApplicationManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Configure ( uint argc, const char **argv);
    // Mode d'emploi :
    // Permet de configurer les filtres ou actions
    // renseignés par les options sur la ligne de commande.
    // La méthode renverra true si il n'y a pas eu d'erreurs au niveau
    // des arguments, sinon false (par exemple, si l'utilisateur mentionne
    // l'option -t mais qu'il ne mentionne pas d'heure).

    bool ExecuteAnalyze ( );
    // Mode d'emploi :
    // Cette méthode va engendrer la lecture et le traitement du fichier
    // log passé en ligne de commande. C'est par le biais de cette
    // que le graphe pourra être généré et que le top 10 sera affiché.
    // Cette méthode renverra true si l'analyse s'est correctement passée,
    // sinon elle renverra false s'il y a eu une erreur pendant l'analyse.

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    ApplicationManager ( );
    // Mode d'emploi :
    // Constructeur par défaut de la classe <ApplicationManager>

    virtual ~ApplicationManager ( );
    // Mode d'emploi :
    // Destructeur de la classe <ApplicationManager>

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    bool isValidHour ( uint _hour ) const;
    // Mode d'emploi :
    // Cette méthode permet de savoir si l'heure passé en paramètre est comprise dans
    // l'intervalle [hour, hour + 1].
    // La méthode renverra true si c'est la cas, sinon false.
    // Contrat d'uitlisation :
    // Cette méthode doit être appelée uniquement si l'utilisateur a précisé 
    // l'option -t au lancement de l'application. 

//----------------------------------------------------- Attributs protégés
    bool isExcludingFiles;
    bool isFilteringByHour;
    bool hasChoosenExportFile;
    string exportFilename;
    string importFilename;
    string baseURL;
    uint hour;
    Graph graph;

private:
    static const string HOUR_OPTION_FLAG;
    static const string EXPORT_OPTION_FLAG;
    static const string EXCLUDE_FILES_OPTION_FLAG;
    static const string CONFIG_FILENAME;

    static const uint INVALID_HOUR;
    static const pair<uint, uint> VALID_HOUR_INTERVAL;
};

#endif // APPLICATION_MANAGER_H
