#ifndef Pieza_H
#define Pieza_H
#include <iostream>
#include <string.h>
using namespace std;
class Pieza{

    private:
        int id;
        string nombre;
        int aerodinamica;
        int frenada;
        int velocidadMax;
        int manejo;
        int aceleracion;
        int precio;
    public:
        bool debug=false;
        Pieza();
        Pieza(const Pieza& Pieza);
        ~Pieza();


// SET Y GET:
/**
 * @brief Set the Id pieza object
 * 
 * @param PIEZA (E) es un parámetro de tipo Pieza que pasará el objeto para ser copiado.
 */
void setId_pieza(const int& PIEZA);

/**
 * @brief Set the Nombre pieza object
 * 
 * @param NOMBRE (E) Parámetro de entrada que va a pasar el nombre de la pieza.
 */
void setNombre_pieza(const string& NOMBRE);

/**
 * @brief Set the Aerodinamica object
 * 
 * @param AERODINAMICA (E) parámetro de entrada que va a pasar el tipo de aerodinamica.
 */
void setAerodinamica(const int& AERODINAMICA);

/**
 * @brief Set the Frenada object
 * 
 * @param FRENADA (E) parámetro de entrada que va a pasar la frenada para guardarlo en su atributo correspondiente.
 */
void setFrenada(const int &FRENADA);


/**
 * @brief Set the Velocidad Max object
 * 
 * @param ID_PIEZA (E) parámetro que va a pasar el id de la pieza.
 */
void setVelocidadMax(const int& ID_PIEZA);

/**
 * @brief Set the Manejo object
 * 
 * @param VELOCIDADMAX Parámetro que va a pasar la velocidad máxima que puede alcanzar un vehículo.
 */
void setManejo(const int& VELOCIDADMAX);


/**
 * @brief Set the Aceleracion object
 * 
 * @param ACELERACION (E) parámetro de entrada que va a pasar la aceleración  del vehículo.
 */
void setAceleracion(const int& ACELERACION);


/**
 * @brief Set the Precio object
 * 
 * @param PRECIO (E) Parámetro que va a pasar el precio en € del vehículo.
 */
void setPrecio(const double& PRECIO);

/**
 * @brief Get the Id pieza object
 * 
 * @return int 
 */
int getId_pieza() const;

/**
 * @brief Get the Nombre pieza object
 * 
 * @return string 
 */
string getNombre_pieza() const;

/**
 * @brief Get the Aerodinamica object
 * 
 * @return int 
 */
int getAerodinamica() const;

/**
 * @brief Get the Frenada object
 * 
 * @return int 
 */
int getFrenada() const;

/**
 * @brief Get the Velocidad Max object
 * 
 * @return int 
 */
int getVelocidadMax() const;

/**
 * @brief Get the Manejo object
 * 
 * @return int 
 */
int getManejo() const;

/**
 * @brief Get the Acelracion object
 * 
 * @return int 
 */
int getAcelracion() const;

/**
 * @brief Get the Precio object
 * 
 * @return int 
 */
int getPrecio() const;










// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------




// Métodos adicionales:
/**
 * @brief Construct a new ostream object
 * 
 * @param salida (E) parámetro que van a pasar un valor para ser guardado en su atributo correspondiente.
 * @param pieza (E) parámetro que van a pasar un valor para ser guardado en su atributo correspondiente.
 */
friend ostream& operator << (ostream& salida, const Pieza& pieza);

/**
 * @brief Construct a new istream object
 * 
 * @param entrada (E) parámetro de tipo istream que sirve para introducir datos 
 * @param pieza (E) parámetro que se encarga de pasar para escribir un objeto de tipo Pieza.
 */
friend istream& operator >> (istream& entrada, Pieza& pieza);

/**
 * @brief Método que se va a encargar de hacer la sobrecarga de =.
 * 
 * @param p (E) parámetro que se va a encargar de pasar el objeto Pieza para poder copiarlo o ser asignado a uno nuevo.
 * @return Pieza& 
 */
Pieza& operator=(Pieza& p);
};
#endif


