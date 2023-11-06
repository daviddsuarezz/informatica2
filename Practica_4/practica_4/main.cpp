#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <limits>
#include <sstream>


using namespace std;

class Enrutador { // Define una clase llamada Enrutador

private: // Especifica que las siguientes variables son privadas
    string id; // Declara una variable de cadena para el ID del enrutador
    map<string, int> tabla; // Declara un mapa para la tabla de enrutamiento

public: // Especifica que las siguientes funciones son públicas

    Enrutador(); // Declara un constructor por defecto
    Enrutador(string n){ // Declara un constructor que toma un string como argumento
        id = n; // Asigna el argumento a la variable id
    }
    string getNombre(){ // Declara una función para obtener el nombre del enrutador
        return id; // Devuelve el ID del enrutador
    }
    map<string,int> getTabla(){ // Declara una función para obtener la tabla de enrutamiento
        return tabla; // Devuelve la tabla de enrutamiento
    }
    void setNombre(string nombre){ // Declara una función para establecer el nombre del enrutador
        id = nombre ; // Asigna el argumento a la variable id
    }
    void setTabla(map<string,int>t){ // Declara una función para establecer la tabla de enrutamiento
        tabla = t; // Asigna el argumento a la variable tabla
    }
    void actualizarTablaEnrutamiento(string destino, int costo){ // Declara una función para actualizar la tabla de enrutamiento
        tabla[destino] = costo; // Actualiza el costo de la ruta al destino en la tabla de enrutamiento
    }
    void eleminar_enlace(string destino){ // Declara una función para eliminar un enlace
        tabla.erase(destino); // Elimina la clave destino en la tabla de enrutamiento
    }
    void modificar_enlace(string destino, int costo){ // Declara una función para modificar un enlace
        tabla[destino] = costo; // Modifica el costo de la ruta al destino en la tabla de enrutamiento
    }
    void mostrar_tabla(){ // Declara una función para mostrar la tabla de enrutamiento
        cout << "Tabla de enrutamiento del enrutador " << id << ":\n"; // Imprime el ID del enrutador
        cout << "Destino\tCosto\n"; // Imprime los encabezados de la tabla
        for (auto par : tabla) { // Recorre el mapa usando un iterador
            cout << par.first << "\t" << par.second << "\n"; // Imprime la clave y el valor asociado a esta
        }
        cout << "\n"; // Imprime una línea en blanco
    }
}; // Fin de la definición de la clase


class Red { // Define una clase llamada Red

private: // Especifica que las siguientes variables son privadas
    map<string, Enrutador*> enrutadores; // Declara un mapa para los enrutadores

public: // Especifica que las siguientes funciones son públicas

    Red() { // Declara un constructor por defecto
        enrutadores.clear(); // Limpia el mapa de enrutadores
    }

    map<string, Enrutador*> getEnrutadores() { // Declara una función para obtener los enrutadores
        return enrutadores; // Devuelve el mapa de enrutadores
    }

    void agregarEnrutador(string id) { // Declara una función para agregar un enrutador
        enrutadores[id] = new Enrutador(id); // Crea un nuevo enrutador y lo añade al mapa
    }

    void removerEnrutador(std::string id) { // Declara una función para remover un enrutador
        enrutadores.erase(id); // Elimina el enrutador del mapa
    }

    void actualizarTablaEnrutamiento(std::string id1, std::string id2, int costo) { // Declara una función para actualizar la tabla de enrutamiento
        enrutadores[id1]->actualizarTablaEnrutamiento(id2, costo); // Actualiza la tabla de enrutamiento del enrutador id1
        enrutadores[id2]->actualizarTablaEnrutamiento(id1, costo); // Actualiza la tabla de enrutamiento del enrutador id2
    }

