//--------- Programme main de test de la classe <Ensemble>
////////////////////////// INCLUDE

using namespace std;
#include <iostream>

//--------- Include personnel
#include "Ensemble.h"

// static void testAffichageEnsembleTU1 ( ) 
// {
//     Ensemble ensemble ( 0 );
//     ensemble.Afficher ( );
// }

// static void testDeuxiemeConstucteurAvecTableauVide ( ) 
// {
//     Ensemble ensemble ( nullptr, 5 );
//     ensemble.Afficher( );
// }

// static void testDeuxiemeConstucteurAvecTableauNonVide ( ) 
// {
//     int tab [] = { 0, 10, 109, -8, 67, -987878, 5464, 454, 2, 78 };
//     Ensemble ensemble ( tab, 10 );
//     ensemble.Afficher( );
// }

// static void testDeuxiemeTailleNull ( )
// {
//     int tab [] = { 0, 1, 2 };
//     Ensemble ensemble ( tab, 0 );
//     ensemble.Afficher ( );
// }

// static void testDeuxiemeDoublon ( ) 
// {
//     int tab [] = { 0, 0, 1, 2, 3, 4 };
//     Ensemble ensemble ( tab, 6 );
//     ensemble.Afficher ( );
// }

// static void testDeuxiemeTailleMin ( ) 
// {
//     int tab [] = { 0, 1, 2, 3, 4, 5678, 5, 4 };
//     Ensemble ensemble ( tab, 6 );
//     ensemble.Afficher ( );
// }


// void testTroisiemeEnsembleEgaux ( ) 
// {
//     int tab [] = { 0, 1, 2, 3 };
//     Ensemble p1 ( tab, 4 ), p2 ( tab, 4 );
//     cout << p1.EstEgal ( p2 ) << endl;
// }

// void testTroisiemeEnsembleNonEgauxMaisTailleEgal ( ) 
// {
//     int t1 [] = { 0, 1, 2, 3}, t2 [] = { 0, 1, 2, 4};
//     Ensemble p1 ( t1, 4 ), p2 ( t2, 4 );

//     cout << p1.EstEgal ( p2 ) << endl;
// }

// void testTroisiemeEnsembleTailleDifferente ( )
// {
//     int tab [] = { 0, 1, 2, 4 };
//     Ensemble p1 ( tab, 1 ), p2 ( tab, 2 );

//     cout << p1.EstEgal ( p2 ) << endl; 
// }

// void quatriemeInclusionLarge ( )
// {
//     int tab [] = { 0, 1, 2, 4, 567, 567  };
//     Ensemble p1 ( tab, 6 ), p2 ( tab, 6 );

//     // devrait afficher 1

//     cout << p1.EstInclus ( p2 ) << endl;
// }

// void quatriemeNonInclusion ( ) 
// {
//     int t1 [] = { 1, 0, 34 };
//     int t2 [] = { 1, 0, 456 };
//     Ensemble p1 ( t1, 3 ), p2 ( t2, 3 );

//     // devrait afficher 0
//     cout << p1.EstInclus ( p2 ) << endl;
// }

// void quatriemeInclusionStricte ( ) 
// {
//     int t1 [] = { 1, 3, 4 }, t2 [] = { 1, 3, 4, 5 };
//     Ensemble p1 ( t1, 3 ), p2 ( t2, 4 );

//     // devrait afficher 2
//     cout << p1.EstInclus( p2 ) << endl;
// }

// void quatriemeEnsembleVide ( ) 
// {
//     Ensemble p1 ( nullptr, 0 ), p2 ( nullptr, 0 );
//     cout << p1.EstInclus( p2 ) << endl;
// }

// void quatriemeEnsembleNonInclusion2 ( )
// {
//     int t1 [] = { 1, 2, 3 }, t2 [] = { 1, 2, 5, 4 };
//     Ensemble p1 ( t1, 3 ), p2 ( t2, 4 );

//     // 2
//     cout << p1.EstInclus ( p2 ) << endl;
// }

// void quatriemeInclusionStricte2 ( ) 
// {
//     int tab [] = { 1 };

//     Ensemble p1 ( nullptr, 3 ), p2 ( tab, 1 );

//     cout << p1.EstInclus ( p2 ) << endl;
// }

void cinquiemeTestPlein ( ) 
{
    // devrait afficher 1
    int tab [] = { 1, 2, 3 };
    Ensemble p1 ( tab, 3 );
    cout << p1.Ajouter ( 4 ) << endl;
}

void cinquiemeDejaPresent ( ) 
{
    // devrait afficher 0
    Ensemble p1 ( nullptr, 3 );
    p1.Afficher ( );
}

void cinquiemeAjoute ( ) 
{
    // devrait afficher 2
    int tab [] = { 1, 2, 2 };
    Ensemble p1 ( tab, 3 );
    cout << p1.Ajouter ( 100 ) << endl;
}

