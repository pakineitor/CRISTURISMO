#include "Pieza.h"
#include "Vehiculo.h"
#include "Garage.h"
#include "Jugador.h"
#include "Cristurismo.h"
#include <iostream>
#include <string.h>
#include "Admin.h"
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


        Cristurismo::Cristurismo(){
               if(this->debug==true){
                        cout << YELLOW << "Entro al constructor de Cristurismo por defecto" << RESET <<endl;
               }
                
                


                this->setLogin_player("Null");
                this->setPassword("Null");
                this->setPrecioDiesel(0);
                this->setPrecioGasolina(0);
                
                // Creo el catálogo de las piezas:
                this->setTotal_piezas(0);
                this->catalogo_pieza=new Pieza[this->getTotal_piezas()+1];
                if(this->catalogo_pieza==0){
                        cerr << "ERROR, NO QUEDA ESPACIO." << endl;
                        exit(-1);
                }




                // Creo el vector de los vehículos que simula el catálogo del sistema.
                this->setTotal_Vehiculos(0);
                this->catalogo_vehiculos=new Vehiculo[this->getTotal_Vehiculo()+1];
               
                if(this->catalogo_vehiculos==0){
                        cerr << "ERROR, NO QUEDA ESPACIO" << endl;
                        exit(-1);
                }

                // Creo vector Jugadores:
                this->setTotalPlayers(0);
                this->players=new Jugador[this->getTotal_Players()+1];
                
                if(this->players==0){
                        cerr << "ERROR, NO QUEDA ESPACIO" << endl;
                        exit(-1);
                }
                
               
                


        }

        Cristurismo::Cristurismo(const Cristurismo& C){
                if(this->debug==true){
                        cout << YELLOW << "Entro al constructor de Cristurismo por copia" << RESET <<endl;
               }

                this->setLogin_player(C.getLogin());
                this->setPassword(C.getPassword());
                this->setPrecioDiesel(C.getPrecioDiesel());
                this->setPrecioGasolina(C.getPrecioGasolina());

                this->setTotal_piezas(C.getTotal_piezas());
                this->catalogo_pieza=new Pieza[this->getTotal_piezas()];
                if(this->catalogo_pieza==0){
                        cerr << RED << "ERROR, NO QUEDA ESPACIO" << RESET << endl;
                        exit(-1);
                }

                // Copiamos el contenido del vector de C en el vector del objeto creado.
                for(int i=0; i<this->getTotal_piezas();i++){
                        this->catalogo_pieza[i]=C.catalogo_pieza[i];
                }

                this->setTotal_Vehiculos(C.getTotal_Vehiculo());
                this->catalogo_vehiculos=new Vehiculo[this->getTotal_Vehiculo()];
                if(this->catalogo_vehiculos==0){
                        cerr << RED << "ERROR, NO QUEDA ESPACIO" << RESET << endl;
                        exit(-1);
                }

                // Copiamos el contenido:
                for(int i=0; i<this->getTotal_Vehiculo(); i++){
                        this->catalogo_vehiculos[i]=C.catalogo_vehiculos[i];
                }

                this->setTotalPlayers(C.getTotal_Players());
                this->players=new Jugador[C.getTotal_Players()];
                if(this->players==0){
                        cerr << RED << "ERROR, NO QUEDA ESPACIO" << RESET << endl;
                        exit(-1);
                }

                // Copiamos el contenido:
                for(int i=0; i<this->getTotal_Players();i++){
                        this->players[i]=C.players[i];
                }

        }
        Cristurismo::~Cristurismo(){
                if(this->debug==true){
                        cout << RED << "Entro al destructor de Cristurismo" << RESET << endl;
                }

                this->setLogin_player("Null");
                this->setPassword("Null");
                this->setPrecioDiesel(0);
                this->setPrecioGasolina(0);

                delete [] this->players;
                this->players=NULL;
                
                delete [] this->catalogo_pieza;
                this->catalogo_pieza=NULL;
                // cout << "Sigo hacia catalogo de vehiculos" << endl;

                delete [] this->catalogo_vehiculos;
                this->catalogo_vehiculos=NULL;
                if(this->debug==true)
                        cout << "Ya he terminado de destruir el sistema" << endl;
                


        }

        void Cristurismo::Agregar_jugador(Jugador& j){
                if(this->debug==true)
                    cout << MAGENTA << "ENTRO A AGREGAR JUGADOR EN LA POSICIÓN --> " << RESET << endl;
               
                this->Resize_lista_players(this->getTotal_Players()+1);
                this->players[this->getTotal_Players()-1]=j; //Agrego en la penúltima posición.
        }


        void Cristurismo::Modificar_Jugador(const int& x){
                        int valor=0;
                        cout << GREEN << "Jugador Nº --> " << RESET << x << endl;
                        cout << this->getJugador(x);
                       
                

                

                do{
                        cout  << BLUE << "Pulsa 0 para salir" << endl;
                        cout << "Pulsa 1 para modificar el id del jugador" << endl;
                        cout << "Pulsa 2 para modificar el nombre del jugador" << endl;
                        cout << "Pulsa 3 para cambiarle sus créditos" << endl;
                        cout << RESET << endl;
                        cin >> valor;

                        if(valor<0 or valor>3){
                                cerr << BOLDRED << "OPCIÓN INCORRECTA." << RESET << endl;
                        }

                        if(valor==0){
                                cout << GREEN << "Opción cancelada" << endl;
                                cout << RESET << endl;
                        }

                        if(valor==1){
                                int id;
                                cout << BLUE << "Introduce una id nueva" << RESET << endl;
                                cin >> id;

                                id=this->Filtro_numeros(id);

                                // Bucle que va a recorrer el vctor para asegurar de que la id introducida por el usuario sea distinta a las que hay, ya que no PUEDEN repetirse.
                                for(int i=0; i<this->getTotal_Players();i++){
                                       
                                        while(this->getJugador(i).getId_player()==id){
                                                cerr << RED << "Esta id ya está ocupada, por favor, introduce otra." << RESET << endl;
                                                cin >> id;
                                                i=0;

                                        }
                                        
                                }

                                this->getJugador(x).setId_player(id);
                                cout << GREEN << "ID de jugador cambiada con éxito :D" << RESET << endl;
                                cout << this->getJugador(x);
                                cout << endl;
                                
                        }





                        if(valor==2){
                                string nombre;
                                cout << BLUE << "Introduce el nuevo login del jugador " << endl;
                                cin >> nombre;
                                this->getJugador(x).setLogin(nombre);
                                cout << endl;
                        }



                        if(valor==3){
                                int valor=0;
                                cout << BLUE << "Introduce la cantidad nueva de créditos del jugador" << RESET << endl;
                                cin >> valor;

                                this->getJugador(x).setCreditos(this->Filtro_numeros(valor));
                                cout << this->getJugador(x);
                                cout << endl;
                        }




                }while(valor!=0);

        }




        void Cristurismo::Eliminar_jugador(const int& i){
               if(this->debug==true)
                    cout << MAGENTA << "ENTRO A ELIMINAR JUGADOR EN LA POSICIÓN --> " << RESET << i << endl;

                // Reordeno el vector de los jugadores.
                for(int j=i; j<this->getTotal_Players()-1;j++){
                        this->players[j]=this->players[j+1];
                }

                this->Resize_lista_players(this->getTotal_Players()-1);
        }
        void Cristurismo::setTotalPlayers(const int& TOTAL_PLAYER){
                this->total_player=TOTAL_PLAYER;
        }
        
        
        void Cristurismo::AgregarVehiculo(Vehiculo& v){
               if(this->debug==true)
                    cout << MAGENTA << "ENTRO A AGREGAR VEHÍCULO" << RESET << endl;

                this->Resize_catalogo_vehiculos(this->getTotal_Vehiculo()+1);
                this->catalogo_vehiculos[this->getTotal_Vehiculo()-1]=v;
        }


        int Cristurismo::Filtro_numeros(int n){
               
                while(n<0){ 
                        cerr << RED << "No se admiten valores negativos para este atributo" << endl;
                        cin >> n;
                }
                return n;

        }

        void Cristurismo::Modificar_Vehiculo(const int& x){
                if(this->debug==true){
                        cout << "Entro al Modificar Vehículo" << endl;
                }
                        int opcion=0;

                        cout << this->getVehiculoCatalogo(x);

                        cout << YELLOW << "Pulsa 0 si desea salir" << endl;
                        cout << "Pulsa 1 para modificar el id del vehículo" << endl;
                        cout << "Pulsa 2 para modificar la marca del vehículo" << endl;
                        cout << "Pulsa 3 para modificar el modelo del vehículo" << endl;
                        cout << "Pulsa 4 para modificar el tipo de combustible" << endl;
                        cout << "Pulsa 5 para modificar la cilindrada de combustible" << endl;
                        cout << "Pulsa 6 para modificar la capacidad máxima del vehículo" << endl;
                        cout << "Pulsa 7 para modificar los caballos del vehículo" << endl;
                        cout << "Pulsa 8 para modificar la aerodinámica del vehículo" << endl;
                        cout << "Pulsa 9 para modificar la aceleración del vehículo" << endl;
                        cout << "Pulsa 10 para modifiar el manejo del vehículo" << endl;
                        cout << "Pulsa 11 para modificar la Velocidad maxima del vehículo " << endl;
                        cout << "Pulsa 12 para modificar la frenada del vehículo" << endl;
                        cout << "Pulsa 13 para modificar el combustible actual" << endl;
                        cout << "Pulsa 14 para modificar el precio actual " << endl;
                        cout << "Pulsa 15 para modificar el precio base" << RESET << endl;
                        cout << endl;
                        cout << BOLDRED << "AVISO: Los espacios se deberán marcar en todas las palabras con ''_'' " << RESET << endl;
                        cin >> opcion;

                        while(opcion < 0 or opcion > 15){
                                cerr << BOLDRED << "ERROR, POR FAVOR ELIJA USTED UN Nº ENTRE 0 Y 15" << RESET << endl;
                                cin >> opcion;
                        }
                        

                                if(opcion==0){
                                                cout << CYAN << "HASTA PRONTO ^^" << RESET << endl;
                                }                                        
                                

                               if(opcion==1){
                                        int id;
                                        cout << "Introduce un nuevo id" << endl;
                                        cin >> id;

                                        id=this->Filtro_numeros(id);

                                        for(int i=0; i<this->getTotal_Vehiculo();i++){
                                               
                                                while(this->getVehiculoCatalogo(i).getId_vehiculo()==id){
                                                        cerr << RED << "Esta id ya está ocupada, por favor, introduce otra" << RESET << endl;
                                                        cin >> id;
                                                        i=0;
                                                }
                                        }

                                        this->getVehiculoCatalogo(x).setId_vehiculo(id);
                                        cout << endl;
                                        cout << this->getVehiculoCatalogo(x);


                                }
                                

                                if(opcion==2){
                                        string marca;
                                        cout << "Introduce la nueva marca " << endl;
                                        cin >> marca;
                                        this->getVehiculoCatalogo(x).setMarca(marca);
                                        cout << this->getVehiculoCatalogo(x);
                                        
                                }
                                

                                if(opcion==3){
                                        string modelo;
                                        cout << "Introduce el nuevo modelo del vehículo" << endl;
                                        cin >> modelo;
                                        this->getVehiculoCatalogo(x).setModelo(modelo);
                                        cout << this->getVehiculoCatalogo(x);


                                }
                                

                                if(opcion==4){
                                        string tipo_combustible;
                                        cout << "Introduce el tipo de combustible" << endl;
                                        cin >> tipo_combustible;

                                        this->getVehiculoCatalogo(x).setTipoCombustible(tipo_combustible);
                                        cout << this->getVehiculoCatalogo(x);
                                }
                                

                                if(opcion==5){
                                        int cilindrada=0;
                                        cout << "Introduce la cilindrada dle vehículo" << endl;
                                        cin >> cilindrada;
                                        cilindrada=this->Filtro_numeros(cilindrada);
                                        this->getVehiculoCatalogo(x).setCilindrada(this->Filtro_numeros(cilindrada));
                                        cout << this->getVehiculoCatalogo(x);

                                }
                                

                                if(opcion==6){
                                        int valor;
                                        cout << "Introduce la capacidad máxima de combustible del vehículo" << endl;
                                        cin >> valor;
                                        this->getVehiculoCatalogo(x).setCapacidadDepositoMax(this->Filtro_numeros(valor)); 
                                        cout << this->getVehiculoCatalogo(x);
                                }
                                

                                if(opcion==7){
                                        int valor=0;
                                        cout << "Introduce los caballos del vehículo" << endl;
                                        cin >> valor;
                                        this->getVehiculoCatalogo(x).setCaballos(this->Filtro_numeros(valor));
                                        cout << this->getVehiculoCatalogo(x);
                                }
                                

                                if(opcion==8){
                                        int valor=0;
                                        cout << "Introduce la aerodinámica nueva del vehículo" << endl;
                                        cin >> valor;
                                        this->getVehiculoCatalogo(x).setAerodinamica(this->Filtro_numeros(valor));
                                        cout << this->getVehiculoCatalogo(x);
                                }
                                

                                if(opcion==9){
                                        int valor=0;
                                        cout << "Introduce la aceleración del vehículo" << endl;
                                        cin >> valor;
                                        this->getVehiculoCatalogo(x).setAceleracion(this->Filtro_numeros(valor));
                                        cout << this->getVehiculoCatalogo(x);

                                }
                                

                            if(opcion==10){
                                    int valor=0;
                                    cout << "Introduce el manejo del vehículo" << endl;
                                    cin >> valor;
                                    this->getVehiculoCatalogo(x).setManejo(this->Filtro_numeros(valor));
                                    cout << this->getVehiculoCatalogo(x) << endl;
                            }

                                
                                

                            if(opcion==11){
                                    int valor=0;
                                    cout << "Introduce la vel.máx del vehículo" << endl;
                                    cin >> valor;
                                    this->getVehiculoCatalogo(x).setVelocidadMax(this->Filtro_numeros(valor));
                                    cout << this->getVehiculoCatalogo(x);
                            }

                                
                                

                            if(opcion==12){
                                    int valor=0;
                                    cout << "Introduce la frenada del vehículo" << endl;
                                    cin >> valor;
                                    this->getVehiculoCatalogo(x).setFrenada(this->Filtro_numeros(valor));
                                    cout << this->getVehiculoCatalogo(x);
                            }

                                
                                

                            if(opcion==13){
                                    int valor=0;
                                    cout << "Introduce el combustible actual" << endl;
                                    cin >> valor;
                                    this->getVehiculoCatalogo(x).setCombustibleActual(this->Filtro_numeros(valor));
                                    cout << this->getVehiculoCatalogo(x);
                            }

                                
                                

                        if(opcion==14){
                                int valor=0;
                                cout << "Introduce el precio actual del coche" << endl;
                                cin >> valor;
                                this->getVehiculoCatalogo(x).setPrecioActual(this->Filtro_numeros(valor));
                                cout << this->getVehiculoCatalogo(x);

                        }

                                
                                

                        if(opcion==15){
                                int valor=0;
                                cout << "Introduce el precio base del vehículo" << endl;
                                cin >> valor;
                                this->getVehiculoCatalogo(x).setPrecioBase(this->Filtro_numeros(valor));
                                cout << this->getVehiculoCatalogo(x);

                        }
                                

                               
                                
                        

        }





        void Cristurismo::EliminarVehiculo(const int& i){
               if(this->debug==true)
                 cout << MAGENTA << "ENTRO A ELIMINAR VEHÍCULO DE LA POSICIÓN-->" << RESET << i << endl;

                //Reordeno el vector:
                for(int j=i;j<this->getTotal_Vehiculo()-1;j++){
                        this->catalogo_vehiculos[j]=this->catalogo_vehiculos[j+1];
                }

                this->Resize_catalogo_vehiculos(this->getTotal_Vehiculo()-1);
        }

        void Cristurismo::setTotal_Vehiculos(const int& TOTAL_VEHICULOS){
                this->total_vehiculo=TOTAL_VEHICULOS;
        }

        void Cristurismo::Agregar_Piezas_Catalogo(Pieza& p){
                if(this->debug==true)
                    cout << MAGENTA << "ENTRO EN AGREGAR PIEZA AL CATÁLOGO " << RESET << endl;
               
                this->Resize_catalogo_piezas(this->getTotal_piezas()+1);
                this->catalogo_pieza[this->getTotal_piezas()-1]=p;
        }
        void Cristurismo::Eliminar_Piezas_catalogo(const int& i){
                if(this->debug==true)
                 cout << MAGENTA << "ENTRO EN ELIMINAR PIEZA DE LA POSICIÓN --> " << RESET << i << endl;
               
                // Reordeno el vector:
                for(int j=i; j<this->getTotal_piezas()-1; j++){
                        this->catalogo_pieza[j]=this->catalogo_pieza[j+1];
                }

                this->Resize_catalogo_piezas(this->getTotal_piezas()-1);
        }

        void Cristurismo::setTotal_piezas(const int& total_piezas){
                this->total_piezas=total_piezas;
        }

        void Cristurismo::setPrecioGasolina(const double& PRECIO){
                this->PrecioGasolina=PRECIO;
        }

        void Cristurismo::setPrecioDiesel(const double& PRECIO){
                this->PrecioDiesel=PRECIO;
        }

        

        void Cristurismo::setTotal_busqueda(const int& TOTAL_BUSQUEDAD){
                this->totalBusqueda=TOTAL_BUSQUEDAD;
        }

        void Cristurismo::setLogin_player(const string& LOGIN){
                this->LoginAdmin=LOGIN;
        }

        void Cristurismo::setPassword(const string& PASSWORD){
                this->passwordAdmin=PASSWORD;
        }

        Jugador &Cristurismo::getJugador(const int& i){
            if(this->debug==true){   
               cout << "Extraigo al jugador de la posición " << i << endl;
            }   
                return this->players[i];
        }

        int Cristurismo::getTotal_Players() const{
                return this->total_player;
        }

        
        Vehiculo &Cristurismo::getVehiculoCatalogo(const int& i){
            if(this->debug==true)
                cout << "Extraigo el vehículo de la posición " << i << endl;

                return this->catalogo_vehiculos[i];
        }
        
        int Cristurismo::getTotal_Vehiculo() const{
                return this->total_vehiculo;
        }

        Pieza &Cristurismo::getPieza_catalogo(const int& i){
               if(this->debug==true)
                cout << "Extraigo la pieza de la posición " << i << endl;
                return this->catalogo_pieza[i];
        }


        int Cristurismo::getTotal_piezas() const{
                return this->total_piezas;
        }

        double Cristurismo::getPrecioGasolina() const{
                return this->PrecioGasolina;
        }
        double Cristurismo::getPrecioDiesel() const{
                return this->PrecioDiesel;
        }

        string Cristurismo::getLogin() const{
                return this->LoginAdmin;
        }

        string Cristurismo::getPassword() const{
                return this->passwordAdmin;
        }

        void Cristurismo::Resize_lista_players(const int& DIM_NUEVA){
                if(this->debug==true){              
                    cout << YELLOW << "Entro al resize de players con una dimensión nueva de: "<< RESET << DIM_NUEVA << endl;
                    cout << YELLOW << "Antes de actualizar los jugadores del sistema son--> " << RESET << this->getTotal_Players() << endl;
                }
                Jugador *aux = new Jugador[DIM_NUEVA];
                 if(aux==0){
                        cerr << RED << "ERROR, NO QUEDA MEMORIA PARA MÁS PLAYERS" << RESET << endl;
                        exit(-1);
                }

                ////////////////////////////////////////////
                if(DIM_NUEVA > this->getTotal_Players()){
                        if(this->debug==true)
                            cout << "Entro en DIM_NUEVA > DIM_ACTUAL" << endl;
                        
                       

                        // Copiamos el contenido:
                        for(int i=0; i<this->getTotal_Players(); i++){
                                aux[i]=this->players[i];
                        }

                }
                //////////////////////////////////////////////////////////
                if(DIM_NUEVA < this->getTotal_Players()){
                         if(this->debug==true)
                            cout << "Entro en DIM_NUEVA < DIM_ACTUAL" << endl;

                        this->setTotalPlayers(DIM_NUEVA);
                        // Copio contenido.
                        for(int i=0; i<this->getTotal_Players();i++){
                                aux[i]=this->players[i];
                        }
                }

                
                delete [] this->players;
                this->players=aux;
                this->setTotalPlayers(DIM_NUEVA);
                if(this->debug==true)
                        cout << YELLOW << "Ahora, tras haberse modificado la lista de jugadores, los actuales que hay son--> " << RESET << this->getTotal_Players() << endl;
        }


        void Cristurismo::Resize_catalogo_vehiculos(const int& DIM_NUEVA){
                if(this->debug==true){   
                    cout << YELLOW << "Entro al Resize del catálogo de vehículos" << endl;
                    cout << YELLOW << "Los vehículos actuales del sistema son--> " << RESET << this->getTotal_Vehiculo() << endl;
                    cout << "Cantidad nueva que me piden " << DIM_NUEVA << endl;
                }

                
                 Vehiculo* aux = new Vehiculo[DIM_NUEVA];
                        if(aux==0){
                                cerr << RED << "ERROR, NO QUEDA MEMORIA PARA MÁS VEHÍCULOS" << RESET << endl;
                                exit(-1);
                        }

                ///////////////////////////////////////////////
                if(DIM_NUEVA > this->getTotal_Vehiculo()){
                        if(this->debug==true)
                            cout << "Entro a DIM_NUEVA > DIM_ACTUAL" << endl;
                
                        // Copio el contenido:
                        for(int i=0; i<this->getTotal_Vehiculo();i++){
                                aux[i]=this->catalogo_vehiculos[i];
                        }     
                }
                
                /////////////////////////////////////////////////
                if(DIM_NUEVA < this->getTotal_Vehiculo()){
                         if(this->debug==true)
                         cout << "Entro en DIM_NUEVA < DIM_ACTUAL" << endl;

                        this->setTotal_Vehiculos(DIM_NUEVA);
                        
                        // Copio el contenido:
                        for(int i=0; i<this->getTotal_Vehiculo();i++){
                                aux[i]=this->catalogo_vehiculos[i];
                        }

                       
                }
                // Borramos el vector antiguo.
                delete [] this->catalogo_vehiculos;
                this->catalogo_vehiculos=aux;
                this->setTotal_Vehiculos(DIM_NUEVA);
                
                 if(this->debug==true)
                    cout << YELLOW << "La cantidad actual modificar el catĺogo es--> " << this->getTotal_Vehiculo() << RESET << endl;
        }
        
        void Cristurismo::Resize_catalogo_piezas(const int& DIM_NUEVA){
                if(this->debug==true){
                    cout << YELLOW << "Entro al resize de piezas" << RESET << endl;
                    cout << YELLOW << "La cantidad actual de piezas en el catálogo son--> " << this->getTotal_piezas() << RESET << endl;
                }
                Pieza* aux = new Pieza[DIM_NUEVA];
                if(aux==0){
                        cerr << RED << "ERROR, NO QUEDA MEMORIA PARA MÁS PIEZAS" << RESET << endl;
                                exit(-1);
                }
                ///////////////////////////////////////////////////////////
                if(DIM_NUEVA > this->getTotal_piezas()){
                         if(this->debug==true)
                            cout << "Entro en DIM_NUEVA > DIM_ACTUAL" << endl;
                        
                        // Copiamos el contenido:
                        for(int i=0; i<this->getTotal_piezas();i++){
                                aux[i]=this->catalogo_pieza[i];
                        }
                }

                ////////////////////////////////////////////////////////
                if(DIM_NUEVA < this->getTotal_piezas()){
                     if(this->debug==true)
                        cout << "Entro a DIM_NUEVA < DIM_ACTUAL" << endl;

                        this->setTotal_piezas(DIM_NUEVA);

                        // COPIAMOS CONTENIDO:
                        for(int i=0; i<this->getTotal_piezas();i++){
                                aux[i]=this->catalogo_pieza[i];
                        }      
                }
                
                // Borramos el contenido.
                delete [] this->catalogo_pieza;
                this->catalogo_pieza=aux; 
                this->setTotal_piezas(DIM_NUEVA);
                if(this->debug==true)
                cout << YELLOW << "El catálogo de piezas tras modificarse tiene-->" << RESET << this->getTotal_piezas() << endl;

        }

        ostream& operator << (ostream& flujo,Cristurismo& c){
                if(c.debug==true){
                        cout << MAGENTA << "Entro a la sobrecarga de cout de Cristurismo" << RESET << endl;
                }

                flujo << "Jugador ";
                for(int i=0; i<c.getTotal_Players();i++){
                        flujo << i << endl;
                        flujo << c.getJugador(i) << endl;
                }

                flujo << "vehículo ";
                for(int i=0; i<c.getTotal_Vehiculo(); i++){
                        flujo << i << endl;
                        flujo << c.getVehiculoCatalogo(i);
                }


                flujo << "Pieza ";
                for(int i=0; i<c.getTotal_piezas();i++){
                        flujo << i << endl;
                        flujo << c.getPieza_catalogo(i);
                }
                return flujo;

        }


