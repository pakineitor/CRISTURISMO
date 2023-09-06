#include "Jugador.h"
#include "Garage.h"
#include "Vehiculo.h"
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
    
    Jugador::Jugador(){
        if(this->debug==true){
            cout << "Entro al constructor de jugador por defecto" << endl;
        }
        Garage g;
        this->setCreditos(0);
        this->setId_player(0);
        this->setLogin("Null");
        this->setPassword("NULL");
        this->setNumeroVictorias(0);
        this->setTipoCarnet(true);
        this->Agregar_garaje(g);
        
        
    }

    Jugador::Jugador(Jugador &J){
        if(this->debug==true){
            cout << "Entro al constructor de jugador por copia" << endl;
        }
        this->setCreditos(J.getCreditos());
        this->setId_player(J.getId_player());
        this->setLogin(J.getLogin());
        this->setPassword(J.getPassword());
        this->setNumeroVictorias(J.getNumero_victorias());
        this->setCreditos(J.getCreditos());
        this->Agregar_garaje(J.getGaraje_player());
        
    }
    Jugador::~Jugador(){
        if(this->debug==true){
            cout << "Entro al destructor de jugador" << endl;
        }
        
        this->setCreditos(0);
        this->setId_player(0);
        this->setLogin("Null");
        this->setPassword("NULL");
        this->setNumeroVictorias(0);
        this->setTipoCarnet(true);
        
    }

    // -------------------------------------GET--------------------------------------------------------
    void Jugador::setId_player(const int& ID_PLAYER){
        this->id_player=ID_PLAYER;
    }
    void Jugador::setLogin(const string& LOGIN){
        this->login=LOGIN;
    }
    void Jugador::setPassword(const string& PASSWORD){
        this->password=PASSWORD;
    }
    void Jugador::setCreditos(const double& CREDITOS){
        this->creditos=CREDITOS;
    }
    // void Jugador::setTotalVehiculos(const int& TOTAL_VEHICULOS);
    // void Jugador::setVehiculoGaraje(Vehiculo *v);

    void Jugador::setTipoCarnet(const bool& tipo){
        //  this->tipoCarnet=tipo;
    }
    void Jugador::setNumeroVictorias(int nuevo_num){
        this->numero_victorias=nuevo_num;
    }

    void Jugador::Agregar_garaje(Garage& g){
        this->garaje_player=g;
    }
    
    // ------------------------------------------------GET--------------------------------------------
    int Jugador::getId_player() const{
        return this->id_player;
    }
    string Jugador::getLogin() const{
        return this->login;
    }
    string Jugador::getPassword() const{
        return this->password;
    }
    double Jugador::getCreditos() const{
        return this->creditos;
    }
    
   

    bool Jugador::getTipo_carnet(const int& i) const{
        return this->tipoCarnet[i];
    }
    int Jugador::getNumero_victorias() const{
        return this->numero_victorias;
    }

    Garage &Jugador::getGaraje_player() {
        if(this->debug==true)
        cout << "Extraigo el garaje del jugador" << endl;

        return this->garaje_player;
    }

    istream& operator >> (istream& flujo, Jugador& j){
      if(j.debug==true)
        cout << MAGENTA << "Entro a la sobrecarga de cin del jugador" << RESET << endl;
       
        string palabra;
        int x;
        double saldo;

        cout << "Id: " << endl;
        flujo >> x;

        j.setId_player(x);
        
        cout << "Login: " << endl;
        flujo >> palabra;
        j.setLogin(palabra);

        cout << "Password: " << endl;
        flujo >> palabra;
        j.setPassword(palabra);

        cout << "Nº de victorias:" << endl;
        flujo >> x;
        j.setNumeroVictorias(x);

        cout << "Nº de créditos: " << endl;
        flujo >> saldo;
        j.setCreditos(saldo); 
        return flujo;

    }

    
    ostream& operator << (ostream& flujo,Jugador& j){
        if(j.debug==true)
            cout << MAGENTA << "Entro a la sobrecarga de cout del jugador" << RESET << endl;

        flujo << BLUE << "ID_PLAYER " << RESET << j.getId_player() << endl;
        flujo << BLUE << "Jugador --> " << RESET << j.getLogin() << endl;
        flujo << BLUE << "Número de victorias " << RESET <<  j.getNumero_victorias() << endl;
        flujo << BLUE << "Créditos-> " << RESET << j.getCreditos() << endl;
        flujo << j.getGaraje_player() << endl;
        

         return flujo;
    }

    Jugador& Jugador::operator=(Jugador& j){
        if(this->debug==true){
            cout << MAGENTA << "Entro a la sobrecarga = de jugador" << RESET << endl;
        }

        if(this!=&j){
           
            this->setCreditos(j.getCreditos());
            this->Agregar_garaje(j.getGaraje_player());
            this->setId_player(j.getId_player());
            this->setNumeroVictorias(j.getNumero_victorias());
            this->setLogin(j.getLogin());
            this->setPassword(j.getPassword());
            this->Agregar_garaje(j.getGaraje_player());
            
        }
        return *this;
    }


    
