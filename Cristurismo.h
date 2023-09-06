#ifndef Cristurismo_H
#define Cristurismo_H
#include "Pieza.h"
#include "Vehiculo.h"
#include "Garage.h"
#include "Jugador.h"
#include <iostream>
#include <string.h>
using namespace std;

class Cristurismo{
    private:
        Jugador* players;
        int total_player;

        Jugador* jugadorActivo;

        Vehiculo* catalogo_vehiculos;
        int total_vehiculo;

        Pieza* catalogo_pieza;
        int total_piezas;

        double PrecioGasolina;
        double PrecioDiesel;
        Vehiculo* resultadoBusqueda;
        int totalBusqueda;

        string LoginAdmin;
        string passwordAdmin;
        /**
         * @brief Método que va a redimensionar el vector de jugadores.
         * 
         * @param DIM_NUEVA (E) parámetro de tipo int constante qye va a pasar la dimensión del nuevo vector para su redimensionamiento.
         */
        void Resize_lista_players(const int& DIM_NUEVA);

        /**
         * @brief Método que va a redimensionar el catálogo de vehículos.
         * 
         * @param DIM_NUEVA (E) parámetro de tipo int constante qye va a pasar la dimensión del nuevo vector para su redimensionamiento.
         */
        void Resize_catalogo_vehiculos(const int& DIM_NUEVA);

        /**
         * @brief Método que va a redimensionar el catálogo de piezas.
         * 
         * @param DIM_NUEVA (E) parámetro de tipo int constante qye va a pasar la dimensión del nuevo vector para su redimensionamiento.
         */
        void Resize_catalogo_piezas(const int& DIM_NUEVA);
   
    public:
        bool debug=false;

        /**
         * @brief Construct a new Cristurismo object
         * 
         */
        Cristurismo();

        /**
         * @brief Construct a new Cristurismo object
         * 
         * @param C (E) parámetro de entrada de tipo Cristurismo que se pasa constante ya qe se va a leer solamente para hacer su copia correspondiente.
         */
        Cristurismo(const Cristurismo& C);

        /**
         * @brief Destroy the Cristurismo object
         * 
         */
        ~Cristurismo();
        // --------------------------------------------Métodos para jugador----------------------------

        /**
         * @brief Método encargado de agregar al vector un jugador.
         * 
         * @param j (E) parámetro de tipo jugador que se pasa para ser guardado.
         */
        void Agregar_jugador(Jugador& j);
        

        /**
         * @brief Método encargado de modificar un jugador.
         * 
         * @param x (E) posición que se pasa para saber el jugador a modificar.
         */
        void Modificar_Jugador(const int& x);




        /**
         * @brief Método que se encarga de eliminar al jugador que el usuario indique.
         * 
         * @param i (E) parámetro que va a indicar la posición para proceder a la ejecución del método.
         */
        void Eliminar_jugador(const int& i);

        /**
         * @brief Set the Total Players object
         * 
         * @param TOTAL_PLAYER (E) parámetro que indica la dimensión del vector de jugadores del sistema.
         */
        void setTotalPlayers(const int& TOTAL_PLAYER);

       

// -------------------------------------------MÉTODOS PARA LOS VEHÍCULOS------------------------------------------
        /**
         * @brief Método que se encarga de establecer un vehículo nuevo al catálogo de vehículos del sistema.
         * 
         * @param v (E) parámetro que pasa un objeto de tipo vehículo para poder ser guardado en su posición correspondiente del catálogo.
         */
        void AgregarVehiculo(Vehiculo& v);


        void Modificar_Vehiculo(const int& x);

        /**
         * @brief Método que se encarga de eliminar un vehículo del catálogo de vehículos.
         * 
         * @param i (E) posición del vehículo a eliminar.
         */
        void EliminarVehiculo(const int& i);


        /**
         * @brief Set the Total Vehiculos object
         * 
         * @param TOTAL_VEHICULOS (E) parámetro que pasa la dimensión del vector de vehículos del sistema (catálogo de vehículos).
         */
        void setTotal_Vehiculos(const int& TOTAL_VEHICULOS);


// ---------------------------------------------------------Métodos para las piezas--------------------------------------
        /**
         * @brief Método que se encarga de agregar una pieza al catálogo del sistema.
         * 
         * @param p (E) objeto de tipo Pieza que se pasa para ser guardado en el vector de Piezas del sistema.
         */
        void Agregar_Piezas_Catalogo(Pieza& p);
        

        

        /**
         * @brief Método que se encarga de eliminar una pieza del catálogo.
         * 
         * @param i (E) parámetro que indica la posición de dicha pieza guardada en el vector.
         */
        void Eliminar_Piezas_catalogo(const int& i);

        /**
         * @brief Set the Total piezas object
         * 
         * @param total_piezas (e) Parámetro que marca la dimensión del vector:
         */
        void setTotal_piezas(const int& total_piezas);


// ------------------------------------------------SET--------------------------------------------