void Cristurismo::Menu_admin(){
        int n=0;
        bool dentro=true;



        cout << MAGENTA << "---------------------------------- CATÁLOGO DE PIEZAS ------------------------------------------------------" << RESET << endl;
        cout << GREEN << "El número de piezas actual del catálogo son --> " << RESET << this->getTotal_piezas() << endl;
        cout << endl;

        for(int i=0; i<this->getTotal_piezas(); i++){
                cout << GREEN << "Pieza número --> " << RESET << i << GREEN << ":" << RESET <<  endl;
                cout << this->getPieza_catalogo(i);
        }


        cout << GREEN << "---------------------------------------- CATÁLOGO DE VEHÍCULOS -------------------------------------------------------------------" << endl;
        cout << GREEN << "Los vehículos actuales disponibles son --> " << RESET << this->getTotal_Vehiculo() << endl;
        cout << endl;
        
        for(int i=0; i<this->getTotal_Vehiculo(); i++){
                cout << GREEN << "Vehículo número " << RESET << i << GREEN << ": " << RESET << endl;
                cout << this->getVehiculoCatalogo(i);
                cout << endl;
                
        }

        cout << GREEN << "------------------------------------------------------Jugadores actuales--------------------------------------------------------------------------------" << RESET << endl;
        cout << GREEN << "Los jugadores actuales activos son ---> " << RESET << this->getTotal_Players() << endl;
        cout << endl;
        for(int i=0; i<this->getTotal_Players(); i++){
                cout << GREEN << "Jugador nº " << RESET << i << GREEN << ":" << RESET << endl;
                cout << this->getJugador(i);
                cout << endl;
        }
                
        cout << GREEN << "Bienvenid@, ¿Qué vas a hacer ahora?" << RESET << endl;
       
        do{ 
                
                cout << endl;
                cout << "Para salir pulsa 0" << endl;
                cout << BOLDGREEN << "Pulsa 1 si deseas agregar una pieza nueva al catálogo" << endl;
                cout << "Pulsa 2 si deseas agregar un vehículo al catálogo" << endl;
                cout << "Pulsa 3 para agregar un Jugador al sistema" << RESET << endl;
                cout << endl;

               
                cout << "Pulsa 5 si deseas modificar un vehículo" << endl;
                cout << "Pulsa 6 para modificar el id o nombre de un jugador" << endl;
                cout << RESET << endl;
                
                cout << CYAN << "Pulsa 7 para eliminar una pieza del catálogo" << endl;
                cout << "Pulsa 8 para eliminar un vehículo del catálogo" << endl;
                cout << "Pulsa 9 para eliminar un jugador del sistema" << endl;
                cout << "Pulsa 10 para mostrar el estado actual del sistema" << endl;
                cout << "Pulsa 11 para ver casificación en el sistema de jugadores" << endl;
                cout << "Pulsa 12 para buscar un vehículo" << endl;
                cout << "Pulsa 13 para activar erase un Vehículo" << endl;
                cout << RESET << endl;
                cin >> n;

                while(n<0 or n>13){
                        cerr << RED << "OPCIÓN INCORRECTA" << RESET << endl;
                        cin >> n;
                }
                        
                        
                if(n==0){

                        cout << BLUE << "Sesión cerrada" << RESET << endl;
                        dentro=false;             
                }

                if(n==1){
                                
                        Pieza nueva;
                        cin >> nueva;
                        int id=0;
                        // for(int i=0; i<this->getTotal_piezas();i++){
                                
                                // Bucle para evitar repeticiones de ID(PK).
                        //         if(nueva.getId_pieza()==this->getPieza_catalogo(i).getId_pieza()){
                                      
                        //                 cerr << BOLDRED << "Esta ID ya existe" << RESET << endl;
                        //                 cin >> id;
                        //                 nueva.setId_pieza(this->Filtro_numeros(id));
                                       
                        //         }

                        //         i=-1;
                        // }

                        this->Agregar_Piezas_Catalogo(nueva);
                        cout << GREEN << "Pieza agregada con éxito" << RESET << endl;
                        cout << endl;
                }
                                        
                                

                if(n==2){
                                
                        Vehiculo v;
                        cin >> v;
                        this->AgregarVehiculo(v);
                        cout << GREEN << "Vehículo agregado con éxito" << RESET << endl;
                                
                }

                if(n==3){
                        Jugador j;
                        cin >> j;
                        this->Agregar_jugador(j);
                        cout << GREEN << "Jugador agregado con éxito" << endl;
                        
                 }

                if(n==4){
                                

                                
                }

                if(n==5){
                        int x;
                        for(int i=0; i<this->getTotal_Vehiculo(); i++){
                                cout << GREEN << "Vehículo nº " << RESET << i << endl;
                                cout << this->getVehiculoCatalogo(i);
                                cout << endl;
                        }
                                        
                        cout << YELLOW << "Introduce el nº vehículo que deseas modificar" << RESET << endl;
                        cin >> x;

                        while(x<0 or x>this->getTotal_Vehiculo()){
                                cerr << BOLDRED << "ERROR, ELIJA USTED UN Nº ENTRE EL 0 Y EL " << this->getTotal_Vehiculo() << RESET << endl;
                                cin >> x;
                        }
                        

                        this->Modificar_Vehiculo(x);

                }

                if(n==6){
                         int valor=0;
                         for(int i=0; i<getTotal_Players();i++){
                                 cout << GREEN << "Jugador nº " << RESET << i << endl;
                                 cout << this->getJugador(i);
                         }

                         cout << MAGENTA << "Elije el el número del jugador a modificar" << RESET << endl;
                         cin >> valor;

                        while(valor>=this->getTotal_Players()){
                                cerr << RED << "Por favor, introduce una cantidad entre 0 y " << this->getTotal_Players()-1 << RESET << endl;
                                cin >> valor;
                        }
                         

                         this->Modificar_Jugador(this->Filtro_numeros(valor));
                 }

                if(n==7){
                                        
                        int x=0;
                                                
                        for(int i=0; i<this->getTotal_piezas(); i++){
                                cout << "PIEZA Nº -->" << i << endl;
                                cout << this->getPieza_catalogo(i);
                                 cout << endl;
                         } 

                        cout << "Introduce el nº de la pieza que deseas eliminar entre 0 y " << this->getTotal_piezas() << endl;
                        cin >> x;
                       
                        while(x<0 or x>this->getTotal_piezas()){
                                cerr << BOLDRED << "ERROR, INTRODUCE UNA CANTIDAD EN EL INTERVALO MENCIONADO ANTERIORMENTE" << RESET << endl;
                                cin>>x;
                        }

                        
                        this->Eliminar_Piezas_catalogo(x);
                        cout << GREEN << "ÉXITO" << RESET << endl;

                                for(int i=0; i<this->getTotal_piezas(); i++){
                                        cout << GREEN <<  "PIEZA Nº -->" << i << endl;
                                        cout << this->getPieza_catalogo(i);
                                        cout << endl;
                                } 


                }
                                

                if(n==8){
                          int opcion=0;
                          for(int i=0; i<this->getTotal_Vehiculo(); i++){
                                  cout << "Vehiculo nº " << i << endl;
                                  cout << this->getVehiculoCatalogo(i);
                                  cout << endl;
                          }
                          cout << "Introduce el nº que desea eliminar entre 0 y  " << this->getTotal_Vehiculo() << endl;
                          cin >> opcion;

                          while(opcion <0 or opcion>this->getTotal_Vehiculo()){
                                cerr << BOLDRED << "ERROR, INTRODUCE UNA CANTIDAD EN EL INTERVALO MENCIONADO ANTERIORMENTE" << RESET << endl;
                                cin>>opcion;
                          }

                          this->EliminarVehiculo(opcion);
                          cout << GREEN << "ÉXITO" << RESET << endl;
                          cout << endl;

                          for(int i=0; i<this->getTotal_Vehiculo(); i++){
                                  cout << GREEN << "VEHÍCULO Nº --> " << RESET << i << endl;
                                  this->getVehiculoCatalogo(i);
                          }                    

                                        

                                

                }

                if(n==9){
                        int n=0;

                        for(int i=0; i<this->getTotal_Players();i++){
                                cout << "Nº de jugador " << i << endl;
                                cout << this->getJugador(i);
                                cout << endl;
                        }

                        cout << "pulsa el nº de jugador que desee eliminar entre 0 y " << this->getTotal_Players() << endl;
                        cin >> n;

                         while(n <0 or n>this->getTotal_Players()){
                                cerr << BOLDRED << "ERROR, INTRODUCE UNA CANTIDAD EN EL INTERVALO MENCIONADO ANTERIORMENTE" << RESET << endl;
                                cin>>n;
                          }

                        this->Eliminar_jugador(n);

                        for(int i=0; i<this->getTotal_Players();i++){
                                cout << "Nº de jugador " << i << endl;
                                cout << this->getJugador(i);
                                cout << endl;
                        }
                        

                }


                               
                if(n==10){
                        cout << CYAN <<  "============================ ESTADO ACTUAL DEL SISTEMA =================================" << RESET <<  endl;
                        cout << endl;
                        cout << CYAN << "CANTIDAD DE PIEZAS --> " << RESET << this->getTotal_piezas() << endl;
                        for(int i=0; i<this->getTotal_piezas(); i++){
                                cout << GREEN << "PIEZA Nº --> " << RESET << i << endl;
                                cout << this->getPieza_catalogo(i);
                                cout << endl;
                        }
                        cout << endl;

                        cout << CYAN << "=======================================================================================0" << RESET << endl;
                        cout << endl;
                        cout << CYAN << "CANTIDAD DE VEHÍCULOS --> " << RESET << this->getTotal_Vehiculo() << endl;
                        for(int i=0; i<this->getTotal_Vehiculo(); i++){
                                cout << GREEN << "Vehículo Nº --> " << RESET << i << endl; 
                                cout << this->getVehiculoCatalogo(i);
                                cout << endl;
                        }

                        cout << CYAN << "=======================================================================================0" << RESET << endl;
                        cout << endl;
                        cout << CYAN << "CANTIDAD DE JUGADORES --> " << RESET << this->getTotal_Players() << endl;
                        for(int i=0; i<getTotal_Players(); i++){
                                 cout << GREEN << "JUGADOR Nº --> " << RESET << i << endl;
                                 cout << this->getJugador(i);
                                 cout << endl;
                        }
                } 


                if(n==11){
                        this->Mostrar_clasificacion_de_jugadores();
                }                       


                 if(n==12){
                         string marca;
                         int id=0;

                         cout << GREEN << "Introduce la marca del vehículo" << RESET << endl;
                         cin >> marca;

                        this->Buscar_Vehiculo(marca);
                 } 


                 if(n==13){
                         this->eraseunVehiculo();
                 }      

        }while(dentro==true);
}




