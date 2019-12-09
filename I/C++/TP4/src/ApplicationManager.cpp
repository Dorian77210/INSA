/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : 04/12/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ApplicationManager> (fichier ApplicationManager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "../includes/ApplicationManager.h"
#include "../includes/FileIO.h"
#include "../includes/Graph.h"

//------------------------------------------------------------- Constantes

// Variables statiques à définir
const string ApplicationManager::HOUR_OPTION_FLAG = "-t";
const string ApplicationManager::EXPORT_OPTION_FLAG = "-g";
const string ApplicationManager::EXCLUDE_FILES_OPTION_FLAG = "-e";
const string ApplicationManager::BASE_INTRANET_URL = "http://intranet-if.insa-lyon.fr/";

const uint ApplicationManager::INVALID_HOUR = 0xFFFFFFFF;
const pair<uint, uint> ApplicationManager::VALID_HOUR_INTERVAL = pair<uint, uint>(0, 24);

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool ApplicationManager::Configure(uint argc, const char **args)
// Algorithme : State machine
{
    string currentArgument;

    if (argc == 0)
    {
        cerr << "Usage : ./analgo <options>." << endl;
        return false;
    }

    // on ne boucle pas sur le fichier
    for (uint i(0); i < argc; i++)
    {
        currentArgument = args[i];
        if (currentArgument == HOUR_OPTION_FLAG) // heure
        {
            // prochain argument attendu : l'heure attendu
            if (i < (argc - 1))
            {
                if ( isFilteringByHour )
                {
                    cerr << "Vous avez déjà donné une heure qui vaut " << hour << ". Veuillez réessayer en en utilisant qu'une seule." << endl;
                    return false;
                } 
                // on passe par un try catch pour vérifier que la conversion s'est bien faîte

                if ( i + 1 == ( argc - 1 ) )
                {
                    cerr << "Vous devez spécifié une heure avec l'option -t. Le dernier paramètre doit correspondre au nom du fichier." << endl;
                    return false;
                }
                
                try
                {
                    hour = stoul(args[++i]);
                }
                catch (const invalid_argument &e)
                {
                    cerr << "L'heure passée en paramètre (" << args[i] << ") n'est pas valide. Ce paramètre doit être un entier positif." << endl;
                    return false;
                }
                // verification des bornes
                if ((hour < VALID_HOUR_INTERVAL.first) || (hour > VALID_HOUR_INTERVAL.second))
                {
                    cerr << "L'heure passée en paramètre (" << args[i] << ") n'est pas valide." << endl;
                    cerr << "Elle doit supérieure ou égale à " << VALID_HOUR_INTERVAL.first
                         << " et inférieure ou égale à " << VALID_HOUR_INTERVAL.second << "." << endl;

                    return false;
                }

                hour = uint(hour);
                isFilteringByHour = true;
            }
            else
            {
                cerr << "Vous avez spécifié l'option " << HOUR_OPTION_FLAG << " sans spécifier d'heure." << endl;
                cerr << "Usage : ./analgo <options> -t <hour> <log>" << endl;
                return false;
            }
        }
        else if (currentArgument == EXPORT_OPTION_FLAG) // fichier d'export
        {
            if ( hasChoosenExportFile )
            {
                cerr << "Vous ne pouvez pas spécifié plus d'un fichier d'export." << endl;
                return false;
            }

            // prochain argument attendu : le fichier d'export
            if (i < (argc - 1))
            {
                // vérification de l'extension
                string filename = args[++i];
                if (!FileIO::IsValidExportFileExtension(filename))
                {
                    cerr << "Le fichier d'export doit avoir une extension en .dot. Le fichier " << currentArgument
                         << " ne possède pas cette extension." << endl;
                    return false;
                }

                exportFilename = filename;
                hasChoosenExportFile = true;
            }
            else
            {
                cerr << "Vous avez spécifié l'option " << EXPORT_OPTION_FLAG << " sans spécifier de fichier d'export." << endl;
                cerr << "Usage : ./analgo <options> -g <filename.dot> <log>" << endl;
                return false;
            }
        }
        else if (currentArgument == EXCLUDE_FILES_OPTION_FLAG) // option d'exlusion de fichier
        {
            if ( isExcludingFiles ) 
            {
                cerr << "Vous avez déjà spécifié l'option -e." << endl;
            } else
            {
                isExcludingFiles = true;
            }
        }
    }

    // nom du fichier
    currentArgument = args[argc - 1];
    if (!FileIO::IsValidImportFileExtension(currentArgument))
    {
        cerr << "Le fichier de log doit possèder une extension .txt ou .log. Le fichier " << currentArgument
             << " ne possède pas cette extension." << endl;
        return false;
    }

    importFilename = currentArgument;

    return true;
} // ------ Fin de Configure


bool ApplicationManager::ExecuteAnalyze()
// Algorithme : Traitement de chaine de caractères
{
    string fileContent, currentLine, currentRawHour, currentURL, currentReferer;
    string ipAddr, currentTime, request, status, data, navigator;
    size_t index;
    uint currentHour;

    // récuperation du contenu
    fileContent = FileIO::ReadFile(importFilename);
    if (fileContent.empty())
    {
        cerr << "Le fichier " << importFilename << " est vide ou n'existe pas. Il ne peut pas être traité." << endl;
        return false;
    }

    stringstream stream(fileContent);

    // analyse du fichier
    while (getline(stream, currentLine))
    {
        // on récupère les informations qui nous intéressent (referer, heure, page courante de la requête)
        
        // Adressse IP
        index = currentLine.find_first_of(" ");
        ipAddr = currentLine.substr(0,index);
        currentLine = currentLine.substr(index + 1);

        // Date
        index = currentLine.find_first_of("[");
        currentLine = currentLine.substr(index + 1);
        index = currentLine.find_first_of("]");
        currentTime = currentLine.substr(0, index);
        currentLine = currentLine.substr(index + 1);
        
        // Heure
        index = currentTime.find_first_of(":");
        currentTime = currentTime.substr(index + 1);
        index = currentTime.find_first_of(":");
        currentRawHour = currentTime.substr(0, index);

        currentHour = stoul(currentRawHour);
        if (isFilteringByHour)
        {
            if (!isValidHour(currentHour))
            {
                // on ne continue pas le traitement de la ligne courante
                continue;
            }
        }

        // Requête
        index = currentLine.find_first_of("\"");
        currentLine = currentLine.substr(index + 1);
        index = currentLine.find_first_of("\"");
        request = currentLine.substr(0, index);
        currentLine = currentLine.substr(index + 1);

        // récuperation de la page courante
        index = request.find_first_of(" ");
        request = request.substr(index + 1);
        index = request.find_first_of(" ");
        currentURL = request.substr(0, index);

        // Retire les paramètres de l'URL si ils existent
        index = currentURL.find_first_of("?");
        if (index != string::npos)
        {
            currentURL = request.substr(0, index);
        }

        // on verifie si on doit exclure l'url courante
        if (isExcludingFiles)
        {
            if (FileIO::IsExcludedFile(currentURL))
            {
                // on ne continue pas le traitement
                continue;
            }
        }

        // Status
        index = currentLine.find_first_of(" ");
        currentLine = currentLine.substr(index + 1);
        index = currentLine.find_first_of(" ");
        status = currentLine.substr(0, index);
        currentLine = currentLine.substr(index);

        // Données en octet
        index = currentLine.find_first_of(" ");
        currentLine = currentLine.substr(index + 1);
        index = currentLine.find_first_of(" ");
        data = currentLine.substr(0, index);
        currentLine = currentLine.substr(index + 1);

        // récuperation du referer
        index = currentLine.find_first_of("\"");
        currentLine = currentLine.substr(index + 1);
        index = currentLine.find_first_of("\"");
        currentReferer = currentLine.substr(0, index);
        currentLine = currentLine.substr(index + 1);

        // Retire les paramètres de l'URL si ils existent
        index = currentReferer.find_first_of("?");
        if (index != string::npos)
        {
            index = currentLine.find_first_of(" ");
            currentReferer = currentLine.substr(0, index);
        }

        // on vérifie que l'url de l'intranet est présente dans le referer, auquel on retire la base url
        if ( currentReferer.find ( BASE_INTRANET_URL ) == 0 )
        {
            currentReferer = currentReferer.substr ( BASE_INTRANET_URL.length ( ) );
        }

        if (isExcludingFiles)
        {
            if (FileIO::IsExcludedFile(currentReferer))
            {
                // on ne continue pas le traitement
                continue;
            }
        }
        // Navigateur
        index = currentLine.find_first_of("\"");
        currentLine = currentLine.substr(index + 1);
        index = currentLine.find_first_of("\"");
        navigator = currentLine.substr(0, index);

        graph.AddDocument(currentURL, currentReferer);
    }

    if (isFilteringByHour)
    {
        cout << "Attention : seuls les pages visitées entre " << hour << " et " << hour + 1 << " ont été prises en compte." << endl;
    }

    if (isExcludingFiles)
    {
        cout << "Attention : les images, fichiers css et javascript n'ont pas été pris en compte." << endl;
    }

    cout << graph.GetNBest() << endl;

    if ( hasChoosenExportFile )
    {
        stringstream buffer;
        buffer << graph;
        if ( ! FileIO::WriteFile ( buffer.str ( ), exportFilename ) )
        {
            cerr << "Erreur lors de l'exportation du graph dans le fichier " << exportFilename << endl;
            return false;
        }
    }

    return true;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
ApplicationManager::ApplicationManager()
    : isExcludingFiles(false),
      isFilteringByHour(false),
      hasChoosenExportFile(false),
      exportFilename(""),
      importFilename(""),
      hour(INVALID_HOUR),
      graph()
{

} // -------- Fin du constructeur par défault de ApplicationManager

ApplicationManager::~ApplicationManager()
// Alogrithme : aucun
{

} // -------- Fin du destructeur de ApplicationManager

//------------------------------------------------------------------ PRIVE

bool ApplicationManager::isValidHour(uint _hour) const
// Algorithme : aucun
{
    return (_hour >= hour) && (_hour <= hour + 1);
} // ------ Fin de isValidHour

//----------------------------------------------------- Méthodes protégées
