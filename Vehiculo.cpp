 #include "Pieza.h"
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
 
 
        Vehiculo::Vehiculo(){
            if(this->debug==true){
                cout << YELLOW << "Entrando al constructor de Vehiculo por defecto."<< RESET << endl;
            }

            this->setTotalPiezas(0);
            this->Tuning=new Pieza*[this->getTotalPiezas()+1];
           
            if(this->Tuning==0){
                cerr << RED << "Error, no queda espacio en la memoria" << RESET << endl;
                exit(-1);
            }

        this->setId_vehiculo(0);
        this->setMarca("NULL");
        this->setModelo("NULL");
        this->setTipoCombustible("NULL");
        this->setCilindrada(0);
        this->setCapacidadDepositoMax(0);
        this->setCaballos(0);
        this->setAerodinamica(0);
        this->setAceleracion(0);
        this->setManejo(0);
        this->setVelocidadMax(0);
        this->setFrenada(0);
        this->setCombustibleActual(0.0);
        
        
        this->setPrecioActual(0);
        this->setPrecioBase(0);
        }


        Vehiculo::Vehiculo(const Vehiculo& v1){
            if(this->debug==true){
                cout << YELLOW << "Entrando al constructor de Vehiculo por copia." << RESET << endl;
            }
            this->setTotalPiezas(v1.getTotalPiezas()); //Actualizo la util de objeto nuevo con el que se pasar para ser copiado.
            this->Tuning=new Pieza*[this->getTotalPiezas()];

            if(this->Tuning==0){
                cerr << RED << "Error, no queda espacio en la memoria" << RESET << endl;
                exit(-1);
            }
            // Copio el contenido de v1 en el objeto que llama al this.
            for(int i=0; i<v1.getTotalPiezas();i++){
                this->Tuning[i]=v1.Tuning[i];
            }

            this->setId_vehiculo(v1.getId_vehiculo());
            this->setMarca(v1.getMarca());
            this->setModelo(v1.getModelo());
            this->setTipoCombustible(v1.getTipoCombustible());
            this->setCilindrada(v1.getCilindrada());
            this->setCapacidadDepositoMax(v1.getCapacidadDepositoMax());
            this->setCaballos(v1.getCaballos());
            this->setAerodinamica(v1.getAerodinamica());
            this->setAceleracion(v1.getAceleracion());
            this->setManejo(v1.getManejo());
            this->setVelocidadMax(v1.getVelocidadMax());
            this->setFrenada(v1.getFrenada());
            this->setCombustibleActual(v1.getCombustibleActual());
            this->setPrecioActual(v1.getPrecioActual());
            this->setPrecioBase(v1.getPrecioBase());
        }


        Vehiculo::~Vehiculo(){
            if(this->debug==true){
                cout << RED << "Entrando al destructor de vehiculo." << RESET << endl;
            }

            this->setId_vehiculo(0);
            this->setMarca("NULL");
            this->setModelo("NULL");
            this->setTipoCombustible("NULL");
            this->setCilindrada(0);
            this->setCapacidadDepositoMax(0);
            this->setCaballos(0);
            this->setAerodinamica(0);
            this->setAceleracion(0);
            this->setManejo(0);
            this->setVelocidadMax(0);
            this->setFrenada(0);
            this->setCombustibleActual(0.0);
            
            this->setPrecioActual(0);
            this->setPrecioBase(0);
            
            // Para mayor seguridad de borrado, limpiamos el vector de punteros a pieza contenido en la clase Vehiculo.
            
                // for(int i=0; i<this->getTotalPiezas();i++){
                //     this->Tuning[i]=NULL;
                // }
            
            this->setTotalPiezas(0);
            
            delete [] this->Tuning;

            
            this->Tuning=NULL;
            
            if(this->debug==true)
                cout <<BOLDRED "Salgo del destructor de vehículo" << RESET << endl;

        }


        void Vehiculo::setId_vehiculo(const int& ID_VEHICULO){
            this->id_vehiculo=ID_VEHICULO;
        }
        void Vehiculo::setMarca(const string& MARCA){
            this->marca=MARCA;
        }
        void Vehiculo::setModelo(const string& MODELO){
            this->modelo=MODELO;
        }
        void Vehiculo::setTipoCombustible(const string& combustible){
            this->tipoCombustible=combustible;
        }
        void Vehiculo::setCilindrada(const int& CILINDRADA){
            this->cilindrada=CILINDRADA;
        }
        void Vehiculo::setCapacidadDepositoMax(const double& CAPACIDAD_MAXIMA_DEL_DEPOSITO){
            this->capacidadDepositoMax=CAPACIDAD_MAXIMA_DEL_DEPOSITO;
        }
        void Vehiculo::setCaballos(const int& CABALLOS){
            this->caballos=CABALLOS;
        }
        void Vehiculo::setAerodinamica(const int& AERODINAMICA){
            this->aerodinamica=AERODINAMICA;
        }
        void Vehiculo::setAceleracion(const int& ACELERACION){
            this->aceleracion=ACELERACION;
        }
        void Vehiculo::setManejo(const int& MANEJO){
            this->manejo=MANEJO;
        }
        void Vehiculo::setVelocidadMax(const int& VELOCIDADMAX){
            this->velocidadMax=VELOCIDADMAX;
        }
        void Vehiculo::setFrenada(const int& FRENADA){
            this->frenada=FRENADA;
        }
        void Vehiculo::setCombustibleActual(const double& COMBUSTIBLEACTUAL){
            this->combustibleActual=COMBUSTIBLEACTUAL;
        }

        void Vehiculo::Agregar_Pieza_Tuneada(Pieza* Nuevo_tuning){
           if(this->debug==true)
                cout << "Las piezas actuales tuneadas son: " << this->getTotalPiezas() << endl;

            this->Resize_Piezas(this->getTotalPiezas()+1);
            this->Tuning[this->getTotalPiezas()-1]=Nuevo_tuning;
            if(this->debug==true)
                cout<< "Piezas actuales después de agregar: " << this->getTotalPiezas() << endl;

        }


        void Vehiculo::Eliminar_pieza_Tuneada(const int& i){
            
                cout << YELLOW << "Elimino la pieza nº " << i << RESET << endl;
            
            this->Tuning[i]=NULL; //Borro ese puntero.

            // Reordeno el vector para quitar del medio ese hueco vacío, es decir, el de la posición i.
            for(int j=i; j<this->getTotalPiezas()-1;j++){
                this->Tuning[j]=Tuning[j+1];
            }
            this->Resize_Piezas(this->getTotalPiezas()-1);

        }

        void Vehiculo::setTotalPiezas(const int& TOTAL_PIEZAS){
            this->totalPiezas=TOTAL_PIEZAS;
        }
        void Vehiculo::setPrecioActual(const double& PRECIO_ACTUAL){
            this->precioActual=PRECIO_ACTUAL;
        }
        void Vehiculo::setPrecioBase(const double& PRECIO_BASE){
            this->precioBase=PRECIO_BASE;
        }

