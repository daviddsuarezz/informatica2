#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

class Enrutador {

private:
    char nombre;
    map<char, int> tabla; // para guardar todos las conexiciones
public:

    Enrutador(); // constructor por defecto
    Enrutador(char n){ // constructor para ingresar el nombre
        nombre = n;
    }
    char getNombre(){
        return nombre;
    }
    map<char,int> getTabla(){
        return tabla;
    }
    void setNombre(char nombre){
        this nombre -> nombre;
    }
    void setTabla(map<char,int>t){
        tabla = t;
    }
    void agregar_enlace(char destino, int costo){
        tabla[destino] = costo;
    }
    void eleminar_enlace(char destino){
        tabla.erase(destino); // eliminar la clave destino en la tabla
    }
    void modificar_enlace(char destino, int costo){
        tabla[destino] = costo;
    }
    void mostrar_tabla(){
       cout << "Tabla de enrutamiento del enrutador " << nombre << ":\n";
       cout << "Destino\tCosto\n";
       for (auto par : tabla) { // Recorrer el mapa usando un iterador
         cout << par.first << "\t" << par.second << "\n"; // el .first me imprime la clave, y .second me imprime el valor asociado a esta
       }
     cout << "\n";
    }
        };
    }

}

    class Red{

private:
    vector<Enrutador> enrutadores;

public:
    Red(){
     enrutadores.clear();
    }

    vector<Enrutador> get_enrutadores(){
     return enrutadores;
    }

    void set_enrutadores(Enrutador nuevo){
        enrutadores.push_back(nuevo);
    }
    void eliminar_enrutador(char n) { // Eliminar un enrutador del vector por su nombre
        for (int i = 0; i < enrutadores.size(); i++) { // Recorrer el vector
         if (enrutadores[i].getNombre() == n) { // Si se encuentra el enrutador buscado
             enrutadores.erase(enrutadores.begin() + i); // Se elimina del vector
             break; // Se termina el ciclo
         }
        }
    }
    *Enrutador buscar_enrutador(char nombre_enrutador){
        for(int i = 0; i < enrutadores.size(); i++){
         if(enrutadores[i].getNombre() == nombre_enrutador){
             return &enrutadores[i];
         }
        }
        return nullptr;
    }
    void mostrar_red();{
        cout << "Red de enrutadores:\n";
        for(auto it = enrutadores.begin(); auto it != enrutadores.end(); ++it){
         it->mostrar_tabla();
        }
    }





    }


int main()
{

    return 0;
}
