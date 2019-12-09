/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : 04/12/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <FileIO> (fichier FileIO.h) ----------------
#if ! defined ( FILE_IO_H )
#define FILE_IO_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FileIO>
// Interface de la classe FileIO.
// Toutes les lectures/écritures de fichier se 
// feront via cette classe.
//------------------------------------------------------------------------

class FileIO
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static string ReadFile ( string filename );
    // Mode d'emploi :
    // Cette méthode permet de lire l'entièreté d'un fichier et 
    // de renvoyer son contenu.
    // Cette méthode affichera un message d'erreur si le fichier n'existe
    // pas ou si on n'arrive pas à ouvrir le fichier. De plus, elle retournera
    // un chaîne de caractère vide. 

    static bool WriteFile ( string data, string filename );
    // Mode d'emploi :
    // Cette méthode permet de sauvegarder le paramètre data dans le fichier
    // filename. Elle renverra true si l'écriture s'est bien passée, 
    // false sinon (si le fichier n'a pas pu être ouvert ou s'il y a eu
    // un problème pendant l'écriture).

    static bool IsValidImportFileExtension ( string filename );
    // Mode d'emploi :
    // Cette méthode si un fichier de log possède une extension valide.
    // Les extensions valides sont les .txt et .log. 
    // La méthode retournera true si l'extension du fichier correspond à une des 
    // deux extensions supportées, sinon false.

    static bool IsValidExportFileExtension ( string filename );
    // Mode d'emploi :
    // Cette méthode vérifie si un fichier d'export possède une extension valide.
    // La seule extension valide est .dot.
    // La méthode retournera true si l'extension du fichier est correcte, sinon false. 

    static bool IsExcludedFile ( string filename );
    // Mode d'emploi :
    // Cette méthode vérifie si un fichier doit être exclue de l'analyse du log.
    // Un fichier considérée comme exclu est soit une image, soit un fichier css
    // soit un fichier javascript.
    // La méthode renvoit true si le fichier est exclue, sinon false

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

private:
    static const string IMPORT_TXT_EXTENSION;
    static const string IMPORT_LOG_EXTENSION;
    static const string EXPORT_FILE_EXTENSION;

    static const vector<string> EXCLUDING_FILES_EXTENSION;
};

#endif // FILE_IO_H