void Cristurismo::Buscar_Vehiculo(string& marca){
       int dimension=this->getTotal_Vehiculo();
       
       int contador=0;
       int contador2=0;
       
       Vehiculo *v_catalogo=new Vehiculo[dimension];
        Vehiculo* v_garaje=new Vehiculo[dimension];

       if(v_catalogo==0){
               cerr << RED << "NO QUEDA ESPACIO EN LA MEMORIA" << RESET << endl;
               exit(-1);
       }

        if(v_garaje==0){
               cerr << RED << "NO QUEDA ESPACIO EN LA MEMORIA" << RESET << endl;
               exit(-1);
       }


        // Bucle que va a recorrer el catálogo para ir comparando.
        
        for(int i=0; i<this->getTotal_Vehiculo();i++){

        //        Si las marcas coinciden pues copio el vehículo.
                if(this->getVehiculoCatalogo(i).getMarca()==marca){
                        v_catalogo[contador]=this->getVehiculoCatalogo(i);
                        contador++;
                }
               /*  // Bucle que recorre el vector de vehículos que se halla en garaje.
                for(int j=0; j<this->getJugador(i).getGaraje_player().getCantidad_Vehiculos();j++){
                        
                        if(this->getJugador(i).getGaraje_player().getVehiculo(j).getMarca()==marca){
                                v_garaje[contador2]=this->getJugador(i).getGaraje_player().getVehiculo(j);
                                contador2++;
                        }
                } */
        }

        cout << BLUE << "Vehículos en el catálogo"<< endl;
        cout << BLUE << "=====================================" << RESET << endl;
        cout << endl;
        for(int i=0; i<dimension;i++){
                cout << v_catalogo[i] << endl;
                cout << endl;
        }

        // cout << GREEN << "Vehículo en garaje" << endl;
        // cout << GREEN << "==========================================" << RESET << endl;
        // for(int i=0; i<dimension; i++){
        //         cout << v_garaje[i];
        //         cout << endl;
        // }

       
        
}