        /**
         * @brief Set the Precio Gasolina object
         * 
         * @param PRECIO (E) parámetro que pasa el precio de la gasolina.
         */
        void setPrecioGasolina(const double& PRECIO);

        /**
         * @brief Set the Precio Diesel object
         * 
         * @param PRECIO (E) Parámetro que pasa el precio del diésel.
         */
        void setPrecioDiesel(const double& PRECIO);

        // /**
        //  * @brief Set the Resultado Busqueda object
        //  * 
        //  * @param v (E) 
        //  */
        // void setResultadoBusqueda(Vehiculo* v);

        /**
         * @brief Set the Total busqueda object
         * 
         * @param TOTAL_BUSQUEDAD (E) parámetro que pasa la dimensión del vector de búsquedas que es como un histórico de los coches que se buscan.
         */
        void setTotal_busqueda(const int& TOTAL_BUSQUEDAD);

        /**
         * @brief Set the Login player object
         * 
         * @param LOGIN (E) parámetro de tipo string que pasará el login del jugador.
         */
        void setLogin_player(const string& LOGIN);

        /**
         * @brief Set the Password object
         * 
         * @param PASSWORD (E) parámetro que se encarga de pasar la contraseña del jugador.
         */
        void setPassword(const string& PASSWORD);


// ----------------------------------------------GET----------------------------------------------

        /**
         * @brief Get the Jugador object
         * 
         * @param i (E) parámetro que pasa la posición de la cual se va a extraer la burbuja para mostrarla.
         * @return Jugador 
         */
        Jugador &getJugador(const int& i);

        /**
         * @brief Get the Total Players object
         * 
         * @return int 
         */
        int getTotal_Players() const;
        
        /**
         * @brief Get the Vehiculo Catalogo object
         * 
         * @param i @param i (E) parámetro que pasa la posición de la cual se va a extraer la burbuja para mostrarla.
         * @return Vehiculo 
         */
        Vehiculo &getVehiculoCatalogo(const int& i);

        /**
         * @brief Get the Total Vehiculo object
         * 
         * @return int 
         */
        int getTotal_Vehiculo() const;

        /**
         * @brief Get the Pieza catalogo object
         * 
         * @param i @param i (E) parámetro que pasa la posición de la cual se va a extraer la burbuja para mostrarla.
         * @return Pieza 
         */
        Pieza &getPieza_catalogo(const int& i);

        /**
         * @brief Get the Total piezas object
         * 
         * @return int 
         */
        int getTotal_piezas() const;

        /**
         * @brief Get the Precio Gasolina object
         * 
         * @return double 
         */
        double getPrecioGasolina() const;

        /**
         * @brief Get the Precio Diesel object
         * 
         * @return double 
         */
        double getPrecioDiesel() const;
        /**
         * @brief Get the Vehiculo Resultado object
         * 
         * @param i @param i (E) parámetro que pasa la posición de la cual se va a extraer la burbuja para mostrarla.
         * @return Vehiculo* 
         */
        Vehiculo* getVehiculoResultado(const int& i);

        /**
         * @brief Get the Total vehiculos resultado object
         * 
         * @return int 
         */
        int getTotal_vehiculos_resultado() const;


        /**
         * @brief Get the Login object
         * 
         * @return string 
         */
        string getLogin() const;

        /**
         * @brief Get the Password object
         * 
         * @return string 
         */
        string getPassword() const;

// -------------------------------------------------MÉTODOS ADICIONALES-----------------------------------------------------------------

        /**
         * @brief Método que sirve para realizar la sobrecarga ostream de Cristurismo.
         * 
         * @param flujo (E) objeto de entrada de tipo ostream que sirva para la salida del flujo de los datos.
         * @param c (E) obheto Cristurismo que va a ser leído para poder mostrar su información.
         * @return ostream& 
         */
        friend ostream& operator << (ostream& flujo,Cristurismo& c);

        /**
         * @brief Método que crea y guarda unos datos por defecto mientras el programa o su ambito esté activo.
         * 
         */
        void Cargar_datos();

        /**
         * @brief 
         * 
         */
        void Menu_admin();


        /**
         * @brief 
         * 
         * @param i 
         */
        void Menu_jugador(const int& i);

        /**
         * @brief 
         * 
         */
        void Mostrar_clasificacion_de_jugadores();

        /**
         * @brief 
         * 
         * @param n 
         * @return int 
         */
        int Filtro_numeros(int n);
        /**
         * @brief 
         * 
         * @param marca 
         */
       void Buscar_Vehiculo(string& marca);
       /**
        * @brief Método que consiste en borrar un vehículo tanto del sistema como del garaje.
        * 
        * @param I (E) parámetro constante que indica la posición del vector.
        */
       void eraseunVehiculo(); 

};
#endif