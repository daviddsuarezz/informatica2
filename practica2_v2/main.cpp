#include <iostream>
#include "ejercicios.h"
#include <string>
using namespace std;
int main()
{
    int opcion; // Variable para guardar la opción del usuario
    cout << "Ingrese el número de la función que quiere ejecutar:\n";
    cin >> opcion; // Leer la opción del usuario
    switch (opcion) { // Hacer un switch según la opción
    case 2: // Si es 2
        probar_funcion_c(); // Llamar a la función probar_funcion_c
        break; // Salir del switch
    case 3: // Si es 3
        problema1(); // Llamar a la función problema1
        break; // Salir del switch
    case 4: // Si es 4
        problema2(); // Llamar a la función problema2
        break; // Salir del switch
    case 5: // Si es 5
        problema3(); // Llamar a la función problema3
        break; // Salir del switch
    case 6: // Si es 6
        problema4(); // Llamar a la función problema4
        break; // Salir del switch
    case 7: // Si es 7
        problema5(); // Llamar a la función problema5
        break; // Salir del switch
    case 8: // Si es 8
        problema6(); // Llamar a la función problema6
        break; // Salir del switch
    case 9: // Si es 9
        problema7(); // Llamar a la función problema7
        break; // Salir del switch
    case 10: // Si es 10
        problema8(); // Llamar a la función problema8
        break; // Salir del switch
    case 11: // Si es 11
        problema9(); // Llamar a la función problema9
        break; // Salir del switch
    }
}
