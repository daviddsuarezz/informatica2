#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
#include <map>
#include <sstream>
#define ARCHIVO_USUARIOS "usuarios"
#define archivo_usuarios_codificado "usuarios_codificados"
#define transacciones_codificadas "transacciones_codificadas"

using namespace std;

// Función para convertir un caracter a un string binario de n bits
string char_a_binario(char caracter){
    bitset<8> b(caracter); // convertir el caracter en una secuencia de 8 bits
    string s = b.to_string(); // convierte la secuencia a un string
    return s;// devuelve los ultimos n bits del string

}
 // funcion para construir un binario a char
char binario_a_char(string s){
    if (s.length() != 8) {
        cout << "Error: la cadena binaria debe tener exactamente 8 bits.\n";
        return '\0';
    }
    bitset<8> b(s); // Convertir el string a un bitset de 8 bits

    return static_cast<char>(b.to_ulong()); // Convertir el conjunto de bits en un número y luego a un carácter
    // el to ulong convierte el bitset a un numero sin signo, y el static_cast, convierte ese numero a un char
}

// invertir los bits de un string

string invertir(string s) {
    for (auto& c : s) { // Para cada carácter en la cadena el auto es que asume el valor, lo que esta haciendo es iterar sobre la cadeana de carcateres
        c = (c == '0') ? '1' : '0'; // Si el carácter es '0', cámbialo a '1', y viceversa
    }
    return s; // Devolver la cadena invertida
}

// Función para desplazar los bits de una cadena una posición a la izquierda
string desplazar(string s) {
    return s.back() + s.substr(0, s.size()-1); // Devolver la subcadena desde el segundo carácter hasta el final, seguida del primer carácter
    // la funcion back lo que hace es recolectar el ultimo caracter, entonces con la suma lo que se hace es poner este ultimo de primer
    // y tomar lo restante de la cadena
}


// Función para desplazar los bits de una cadena una posición a la derecha
string desplazar_derecha(string s) {
    return s.substr(1, s.size()-1) + s[0]; // Devolver la subcadena desde el segundo carácter hasta el final, seguida del primer carácter
    // lo que hace el substr extra la cadena del string desde la posicion 1 hasta la final menos uno, y ahi inclluye el primer caracter
}


// Creamos una función que divide un string en grupos de bits, y cada grupo los introduce a un vector
vector<string> dividir(string s, int n) {
    // Creamos un vector para almacenar los grupos
    vector<string> grupos;
    // Recorremos el string de n en n posiciones
    for (int i = 0; i < s.size(); i += n) {
        // Obtenemos el grupo desde la posición i hasta el tamaño n
        string grupo = s.substr(i, n);
        // Añadimos el grupo al vector
        grupos.push_back(grupo);
    }
    // Devolvemos el vector con los grupos
    return grupos;
}


 //funcion para codificicar
