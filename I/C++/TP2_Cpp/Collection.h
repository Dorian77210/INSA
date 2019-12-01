/*************************************************************************
                           Collection.h  -  Interface de la classe Collection
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//------------------ Interface de la classe <Collection> (fichier Collection.h)----------

#if ! defined ( COLLECTION_H )
#define COLLECTION_H

//--------- INCLUDES
#include "Trajet.h"

// ------ Constantes
const unsigned int COLLECTION_TAILLE_PAR_DEFAUT = 10;
const unsigned int FACTEUR_REDIMENSIONNEMENT = 10;

class Collection 
{
    //--------------------------- PARTIE PUBLIQUE
    public: 
        //-------- Constructeurs et destructeur ----------
        Collection ( unsigned int tailleMax = COLLECTION_TAILLE_PAR_DEFAUT );
        // Constructeur permettant de creer un collection de trajets
        // Le parametre "tailleMax" definit la taille maximale de la collection
        
        virtual ~Collection ( );
        // Destructeur d'une collection. Il permet de supprimer tous les trajets 
        // associés à la collection

        //------------------------------- Méthodes publiques
        void Ajouter ( const Trajet* trajet );
        // La methode "Ajouter" permet d'ajouter un trajet dans la collection courante
        // Le parametre "trajet" est le trajet à ajouter dans la collection. Il est constant
        // car nous partons du principe que nous pourrons pas le modifier

        const Trajet* GetTrajet ( unsigned int index ) const;
        // Permet de recuperer un trajet dans la collection a l'indice "index"
        // L'indice "index" est utilisé pour trouver le trajet dans l'attributs "trajets"

        unsigned int GetTaille ( ) const;
        // Permet de recuperer la taille de la collection. Cette méthode peut 
        // être utilisée pour itérer sur les trajets par exemple.

    //----------------------- PARTIE PRIVEE
    private:
        //--------------- Méthodes privées
        void reajuster ( void );
        // Methode qui permet d'augementer la capacité du tableau de trajets. 
        // A chaque appel de rajuster, le capacité du tableau est augmenté de la constante
        // "FACTEUR_REDIMENSIONNEMENT"

    //----------------------- PARTIE PROTEGEE
    protected:
        unsigned int tailleMax;
        unsigned int tailleCourante;
        Trajet const ** trajets;
};

#endif // COLLECTION_H