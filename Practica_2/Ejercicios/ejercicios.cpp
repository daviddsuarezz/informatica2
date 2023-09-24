#include <iostream>
#include "ejercicios.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;
char letra_aleatoria();

    void fun_c(double *a, int n, double *promedio, double *suma)
    {
        int i;
        *suma = 0.0;
        for (i = 0; i < n; i++)
            *suma += *(a + i);
        *promedio = (double) *suma / n;
    }

    void probar_funcion_c(){
        // Crear un arreglo de tipo double con los valores a promediar
        double a[] = {1.5, 2.3, 4.7, 3.2};
        // Crear una variable de tipo int con el tamaño del arreglo
        int n = sizeof(a) / sizeof(a[0]);
        // Crear dos variables de tipo double para almacenar el resultado del promedio y la suma
        double promedio, suma;
        // Llamar a la función fun_c pasando la dirección de memoria de cada variable como parámetro
        fun_c(a, n, &promedio, &suma);
        // Imprimir el resultado del promedio y la suma
        printf("El promedio es: %.2f\n", promedio);
        printf("La suma es: %.2f\n", suma);
    }
    
    void ejercicio2(){
        //https://www.tinkercad.com/things/5ZbexiClQy7
    }
    char letra_aleatoria() {
        return 'A' + rand() % 26;
    }
    void imprimir_arreglo(char arreglo[], int tamaño) {
        for (int i = 0; i < tamaño; i++) {
            cout << arreglo[i];
        }

        cout << endl;
    }
    void contar_frecuencias(char arreglo[], int tam) {
        // Arreglo que almacena las frecuencias de cada letra
        int frec[26] = {0};
        // Recorremos el arreglo y actualizamos las frecuencias
        for (int i = 0; i < tam; i++) {
            // Restamos 'A' para obtener el índice correspondiente a la letra
            int indice = arreglo[i] - 'A';
            // Incrementamos la frecuencia de la letra en el índice
            frec[indice]++;
        }
        // Recorremos el arreglo de frecuencias e imprimimos las que son mayores a cero
        for (int i = 0; i < 26; i++) {
            // Sumamos 'A' para obtener la letra correspondiente al índice
            char letra = 'A' + i;
            // Si la frecuencia es mayor a cero, la imprimimos
            if (frec[i] > 0) {
                cout << letra << ": " << frec[i] << endl;
            }
        }
    }


    void problema1(){
        srand(time(NULL));
        // Definimos el tamaño del arreglo
       const int TAM = 1 + rand() % 200;
        // Creamos el arreglo de caracteres
        char arreglo[TAM];
        // Llenamos el arreglo con letras mayúsculas aleatorias
        for (int i = 0; i < TAM; i++) {
            arreglo[i] = letra_aleatoria();
        }
        // Imprimimos el arreglo
        imprimir_arreglo(arreglo, TAM);
        // Contamos e imprimimos las frecuencias de cada letra en el arreglo
        contar_frecuencias(arreglo, TAM);

    }
    int cadena(string cadena){
        int numero = 0;
        int signo = 1;
        int posicion = 0;
        if (cadena[0] == '-'){
            signo = -1;
             posicion++;
        }

        while(posicion < cadena.length()){
            int digito = cadena[posicion] - '0';
            if(digito <0 || digito > 9){
                throw invalid_argument("La cadena no es numérica");
            }
            numero = numero *10 + digito;
            posicion++;
        }
        return numero * signo;
    }

    void problema2(){
        string prueba1 = "123";
        cout << "La cadena " << prueba1 << " se convierte en el número " << cadena(prueba1) << endl;

                    // Prueba con una cadena negativa
                    string prueba2 = "-456";
        cout << "La cadena " << prueba2 << " se convierte en el número " << cadena(prueba2) << endl;

                    // Prueba con una cadena inválida
                    string prueba3 = "78a9";
        cout << "La cadena " << prueba3 << " se convierte en el número " << cadena(prueba3) << endl;

    }

    string m_a_mayusculas(string cadena){

        string resultado = "";
        for(int i = 0; i < cadena.length(); i++ ){
            char caracter = cadena[i];
            if(caracter >= 'a' && caracter <= 'z'){
                caracter = caracter -  'a' + 'A';

            }
            resultado += caracter;

        }
        return resultado;
    }

    void problema3(){
        cout << "Ingrese una cadena: ";
        string cadena;
        //La función lee todos los caracteres que el usuario ingresa hasta que encuentra un salto de línea (\n), que es el que se genera al presionar la tecla Enter.
        getline(cin, cadena);

        // Mostramos la cadena original y la convertida a mayúsculas
        cout << "Original: " << cadena << endl;
        cout << "En mayuscula: " << m_a_mayusculas(cadena) << endl;

    }
    void separacion_de_cadenas(string cadena,string  &numero, string &caracteres ){
        numero= "";
        caracteres = "";
        for(int i = 0; i < cadena.length(); i++ ){
            char caracter = cadena[i];
            if(caracter >= 'a' && caracter <= 'z' || caracter >= 'A' && caracter <= 'Z') {
                caracteres += caracter;

            }
            else{
                numero += caracter;
            }

        }
    }

    void problema4(){
        cout << "Ingrese una cadena: ";
        string cadena;
        //La función lee todos los caracteres que el usuario ingresa hasta que encuentra un salto de línea (\n), que es el que se genera al presionar la tecla Enter.
        getline(cin, cadena);
        // Creamos una variable pair que almacena el resultado de la función
        string numero;
        string texto;
        // Llamamos a la función pasando las variables como parámetros por referencia
        separacion_de_cadenas(cadena, numero, texto);
        cout << "Original: " << cadena << endl;
        cout << "Texto:  " << texto << endl;
        cout << "Numeros:  " << numero << endl;
    }

    int valorRomano(char caracter) {
        switch (caracter) {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return -1;
        }
    }
    int convertirRomano(string numero, int i) {
        // Caso base: si se llega al final de la cadena, se devuelve 0
        if (i == numero.length()) {
            return 0;
        }
        // Caso recursivo: si el caracter esta seguido por uno de mayor valor, se resta su valor y se llama a la función con el siguiente índice
        if (i < numero.length() - 1 && valorRomano(numero[i]) < valorRomano(numero[i + 1])) {
            return -valorRomano(numero[i]) + convertirRomano(numero, i + 1);
        }
        // Caso recursivo: si no, se suma su valor y se llama a la función con el siguiente índice
        else {
            return valorRomano(numero[i]) + convertirRomano(numero, i + 1);
        }
    }
    int convertirRomano2(string numero) {
        int n = numero.length();
        int suma = 0;
        // Recorrer el string desde el final hasta el inicio
        for (int i = n - 1; i >= 0; i--) {
            // Obtener el valor del caracter actual
            int valor = valorRomano(numero[i]);
            // Si el caracter es menor que el anterior, restar su valor
            if (i < n - 1 && valor < valorRomano(numero[i + 1])) {
                suma -= valor;
            }
            // Si no, sumar su valor
            else {
                suma += valor;
            }
        }
        return suma;
    }

    void problema5(){
        string romano;
        cout << "Ingrese un numero romano: ";
        cin >> romano;
        // Validar el numero romano
        if (valorRomano(romano[0]) != -1) {
            // Convertir y mostrar el resultado
            int arabe = convertirRomano2(romano);
            cout << "El numero ingresado fue: " << romano << endl;
            cout << "Que corresponde a: " << arabe << endl;
        }
        else {
            // Mostrar un mensaje de error
            cout << "El numero ingresado no es valido" << endl;
        }
        //https://www.tinkercad.com/things/4Jcexjn2Upw
    }
    bool estaRepetido(int m[][10], int num, int valor, int fila, int columna){

        for(int i = 0; i < num; i++){

            for(int j = 0; j < num; j++){
                if(m[i][j] == valor && (i!= fila || j != columna ) ){
                    return true;
                }
            }
        }
        return false;

    }

    int problema6(){
        int n;
        cout << "ingrese el tamaño de la matriz cuadrada " << endl;
        cin >> n;
        if(n <= 0){
            cout << "El tamaño debe ser un numero entero postivo";
        }
        int m[10][10];
        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){
                m[i][j] = 0;
            }
        }
        cout << "ingrese los valores de la matriz: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "m[" << i << "][" << j << "] = ";
                cin >> m[i][j];
                // Validar que el valor sea válido y no esté repetido
                if (m[i][j] <= 0 || estaRepetido(m, n, m[i][j], i, j)) {
                    cout << "El valor debe ser un número entero positivo y no debe repetirse" << endl;
                        return 0;
                }
            }
        }
        cout << "La matriz ingresada es:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "| ";
            for (int j = 0; j < n; j++) {
                // Usar setw para alinear los valores
                cout << setw(3) << m[i][j] << " ";
            }
            cout << "|" << endl;
        }
        int constante = 0;
            for (int j = 0; j < n; j++) {
            constante += m[0][j];
        }

        bool esmagico = true;
        // Comparar la suma de los valores de las demás filas con la constante
        for(int i = 1; i < n && esmagico; i++){
            int sumaFila = 0;
            for (int j = 0; j<n; j++){
                sumaFila += m[i][j];
            }
            if(sumaFila != constante){
                esmagico = false;
            }
        }
        // Comparar la suma de los valores de las columnas con la constante
        for(int j=0; j < n && esmagico; j++){
            int sumaCol = 0;
            for(int i = 0; i < n; i++){
                sumaCol += m[i][j];
            }
        if(sumaCol != constante){
            esmagico = false;
        }
        }

        int sumaDiag1 = 0;
        for(int i = 0; i<n; i++){
            sumaDiag1 += m[i][i];

        }
        if(sumaDiag1 != constante){
            esmagico = false;
        }
        // Comparar la suma de los valores de la diagonal secundaria con la constante
        int sumaDiag2 = 0;
        for (int i = 0; i < n; i++) {
            sumaDiag2 += m[i][n - i - 1];
        }
        if (sumaDiag2 != constante) {
            esmagico = false;
        }
        if (esmagico) {
            cout << "La matriz es un cuadrado mágico" << endl;
        }
        else {
            cout << "La matriz no es un cuadrado mágico" << endl;
        }

    }
    int** rotarMatriz(int** m) {
        // Crear una nueva matriz dinámica de 5x5
        int** r = new int*[5]; // se crea un puntero doble que estará apuntando a un arreglo de punteros
        for (int i = 0; i < 5; i++) {
            r[i] = new int[5]; // luego a cada puntero de ese arreglo se le asigna un arreglo de 5 espacos
        }
        // Recorrer la matriz original y asignar los valores rotados a la nueva matriz
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
            // La fila i se convierte en la columna (4 - j) y la columna j se convierte en la fila i
            r[i][j] = m[4 - j][i]; // la posicion 0,0 sera la posicion 0,4 osea la primer columna, se convierte en la primera fila pero al reves
        }
        // Devolver la nueva matriz rotada
        return r;
    }

    void problema7(){
        int** m = new int*[5];
        for (int i = 0; i < 5; i++) {
            m[i] = new int[5];
            for (int j = 0; j < 5; j++) {
            m[i][j] = 0;
            }
        }
        int contador = 1;
        // Usar dos bucles anidados para recorrer la matriz por filas y columnas
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
            // Asignar el valor del contador a cada celda de la matriz e incrementar el contador en uno
            m[i][j] = contador;
            contador++;
            }
        }
        // Imprimir la matriz original en la salida estándar, usando un formato adecuado para mostrar los valores alineados
        cout << "Matriz original:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "| ";
            for (int j = 0; j < 5; j++) {
            // Usar setw para alinear los valores
            cout << setw(2) << m[i][j] << " ";
            }
            cout << "|" << endl;
        }
        int** r;
        // Llamar a la función con la matriz original y guardar el resultado en la variable
        r = rotarMatriz(m);
        // Imprimir la matriz rotada 90 grados en la salida estándar, usando el mismo formato que antes
        cout << "Matriz rotada 90 grados:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "| ";
            for (int j = 0; j < 5; j++) {
            cout << setw(2) << r[i][j] << " "; // el setw sirve para alinear.
            }
            cout << "|" << endl;
        }
        // Repetir los pasos anteriores dos veces más, usando la matriz rotada como argumento de la función, para obtener las matrices rotadas 180 y 270 grados
        r = rotarMatriz(r);
        cout << "Matriz rotada 180 grados:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "| ";
            for (int j = 0; j < 5; j++) {
            cout << setw(2) << r[i][j] << " ";
            }
            cout << "|" << endl;
        }
        r = rotarMatriz(r);
        cout << "Matriz rotada 270 grados:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "| ";
            for (int j = 0; j < 5; j++) {
            cout << setw(2) << r[i][j] << " ";
            }
            cout << "|" << endl;
        }
        // Liberar la memoria de las matrices dinámicas
        for (int i = 0; i < 5; i++) {
            delete[] m[i]; // eliminamos primero las columnas, por medio de las filas osea del arreglo de punteros
            delete[] r[i];
        }
        delete[] m; // esto hace referencia al arreglo de puntero, que en teoria son las filas.
        delete[] r;

    }