string modo_codificar_1(string fuente, string salida, int n, int metodo) {
    ifstream in(fuente); // se crea la variable fuente, con la cual es la que se abrira para obtener los datos a codificar
    ofstream out(salida, ios::binary); // archivo donde se va a colocar ya los datos codificados, con tipo de escritura bianria
    string bloque = ""; // creacion de un strin
    int unos = 0; // Contador de unos en el bloque anterior
    int ceros = 0; // Contador de ceros en el bloque anterior
    if (!in.is_open() || !out.is_open()) { // comprueba si se puede abrir los archvos
        cout << "Error al abrir los archivos.\n";
        return 0;
    }
       string linea;
    while (getline(in, linea)) { // Leer el archivo línea por línea
        for (char c : linea) { // itera sobre la linea, para obtener cada caracter
            bloque += char_a_binario(c); // lo agrega al string, una vez transformado, al binario correspondiente de cada caracter
        }
    }

    // Llamamos a la función dividir y obtenemos un vector con los grupos
    vector<string> semillas = dividir(bloque, n); // dividimos el bloque en la semilla que nos ingresó el usuario
    string resultado = ""; // creamos un nuevo string
 if(metodo == 1){
   for (int i = 0; i < semillas.size(); i++) { //vamos a iterar sobre el vector para ir cambaindo semilla a semilla
        string temporal = "";
        temporal = semillas[i]; // toma la semilla i
        if(i == 0){
            resultado += invertir(temporal); // siempre va a entrarr debido a que la primera no cambia
        }
        else {
            string contador = semillas[i-1]; // va a contar siempre los ceros y unos de la semilla anterior
            for(char b : contador){
                if( b == '0') ceros ++;
                else unos++;

            }


            if (ceros == unos){ // si son iguales invierte los uno y los ceros
                resultado += invertir(temporal);
            }
            else if (ceros > unos){
                for(int j = 1; j < n; j +=2){ // si los ceros son mayores que los unos, va a cambiar cada 2 el digito que este en esa posicion
                    temporal[j] = (temporal[j] == '0') ? '1': '0';
                }
                resultado += temporal;
            }
            else{
                for(int i = 2; i < n; i +=3){ // si los ceros son menores que los unos, va a cambiar cada 3 el digito que este en esa posicion
                    temporal[i] = (temporal[i] == '0') ? '1': '0';
                }
                resultado += temporal;
            }

        }
        ceros = 0;
        unos = 0;


    }
      out << resultado;
 }



 if(metodo == 2){
      for (int i = 0; i < semillas.size(); i++) { // va a desplazar hacia la izquiera toda la cadena de la semilla
        string temporal = "";
        temporal = semillas[i];

        resultado += desplazar(temporal);
      }
      out << resultado;
 }
 return resultado;

}

string decodificar(string fuente, string salida, int n, int metodo) {
 ifstream in(fuente , ios::binary);
 ofstream out(salida);
 string bloque = "";
 int unos = 0; // Contador de unos en el bloque anterior
 int ceros = 0; // Contador de ceros en el bloque anterior
 if (!in.is_open() || !out.is_open()) {
      cout << "Error al abrir los archivos.\n";
      return 0 ;
 }
 string linea;
 while (getline(in, linea)) { // Leer el archivo línea por línea
      for (char c : linea) { // Procesar cada carácter en la línea
        bloque += c;
      }
 }

 // Llamamos a la función dividir y obtenemos un vector con los grupos
 vector<string> semillas = dividir(bloque, n);
 string resultado = "";
 vector <string> decodificados; // este vector see usara para poder contar las semillas anteriores
 if(metodo == 1){
      for (int i = 0; i < semillas.size(); i++) {
        string temporal = "";
        temporal = semillas[i];
        if(i == 0){
            resultado += invertir(temporal);
            decodificados.push_back(resultado);
        }
        else {
            string contador = decodificados[i-1];
            for(char b : contador){ // itera sobre el caracter
                if( b == '0') ceros ++;
                else unos++;

            }


            if (ceros == unos){
                resultado += invertir(temporal);
                decodificados.push_back(invertir(temporal));
            }
            else if (ceros > unos){
                for(int j = 1; j < n; j +=2){
                    temporal[j] = (temporal[j] == '0') ? '1': '0';
                }
                resultado += temporal;
                decodificados.push_back(temporal);
            }
            else{
                for(int i = 2; i < n; i +=3){
                    temporal[i] = (temporal[i] == '0') ? '1': '0';
                }
                resultado += temporal;
                decodificados.push_back(temporal);
            }

        }
        ceros = 0;
        unos = 0;


      }
      vector<string> semillascodificadas = dividir(resultado, 8); // en este caso este es el mayor cambio debido a que se crea una cadena de caracteres, y esta al final se divide en grupos de 8 para poder sacar el caracter
      // Mostramos el vector con los grupos
      for(int i = 0; i < semillascodificadas.size(); i++) {
        string temporal = "";
        temporal = semillascodificadas[i];
        out << binario_a_char(temporal);
      }
 }



 if(metodo == 2){
      for (int i = 0; i < semillas.size(); i++) {
        string temporal = "";
        temporal = semillas[i];

        resultado += desplazar_derecha(temporal);
      }
      vector<string> semillascodificadas = dividir(resultado, 8);
      for(int i = 0; i < semillascodificadas.size(); i++) {
        string temporal = "";
        temporal = semillascodificadas[i];
        out << binario_a_char(temporal);

      }
 }
 in.close();
 out.close();
 return resultado;

}





