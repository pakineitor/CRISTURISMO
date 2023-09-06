#ifndef Vehiculo_H
#define Vehiculo_H
#include "Pieza.h"
#include <iostream>
#include <string.h>
using namespace std;

class Vehiculo{
    protected:
        int id_vehiculo;
        string marca;
        string modelo;
        string tipoCombustible;
        int cilindrada;
        double capacidadDepositoMax;
        int caballos;
        int aerodinamica;
        int aceleracion;
        int manejo;
        int velocidadMax;
        int frenada;
        double combustibleActual;
        Pieza **Tuning;
        int totalPiezas;
        int precioActual;
        int precioBase;
        void Resize_Piezas(const int& NUEVA_DIMENSION);
        
    public:
        bool debug=true;

        /**
         * @brief Construct a new Vehiculo object
         * 
         */
        Vehiculo();

        /**
         * @brief Construct a new Vehiculo object
         * 
         * @param v1 (E) es un parámetro constante cuya variable es un objeto que va a ser copiado para crear uno nuevo.
         */
        Vehiculo(const Vehiculo& v1);

        /**
         * @brief Destroy the Vehiculo object
         * 
         */
        ~Vehiculo();

        /**
         * @brief Set the Id vehiculo object
         * 
         * @param ID_VEHICULO (E) establecerá el id del vehículo.
         */
        void setId_vehiculo(const int& ID_VEHICULO);


        /**
         * @brief Set the Marca object
         * 
         * @param MARCA (E) parámetro de entrada que establecerá en el atributo correspondiente los valores literales que pasen.
         */
        void setMarca(const string& MARCA);


        /**
         * @brief Set the Modelo object
         * 
         * @param MODELO (E) parámetro de entrada que establecerá en el atributo correspondiente los valores literales que pasen.
         */
        void setModelo(const string& MODELO);


        /**
         * @brief Set the Tipo Combustible object
         * 
         * @param combustible (E) parámetro de entrada que establecerá en el atributo correspondiente los valores literales que pasen.
         */
        void setTipoCombustible(const string& combustible);


        /**
         * @brief Set the Cilindrada object
         * 
         * @param CILINDRADA 
         */
        void setCilindrada(const int& CILINDRADA);


        /**
         * @brief Set the Capacidad Deposito Max object
         * 
         * @param CAPACIDAD_MAXIMA_DEL_DEPOSITO (E) establece la capacidad total que el depósito del vehículo tendrá.
         */
        void setCapacidadDepositoMax(const double& CAPACIDAD_MAXIMA_DEL_DEPOSITO);


        /**
         * @brief Set the Caballos object
         * 
         * @param CABALLOS (E) establecerá el caballos del coche.
         */
        void setCaballos(const int& CABALLOS);


        /**
         * @brief Set the Aerodinamica object
         * 
         * @param AERODINAMICA (E) establecerá el valor que tenga o aporte al coche.
         */
        void setAerodinamica(const int& AERODINAMICA);


        /**
         * @brief Set the Aceleracion object
         * 
         * @param ACELERACION (E) establece el valor del rasgo que aporte este parámetro.
         */
        void setAceleracion(const int& ACELERACION);


        /**
         * @brief Set the Manejo object
         * 
         * @param MANEJO (E) establece el valor del rasgo que aporte este parámetro.
         */
        void setManejo(const int& MANEJO);


        /**
         * @brief Set the Velocidad Max object
         * 
         * @param VELOCIDADMAX (E) establece el valor del rasgo que aporte este parámetro.
         */
        void setVelocidadMax(const int& VELOCIDADMAX);


        /**
         * @brief Set the Frenada object
         * 
         * @param FRENADA (E) establece el valor del rasgo que aporte este parámetro.
         */
        void setFrenada(const int& FRENADA);


        /**
         * @brief Set the Combustible Actual object
         * 
         * @param COMBUSTIBLEACTUAL (E) establece el valor del rasgo que aporte este parámetro.
         */
        void setCombustibleActual(const double& COMBUSTIBLEACTUAL);


        /**
         * @brief Set the Pieza Tuneada object
         * 
         * @param tuning (E) establecerá la pieza que contenga el coche, pasandola como puntero que estará apuntando a esa pieza.
         */
        void Agregar_Pieza_Tuneada(Pieza* Nuevo_tuning);

        /**
         * @brief Método que va a eliminar una pieza tuneada del coche.
         * 
         * @param i (E) parámetro que va a indicar la posición de la pieza que va a ser borrada.
         */
        void Eliminar_pieza_Tuneada(const int& i);

