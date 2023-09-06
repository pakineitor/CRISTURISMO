#ifndef Coche_H
#define Coche_H
#include "Pieza.h"
#include "Vehiculo.h"
#include <iostream>
#include <string.h>
using namespace std;

class Coche:public Vehiculo{
    private:
        bool trompo;
        
    public:
        Coche();
        ~Coche();
        bool debug=true;
        void setHacer_trompo();
        void getHacer_trompo();

        
    
        
};
#endif