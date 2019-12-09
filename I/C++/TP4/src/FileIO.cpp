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
#include <fstream>
#include <sstream>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "../includes/FileIO.h"

//------------------------------------------------------------- Constantes
const string FileIO::IMPORT_TXT_EXTENSION = "txt";
const string FileIO::IMPORT_LOG_EXTENSION = "log";
const string FileIO::EXPORT_FILE_EXTENSION = "dot";
const vector<string> FileIO::EXCLUDING_FILES_EXTENSION = {
    "png", "jpg", "gif", "css", "js", "jpeg"
};
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string FileIO::ReadFile ( string filename )
// Algorithme :
{
    // test de l'ouverture du fichier
    ifstream infile ( filename, ifstream::binary );
    if ( !infile )
    {
        // erreur d'ouverture
        cerr << "Erreur lors de l'ouverture du fichier " << filename << "." << endl;
        return "";
    }

    stringstream buffer;
    if( ! ( buffer << infile.rdbuf ( ) ) )
    {
        cerr << "Erreur durant la lecture du fichier " << filename << "." << endl;
        infile.close ( );
        return "";
    }

    infile.close ( );

    return buffer.str ( );

} //----- Fin de ReadFile

bool FileIO::WriteFile ( string data, string filename )
// Algorithme : aucun
{
    bool result = true;
    ofstream outfile ( filename );
    if ( !outfile )
    {
        cerr << "Erreur lors de l'ouverture du fichier " << filename << "." << endl; 
        return false;
    }

    if ( ! ( outfile << data ) )
    {
        cerr << "Erreur lors de l'écriture dans le fichier " << filename << "." << endl;
        outfile.close ( );
        result = false;
    }

    outfile.close ( );
    return result;
} // ------ Fin de WriteFile

bool FileIO::IsValidImportFileExtension ( string filename )
// Algorithme : aucun
{
    size_t lastPointIndex = filename.find_last_of ( "." );
    string currentExtension = filename.substr ( lastPointIndex + 1 );
    return ( currentExtension == IMPORT_LOG_EXTENSION ) || ( currentExtension == IMPORT_TXT_EXTENSION );
} // ----- Fin de IsValidFileExtension

bool FileIO::IsValidExportFileExtension ( string filename )
// Algorithme : aucun
{
    size_t lastPointIndex = filename.find_last_of ( "." );
    string currentExtension = filename.substr ( lastPointIndex + 1 );
    return currentExtension == EXPORT_FILE_EXTENSION;
} // ----- Fin de IsValidExportFileExtension

bool FileIO::IsExcludedFile ( string filename )
// Algorithme : aucun
{
    size_t lastPointIndex = filename.find_last_of ( "." );
    string currentExtension = filename.substr ( lastPointIndex + 1 );

    return find ( EXCLUDING_FILES_EXTENSION.begin ( ), EXCLUDING_FILES_EXTENSION.end ( ), currentExtension ) != EXCLUDING_FILES_EXTENSION.end ( ); 
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