void Cristurismo::Menu_jugador(const int& i){
        int x;
        
        cout << BLUE << "Hola de nuevo   " << this->getJugador(i).getLogin() << " :)" << endl;
        cout << endl;

         do{
                cout << BLUE << "Pulsa 0 para salir/cambiar de usuario" << endl;
                cout << "Pulsa 1 para ver tu garaje" << endl;
                cout << "Pulsa 2 para desasignar una pieza de un vehículo" << endl;
                cout << "Pulsa 3 para agregar una pieza del sistema al vehículo que hayas seleccionado" << endl;
                cout << "Pulsa 4 para comprar un vehículo" << endl;
                cout << "Pulsa 5 para vender algún vehículo de tu garaje" << endl;
                cin >> x;

                x=this->Filtro_numeros(x);

                if(x==0){
                       
                        cout << BLUE << "HASTA PRONTO" << RESET << endl;
                }

                if(x==1){
                     cout << this->getJugador(i).getGaraje_player();                           
                }

                if(x==2){
                        int id=0;
                        int n=0;
                        bool parar=false;
                        
                        if(this->getJugador(i).getGaraje_player().getCantidad_Vehiculos()>0){
                                        
                                cout << "Selecciona el nº de vehículo al que desees entrar." << endl;
                                cin >> id;
                                 while(id<0 or id>this->getJugador(i).getGaraje_player().getCantidad_Vehiculos()){
                                         cerr << BOLDRED << "ERROR, OPCIÓN INCORRECTA, INTRODUZCA ENTRE 0 Y " << this->getJugador(i).getGaraje_player().getCantidad_Vehiculos()<< RESET << endl;
                                        cin >> id;
                                }

                                

                                cout << this->getJugador(i).getGaraje_player().getVehiculo(id);
                                cout << endl;
                                cout << BLUE << "Introduce el nº de pieza que deseas borrar " << RESET << this->getJugador(i).getGaraje_player().getCantidad_Vehiculos() << endl;
                                cin >> n;

                                while(n<0 or n>this->getJugador(i).getGaraje_player().getCantidad_Vehiculos()){
                                        cerr << BOLDRED << "ERROR, OPCIÓN INCORRECTA, INTRODUZCA ENTRE 0 Y " << this->getJugador(i).getGaraje_player().getCantidad_Vehiculos()<< RESET << endl;
                                        cin >> n;

                                }


                                if(this->getJugador(i).getGaraje_player().getVehiculo(id).getTotalPiezas()>0){
                                        this->getJugador(i).getGaraje_player().getVehiculo(id).Eliminar_pieza_Tuneada(n);
                                        cout << GREEN << "Pieza borrada con éxito" << endl;
                                }

                        }

                        if(this->getJugador(i).getGaraje_player().getCantidad_Vehiculos()==0){
                                cerr << RED << "No hay ningún vehículo guardado en el garaje" << RESET << endl;
                        }

                        if(this->getJugador(i).getGaraje_player().getVehiculo(id).getTotalPiezas()==0){
                                cerr << RED << "Lo sentimos, pero no queda ninguna pieza en el vehículo." << RESET << endl;
                        }


                        
                }

                if(x==3){
                        int n=0;
                        int id=0;
                       
                        if(this->getJugador(i).getGaraje_player().getCantidad_Vehiculos()>0){
                                cout << "Selecciona en nº de vehículo al quedees entrar." << endl;
                                cin >> id;

                                id=this->Filtro_numeros(id);

                                cout << this->getJugador(i).getGaraje_player().getVehiculo(id);
                        
                                for(int i=0; i<this->getTotal_piezas(); i++){
                                        cout << "PIEZA Nº " << RESET << i << endl;
                                        cout << this->getPieza_catalogo(i);
                                 }

                                cout << GREEN << "Selecciona el número de pieza que desees añadir" << endl;
                                cin >> n;
                                n=this->Filtro_numeros(n);
                                this->getJugador(i).getGaraje_player().getVehiculo(id).Agregar_Pieza_Tuneada(&this->getPieza_catalogo(n));
                        }

                        if(this->getJugador(i).getGaraje_player().getCantidad_Vehiculos()==0){
                                cerr << BOLDRED << "No tienes ningún vehículo en el garaje" << RESET << endl;
                        }

                }

        }while(x!=0);
}