    vector<string> caminoMasCorto(string origen, string destino) { // Declara una función para encontrar el camino más corto
        map<string, int> distancias; // Declara un mapa para las distancias
        map<string, string> predecesores; // Declara un mapa para los predecesores
        vector<string> nodosNoVisitados; // Declara un vector para los nodos no visitados

        // Inicializar las distancias y predecesores
        for (auto& enrutador : enrutadores) { // Recorre el mapa de enrutadores
            string id = enrutador.second->getNombre(); // Obtiene el nombre del enrutador
            distancias[id] = numeric_limits<int>::max(); // Inicializa la distancia a infinito
            predecesores[id] = ""; // Inicializa el predecesor a vacío
            nodosNoVisitados.push_back(id); // Añade el enrutador a los nodos no visitados
        }

        // La distancia del origen a sí mismo es 0
        distancias[origen] = 0;

        while (!nodosNoVisitados.empty()) { // Mientras haya nodos no visitados
            // Encontrar el nodo no visitado con la distancia más corta
            string nodoActual = "";
            int distanciaMinima = numeric_limits<int>::max();
            for (string nodo : nodosNoVisitados) { // Recorre los nodos no visitados
                if (distancias[nodo] < distanciaMinima) { // Si la distancia del nodo es menor que la distancia mínima
                    distanciaMinima = distancias[nodo]; // Actualiza la distancia mínima
                    nodoActual = nodo; // Actualiza el nodo actual
                }
            }

            // Eliminar el nodo actual de los nodos no visitados
            nodosNoVisitados.erase(remove(nodosNoVisitados.begin(), nodosNoVisitados.end(), nodoActual), nodosNoVisitados.end());

            // Actualizar las distancias de los vecinos del nodo actual
            map<string, int> vecinos = enrutadores[nodoActual]->getTabla(); // Obtiene los vecinos del nodo actual
            for (auto& vecino : vecinos) { // Recorre los vecinos
                int distanciaAlternativa = distancias[nodoActual] + vecino.second; // Calcula la distancia alternativa
                if (distanciaAlternativa < distancias[vecino.first]) { // Si la distancia alternativa es menor que la distancia actual
                    distancias[vecino.first] = distanciaAlternativa; // Actualiza la distancia
                    predecesores[vecino.first] = nodoActual; // Actualiza el predecesor
                }
            }
        }

        // Reconstruir el camino desde el destino al origen
        vector<string> camino; // Declara un vector para el camino
        for (string nodo = destino; nodo != ""; nodo = predecesores[nodo]) { // Recorre los predecesores desde el destino hasta el origen
            camino.insert(camino.begin(), nodo); // Inserta el nodo al principio del camino
        }

        return camino; // Devuelve el camino
    }

    void mostrarTablasEnrutamiento() { // Declara una función para mostrar las tablas de enrutamiento
        for (auto& par : enrutadores) { // Recorre el mapa de enrutadores
            par.second->mostrar_tabla(); // Muestra la tabla de enrutamiento del enrutador
        }
    }


    void cargarDesdeArchivo(string nombreArchivo) { // Declara una función para cargar una red desde un archivo
        ifstream archivo(nombreArchivo); // Abre el archivo
        string linea; // Declara una variable para almacenar cada línea del archivo
        vector<string> nombresEnrutadores; // Declara un vector para almacenar los nombres de los enrutadores

        if (archivo.is_open()) { // Si el archivo se abrió correctamente
            // Leer la primera línea para obtener los nombres de los enrutadores
            if (getline(archivo, linea)) { // Si se pudo leer una línea
                stringstream ss(linea); // Crea un flujo de strings a partir de la línea
                string nombre; // Declara una variable para almacenar cada nombre
                while (getline(ss, nombre, ';')) { // Mientras se pueda leer un nombre separado por ';'
                    nombresEnrutadores.push_back(nombre); // Añade el nombre al vector
                    agregarEnrutador(nombre); // Agrega un enrutador con ese nombre
                }
            }

            // Leer las líneas restantes para obtener los costos de los enlaces
            int i = 0; // Declara un contador para el enrutador actual
            while (getline(archivo, linea)) { // Mientras se pueda leer una línea
                stringstream ss(linea); // Crea un flujo de strings a partir de la línea
                string costostr; // Declara una variable para almacenar cada costo como string
                // Ignorar el nombre del enrutador al principio de la línea
                getline(ss, costostr, ';'); // Lee el nombre del enrutador y lo ignora
                int j = 0; // Declara un contador para el enrutador destino
                while (getline(ss, costostr, ';')) { // Mientras se pueda leer un costo separado por ';'
                    if (i != j) { // Si el enrutador destino no es el mismo que el actual
                        istringstream costoStream(costostr); // Crea un flujo de strings a partir del costo
                        int costo; // Declara una variable para almacenar el costo como entero
                        costoStream >> costo; // Convierte el costo a entero
                        actualizarTablaEnrutamiento(nombresEnrutadores[i], nombresEnrutadores[j], costo); // Actualiza la tabla de enrutamiento
                    }
                    j++; // Incrementa el contador del enrutador destino
                }
                i++; // Incrementa el contador del enrutador actual
            }

            archivo.close(); // Cierra el archivo
        } else {
            cout << "No se pudo abrir el archivo.\n"; // Imprime un mensaje de error si no se pudo abrir el archivo
        }
    }

