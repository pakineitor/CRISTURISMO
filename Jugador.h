#ifndef Jugador_H
#define Jugador_H
#include "Garage.h"
#include "Vehiculo.h"
#include <iostream>
#include <string.h>
using namespace std;
class Jugador{
    private:
        int id_player;
        double creditos;
        int numero_victorias;
        bool tipoCarnet[3];
        Garage garaje_player;
        void Menu_player();

    protected:
        string login;
        string password;
        

    public:
        bool debug=false;
        /**
         * @brief Construct a new Jugador object
         * 
         */
        Jugador();


        /**
         * @brief Construct a new Jugador object
         * 
         * @param J (E) es un objetode tipo Jugador que lo pasa por parámetro actual.
         */
        Jugador(Jugador &J);


        /**
         * @brief Destroy the Jugador object
         * 
         */
        ~Jugador();

        // -------------------------------------GET--------------------------------------------------------

        /**
         * @brief Set the Id player object
         * 
         * @param ID_PLAYER (E) pasa un valor entero que representa el Id del jugador.
         */
        void setId_player(const int& ID_PLAYER);

        /**
         * @brief Set the Login object
         * 
         * @param LOGIN (E) pasa una cadena de texto para representar al login del Jugador.
         */
        void setLogin(const string& LOGIN);

        /**
         * @brief Set the Password object
         * 
         * @param PASSWORD (E) pasa una cadena de texto que representa la contraseña del Jugador.
         */
        void setPassword(const string& PASSWORD);

        /**
         * @brief Set the Creditos object
         * 
         * @param CREDITOS (E) pasa un literal de tipo double que representa el dinero del juego que tiene cada jugador independientemente.
         */
        void setCreditos(const double& CREDITOS);

    

        /**
         * @brief Set the Garaje player object
         * 
         * @param g (E) pasa un objeto de tipo garaje para asignarlo a un jugador.
         */
        void Agregar_garaje(Garage& g);

        /**
         * @brief Set the Tipo Carnet object
         * 
         * @param tipo (E) es un bool que te dice si el carnet del jugador está en su posesión o no.
         */
        void setTipoCarnet(const bool& tipo);

        /**
         * @brief Set the Numero Victorias object
         * 
         * @param nuevo_num (E) dato de tipo int que representa el número total de victorias que el usuario lleve en todo momento.
         */
        void setNumeroVictorias(int nuevo_num);

    
        // ------------------------------------------------GET--------------------------------------------

        /**
         * @brief Get the Id player object
         * 
         * @return int 
         */
        int getId_player() const;

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

        /**
         * @brief Get the Creditos object
         * 
         * @return double 
         */
        double getCreditos() const;

        

        /**
         * @brief Get the Garaje player object
         * 
         * @return Garage 
         */
        Garage &getGaraje_player();

        /**
         * @brief Get the Tipo carnet object
         * 
         * 
         * @return true 
         * @return false 
         */
        bool getTipo_carnet(const int& i) const;

        /**
         * @brief Get the Numero victorias object
         * 
         * @return int 
         */
        int getNumero_victorias() const;

    
        // ---------------------------------------------------Métodos adicionales-----------------------------------------------
        /**
         * @brief 
         * 
         * @param flujo 
         * @param j 
         * @return istream& 
         */
        friend istream& operator >> (istream& flujo, Jugador& j);

        /**
         * @brief 
         * 
         * @param flujo 
         * @param j 
         * @return ostream& 
         */
        friend ostream& operator << (ostream& flujo,Jugador& j);

        /**
         * @brief Método que va a hacer la sobrecarga del = de jugador.
         * 
         * @param j (E) objeto de tipo Jugador que va a ser copiado.
         * @return Jugador& 
         */
        Jugador& operator=(Jugador& j);


       

};
#endif