void Cristurismo::Cargar_datos(){
        Pieza p, p1, p2, p3;
        Vehiculo v, v1, v2, v3, v4;
        Garage g, g1, g2;
        Jugador j, j1, j2, admin;
        int opcion=0;
        string login, password;
        bool dentro=false;


            cout << MAGENTA << "************************************** BIENVENID@ A CRISTURISMO **************************************************" << RESET << endl;
            


            p.setAceleracion(30);
            p.setAerodinamica(0);
            p.setFrenada(0);
            p.setId_pieza(111);
            p.setManejo(0);
            p.setNombre_pieza("Nitro");
            p.setPrecio(450);
            p.setVelocidadMax(10);
            this->Agregar_Piezas_Catalogo(p);

            p1.setAceleracion(30);
            p1.setAerodinamica(20);
            p1.setFrenada(10);
            p1.setId_pieza(222);
            p1.setManejo(35);
            p1.setNombre_pieza("Alerón (FC)");
            p1.setPrecio(250);
            p1.setVelocidadMax(15);
            this->Agregar_Piezas_Catalogo(p1);


            p2.setAceleracion(30);
            p2.setAerodinamica(0);
            p2.setFrenada(0);
            p2.setId_pieza(632);
            p2.setManejo(0);
            p2.setNombre_pieza("Chasis_Reforzado");
            p2.setPrecio(2500);
            p2.setVelocidadMax(-10);
            this->Agregar_Piezas_Catalogo(p2);


            p3.setAceleracion(0);
            p3.setAerodinamica(0);
            p3.setFrenada(0);
            p3.setId_pieza(344);
            p3.setManejo(5);
            p3.setNombre_pieza("Luces_Xenón");
            p3.setPrecio(50);
            p3.setVelocidadMax(0);
            this->Agregar_Piezas_Catalogo(p3);


        


            v.setId_vehiculo(1012);
            v.setMarca("Audi");
            v.setModelo("c_cuatro");
            v.setTipoCombustible("Diesel++");
            v.setAceleracion(100);
            v.setAerodinamica(120);
            v.setCaballos(250);
            v.setCapacidadDepositoMax(50);
            v.setVelocidadMax(290);
            v.setCilindrada(40);
            v.setCombustibleActual(30);
            v.setFrenada(120);
            v.setManejo(150);
            v.setPrecioActual(200000);
            v.setPrecioBase(200000);
            v.setTotalPiezas(0);
            this->AgregarVehiculo(v);

            v1.setId_vehiculo(1029);
            v1.setMarca("Mustan");
            v1.setModelo("X_DEPORT_X");
            v1.setTipoCombustible("Gasolina");
            v1.setAceleracion(120);
            v1.setAerodinamica(100);
            v1.setCaballos(300);
            v1.setCapacidadDepositoMax(50);
            v1.setVelocidadMax(380);
            v1.setCilindrada(400);
            v1.setCombustibleActual(37);
            v1.setFrenada(120);
            v1.setManejo(150);
            v1.setPrecioActual(200000);
            v1.setPrecioBase(200000);
            v1.setTotalPiezas(0);
            this->AgregarVehiculo(v1);


            v2.setId_vehiculo(888);
            v2.setMarca("SEAT");
            v2.setModelo("ALTEA");
            v2.setTipoCombustible("Diesel++");
            v2.setAceleracion(120);
            v2.setAerodinamica(100);
            v2.setCaballos(100);
            v2.setCapacidadDepositoMax(30);
            v2.setVelocidadMax(180);
            v2.setCilindrada(75);
            v2.setCombustibleActual(30);
            v2.setFrenada(95);
            v2.setManejo(50);
            v2.setPrecioActual(45270);
            v2.setPrecioBase(45270);
            v2.setTotalPiezas(0);
            this->AgregarVehiculo(v2);


            v3.setId_vehiculo(7593);
            v3.setMarca("Aston_Martin");
            v3.setModelo("SPORT");
            v3.setTipoCombustible("Gasolina");
            v3.setAceleracion(250);
            v3.setAerodinamica(300);
            v3.setCaballos(800);
            v3.setCapacidadDepositoMax(80);
            v3.setVelocidadMax(380);
            v3.setCilindrada(450);
            v3.setCombustibleActual(76);
            v3.setFrenada(240);
            v3.setManejo(220);
            v3.setPrecioActual(1500000);
            v3.setPrecioBase(1500000);
            v3.setTotalPiezas(0);
            this->AgregarVehiculo(v3);

            v4.setId_vehiculo(7593);
            v4.setMarca("Ferrari");
            v4.setModelo("BEYRON");
            v4.setTipoCombustible("Gasolina");
            v4.setAceleracion(350);
            v4.setAerodinamica(250);
            v4.setCaballos(1200);
            v4.setCapacidadDepositoMax(120);
            v4.setVelocidadMax(400);
            v4.setCilindrada(800);
            v4.setCombustibleActual(100);
            v4.setFrenada(300);
            v4.setManejo(200);
            v4.setPrecioActual(5500000);
            v4.setPrecioBase(5500000);
            v4.setTotalPiezas(0);
            this->AgregarVehiculo(v4);

        


            g.setId_garage(111);
            g1.setId_garage(555);
            g2.setId_garage(673);

            v.Agregar_Pieza_Tuneada(&p);
            v.Agregar_Pieza_Tuneada(&p1);

            g2.Agregar_vehiculo(v);
            g2.Agregar_vehiculo(v1);
            g2.Agregar_vehiculo(v2);

            v3.Agregar_Pieza_Tuneada(&p1);
            v3.Agregar_Pieza_Tuneada(&p3);
            v3.Agregar_Pieza_Tuneada(&p2);
            g.Agregar_vehiculo(v3);
            g.Agregar_vehiculo(v);

            g1.Agregar_vehiculo(v);
            g1.Agregar_vehiculo(v2);


            j.setId_player(1);
            j.setLogin("Fernando_Esteso");
            j.setPassword("Usuario123");
            j.setNumeroVictorias(20);
            j.Agregar_garaje(g);
            this->Agregar_jugador(j);



            j1.setId_player(132);
            j1.setLogin("Delegado_CHETO");
            j1.setPassword("Alejandro_Elvira");
            j1.setNumeroVictorias(354);
            j1.Agregar_garaje(g2);
            this->Agregar_jugador(j1);



            j2.setId_player(1);
            j2.setLogin("Jose_gras");
            j2.setPassword("padre123");
            j2.setNumeroVictorias(20);
            j2.Agregar_garaje(g1);
            this->Agregar_jugador(j2);

            admin.setLogin("Jaime_MATAS");
            admin.setPassword("Josegrass");
            
        do{ 
                cout << MAGENTA << "Pulsa 1 para iniciar sesión como admin" << endl;
                cout << "Pulsa 2 para iniciar sesión como Jugador" << RESET << endl;
                cout << "Pulsa 0 para salir" << endl;
        
                cin >> opcion;

        
                if(opcion==0){
                        dentro=false;
                        cout << "Bye ^^" << endl;
                }

                if(opcion==1){
                        cout << MAGENTA << "Muy buenas, por favor introduce tu Login" << RESET << endl;
                        cin >> login;

                        if(login!=admin.getLogin()){
                                
                                while(login!=admin.getLogin()){
                                        cerr << RED << "Login incorrecto" << RESET << endl;
                                        cin >> login;

                                        
                                }

                        }

                        cout << MAGENTA << "Introduce tu contraseña" << RESET <<  endl;
                        cin >> password;
                

                        if(password!=admin.getPassword()){
                                
                                while(password!=admin.getPassword()){
                                        cerr << RED << "Contraseña incorrecta" << RESET << endl;
                                        cin >> password;

                                }       
                        }

                        if(password==admin.getPassword()){
                                dentro=true;
                        }

                        if(dentro==true){
                                this->Menu_admin();
                        }
                }




        if(opcion==2){
                int x=0;
                bool encontrado=false;
                
               
               
                   
                        cout << BLUE << "Introduce tu login:" << RESET << endl;
                        cin >> login;
                
                        for(x=0; x<this->getTotal_Players() and encontrado==false; x++){
                        
                                if(this->getJugador(x).getLogin()==login){
                                        encontrado=true;
                                        x--;
                                       
                                }

                                if(encontrado==false and x==this->getTotal_Players()-1){
                                        
                                        cout << RED << "Lo sentimos pero este login no existe, por favor, vuelva a introducirlo" << RESET << endl;
                                        cin >> login;
                                        x=0;
                                }
                        }

                        

                        if(encontrado==true){
                                cout << BLUE << "Introduzca su contraseña" << RESET << endl;
                                cin >> password;

                                if(password!=this->getJugador(x).getPassword()){
                                        encontrado= false;
                                }

                                while(encontrado==false){
                                        cout << "Error, por favor, introduzca de nuevo la contraseña" << endl;
                                        cin >> password;

                                        if(password==this->getJugador(x).getPassword()){
                                                encontrado=true;
                                        }
                                        
                                }

                        }

                        
                        if(encontrado==true){
                                this->Menu_jugador(x);
                        }

                               
                
                }

                if(opcion<0 or opcion>1){
                        cerr << RED << "Opción incorrecta" << RESET << endl;
                }
        
        }while(opcion!=0);
}

        
        