int prueba_codificar(){
    ofstream file;
    ofstream file2;
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

    file.open(fuente.c_str()); // lo abre en modo escritura

    if (file.is_open()) {
        // Pedimos al usuario que ingrese las letras que quiere guardar
        string letras;
        cout << "Ingrese las letras que quiere guardar: ";
        cin >> letras;
        // Escribimos las letras en el archivo
        file << letras << "\n";
        // Cerramos el archivo
        file.close();
        // Mostramos un mensaje de éxito
        cout << "El archivo se escribió correctamente.\n";
    }
    else {
        // Mostramos un mensaje de error
        cout << "No se pudo abrir el archivo.\n";
    }

    cout << "Ingrese el nombre del archivo salida: ";
    cin >> salida; // Leer el nombre del archivo salida
    file2.open(salida);
    file.close();
    file2.close();
    if (true) { // Si se eligió el primer método
       modo_codificar_1(fuente, salida, n, metodo); // Codificar el archivo usando el primer método
        cout << "1";
    }
    return 0;

}

int prueba_decodificar(){

    int n; // Variable para guardar la semilla de codificación
    int metodo; // Variable para guardar el método de codificación
    string fuente; // Variable para guardar el nombre del archivo fuente
    string salida; // Variable para guardar el nombre del archivo salida

    cout << "Ingrese la semilla de codificación (n): ";
            cin >> n; // Leer la semilla de codificación

    cout << "Ingrese el método de codificación (1 o 2): ";
    cin >> metodo; // Leer el método de codificación

    cout << "Ingrese el nombre del archivo fuente de la codificacion: ";
    cin >> fuente; // Leer el nombre del archivo fuente

    ifstream file3(fuente, ios::binary);
    if (!file3.is_open()) {
        cout << "No se pudo abrir el archivo fuente.\n";
        return 1;
    }
      file3.close();

    cout << "Ingrese el nombre del archivo salida de la decodificacion: ";
    cin >> salida; // Leer el nombre del archivo salida

    ofstream file4(salida);
    if (!file4.is_open()) {
        cout << "No se pudo abrir el archivo de salida.\n";
        return 1;
    }

    file4.close();
    if (true) { // Si se eligió el primer método
       decodificar(fuente, salida, n, metodo); // Codificar el archivo usando el primer método
        cout << "1" << endl;
    }
    return 0;
}
// se declara una estructura tipo usario, la cual contendra la cedula, la calve y el salod, esto se hace por facilidad
struct Usuario {
    int cedula; // La cédula del usuario
    string clave; // La clave del usuario
    int saldo; // El saldo del usuario
};


bool validar_admin() { // se su pone que el admin ya ingreso su contraseña
    string clave; // sse crea un string
    ifstream in("sudo"); // toma el valor del archivo que se va a ver
    string fuente; // sse crea un string
    string salida; // sse crea un string
    int n;
    int metodo;
    if (in.is_open()) { // si el archivo abre lo leera linea por linea y se copia la contraseña puesta ahi
        getline(in, clave);
        in.close();
    } else {
        cout << "No se pudo abrir el archivo sudo.txt.\n";
        return false;
    }
    fuente = "contraseña_admin";
    salida = "contraseña_admin_codificada";
        n = 4;
    metodo = 1;


     // esto se hara para tener tres intentos el admin validar su contraseña
    int contador = 0;
    while (contador < 3){
        string clave_ingresada;
        cout << "Ingrese la contraseña: ";
                cin >> clave_ingresada;

        // Abre el archivo en modo de escritura, esto sobrescribirá el contenido existente
        ofstream file(fuente.c_str());
        if (!file.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return false;
        }

        // Escribe la nueva contraseña en el archivo
        file << clave_ingresada << "\n";
        file.close();
        // se codifica la contraseña que se encuentra ahi, para comparala con la contraseña ingresada por el usuario
        clave_ingresada = modo_codificar_1(fuente, salida, n, metodo );
        if (clave == clave_ingresada){
        contador += 5;
        cout << "contraseña correcta" << endl;
                return clave == clave_ingresada; // Aquí deberías comparar las claves encriptadas
        }
        else{
        contador += 1;
        cout << "contraseña incorrecta"<< endl; // tiene tres intentos
        }
    }
    cout << "usuario bloqueado";
}

