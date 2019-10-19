#ifndef COMPTAGE_H
#define COMPTAGE_H

#include <iostream>
using namespace std;

class Comptage 
{
    public:
        inline Comptage ( void ) 
        {
            numInstance = ++Comptage::nbrRestants;
            #ifdef MAP
                cout << "Appel au constructeur de la classe <Comptage>, instance numero " << numInstance << " , instance restantes " << Comptage::nbrRestants << endl;
            #endif
        }

        inline Comptage ( const Comptage & comptage ) 
        {
            numInstance = ++Comptage::nbrRestants;
            #ifdef MAP
                cout << "Appel au constructeur de copie de la classe <Comptage>, instance numero " << numInstance << " , instance restantes " << Comptage::nbrRestants << endl;                
            #endif
        }

        inline ~Comptage( )
        {
            Comptage::nbrRestants--;
            #ifdef MAP
                cout << "Appel au destructeur de la classe <Comptage>, instance numero " << numInstance << " , instance restantes " << Comptage::nbrRestants << endl;                
            #endif
        } 


    protected:
        static int nbrRestants;
        int numInstance;
};

#endif