    void guardarEnArchivo(string nombreArchivo) { // Declara una función para guardar una red en un archivo
        ofstream archivo(nombreArchivo); // Abre el archivo

        if (archivo.is_open()) { // Si el archivo se abrió correctamente
            // Escribir los nombres de los enrutadores en la primera línea
            for (auto& par : enrutadores) { // Recorre el mapa de enrutadores
                archivo  << par.second->getNombre() << ";"; // Escribe el nombre del enrutador seguido de ';'
            }
            archivo << "\n"; // Escribe un salto de línea

            // Escribir los costos de los enlaces en las líneas restantes
            for (auto it1 = enrutadores.begin(); it1 != enrutadores.end(); ++it1) { // Recorre el mapa de enrutadores
                archivo << it1->second->getNombre(); // Escribe el nombre del enrutador
                for (auto it2 = enrutadores.begin(); it2 != enrutadores.end(); ++it2) { // Recorre el mapa de enrutadores
                    archivo << ";"; // Escribe un ';'
                    if (it1 == it2) { // Si los enrutadores son el mismo
                        archivo << "0"; // Escribe un '0'
                    } else if (it1->second->getTabla().count(it2->first)) { // Si existe un enlace entre los enrutadores
                        archivo << it1->second->getTabla()[it2->first]; // Escribe el costo del enlace
                    } else {
                        archivo << "inf"; // Escribe 'inf' si no existe un enlace
                    }
                }
                archivo << "\n"; // Escribe un salto de línea
            }

            archivo.close(); // Cierra el archivo
        } else {
            cout << "No se pudo abrir el archivo.\n"; // Imprime un mensaje de error si no se pudo abrir el archivo
        }
    }

    int costoEnvio(string origen, string destino) { // Declara una función para calcular el costo de envío
        vector<string> camino = caminoMasCorto(origen, destino); // Obtiene el camino más corto
        int costoTotal = 0; // Declara una variable para el costo total
        for (int i = 0; i < camino.size() - 1; i++) { // Recorre el camino
            costoTotal += enrutadores[camino[i]]->getTabla()[camino[i+1]]; // Suma el costo del enlace al costo total
        }
        return costoTotal; // Devuelve el costo total
    }

