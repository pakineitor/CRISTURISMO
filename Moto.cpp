#include "Moto.h"
#include "Pieza.h"
#include <iostream>
#include <string.h>
using namespace std;
    
    Moto::Moto(){
        if(this->debug==true)
            cout << "Entro en el constructor por defecto de Moto" << endl;
        this->setHacer_caballito(false);


    }

    Moto::~Moto(){
        if(this->debug==true)
            cout << "Entro en el destructor de moto" << endl;
    }

    void Moto::setHacer_caballito(const bool &caballito){
        this-> hacer_caballito=caballito;
    }

    bool Moto::getHacer_caballito() const{
        return this->hacer_caballito;
    }