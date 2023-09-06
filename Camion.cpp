#include "Vehiculo.h"
#include "Camion.h"
#include "Pieza.h"
#include <iostream>
#include <string.h>

Camion::Camion(){
    if(this->debug==true)
        cout << "Entro al constructor de Camión por defecto" << endl;

        
}

Camion::~Camion(){
    if(this->debug==true){}
        cout << "Entro al destructor de Camión" << endl;
}