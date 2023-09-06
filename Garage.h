#ifndef Garage_H
#define Garage_H
#include "Vehiculo.h"
#include <iostream>
#include <string.h>
using namespace std;
class Garage{
    private:
        int id;
        int cantidad_vehiculos;
        Vehiculo* vehiculo_garage;

        /**
         * @brief Método que se encarga de redimensionar el vector de vehículos del garaje
         * 
         * @param NUEVA_DIM (E) pasa una nueva dimensión constante para actualizar la dimensión del vector.
         */
        void Resize_garage(const int& NUEVA_DIM);

    public:
        bool debug=true;
        /**
         * @brief Construct a new Garage object
         * 
         */
        Garage();

        /**
         * @brief Construct a new Garage object
         * 
         * @param g (E) Objeto de tipo Garaje que se pasa constante para ser leído y copiado.
         */
        Garage(const Garage& g);

        /**
         * @brief Destroy the Garage object
         * 
         */
        ~Garage();

        /**
         * @brief Set the Id garage object
         * 
         * @param ID_GARAGE (E) parámetro de tipo int que va a pasarle un valor literal de tipo int para guardarlo en el atributo correspondiente.
         */
        void setId_garage(const int& ID_GARAGE);


        /**
         * @brief Set the Cantidad Vehiculos object
         * 
         * @param CANTIDAD_VEHICULOS (E) parámetro que pasará el valor al atributo correspondiente.
         */
        void setCantidad_Vehiculos(const int& CANTIDAD_VEHICULOS);

        /**
         * @brief Get the Id garage object
         * 
         * @return int 
         */
        int getId_garage() const;


        /**
         * @brief Get the Cantidad Vehiculos object
         * 
         * @return int 
         */
        int getCantidad_Vehiculos() const;


        /**
         * @brief Get the Vehiculo object
         * 
         * @param i (E) parametro que marca la posición del vector para extraer el vehículo o vehículos que nos interesen.
         * @return Vehiculo 
         */
        Vehiculo &getVehiculo(const int& i) const;


        

        /**
         * @brief Método que se encarga de añadir un vehículo al vector de vehículos del garaje.
         * 
         * @param v1 (E) es un objeto de tipo Vehículo que se encarga de pasar el objeto.
         */
        void Agregar_vehiculo(Vehiculo& v1);

        /**
         * @brief Método encargado de eliminar del vector de vehículos del garaje un vehículo.
         * 
         * @param i (E) pasa la posición del vector del vehículo que se va a quere borrar.
         */
        void Eliminar_vehiculo(const int& i);

        /**
         * @brief Método encargado de sobrecargar el << para poder mostrar el objeto.
         * 
         * @param flujo (E) parámetro de tipo ostream que se utiliza para hacer el cout.
         * @param g (E) parámetrp de tipo garaje que es constante para leer solamente sus valores.
         * @return ostream& 
         */
        friend ostream& operator << (ostream& flujo, const Garage& g);

        /**
         * @brief Método encargado de establecer la sobrecarga del cin para poder escribir el objeto.
         * 
         * @param flujo (E) operador de tipo istream que se encarga de sobrecargar sidcho cargador.
         * @param g (E) parámetro de tipo Garage que se modificará por los datos introducidos.
         * @return istream& 
         */
        friend istream& operator >>(istream& flujo, Garage& g);

        /**
         * @brief Método que se encarga de sobrecargar la asignación de Garaje.
         * 
         * @param g (E) objeto de tipo garaje.
         * @return Garage& 
         */
        Garage& operator=(const Garage& g);
    
    


    
};
#endif