// Mapa para almacenar los usuarios. La clave es la cédula del usuario.
map<int, Usuario> usuarios;

void cargar_usuarios_desde_archivo() {
    ifstream file(ARCHIVO_USUARIOS); // abre el archivo usuarios
    string line;
    while (getline(file, line)) { //lee mientras pueda linea por linea
        stringstream ss(line); //declaro la linea como un flujo de entrada para poder hacer operaciones con ella
        string usuario_info;
        while (getline(ss, usuario_info, ';')) { // por ejemplo aqui partimos esa linea, por cada punto y coma, y se guarda en el string usaurio_info separada por espacios
        Usuario usuario; // declaramos una estructura
        stringstream uss(usuario_info); // declaramos otro flujo de entrada pero ya partiendose del string usuario_info
        uss >> usuario.cedula; // aqui lee la cadena usuario info, hasta un espacio y lo guarda eso en la cedula
        uss >> usuario.clave; // retoma desde el espacio y lo guarda en la clave del usuario
        uss >> usuario.saldo; // ingresa el saldo
        usuarios[usuario.cedula] = usuario; // Almacenar el usuario en el mapa
        }
    }
    file.close();
}

// Función para verificar si un usuario existe en el sistema
Usuario verificar_usuario() {
    int cedula_ingresada; // La cédula ingresada por el usuario
    string clave_ingresada; // La clave ingresada por el usuario
    cout << "Ingrese la cédula: ";
            cin >> cedula_ingresada;
    cout << "Ingrese la clave: ";
    cin >> clave_ingresada;

    // Verifica si el usuario existe en el sistema y si la clave es correcta
    if (usuarios.count(cedula_ingresada) > 0 && usuarios[cedula_ingresada].clave == clave_ingresada) { // verifica por medio de la funcion count la clave en el diccionario contando cuantaas hay igual, y luego se va al mapa y i
        cout << "Usuario existente. Cédula: " << usuarios[cedula_ingresada].cedula // imprime los datos del usuario asociado a esa cedula
             << ", Clave: " << usuarios[cedula_ingresada].clave
             << ", Saldo: " << usuarios[cedula_ingresada].saldo << "\n";
        return usuarios[cedula_ingresada];
    } else {
        cout << "Usuario no encontrado.\n";
        exit(0); // Termina el programa si la cédula o la clave son incorrectas
    }
}


int transaccion_numero = 0;


void cargar_numero_transaccion() { // se carga en un string todo lo que haya en el archivo transacciones
    ifstream file("transacciones.txt");
    string line;
    while (getline(file, line, ';')) { // Usa ';' como delimitador para identificar cada cuanto hay unas transaccion
        ++transaccion_numero;
    }
    file.close();
}
void registrar_transaccion(int cedula, int monto, string tipo) { // registra la transcciones en el mismo archivo
    ofstream file("transacciones.txt", ios::app);

    file <<(transaccion_numero += 1) << " " << cedula << " " << monto << " " << tipo<< ";"; // se escribe sobre el archivo, ingresa los valor de un modo en los que se pueda leer e identificar
    file.close();
}
void guardar_usuarios_en_archivo() {
    ofstream file(ARCHIVO_USUARIOS); // abre un archivo de ussuarios
    for (auto& usuario : usuarios) { // itera sobre el mapa
        file << usuario.second.cedula << " " << usuario.second.clave << " " << usuario.second.saldo << ";"; // la funcion tipo second nos ayuda asociar clavv-valor
    }
    file.close();
}