        /**
         * @brief Set the Total Piezas object
         * 
         * @param TOTAL_PIEZAS (E) define la cantidad total de piezas que hay en el coche.
         */
        void setTotalPiezas(const int& TOTAL_PIEZAS);


        /**
         * @brief Set the Precio Actual object
         * 
         * @param PRECIO_ACTUAL (E) el precio que tendrá el coche actualmente, es decir, con todas las modificaciones que se hagan y dicho precio estrá en €.
         */
        void setPrecioActual(const double& PRECIO_ACTUAL);


        /**
         * @brief Set the Precio Base object
         * 
         * @param PRECIO_BASE (E) precio que se establecerá con el coche original, es decir, sin modificaciones ni nada por el estilo.
         */
        void setPrecioBase(const double& PRECIO_BASE);
        
      




// ------------------------------------------------------------------------------------------------------------------------------------
        /**
         * @brief Get the Id vehiculo object
         * 
         * @return int 
         */
         int getId_vehiculo() const;

         /**
          * @brief Get the Marca object
          * 
          * @return string 
          */
         string getMarca() const;


         /**
          * @brief Get the Modelo object
          * 
          * @return string 
          */
         string getModelo() const;


         /**
          * @brief Get the Tipo Combustible object
          * 
          * @return string 
          */
         string getTipoCombustible() const;


         /**
          * @brief Get the Cilindrada object
          * 
          * @return int 
          */
         int getCilindrada() const;


         /**
          * @brief Get the Capacidad Deposito Max object
          * 
          * @return double 
          */
         double getCapacidadDepositoMax() const;


         /**
          * @brief Get the Caballos object
          * 
          * @return int 
          */
         int getCaballos() const;


         /**
          * @brief Get the Aerodinamica object
          * 
          * @return int 
          */
         int getAerodinamica() const;


         /**
          * @brief Get the Aceleracion object
          * 
          * @return int 
          */
         int getAceleracion() const;


         /**
          * @brief Get the Manejo object
          * 
          * @return int 
          */
         int getManejo() const;



         /**
          * @brief Get the Velocidad Max object
          * 
          * @return int 
          */
         int getVelocidadMax() const;


         /**
          * @brief Get the Frenada object
          * 
          * @return int 
          */
         int getFrenada() const;


         /**
          * @brief Get the Combustible Actual object
          * 
          * @return double 
          */
         double getCombustibleActual() const;


         /**
          * @brief Get the Pieza Tuneada object
          * 
          * @param i (E) parámetro que pasa la psoición del vector en la cual e va extraer la pieza. 
          * @return Pieza* 
          */
         Pieza *getPieza_Tuneada(const int& i) const;


        /**
         * @brief Get the Total Piezas object
         * 
         * @return int 
         */
         int getTotalPiezas() const;


         /**
          * @brief Get the Precio Actual object
          * 
          * @return int 
          */
         int getPrecioActual() const;


         /**
          * @brief Get the Precio Base object
          * 
          * @return int 
          */
         int getPrecioBase() const;
         

// --------------------------------------MÉTODOS ADICIONALES----------------------------------------------------------
        

        /**
         * @brief Método de la clase ostream encargado de mostrar los datos de un objeto sobrecargandolos.
         * 
         * @param flujo (E) parámetro de entrada que se encarga de sobrecargar el cout para mostrar de los daos literales.
         * @param v1 (E) objeto que va a ser leído para mostrar esos valores en sus atributos correspondientes.
         * @return istream& 
         */
        friend ostream& operator << (ostream& flujo, const Vehiculo& V1); 


        /**
         * @brief 
         * 
         * @param flujo (E) parámetro de entrada que se encarga de sobrecargar el cin para la introducción de los daos literales.
         * @param V1 (E) objeto que va a guardar esos valores en sus atributos correspondientes.
         * @return istream& 
         */
        friend istream& operator >> (istream& flujo, Vehiculo& V1);
       
        /**
         * @brief Método que hará la sobrecarga de la asignación.
         * 
         * @param v1 (E) objeto de tipo Vehiculo que va a ser copiado o asignado.
         * @return Vehiculo& 
         */
        Vehiculo &operator=(Vehiculo& v1);
    //    Pendiente de pensar un método para que se modifiquen datos y precio si añade un conjunto de piezas o una sola tuneada ya que puede aumentar o disminuir algunos rasgos del vehiculo.
    

   
};
#endif

