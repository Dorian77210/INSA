/*************************************************************************
                        Noeud  -  Classe qui represente un noeud
                        dans un arbre de trajets 
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

// ---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) -------

// --------------- INCLUDES SYSTEMES
#include <iostream>
#include <cstring>

// -------------- INCLUDES SYSTEMES
#include <iostream>
using namespace std;
// -------------- Includes personnels
#include "Noeud.h"
#include "Trajet.h"
#include "Collection.h"

// --------------- Partie publique

// ------------- Methodes publiques
bool Noeud::Ajouter ( const Trajet* trajet, const char* arrivee )
{
    const char* trajetArrivee = trajet->GetVilleArrivee ( );
    const char* trajetDepart = trajet->GetVilleDepart ( );
    const char* departAssocie = trajetAssocie->GetVilleDepart ( );
    const char* arriveeAssociee = trajetAssocie->GetVilleArrivee ( );

    bool estAjoute = false;

    if ( enfant != NOEUD_NULL ) estAjoute = estAjoute || enfant->Ajouter ( trajet, arrivee );
    if ( prochain != NOEUD_NULL ) estAjoute = estAjoute || prochain->Ajouter ( trajet, arrivee );
    if ( strcmp ( trajetArrivee, arrivee ) == 0 ) 
    {
        // on arrive en fin de branche, cette branche est donc un trajet possible
        if ( estTrajetDirect ) return false; // pas besoin d'ajouter de noeuds puisqu'un trajets directs n'a pas besoin d'enfants

        estValide = true;
        // creation du noeuf enfant ou rajout a la fin de l'enfant
        if ( strcmp ( arriveeAssociee, trajetDepart ) == 0 ) 
        {
            if ( enfant == NOEUD_NULL ) 
            {
                enfant = new Noeud ( trajet, this );
                enfant->estValide = true;
            } else
            {
                Noeud* voisin = enfant->AjouterVoisin ( trajet );
                voisin->estValide = true;
            }

            estAjoute = estAjoute || true;
        } else
        {
            return false; // on ne peut pas ajouter de noeud
        }

        // on remonte dans l'arbre
        Noeud* _parent = parent;
        while ( _parent != NOEUD_NULL ) 
        {
            _parent->estValide = true;
            _parent = _parent->parent;
        }
    } else if ( strcmp ( departAssocie, trajetDepart ) == 0 && strcmp ( arriveeAssociee, arrivee ) != 0 )
    {
        // doit ajouter un voisin
        AjouterVoisin ( trajet );
        estAjoute = estAjoute || true;
    } else if ( strcmp ( arriveeAssociee, trajetDepart ) == 0 && strcmp ( arriveeAssociee, arrivee ) != 0 ) 
    {
        // ajout de l'enfant
        if ( enfant == NOEUD_NULL )
        {
            enfant = new Noeud ( trajet, this );
        }
        else 
        {
            AjouterVoisin ( trajet );
        }

        estAjoute = estAjoute || true;
    } else {
        // arrive != depart, fin de branche
        estAjoute = estAjoute || false;
    }

    return estAjoute;
} // Fin de Ajouter

Noeud* Noeud::AjouterVoisin ( const Trajet* trajet )
{
    Noeud* courant;

    for ( courant = this; courant->prochain != NOEUD_NULL; courant = courant->prochain );

    Noeud* noeud = new Noeud ( trajet, parent );
    courant->prochain = noeud;

    return noeud;
} // Fin de AjouterVoisin

void Noeud::Afficher ( void ) 
{
    // Algorithme recursif pour afficher les trajets valides
    Noeud* noeud;
    for ( noeud = this; noeud != NOEUD_NULL; noeud = noeud->prochain )
    {
        if ( noeud->estValide ) 
        {
            if ( noeud->estTrajetDirect ) 
            {
                noeud->trajetAssocie->Afficher ( );
                cout << endl;
            } else {
                 if ( noeud->enfant != NOEUD_NULL ) 
                {
                    noeud->enfant->Afficher ( );
                } 
                else
                {
                    // on arrive en fin de branche
                    noeud->afficher ( );
                }   
            }
        } 
    }
} // Fin de Afficher

const bool Noeud::EstValide ( void ) const
{
    return estValide;
} // Fin de EstValide

const Noeud* Noeud::GetVoisin ( void ) const
{
    return prochain;
} // Fin de GetVoisin

void Noeud::SetEstValide ( bool _estValide ) 
{
    estValide = _estValide;
} // Fin de SetEstValide

void Noeud::SetEstTrajetDirect ( bool _estTrajetDirect ) 
{
    estTrajetDirect = _estTrajetDirect;
} // Fin de SetEstTrajetDirect


// ------- Partie privee
void Noeud::afficher ( void ) 
{
    if ( parent != NOEUD_NULL ) 
    {
        parent->afficher ( );
        trajetAssocie->Afficher ( );
        if ( enfant != NOEUD_NULL ) 
        {
            cout << " - ";
        } else 
        {
            cout << endl;
        }
    } else
    {
        trajetAssocie->Afficher ( );
        cout << " - ";
    }
} // Fin de afficher

// ---------------------- Constructeur - destructeur
Noeud::Noeud ( const Trajet* _trajetAssocie, Noeud* _parent, bool _estTrajetDirect ) 
    : estValide ( false ), estTrajetDirect ( _estTrajetDirect )
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe <Noeud>" << endl;
    #endif

    trajetAssocie = _trajetAssocie;
    parent = _parent;
    enfant = prochain = NOEUD_NULL;
} // Fin de Noeud (constructeur)

Noeud::~Noeud ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de la classe <Noeud>" << endl;
    #endif

    if ( enfant != NOEUD_NULL ) delete enfant;
    if ( prochain != NOEUD_NULL ) delete prochain;
} // Fin de ~Noeud