void registrar_usuario() {
    Usuario usuario; // crea una estructura tipo usuario
    bool cedula_valida = false;

    // Continúa pidiendo una cédula hasta que se ingrese una válida
    while (!cedula_valida) {
        cout << "Ingrese la cédula del usuario: ";
                cin >> usuario.cedula; // se guarda en el apartado cedula

        // Verificar si la cédula ya existe en el sistema
        if (usuarios.count(usuario.cedula) > 0) { // como la cedula es la clave, lo que hace la funcion .count es revisar las claves del mapa, por ende se esta comparando las claves con el valor de cedula ingresado
        cout << "Error: Ya existe un usuario con esa cédula. Por favor, intente de nuevo.\n";
        } else {
        cedula_valida = true;
        }
    }
    // si asi es verdadero pues ingresa los valores faltantes
    cout << "Ingrese la clave del usuario: ";
    cin >> usuario.clave;
    cout << "Ingrese el saldo inicial del usuario (COP): ";
    cin >> usuario.saldo;

    usuarios[usuario.cedula] = usuario; // Almacenar el nuevo usuario en el mapa
}

int main (){
    int opcion1 = 0;
    string tipo = "";
    cout << "Seleccione una opción:\n1. Administrador\n2. Usuario\n";
            cin >> opcion1;

    switch (opcion1) {
    case 1: // Administrador
        cout << "Has seleccionado Administrador.\n";
        if (validar_admin()) {
        cout << "Registro de ususarios" << endl;
        int contador = 1;
        while(contador == 1){
            cargar_usuarios_desde_archivo();
            registrar_usuario();
            guardar_usuarios_en_archivo();
            modo_codificar_1(ARCHIVO_USUARIOS, archivo_usuarios_codificado, 4, 1);
            decodificar(archivo_usuarios_codificado, ARCHIVO_USUARIOS, 4, 1);
            cout << "Ingresa 1- si quieres ingresar otro usuario, 2- si quieres parar";
            cin >> contador;
            }
        }
        break;
    case 2: // Usuario
        cout << "Has seleccionado Usuario.\n";
        cargar_usuarios_desde_archivo(); // Carga los usuarios desde un archivo
        Usuario usuario = verificar_usuario(); // Verifica si un usuario existe en el sistema
        int opcion;
        cout << "Seleccione una opción:\n1. Consultar saldo\n2. Retirar dinero\n";
                cin >> opcion;

        switch (opcion) {
        case 1: // Consultar saldo
            tipo = "consulta";
        cout << "Saldo: " << usuario.saldo - 1000 << "\n"; // Resta el costo por consulta
        usuario.saldo -= 1000; // Actualiza el saldo del usuario
        cargar_numero_transaccion();
        registrar_transaccion(usuario.cedula, -1000, tipo); // Registra la transacción
        modo_codificar_1("transacciones.txt", transacciones_codificadas, 4, 1);
        decodificar(transacciones_codificadas, "nuevas_transacciones_decodificadas", 4, 1);
        break;
        case 2: { // Retirar dinero
        int cantidad;
        tipo = "retiro";
        cout << "Ingrese la cantidad a retirar: ";
        cin >> cantidad;
        if (usuario.saldo >= cantidad + 1000) { // Verifica si hay suficiente saldo
            cout << "Retiro exitoso. Nuevo saldo: " << usuario.saldo - cantidad - 1000 << "\n"; // Muestra el nuevo saldo
            usuario.saldo -= cantidad + 1000; // Actualiza el saldo del usuario
            cargar_numero_transaccion();
            registrar_transaccion(usuario.cedula, -cantidad, tipo); // Registra la transacción
            modo_codificar_1("transacciones.txt", transacciones_codificadas, 4, 1);
            decodificar(transacciones_codificadas, "nuevas_transacciones_decodificadas", 4, 1);
        } else {
            cout << "Saldo insuficiente.\n";
        }
        break;
        }
        default:
        cout << "Opción no válida.\n";
        break;
        }
        // Actualiza la información del usuario en el mapa de usuarios y en el archivo principal
        usuarios[usuario.cedula] = usuario;
        guardar_usuarios_en_archivo();
        break;
    }


}