// ------------------------------------------------------------------------------------------------------------------------------------

         int Vehiculo::getId_vehiculo() const{
             return this->id_vehiculo;
         }
         string Vehiculo::getMarca() const{
             return this->marca;
         }
         string Vehiculo::getModelo() const{
             return this->modelo;
         }
         string Vehiculo::getTipoCombustible() const{
             return this->tipoCombustible;
         }
         int Vehiculo:: getCilindrada() const{
             return this->cilindrada;
         }
         double Vehiculo::getCapacidadDepositoMax() const{
             return this->capacidadDepositoMax;
         }
         int Vehiculo::getCaballos() const{
             return this->caballos;
         }
         int Vehiculo::getAerodinamica() const{
             return this->aerodinamica;
         }
         int Vehiculo::getAceleracion() const{
             return this->aceleracion;
         }
         int Vehiculo::getManejo() const{
             return this->manejo;
         }
         int Vehiculo::getVelocidadMax() const{
             return this->velocidadMax;
         }
         int Vehiculo::getFrenada() const{
             return this->frenada;
         }
         double Vehiculo::getCombustibleActual() const{
             return this->combustibleActual;
         }
         Pieza *Vehiculo::getPieza_Tuneada(const int& i) const{
             if(this->debug==true){
                 cout << "Extraigo la pieza de la posición" << i << endl;
             }
            return this->Tuning[i];
             
         }
         int Vehiculo::getTotalPiezas() const{
             return this->totalPiezas;
         }
         int Vehiculo::getPrecioActual() const{
             return this->precioActual;
         }
         int Vehiculo::getPrecioBase() const{
             return this->precioBase;
         }

