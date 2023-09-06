#include "Pieza.h"
#include <iostream>
#include <string.h>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
using namespace std;

// Constructor.

Pieza::Pieza(){
    if(this->debug==true){
        cout << "Entrando al constructor de pieza por defecto" << endl;
    }

    this->setId_pieza(0);
    this->setNombre_pieza("Null");
    this->setAerodinamica(0);
    this->setAceleracion(0);
    this->setFrenada(0);
    this->setVelocidadMax(0);
    this->setManejo(0);
    this->setAceleracion(0);
    this->setPrecio(0);



}

Pieza::Pieza(const Pieza& pieza){

    if(this->debug==true){
        cout << "Entrando al constructor de pieza por copia" << endl;
    }    

    this->setId_pieza(pieza.getId_pieza());
    this->setNombre_pieza(pieza.getNombre_pieza());
    this->setAerodinamica(pieza.getAerodinamica());
    this->setAceleracion(pieza.getAcelracion());
    this->setFrenada(pieza.getFrenada());
    this->setVelocidadMax(pieza.getVelocidadMax());
    this->setManejo(pieza.getManejo());
    this->setAceleracion(pieza.getAcelracion());
    this->setPrecio(pieza.getPrecio());

}


Pieza::~Pieza(){
    if(this->debug==true){
        cout << RED << "Entro al destructor de pieza" << RESET << endl;
    }

    this->setId_pieza(0);
    this->setNombre_pieza("Null");
    this->setAerodinamica(0);
    this->setAceleracion(0);
    this->setFrenada(0);
    this->setVelocidadMax(0);
    this->setManejo(0);
    this->setAceleracion(0);
    this->setPrecio(0);

    if(this->debug==true){
        cout << RED << "Salgo del destructor de pieza" << RESET << endl;
    }
    
}

    void Pieza::setId_pieza(const int& ID_PIEZA){
        this->id=ID_PIEZA;
    }


    void Pieza::setNombre_pieza(const string& NOMBRE){
        this->nombre=NOMBRE;
    }

    void Pieza::setAerodinamica(const int& AERODINAMICA){
            this->aerodinamica=AERODINAMICA;
    }

    void Pieza::setAceleracion(const int& ACELERACION){
        this->aceleracion=ACELERACION;
    }


    void Pieza::setFrenada(const int& FRENADA){
        this->frenada=FRENADA;
    }


    void Pieza::setVelocidadMax(const int& VELOCIDADMAX){
        this->velocidadMax=VELOCIDADMAX;
    }

    void Pieza::setManejo(const int& MANEJO){
        this->manejo=MANEJO;
    }


    void Pieza::setPrecio(const double& PRECIO){
        this->precio=PRECIO;
    }





int Pieza::getId_pieza() const{
    return this->id;
}

string Pieza::getNombre_pieza() const{
    return this->nombre;
}

int Pieza::getAerodinamica() const{
    return this->aerodinamica;
}

int Pieza::getFrenada() const{
    return this->frenada;
}

int Pieza::getVelocidadMax() const{
    return this->velocidadMax;
}

int Pieza::getManejo() const{
    return this->manejo;
}

int Pieza::getAcelracion() const{
    return this->aceleracion;
}

int Pieza::getPrecio() const{
    return this->precio;
}


ostream& operator << (ostream& salida, const Pieza& pieza){
    salida << BOLDCYAN <<  "Id_Pieza-->  " << RESET << pieza.getId_pieza() << endl; 
    salida << BOLDCYAN << "Nombre --> " << RESET << pieza.getNombre_pieza() << endl;
    salida << BOLDCYAN << "Aerodinámica --> " << RESET << pieza.getAerodinamica() << endl;
    salida << BOLDCYAN << "Manejo " << RESET << pieza.getManejo() << endl;
    salida << BOLDCYAN << "Aceleración --> "<< RESET << pieza.getAcelracion() << endl;
    salida << BOLDCYAN << "Velocidad MAX --> " << RESET << pieza.getVelocidadMax() << endl;
    salida << BOLDCYAN << "Frenada " << RESET << pieza.getFrenada() << endl;
    salida << BOLDCYAN << "Precio --> " << RESET << pieza.getPrecio() << "€" << endl;
    cout << endl;
    return salida;


}


 istream& operator >> (istream& entrada, Pieza& pieza){
    int id, aerodinamica, manejo, aceleracion, vel_max,frenada, precio;
    string nombre;
    
     cout << "Introduce el Id de la pieza" << endl;
     entrada>> id;
     
    pieza.setId_pieza(id);

     cout << "Introduce el nombre" << endl;

     entrada >> nombre;
     pieza.setNombre_pieza(nombre);
     

     cout << "Introduce la aerodinamica " << endl;
     entrada >> aerodinamica;
     pieza.setAerodinamica(aerodinamica);

     cout << "Introduce el manejo" << endl;
     entrada >> manejo;
     pieza.setManejo(manejo);

     cout << "Introduce la aceleración del vehículo" << endl;
     entrada>> aceleracion;
     pieza.setAceleracion(aceleracion);

     cout << "Introduce la velocidad máxima" << endl;
     cin >> vel_max;
     pieza.setVelocidadMax(vel_max);

     cout << "Introduce la frenada" << endl;
     entrada >> frenada;
     pieza.setFrenada(frenada);


     cout << "Introduce el precio de la pieza" << endl;
     entrada >> precio;
     pieza.setPrecio(precio);
    
    
    
    return entrada;


} 


Pieza& Pieza::operator=(Pieza& p){
   if(this->debug==true){
       cout << YELLOW << "Entro a la sobrecarga = de pieza" << RESET << endl;
   }
   
    this->setAceleracion(p.getAcelracion());
    this->setAerodinamica(p.getAerodinamica());
    this->setFrenada(p.getFrenada());
    this->setId_pieza(p.getId_pieza());
    this->setManejo(p.getManejo());
    this->setNombre_pieza(p.getNombre_pieza());
    this->setPrecio(p.getPrecio());
    this->setVelocidadMax(p.getVelocidadMax());
    return *this;
}