void sixiemeAjoutDeltaPositif ( ) 
{
    int tab [] = { 1, 2, 3 };
    Ensemble p1 ( tab, 3 );
    p1.Afficher ( );
    p1.Ajuster ( 45 );
    p1.Afficher ( );
}

void sixiemeAjoutDeltaNegatifChangements ( ) 
{
    int tab [] = { 1, 2, 2, 2, 5 };
    Ensemble p1 ( tab, 5 );
    p1.Afficher();
    p1.Ajuster ( -2 );
    p1.Afficher();
}

void sixiemeAjoutNull ( )
{
    int tab[] = { 1, 2, 2, 2, 4 };
    Ensemble p1 ( tab, 5 );
    p1.Afficher ( );
    p1.Ajuster ( 0 );
    p1.Afficher ( );
}

void sixiemeAjoutDeltaNegatifSansChangement ( ) 
{
    int tab[] = { 1, 2, 2, 2, 5 };
    Ensemble p1 ( tab, 5 );
    p1.Afficher ( );
    p1.Ajuster ( -5 );
    p1.Afficher ( );
}

void septiemeTestDeletion ( ) 
{
    int tab[] = { 1, 2, 2, 2, 5 };
    Ensemble p1 ( tab, 5 );
    p1.Afficher ( );
    p1.Retirer ( 1 );
    p1.Afficher ( );
}

void septiemeTestNoDeletion ( ) 
{
    int tab[] = { 1, 2, 2, 2, 5 };
    Ensemble p1 ( tab, 5 );
    p1.Afficher ( );
    p1.Retirer ( 577 );
    p1.Afficher ( );
}

void huitiemeTestNoDeletion ( ) 
{
    int tab[] = { 1, 2, 2, 2, 5 }, t [] = { 0, 22 };
    Ensemble p1 ( tab, 5 );
    Ensemble p2 ( t, 2 );

    p1.Afficher ( );
    cout << "Retires : " << p1.Retirer ( p2 ) << endl;
    p1.Afficher ( );
}

void huitiemeTestDeletion ( )
{
    int tab[] = { 1, 2, 2, 2, 5 }, t [] = { 1, 2, 34 };
    Ensemble p1 ( tab, 5 );
    Ensemble p2 ( t, 2 );

    p1.Afficher ( );
    cout << "Retires : " << p1.Retirer ( p2 ) << endl;    
    p1.Afficher ( );
}

void huitiemeTestCompleteDeletion ( ) 
{
    int tab[] = { 1, 2, 2, 2, 5 };
    Ensemble p1 ( tab, 5 );
    Ensemble p2 ( 9 );

    p2.Afficher ( );
    cout << "Retires : " << p2.Retirer ( p1 ) << endl;    
    p2.Afficher ( );
}

void dixiemeTestIntersectionComplete ( ) 
{
    int tab[] = { 1, 2, 2, 2, 5 };
    Ensemble p1 ( tab, 5 );
    Ensemble p2 ( tab, 5 );
    p1.Afficher ( );
    cout << "Elements supprimes : " << p1.Intersection ( p2 ) << endl;
    p1.Afficher ( );
}

void dixiemeTestNonIntersection ( ) 
{
    int t1 [] = { 1, 2, 2, 2, 5}, t2 [] = { 4, 67 };
    Ensemble p1 ( t1, 5 ), p2 ( t2, 2 );

    p1.Afficher ( );
    cout << "Element supprimes : " << p1.Intersection ( p2 ) << endl;
    p1.Afficher ( );
}

void dixiemeTestIntersection ( ) 
{
    int t1 [] = { 1, 2, 3, 4, 5 }, t2 [] = { 1, 2, 3 };
    Ensemble p1 ( t1, 5 ), p2 ( t2, 3 );
    p1.Afficher ( );
    cout << "Elements supprimes : " << p1.Intersection ( p2 ) << endl;
    p1.Afficher ( );
}

void neuviemeAlreadyEquals ( ) 
{
    int tab [] = { 1, 2, 3, 4, 5 };
    Ensemble p1 ( tab, 5 ), p2 ( tab, 5 );
    p1.Afficher ( );
    cout << "Elements rajoutes : " << p1.Reunir ( p2 ) << endl;
    p1.Afficher ( );
}

void neuviemeIntersectWithOverflow ( )
{
    int tab [] = { 1, 2, 3, 4, 5}, t [] = { 6, 7, 8 };
    Ensemble p1 ( tab, 5 ), p2 ( t, 3 );
    p1.Afficher ( );
    cout << "Elements rajoutes : " << p1.Reunir ( p2 ) << endl;
    p1.Afficher ( );
}

int main ( int argc, const char** argv ) 
{
    neuviemeIntersectWithOverflow ( );
    return 0;
}