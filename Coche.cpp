#include "Coche.h"
#include "Pieza.h"
#include <iostream>
#include <string.h>
using namespace std;

        Coche::Coche(){
            if(this->debug==true)
                cout << "Entro al constructor de Coche" << endl;
        }

        Coche::~Coche(){
            if(this->debug==true)
                cout << "Entro al destructor de coche" << endl;
        }


        void setHacer_trompo(bool activado);
        void getHacer_trompo(bool activado);

