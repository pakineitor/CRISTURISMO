// #include "Cristurismo.h"
// #include "Admin.h"
// #include <iostream>
// #include <string.h>
// #define RESET   "\033[0m"
// #define BLACK   "\033[30m"      /* Black */
// #define RED     "\033[31m"      /* Red */
// #define GREEN   "\033[32m"      /* Green */
// #define YELLOW  "\033[33m"      /* Yellow */
// #define BLUE    "\033[34m"      /* Blue */
// #define MAGENTA "\033[35m"      /* Magenta */
// #define CYAN    "\033[36m"      /* Cyan */
// #define WHITE   "\033[37m"      /* White */
// #define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
// #define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
// #define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
// #define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
// #define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
// #define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
// #define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
// #define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
// using namespace std;

// Admin::Admin(){
//     if(this->debug==true)
//         cout << "Entro en el constructor por defecto de Admin" << endl;

// }

// Admin::~Admin(){
//     if(this->debug==true)
//         cout << "Entro al destructor de Admin" << endl;
// }

// void Admin::Menu_admin(){
//     int opcion=0;
//     bool dentro=true;
//     cout << MAGENTA << "Bienvenido sr/sra " << this->getLogin() << endl;
//     cout << "¿QUÉ DESEA HACER AHORA? " << RESET << endl;
//     cout << endl;
    
//     cout << GREEN << "Pulsa 0 para salir" << endl;
//     cout << "Pulsa 1 para agregar una pieza al catálogo." << endl;
//     cout << "Pulsa 2 para agregar un vehículo al catálogo." << endl;
//     cout << "Pulsa 3 para validar/agregar un jugador al catálogo." << RESET <<  endl;

//     cout << BLUE << "Pulsa 4 para modificar una pieza." << endl;
//     cout << "Pulsa 5 para modificar un vehículo del catálogo. " << endl;
//     cout << "Pulsa 6 para modificar un jugador" << RESET << endl;

//     cout << YELLOW << "Pulsa 7 para eliminar una pieza del catálogo " << endl;
//     cout << "Pulsa 8 para eliminar un vehículo dle catálogo" << endl;
//     cout << "Pulsa 9 para eliminar un Jugador del sistema" << RESET << endl;
//     cout << endl;

//     cin >> opcion;
    
//     do{
//         switch (opcion){
//             case 0:
//                 dentro=false;
//             break;

//             case 1: 
//                 // Agregar 
//             break;

//             case 2:

//             break;

//             case 3:

//             break;

//             case 4:
//                 string modificar;
//                 int id;
//                 cout << "Introduce el nombre de la pieza que quiere modificar e id o la posición" << endl;
//                 // Que recorrerá el vector para ir busvando la pieza por id y nombre.
//                 cout << "¿Qué desea modificar?" << endl;
//                 cout << CYAN << "Pulse 1 para modificar el id" << endl;
//                 cout << "Pulse 2 para modificar el nombre" << endl;
//                 cout << "Pulse 3 para modificar sus características" << endl;
//                 cout << "Pulse 4 para modificar toda la pieza directamente" << endl;

//             break;
                
//         }


//     }while(dentro==true);


// }