void Cristurismo::Mostrar_clasificacion_de_jugadores(){
       



   
}        
        


void Cristurismo::eraseunVehiculo(){
        int numero=0;
        int id=0;
        // Mostramos el catálogo de vehículos:
        for(int i=0; i<this->getTotal_Vehiculo();i++){
                cout << GREEN << "Vehículo Nº " << i << RESET << endl;
                cout << CYAN << "=======================================" << RESET << endl;
                cout << this->getVehiculoCatalogo(i);
                cout << CYAN << "=======================================" << RESET << endl;
        }

        cout << "Introduce el nº del vehículo que deseas eliminar" << endl;
        cin >> numero;

        while(numero<0 or numero>this->getTotal_Vehiculo()){
                cerr << RED <<"Error, número inválido, introduce del 0 al " << this->getTotal_Vehiculo() << RESET << endl;
                cin >> numero;
        }

        id=this->catalogo_vehiculos[numero].getId_vehiculo();
        cout << "La id del vehículo es --> " << id << endl;

        this->EliminarVehiculo(numero);
        

        // Bucle que va a recorrer el vector de jugadores del sistema.
        for(int i=0; i<this->getTotal_Players();i++){

                // Bucle que va a recorrer el vector de vehículo del garaje del jugador correspondiente.
                for(int j=0;j<this->getJugador(i).getGaraje_player().getCantidad_Vehiculos();j++){
                        
                        if(this->getJugador(i).getGaraje_player().getVehiculo(j).getId_vehiculo()==id){
                                this->getJugador(i).getGaraje_player().Eliminar_vehiculo(j);
                                cout << GREEN  << "Se ha eliminado el vehículo con éxito" << RESET << endl;
                        }
                }
        }
}






        


