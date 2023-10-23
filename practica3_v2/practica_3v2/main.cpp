#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std ;

int main(){


    int n; // Variable para guardar la semilla de codificación
    int metodo; // Variable para guardar el método de codificación
    string fuente; // Variable para guardar el nombre del archivo fuente
    string salida; // Variable para guardar el nombre del archivo salida

    cout << "Ingrese la semilla de codificación (n): ";
            cin >> n; // Leer la semilla de codificación

    cout << "Ingrese el método de codificación (1 o 2): ";
    cin >> metodo; // Leer el método de codificación

    cout << "Ingrese el nombre del archivo fuente: ";
    cin >> fuente; // Leer el nombre del archivo fuente


    cout << "Ingrese el nombre del archivo salida: ";
    cin >> salida; // Leer el nombre del archivo salida

    if (metodo == 1) { // Si se eligió el primer método
        // modo_codificar_1(fuente, salida, n); // Codificar el archivo usando el primer método
        cout << "Archivo codificado con éxito.\n";
    }

}