// --------------------------------MÉTODOS ADICIONALES----------------------------------------------------------------------------------------
    
        void Vehiculo::Resize_Piezas(const int& NUEVA_DIM){
            if(this->debug==true){
                cout << "Entro al resize_piezas de vehículo" << endl;
                cout << "Cantidad de piezas tuneadas agregadas actuales---> " << this->getTotalPiezas() << endl;
            }

            
            Pieza **aux= new Pieza*[NUEVA_DIM];

            // Comparamos qué hacer si la dimensión es mayor que la que tenemos:
            if(NUEVA_DIM > this->getTotalPiezas()){
                if(this->debug==true){
                    cout << "Entro en NUEVA_DIM > DIM_ACTUAL" << endl;
                    cout << endl;
                }

                this->setTotalPiezas(NUEVA_DIM);

                for(int i=0; i<this->getTotalPiezas(); i++){
                    aux[i]=this->Tuning[i];
                }

                // Limpiamos el vector que tenemos antes de eliminarlo del heap.
                for(int i=0; i<this->getTotalPiezas(); i++){
                    this->Tuning[i]=NULL;
                }

            }

            // Si la dimensión es menor:
            if(NUEVA_DIM < this->getTotalPiezas()){
               if(this->debug==true)
                    cout << MAGENTA << "Entro a NUEVA_DIM < DIM_ACTUAL" << RESET << endl;

                this->setTotalPiezas(NUEVA_DIM);
                for(int i=0; i<this->getTotalPiezas(); i++){
                    aux[i]=this->Tuning[i];
                }

                // Limpiamos el vector antes de borrarlo:
                for(int i=0; i<this->getTotalPiezas(); i++){
                    this->Tuning[i]=NULL;
                }
            }

            delete [] this->Tuning;
            this->Tuning=aux;
            
            if(this->debug==true)
                cout << "Piezas tuneadas añadidas totales---> " << this->getTotalPiezas() << endl;
        }


        
        istream& operator>>(istream& flujo, Vehiculo& v1){
            if(v1.debug==true)
                cout << MAGENTA << "Entro a la sobrecarga del >> de Vehículo" << RESET << endl;
            
            int id;
            double x;
            string nombre;
            
            cout << "Id dle vehículo" << endl;
            flujo >> id;

            

            v1.setId_vehiculo(id);

            cout << "Nombre la marca del vehículo" << endl;
            flujo >> nombre;
            v1.setMarca(nombre);
            

            cout << "Introduce el modelo" << endl;
            flujo>>nombre;
            v1.setModelo(nombre);
            

            cout << "Introduce el tipo de combustible" << endl;
            flujo >> nombre;
            v1.setTipoCombustible(nombre);

            cout << "Introduce la capacidad máxima del combustible: " << endl;
            flujo >> x;
            v1.setCapacidadDepositoMax(x);
            

            cout << "Introduce la cilindrada" << endl;
            flujo >> id;
            v1.setCilindrada(id);

            cout << "Introduce los caballos" << endl;
            flujo >> id;
            v1.setCaballos(id);

            cout << "Introduce la aerodinámica" << endl;
            flujo >> id;
            v1.setAerodinamica(id);

            cout << "Introduce la aceleración " << endl;
            flujo >> id;
            v1.setAceleracion(id);

            cout << "Introduce el manejo" << endl;
            flujo >> id;
            v1.setManejo(id);

            cout << "Introduce la velocidad máxima" << endl;
            flujo >> id;
            v1.setVelocidadMax(id);

            cout << "Introduce la frenada" << endl;
            flujo >> id;
            v1.setFrenada(id);

            cout << "Introduce la cantidad de combustible actual" << endl;
            flujo >> x;
            v1.setCombustibleActual(x);

            

            cout << "Introduce el precio actual del vehículo" << endl;
            flujo >> x;
            v1.setPrecioActual(x);

            cout << "Introduce el precio base del vehículo" << endl;
            flujo >> x;
            v1.setPrecioBase(x);

            return flujo;
            
        }


        ostream& operator << (ostream& flujo, const Vehiculo& v1){
            if(v1.debug==true){
                cout << MAGENTA << "Entro a la sobrecarga del cout" << RESET <<  endl;
            }
        
        flujo << CYAN << "ID VEHÍCULO --> " << RESET << v1.getId_vehiculo() << endl;
        flujo << CYAN << "Marca --> " << RESET << v1.getMarca() << endl;
        flujo << CYAN << "Modelo --> " << RESET << v1.getModelo() << endl;
        flujo << CYAN << "Tipo de Combustible--> " << RESET << v1.getTipoCombustible() << endl;
        flujo << CYAN << "Cilindrada --> " << RESET << v1.getCilindrada() << endl;
        flujo << CYAN << "Capacidad máxima de depósito --> " << RESET << v1.getCapacidadDepositoMax() << endl;
        flujo << CYAN << "Caballos -->" << RESET << v1.getCaballos() << endl;
        flujo << CYAN << "Aerodinámica --> " << RESET << v1.getAerodinamica() << endl;
        flujo << CYAN << "Aceleración --> " << RESET << v1.getAceleracion() <<    endl;
        flujo << CYAN << "Manejo --> " << RESET << v1.getManejo() << endl;
        flujo << CYAN << "Velocidad Mácima --> " << RESET << v1.getVelocidadMax() << endl;
        flujo << CYAN << "Manejo --> " << RESET << v1.getFrenada() << endl;
        flujo << CYAN << "Combustible Actual --> " << RESET << v1.getCombustibleActual() << endl;
        flujo << CYAN << "Total de piezas añadidas --> " << RESET << v1.getTotalPiezas() << endl;
        flujo << CYAN << "Precio Actual --> " << RESET << v1.getPrecioActual() << endl;
        flujo << CYAN << "Precio Base --> " << RESET << v1.getPrecioBase() << endl;

            for(int i=0; i<v1.getTotalPiezas(); i++){
               flujo << *v1.getPieza_Tuneada(i);
            }
            return flujo;
        }


        Vehiculo &Vehiculo::operator=(Vehiculo& v1){
            if(this->debug==true){
                cout << MAGENTA << "Entro a la sobrecarga de = de vehículo." << RESET << endl;

            }
            
            if(this!=&v1){    
              
                delete [] this->Tuning;

                this->setId_vehiculo(v1.getId_vehiculo());
                this->setMarca(v1.getMarca());
                this->setModelo(v1.getModelo());
                this->setTipoCombustible(v1.getTipoCombustible());
                this->setCilindrada(v1.getCilindrada());
                this->setCapacidadDepositoMax(v1.getCapacidadDepositoMax());
                this->setCaballos(v1.getCaballos());
                this->setAerodinamica(v1.getAerodinamica());
                this->setAceleracion(v1.getAceleracion());
                this->setManejo(v1.getManejo());
                this->setVelocidadMax(v1.getVelocidadMax());
                this->setFrenada(v1.getFrenada());
                this->setCombustibleActual(v1.getCombustibleActual());
                this->setTotalPiezas(v1.getTotalPiezas());
                this->setPrecioActual(v1.getPrecioActual());
                this->setPrecioBase(v1.getPrecioBase());


                this->Tuning= new Pieza*[v1.getTotalPiezas()];

                if(this->Tuning==0){
                    cerr << RED << "ERROR, no queda espacio en la memoria" << endl;
                    exit(-1);
                }
                

                for(int i=0; i<v1.getTotalPiezas(); i++){
                    this->Tuning[i]=v1.Tuning[i];
                }

                

               

            }  
            return *this;
}