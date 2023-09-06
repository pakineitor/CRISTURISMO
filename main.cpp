#include "Pieza.h"
#include "Vehiculo.h"
#include "Garage.h"
#include "Jugador.h"
#include "Cristurismo.h"
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

int main(){
    int tecla;
    cout << "Test de autoevalucación" << endl;
    cout << "Pulse 1 para crear una pieza por defecto e imprimirla por pantalla" << endl;
    cout << "Pulsa 2 para crear la pieza manualmente" << endl;
    cout << "Pulsa 3 para crearte un vehiculo manualmente" << endl;
    cout << "Pulsa 4 para que se ejecute automáticamente y comprobar el la sobrecarga del =" << endl;
    cout << "Pulsa 5 para probar garaje" << endl;
    cout << "Pulsa 6 para probar Jugador" << endl;
    cout << "Pulsa 7 para hacer el sistema." << endl;
    cin >> tecla;

    while(tecla<0 or tecla>7){
        cerr << BOLDRED << "Introduzca una opción válida " << RESET << endl;
        cin >> tecla;
    }

    if(tecla==1){
            Pieza pieza;
            cout << "Creando una pieza por defecto..." << endl;
    
     pieza.setId_pieza(1);
     pieza.setNombre_pieza("Alerón trasero");
     pieza.setAceleracion(3);
     pieza.setAerodinamica(40);
     pieza.setFrenada(79);
     pieza.setManejo(50);
     pieza.setVelocidadMax(320);
     pieza.setPrecio(1250);
    
            cout << pieza;
            Pieza p2(pieza);
            cout << endl;
            cout << p2 << endl;
    }

    if(tecla==2){
        Pieza p1;
        
        cin>> p1;
        cout << p1 << endl;
        Pieza pieza(p1);
        cout << pieza << endl;
    }
   
    if(tecla==3){
        Vehiculo *v=new Vehiculo();
        Vehiculo *v1=new Vehiculo();

        cin >> *v;
        cout << *v << endl;
        cout << * v1 << endl;
        cout << "IGUALAMOS....." << endl;
        v1=v;
        cout << *v1 << endl;



    }
    
    if(tecla==4){
        Vehiculo *v=new Vehiculo();
        Vehiculo *v1=new Vehiculo();
        v->setId_vehiculo(1012);
        v->setMarca("Audi");
        v->setModelo("c_cuatro");
        v->setTipoCombustible("Diesel++");
        v->setAceleracion(100);
        v->setAerodinamica(120);
        v->setCaballos(250);
        v->setCapacidadDepositoMax(50);
        v->setVelocidadMax(290);
        v->setCilindrada(40);
        v->setCombustibleActual(30);
        v->setFrenada(120);
        v->setManejo(150);
        v->setPrecioActual(200000);
        v->setPrecioBase(200000);

        cout << "Vehículo 1 creado con éxito: " << endl;
        cout << *v << endl;
        cout << "Vehículo 2 sin rellenar: " << endl;
        cout << *v1 << endl;
        cout << "Igualando vehículos..." << endl;
        cout << endl;
        *v1=*v;
        cout << endl;
        cout << "Vehículo 2 rellenado con éxito: " << endl;
        cout << *v1 << endl;

        cout << "Pulsa 1 si deseas añadir una pieza para tunear el coche" << endl;
        cin >> tecla;
        if(tecla==1){
            Pieza *p=new Pieza();
            Pieza *p1=new Pieza();
            cin >> *p;
            cin>> *p1;
            v1->Agregar_Pieza_Tuneada(p);
            v1->Agregar_Pieza_Tuneada(p1);
            *v=*v1;
            cout << *v << endl;

            cout << "Pulse 0 si deseas borrar alguna pieza" << endl;
            cin >> tecla;
            if(tecla==0){
                int i;

                

                cout << "Elige él número de pieza que desees borrar" << endl;
                cin >> i;
                v->Eliminar_pieza_Tuneada(i);
                cout << *v << endl;
                *v1=*v;
                cout << *v1 << endl;
            }
        }
    }


    if(tecla==5){
        int x=0;
        Pieza *p=new Pieza();
        Garage *g=new Garage();
        Vehiculo *v, *v1, *v2;
        v=new Vehiculo();
        v1=new Vehiculo();
        v2=new Vehiculo();

        cout << "Pulsa 1 para crear un Garaje por defecto o pulsa 2 para crearla manual." << endl;
        cin >> x;

        if(x==1){
            
            
            
            cout << "Coche 1: " << endl;
            cout << endl;

            v->setId_vehiculo(1012);
            v->setMarca("Audi");
            v->setModelo("c_cuatro");
            v->setTipoCombustible("Diesel++");
            v->setAceleracion(100);
            v->setAerodinamica(120);
            v->setCaballos(250);
            v->setCapacidadDepositoMax(50);
            v->setVelocidadMax(290);
            v->setCilindrada(40);
            v->setCombustibleActual(30);
            v->setFrenada(120);
            v->setManejo(150);
            v->setPrecioActual(200000);
            v->setPrecioBase(200000);
            v->setTotalPiezas(0);
            g->setId_garage(9);
            g->Agregar_vehiculo(*v);

            cout << "Piezas del coche 1 añadidas---> " << v->getTotalPiezas() << endl;
            cout << endl;

            

            cout << "Coche 2: " << endl;
            cout << endl;
            v1->setId_vehiculo(1111);
            v1->setMarca("FORD");
            v1->setModelo("ZX");
            v1->setTipoCombustible("Sin_Plomo");
            v1->setAceleracion(340);
            v1->setAerodinamica(200);
            v1->setCaballos(250);
            v1->setCapacidadDepositoMax(50);
            v1->setVelocidadMax(300);
            v1->setCilindrada(40);
            v1->setCombustibleActual(40);
            v1->setFrenada(220);
            v1->setManejo(150);
            v1->setPrecioActual(250000);
            v1->setPrecioBase(25000);
            v->setTotalPiezas(0);
            g->setId_garage(9);
            g->Agregar_vehiculo(*v1);
            cout << "Piezas del coche 2 añadidas---> " << v1->getTotalPiezas() << endl;
            cout << endl;

            cout << "Coche 3: " << endl;
            cout << endl;
            v2->setId_vehiculo(1012);
            v2->setMarca("FABIA");
            v2->setModelo("X_ULTRA");
            v2->setTipoCombustible("DESCONOCIDO");
            v2->setAceleracion(0);
            v2->setAerodinamica(0);
            v2->setCaballos(0);
            v2->setCapacidadDepositoMax(0);
            v2->setVelocidadMax(0);
            v2->setCilindrada(0);
            v2->setCombustibleActual(0);
            v2->setFrenada(0);
            v2->setManejo(0);
            v2->setTotalPiezas(0);
            
            
            p->setAceleracion(0);
            p->setAerodinamica(20);
            p->setFrenada(10);
            p->setId_pieza(111);
            p->setManejo(10);
            p->setNombre_pieza("Alerón_Neónico");
            p->setPrecio(240);
            p->setVelocidadMax(20);
            v2->Agregar_Pieza_Tuneada(p);

            cout << "Piezas del coche 3 añadidas---> " << v2->getTotalPiezas() << endl;
            cout << endl;

            v2->setPrecioActual(0);
            v2->setPrecioBase(0);
            g->Agregar_vehiculo(*v2);

           
            cout << *g << endl;

            cout << "Pulse 1 si desea eliminar algún vehículo" << endl;
            cin >> x;
            cout << "Elige la posición del vehículo" << endl;
            cin >> x;
            g->Eliminar_vehiculo(x);
            cout << *g << endl;
            
            

            
        }
       
         
        
        
    }


    if(tecla==6){
            Jugador j;
            Garage g;
            Pieza *p=new Pieza();
            Pieza *p1=new Pieza();
            Vehiculo v, v1;
            int x;
            
            

            cout << "Creamos la pieza tuneada" << endl;
            cout << endl;
            p->setAceleracion(20);
            p->setAerodinamica(50);
            p->setFrenada(69);
            p->setId_pieza(111);
            p->setManejo(90);
            p->setNombre_pieza("Neumático_full");
            p->setPrecio(135);
            p->setVelocidadMax(50);

            cout << "Creando pieza 2" << endl;

            p1->setAceleracion(100);
            p1->setAerodinamica(0);
            p1->setFrenada(0);
            p1->setId_pieza(123);
            p1->setManejo(0);
            p1->setNombre_pieza("NH2");
            p1->setPrecio(1200);
            p1->setVelocidadMax(350);

           cout << GREEN <<  "--------------------CREANDO VEHÍCULOS---------------" << RESET <<endl;
            v.setAceleracion(100);
            v.setTipoCombustible("Diesel++");
            v.setVelocidadMax(300);
            v.setAerodinamica(150);
            v.setCaballos(350);
            v.setCapacidadDepositoMax(60);
            v.setCilindrada(350);
            v.setCombustibleActual(50);
            v.setFrenada(250);
            v.setId_vehiculo(4414);
            v.setManejo(250);
            v.setMarca("Audi");
            v.setModelo("GT");
            v.setPrecioActual(1500000);
            v.setPrecioBase(15000000);
            v.Agregar_Pieza_Tuneada(p);
            cout << GREEN << "----------------------------CREANDO VEHÍCULO 2----------------------" << RESET << endl;
            
            v1.setAceleracion(500);
            v1.setVelocidadMax(350);
            v1.setTipoCombustible("Gasolina");
            v1.setAerodinamica(550);
            v1.setCaballos(1500);
            v1.setCapacidadDepositoMax(100);
            v1.setCilindrada(550);
            v1.setCombustibleActual(100);
            v1.setFrenada(350);
            v1.setId_vehiculo(0001);
            v1.setManejo(450);
            v1.setMarca("Bugatti");
            v1.setModelo("Huracán");
            v1.setPrecioActual(50000000);
            v1.setPrecioBase(50000000);
            v1.Agregar_Pieza_Tuneada(p);
            v1.Agregar_Pieza_Tuneada(p1);

            cout << BOLDWHITE<< "Creando el GARAJE............" << RESET << endl;

            g.setId_garage(8989);
            g.Agregar_vehiculo(v);
            g.Agregar_vehiculo(v1);

            cout << "Creando jugador..." << endl;
            j.setCreditos(20);
            j.setId_player(1221);
            j.setLogin("yeyo");
            j.setNumeroVictorias(2);
            j.setPassword("josegras");
            j.setCreditos(20000);
            j.Agregar_garaje(g);

            cout << j << endl;

            cout << "Si desea eliminar algún vehículo pulse 1" << endl;
            cout << "Si desea eliminar alguna pieza pulse 2" << endl;
            

            cin >> x;
            if(x==1){
                cout << "elige la posición del vehículo mostrada anteriormente" << endl;
                cin >> x;
                g.Eliminar_vehiculo(x);

                cout << "Tras eliminar el vehículo la cantidad es --> " << g.getCantidad_Vehiculos() << endl;
                cout << g << endl;
            }

            

    }


    if(tecla==7){
        bool entrar=false;
        int x=0;
       Cristurismo c;
       
    do{
       cout << MAGENTA << "Este programa te proporciona una gestión de un sistema parecido a GRAN TURISMO." << endl;
       cout << "Si deseas averiguarlo dale a iniciar" << endl;
       cout << "Pulsa 1 para entrar" << endl;
       cout << "Pulsa 0 para salir del programa" << RESET << endl;
       cout << endl;
       cin >> x;
       
       while(x<0 or x>1){
           cerr << RED << "Por favor, introduce una opción válida" << RESET << endl;
           cin >> x;
       }

        if(x==1){
            entrar=true;
        }

        if(x==0){
            entrar=false;
            cout << "CHAITOO" << endl;
        }

        if(entrar==true){
           c.Cargar_datos();
        }

    }while(entrar==true);
       
    }

    
}