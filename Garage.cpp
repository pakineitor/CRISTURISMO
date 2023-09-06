#include "Pieza.h"
#include "Vehiculo.h"
#include "Garage.h"
#include <string.h>
#include <iostream>
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

    Garage::Garage(){
        if(this->debug==true){
            cout << YELLOW << "Entro al constructor por defecto de Garage." << RESET << endl;
        }

        this->setCantidad_Vehiculos(0);
        this->vehiculo_garage=new Vehiculo[this->getCantidad_Vehiculos()+1];
        
        if(this->vehiculo_garage==0){
            cerr << RED << "Error no hay espacio en el sistema" << RESET << endl;
            exit(-1);
        }

        this->setId_garage(0);
    }

    Garage::Garage(const Garage& g){
         if(this->debug==true){
            cout << YELLOW << "Entro al constructor por copia de Garage." << RESET << endl;
        }

        this->setCantidad_Vehiculos(g.getCantidad_Vehiculos());
        this->vehiculo_garage=new Vehiculo[this->getCantidad_Vehiculos()];

        this->setId_garage(g.getId_garage());

        // Copio contenido:
        for(int i=0; i<this->getCantidad_Vehiculos();i++){
            this->vehiculo_garage[i]=g.vehiculo_garage[i];
        }
    }

    Garage::~Garage(){
        
         if(this->debug==true){
            cout << RED << "Entro al destructor por defecto de Garage." << RESET << endl;
        }
        this->setId_garage(0);
        this->setCantidad_Vehiculos(0);
        delete [] this->vehiculo_garage;
        this->vehiculo_garage=NULL;
        

        
    }

        // ------------------------------------------------------------------------SET---------------------------------------------------------------
    void Garage::setId_garage(const int& ID_GARAGE){
        this->id=ID_GARAGE;
    }
    void Garage::setCantidad_Vehiculos(const int& CANTIDAD_VEHICULOS){
        this->cantidad_vehiculos=CANTIDAD_VEHICULOS;
    }
    // -------------------------------------------------------------GET----------------------------------------------------------------------------
    int Garage::getId_garage() const{
        return this->id;
    }
    int Garage::getCantidad_Vehiculos() const{
        return this->cantidad_vehiculos;
    }

    Vehiculo &Garage::getVehiculo(const int& i) const{
        if(this->debug==true)
            cout << YELLOW << "Extraigo el vehiculo de la posición " << i << RESET << endl;

        return this->vehiculo_garage[i];
    }
//-----------------------------------------------------------------MÉTODOS ADICIONALES--------------------------------------------------------- 

    void Garage::Resize_garage(const int& NUEVA_DIM){
        if(this->debug==true){
            cout << YELLOW << "Entro al resize de Garaje cuya dimensión actual es: " << RESET << this->getCantidad_Vehiculos() << endl;
            cout << "Dimensión que me pasan nueva---> " << NUEVA_DIM << endl;
        }
        cout << endl;
        Vehiculo *aux=new Vehiculo[NUEVA_DIM];
        if(aux==0){
            cerr << RED << "ERROR, NO HAY ESPACIO SUFICIENTE" << RESET << endl;
            exit(-1);
        }

        if(NUEVA_DIM > this->getCantidad_Vehiculos()){
             if(this->debug==true)
                cout << MAGENTA << "Entro en NUEVA_DIM > DIM_ACTUAL" << RESET << endl;
            
            
            // Copiamos el contenido al vector nuevo
            for(int i=0; i<this->getCantidad_Vehiculos();i++){
                aux[i]=this->vehiculo_garage[i];
            }

            
        }

        if(NUEVA_DIM < this->getCantidad_Vehiculos()){
            if(this->debug==true)
                cout << MAGENTA << "Entro en NUEVA_DIM < DIM_ACTUAL" << RESET << endl;

            this->setCantidad_Vehiculos(NUEVA_DIM);
           
            // Copiamos el contenido al vector nuevo
            for(int i=0; i<this->getCantidad_Vehiculos();i++){
                aux[i]=this->vehiculo_garage[i];
                
            }

            
        }
            
            
            // delete [] this->vehiculo_garage;
            cout << RED << "YA HA PETADO HUANITO" << RESET << endl;
            cout << endl;
            
           
            this->vehiculo_garage=aux;
             cout << RED << "YA HA PETADO HUANITOOO" << RESET << endl;
            cout << endl;
            
            this->setCantidad_Vehiculos(NUEVA_DIM);
            if(this->debug==true)
                cout << "La cantidad de vehículos después de agregar es de --> " << this->getCantidad_Vehiculos() << endl;
        
    }

    void Garage::Agregar_vehiculo(Vehiculo& v1){
        if(this->debug==true)
        cout << GREEN << "Cantidad de vehículos en el garaje " << RESET << this->getCantidad_Vehiculos() << endl;
       
        this->Resize_garage(this->getCantidad_Vehiculos()+1);
        this->vehiculo_garage[this->getCantidad_Vehiculos()-1]=v1;
       
    }


    void Garage::Eliminar_vehiculo(const int& i){
        if(this->debug==true)
        cout << "La cantidad actual de vehiculos guardados en su garaje son: " << this->getCantidad_Vehiculos() << endl;
       
        // Reordeno el vector:
        for(int j=i; j<this->getCantidad_Vehiculos()-1;j++){
            cout << j << endl;
            this->vehiculo_garage[j]=this->vehiculo_garage[j+1];
        }
           
        cout << "Vector reordenado" << endl;

       

        this->Resize_garage(this->getCantidad_Vehiculos()-1);
        
        if(debug==true)
        cout << "Vehiculos actuales de tu garaje " << this->getCantidad_Vehiculos() << endl;
    }

    
    ostream& operator << (ostream& flujo, const Garage& g){
         if(g.debug==true)
            cout << MAGENTA << "Entro a la sobrecarga del cout de garaje" << RESET << endl;

        flujo << BOLDGREEN << "Id_G--> " << RESET << g.getId_garage() << endl;
        flujo << BOLDGREEN << "Cantidad de vehículos--> " << RESET << g.getCantidad_Vehiculos() << endl;
        
        for(int i=0; i<g.getCantidad_Vehiculos();i++){
            flujo << BOLDGREEN << "Vehículo nº " << RESET << i << endl;
            flujo << g.getVehiculo(i) << endl;
        }
        return flujo;
    }


    istream& operator >>(istream& flujo, Garage& g){
        if(g.debug==true)
            cout << MAGENTA << "Entro a la sobrecarga del cin de garaje" << RESET << endl;

        int id;
        cout << "Introduce el id del garaje" << endl;
        flujo >> id;

      

        g.setId_garage(id);
        return flujo;
    }


    Garage& Garage::operator=(const Garage& g){
        if(this->debug==true){
            cout << MAGENTA << "Entro a la sobrecarga de = de Garaje" << RESET << endl;
        }

        if(this!=&g){
            delete [] this->vehiculo_garage;
            
            this->setCantidad_Vehiculos(g.getCantidad_Vehiculos());
            this->setId_garage(g.getId_garage());
            this->vehiculo_garage=new Vehiculo[g.getCantidad_Vehiculos()];

            if(this->vehiculo_garage==0){
                cerr << RED << "Error, no queda suficiente espacio" << RESET << endl;
                exit(-1);
            }
            
            //  copiamos el contenido del vector de g al vector de este nuevo objeto.
             for(int i=0; i<g.getCantidad_Vehiculos(); i++){
                 this->vehiculo_garage[i]=g.vehiculo_garage[i];
             }

           
            

        }
        return *this;
    }

   