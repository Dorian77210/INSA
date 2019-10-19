#ifndef FILS_COMPTAGE_H
#define FILS_COMPTAGE_H

#include <iostream>
using namespace std;

#include "Comptage.h"

class FilsComptage : public Comptage 
{
    public:
        inline FilsComptage ( void ) 
        {
            #ifdef MAP
                cout << "Appel au constructeur de la classe <FilsComptage>" << endl;
            #endif
        }

        inline FilsComptage ( FilsComptage & filsComptage )
        {
            #ifdef MAP
                cout << "Appel au constructeur de copie de la classe <FilsComptage>" << endl;
            #endif
        }

        inline  ~FilsComptage ( )
        {
            #ifdef MAP
                cout << "Appel au destructeur de la clase <FilsComptage>" << endl;
            #endif
        }

};

#endif