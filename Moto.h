#ifndef Moto_H
#define Moto_H
#include "Pieza.h"
#include "Vehiculo.h"
#include <iostream>
#include <string.h>
using namespace std;

class Moto:public Vehiculo{
    private:
       bool hacer_caballito;
    public:
        bool debug=false;
         Moto();
        ~Moto();
         void setHacer_caballito(bool const &Caballito);
         bool getHacer_caballito() const;
        

    
        
};
#endif