    void generarRedAleatoria(int numEnrutadores) { // Declara una función para generar una red aleatoria
        srand(time(0)); // Inicializa la semilla del generador de números aleatorios
        for (int i = 0; i < numEnrutadores; i++) { // Para cada enrutador
            string id(1, 'A' + i); // Genera un nombre de enrutador
            agregarEnrutador(id); // Agrega el enrutador
            for (int j = 0; j < i; j++) { // Para cada enrutador anterior
                string idVecino(1, 'A' + j); // Genera un nombre de enrutador
                int costo = rand() % 10 + 1; // Genera un costo aleatorio entre 1 y 10
                actualizarTablaEnrutamiento(id, idVecino, costo); // Actualiza la tabla de enrutamiento del enrutador
                actualizarTablaEnrutamiento(idVecino, id, costo); // Actualiza la tabla de enrutamiento del enrutador vecino
            }
        }
    } // Fin de la definición de la clase


};
int main()
{
    Red red; // Crear una nueva red

    int opcion; // Declarar una variable para almacenar la opción del usuario
    do { // Iniciar un bucle do-while
        cout << "Bienvenido a nuestra red \n"; // Imprimir un mensaje de bienvenida
        cout << "1. Agregar enrutador\n"; // Imprimir la opción 1
        cout << "2. Remover enrutador\n"; // Imprimir la opción 2
        cout << "3. Actualizar tabla de enrutamiento\n"; // Imprimir la opción 3
        cout << "4. Cargar red desde archivo\n"; // Imprimir la opción 4
        cout << "5. Costo de envío\n"; // Imprimir la opción 5
        cout << "6. Camino más eficiente\n"; // Imprimir la opción 6
        cout << "7. Generar red aleatoria\n"; // Imprimir la opción 7
        cout << "8. Imprimir tabla de enrutamiento\n "; // Imprimir la opción 8
        cout << "Seleccione una opción: "; // Solicitar al usuario que seleccione una opción
        cin >> opcion; // Leer la opción del usuario
        cout << endl; // Imprimir una línea en blanco
        switch (opcion) { // Iniciar un bloque switch para manejar las diferentes opciones
        case 1:{ // Caso para la opción 1
            bool pointer = true; // Declarar una variable booleana y asignarle el valor true
            do{ // Iniciar un bucle do-while
                cout << "Ingrese el nombre del nuevo enrutador: "; // Solicitar al usuario que ingrese el nombre del nuevo enrutador
                string nuevo; // Declarar una variable para almacenar el nombre del nuevo enrutador
                cin >> nuevo; // Leer el nombre del nuevo enrutador

                // Convertir a mayúsculas
                transform(nuevo.begin(), nuevo.end(), nuevo.begin(), ::toupper); // Convertir el nombre del enrutador a mayúsculas

                // Verificar que sea solo una letra
                if (nuevo.size() != 1 || !isalpha(nuevo[0])) { // Si el nombre del enrutador no es una sola letra
                    cout << "El nombre del enrutador debe ser una sola letra.\n"; // Imprimir un mensaje de error
                } else { // Si el nombre del enrutador es una sola letra
                    // Verificar que el nombre no esté repetido
                    if (red.getEnrutadores().count(nuevo) > 0) { // Si el nombre del enrutador ya está en uso
                        cout << "El nombre del enrutador ya está en uso.\n"; // Imprimir un mensaje de error
                    } else { // Si el nombre del enrutador no está en uso
                        red.agregarEnrutador(nuevo); // Agregar el nuevo enrutador a la red
                        red.guardarEnArchivo("redes"); // Guardar la red en un archivo
                        cout << "Enrutador agregado con éxito\n"; // Imprimir un mensaje de éxito
                        pointer = false; // Cambiar el valor de la variable booleana a false
                    }
                }
            }while(pointer == true); // Continuar el bucle mientras la variable booleana sea true
            break; // Salir del bloque switch
        }
        case 2:{ // Caso para la opción 2
            bool pointer = true; // Declarar una variable booleana y asignarle el valor true
            do{ // Iniciar un bucle do-while
                cout << "ingrese el nombre del enrutador a eleminar: "; // Solicitar al usuario que ingrese el nombre del enrutador a eliminar
                string eliminar; // Declarar una variable para almacenar el nombre del enrutador a eliminar
                cin >> eliminar; // Leer el nombre del enrutador a eliminar
                if (red.getEnrutadores().count(eliminar) <= 0) { // Si el nombre del enrutador no existe
                    cout << "El nombre del enrutador no existe.\n"; // Imprimir un mensaje de error
                }
                else{ // Si el nombre del enrutador existe
                    red.removerEnrutador(eliminar); // Remover el enrutador de la red
                    red.guardarEnArchivo("redes"); // Guardar la red en un archivo
                    cout << endl; // Imprimir una línea en blanco
                    cout << "Enrutador eliminado con exito" << endl ; // Imprimir un mensaje de éxito
                    cout << endl; // Imprimir una línea en blanco
                    pointer = false; // Cambiar el valor de la variable booleana a false
                }
            }while(pointer == true); // Continuar el bucle mientras la variable booleana sea true
            break; // Salir del bloque switch
        }
        case 3: // Caso para la opción 3
        {
            int opcion1; // Declarar una variable para almacenar la opción del usuario
            do { // Iniciar un bucle do-while
                cout << "Bienvenido al menú de actualizar tabla de enrutamiento\n"<< endl; // Imprimir un mensaje de bienvenida
                cout << "Ingrese 1 si quiere seguir y 0 si quiere salir: "<< endl; // Solicitar al usuario que ingrese una opción
                cin >> opcion1; // Leer la opción del usuario
                if (opcion1 == 1) { // Si la opción del usuario es 1
                    cout << "ingrese el enrutador origen" << endl; // Solicitar al usuario que ingrese el enrutador origen
                    string principal; // Declarar una variable para almacenar el enrutador origen
                    cin >> principal; // Leer el enrutador origen
                    cout << "Ingrese el enrutador destino"<< endl; // Solicitar al usuario que ingrese el enrutador destino
                    string secundario; // Declarar una variable para almacenar el enrutador destino
                    cin >> secundario; // Leer el enrutador destino
                    cout << "Ingrese el costo"<< endl; // Solicitar al usuario que ingrese el costo
                    int costo; // Declarar una variable para almacenar el costo
                    cin >> costo; // Leer el costo
                    red.actualizarTablaEnrutamiento(principal, secundario,  costo); // Actualizar la tabla de enrutamiento
                    cout << "Tabla actulizada con exito" << endl; // Imprimir un mensaje de éxito
                }
            } while (opcion1 != 0); // Continuar el bucle mientras la opción del usuario sea diferente de 0

            red.guardarEnArchivo("redes"); // Guardar la red en un archivo
            cout << endl; // Imprimir una línea en blanco

            break; // Salir del bloque switch
        }
        case 4: // Caso para la opción 4
        {
            red.cargarDesdeArchivo("red.txt"); // Cargar la red desde un archivo
            red.guardarEnArchivo("redes"); // Guardar la red en un archivo
            cout << "Archivo Leido con exito" << endl; // Imprimir un mensaje de éxito
            cout << endl; // Imprimir una línea en blanco
            break; // Salir del bloque switch
        }
        case 5: // Caso para la opción 5
        {
            cout << "Costo de envio" << endl;; // Imprimir un mensaje
            cout << "Ingrese el enrutador de origen" << endl; // Solicitar al usuario que ingrese el enrutador de origen
            string origen; // Declarar una variable para almacenar el enrutador de origen
            cin >> origen; // Leer el enrutador de origen
            cout << "Ingrese el enrutador de destino" << endl; // Solicitar al usuario que ingrese el enrutador de destino
            string destino; // Declarar una variable para almacenar el enrutador de destino
            cin >> destino; // Leer el enrutador de destino
            cout << "El costo del envio será: " << red.costoEnvio(origen, destino); // Calcular e imprimir el costo de envío
            cout << endl; // Imprimir una línea en blanco
            break; // Salir del bloque switch
        }
        case 6: // Caso para la opción 6
        {
            cout << "Camino mas eficiente" << endl;; // Imprimir un mensaje
            cout << "Ingrese el enrutador de origen" << endl; // Solicitar al usuario que ingrese el enrutador de origen
            string origen; // Declarar una variable para almacenar el enrutador de origen
            cin >> origen; // Leer el enrutador de origen
            cout << "Ingrese el enrutador de destino" << endl; // Solicitar al usuario que ingrese el enrutador de destino
            string destino; // Declarar una variable para almacenar el enrutador de destino
            cin >> destino; // Leer el enrutador de destino
            cout << "El camino mas eficiente de "<< origen << " a " << destino << " sera:"; // Imprimir un mensaje
            vector<string> camino = red.caminoMasCorto(origen, destino); // Calcular el camino más corto
            for(auto nodo: camino){ // Recorrer el camino
                cout << nodo << " -> " ; // Imprimir cada nodo del camino
            }
            cout << endl; // Imprimir una línea en blanco

            break; // Salir del bloque switch
        }
        case 7: // Caso para la opción 7
        {
            cout << "Ingrese el numero de enrutadores que quieres generar: "; // Solicitar al usuario que ingrese el número de enrutadores
            int numeros; // Declarar una variable para almacenar el número de enrutadores
            cin >> numeros; // Leer el número de enrutadores
            red.generarRedAleatoria(numeros); // Generar una red aleatoria
            red.guardarEnArchivo("Aleatorios.txt"); // Guardar la red en un archivo
            cout << "Archivo generado con exito" << endl; // Imprimir un mensaje de éxito
            cout << endl; // Imprimir una línea en blanco
            break; // Salir del bloque switch
        }
        case 8: // Caso para la opción 8
        {
            cout << "Tabla de enrutadores" << endl; // Imprimir un mensaje
            red.mostrarTablasEnrutamiento(); // Mostrar las tablas de enrutamiento
            break; // Salir del bloque switch
        }
        default: // Caso por defecto
        {
            cout << "Opción no válida. Por favor, intente de nuevo.\n"; // Imprimir un mensaje de error
            break; // Salir del bloque switch
        }
        } // Fin del bloque switch
    } while (opcion < 9); // Continuar el bucle mientras la opción del usuario sea menor que 8
    return 0; // Devolver 0 para indicar que el programa terminó correctamente
} // Fin de la función principal
