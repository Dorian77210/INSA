// Interface définissant une classe Ensemble (fichier Ensemble.h) qui représente
// un ensemble d'entiers au sens mathématique

#if ! defined( ENSEMBLE_H )
#define ENSEMBLE_H

#define nullptr 0

////////////////////////: INCLUDE
//------------ Include système
#include <iostream>

//--------------------------------------- Constantes
// La constante CARD_MAX correspond a la cardiniaité maximale par défaut
// si l'utilisateur ne donne pas de cardinalité maximale lors de la création de l'ensemble
// (en utilisant le premier constructeur)
const int CARD_MAX = 5;

typedef enum { NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE } crduEstInclus;
typedef enum { DEJA_PRESENT, PLEIN, AJOUTE } crduAjouter;

//---------------------------------------- Types
// La constante CARD_MAX est un entier

class Ensemble
{
    //--------------------- PUBLIC
    
    public:
    //--------------------- Méthodes publiques
    
    crduAjouter Ajouter ( int toAdd );
    // La méthode "Ajouter" permer d'ajouter un element a l'ensemble
    // Elle renvoit DEJA_PRESENT si "toAdd" est deja present dasn l'ensemble
    // Elle renvoit "PLEIN" si il n'y a plus de place dans l'ensemble
    // Elle renvoit "AJOUTE" si l'element a pu etre ajouter

    void Afficher( void );
    // La méthode "Afficher" ne prend aucun paramètre
        // Mode d'emploi : 
        // Seulement faire un appel à la méthode "Afficher" 
        // Contrat : 
        // aucun

    
    unsigned int Ajuster ( int delta );
    // La methode "Ajuster" permet d'ajuster la taille de l'ensemble
    // Le parametre "delta" permet de savoir si on doit retrecir ou agrandir l'ensemble
    // La méthode retourne la nouvelle cardnialite maximale

    bool EstEgal ( const Ensemble & otherSet ) const;
        // La méthode "EstEgal" permet de savoir
        // Mode d'emploi
        // Le parametre "otherSet" est un ensemble avec lequel on doit tester l'egalite

    crduEstInclus EstInclus ( const Ensemble & otherSet ) const;
        // La méthode "EstInclus" verifie qu'un ensemble est inclus dans un autre
        // Mode d'emloi
        // Le parametre "otherSet" est l'ensemble avec lequel on doit tester le type d'inclusion
        // La méthode renvoit INCLUSION_LARGE si les deux ensembles sont egaux
        // NON_INCLUSION si les deux ensembles sont différents
        // INCLUSION_STRICTE si le cardnial de otherSet est superieur a l'objet courant et que l'objet courant est inclus dans otherSet

    unsigned int Intersection ( const Ensemble & set );
        // La methode "Intersection" permet de garder les elements communs entre 
        // l'ensemble courant et "set"
        // La methode retourne le nombre d'elements qui ont ete supprime

    bool Retirer ( int element );
        // La methode "Retirer" permet de retirer un element dans l'ensemble
        // Si l'element est present, il sera retire
        // Quoi qu'il arrive, le cardinlite max = cardinalite courante

    unsigned int Retirer ( const Ensemble & set );
        // La methode "Retirer" permet de retirer un ensemble d'elements a l'ensemble courant
        // La methode renvoit le nombre d'elements qui ont ete retire
        //Le parametre "set" represente l'ensemble des elements a retirer

    int Reunir ( const Ensemble & unEnsemble );
        // La methode "Reunir" permet de prendre les elements de "unEnsemble" qui ne sont pas
        // presents dans l'ensemble courant et de les rajouter

    //--------------------- COnstructeurs - destructeur
    Ensemble ( unsigned int cardMax = CARD_MAX );
        // Mode d'emploi
        // Ce constructeur permet de créer un ensemble vide avec une taille maximale
        // donnée en paramètre (ou avec la valeur CARD_MAX) si le paramètre card_max est omis
        // Contrat :
        // Le paramètre card_max >= 0

    Ensemble ( int t[], unsigned int nbElements );
    // Mode d'emploi
    // Ce constructeur permet de créer un ensemble contenant les singletons du tableau "t" passé en paramètre
    // Il prend également en paramètre le nombre d'éléments que nous voulons ajouter dans l'ensemble
    // Contrat de cohérence
    // Le paramètre "nbElements" doit être <= à la taille réelle de "t"


    virtual ~Ensemble( );    
        // Mode d'emploi
        // Ce destructeur permet de supprimer l'ensemble


    protected:
    //------------------ Méthodes protégées
    void resize ( void );
    // La méthode "copyOf" permet de creer une copie de l'ensemble des elements avec une nouvelle taille

    void sort ( void );
    // La méthode "sort" permet de créer une copie triée du tableau d'éléments
        // Mode d'emploi
        // appeler la méthode
        // Contrat

    void shift ( unsigned int begin );
    // La methode permet de deplacer tous les elements a partir d'un index
    // Le parametre "begin" represente le debut pour decaler

    bool isSorted( void ) const;
    // La méthode "isSorted" permet de savoir si un tableau est trié 
    // Elle renvoit vrai si le tableau est trié, faux sinon

    bool isPresent( int value ) const;
    // La methode "isPresent" permet de savoir si un element est dans l'ensemble
    // Elle renvoit vrai si l'element est present, sinon false

    int getElementByIndex ( int element ) const;
    // La methode "getElementByIndex" permet de recuperer l'index 
    // d'un element, si ce-dernier est present
    // La methode renvoit l'index de l'element s'il est present, sinon une valeur negative 

    bool isSingleton( int value );
    // La méthode statique "isSingleton" permet de savoir si un "element" est présent dans "t"
        // Mode d'emploi
        // Le parametre "value" correspond a la valeur a tester

    //------------------- Attributes protégés
    // cardMax : correspond à la cardinalité maximale de l'ensemble
    unsigned int cardMax;

    // currentCard : correspond à la cardinialité courante de l'ensemble
    unsigned int currentCard;

    // elements : correspond a la collection d'elements de l'ensemble
    int* elements;
};  

#endif