#include <iostream>

using namespace std;
void ejercicio1() {
    cout << "Ejecutando el ejercicio 2.. \n";
    int num = 0;
    cout << "Ingresa un numero: ";
    cin >> num;
    cout << "Es ";
    if(num%2 == 0){
        cout << " par";
    }
    else{

        cout << " impar";
    }
}

void ejercicio2() {
    cout << "Ejecutando el ejercicio 4..." << endl;
    int num1 = 0;
    int num2 = 0;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    if (num1>num2){
        cout << "El numero menor es: " << num2;
    }
    else {
        cout << "El numero  menor es: " << num1;
    }
}

void ejercicio3() {
    cout << "Ejecutando el ejercicio 6..." << endl;
    int num1 = 0;
    int num2 = 0;
    int potencia = 0;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    potencia = num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    for(int i = 0; i < num2-1; i ++){
        num1 *= potencia;
    }
    cout << num1;
}

void ejercicio4() {
    cout << "Ejecutando el ejercicio 8..." << endl;
    int num = 0;
    int constante = 0;
    cout << "Ingrese un numero: ";
    cin >> num;
    constante = num;
    for(int i=1; i < constante; i++){
        num *= i;
    }
    cout << num;

}
void ejercicio5() {
    cout << "Ejecutando el ejercicio 10..." << endl;
    int num = 0;
    int constante = 0;
    cout << "ingrese un numero: ";
    cin >> num;
    constante = num;
    for(int i=1; i < constante; i++){
        num = constante;
        num *= i;
        if(num>1 and num<100){
            cout << num << endl;
        }
    }
}

void ejercicio6() {

    cout << "Ejecutando el ejercicio 12..." << endl;
    int num =0;
    int constante = 0;
    cout << "ingrese un numero";
    cin >> num;
    constante = num;
    for(int i=0; i<6; i ++){
        if(i<1){
            cout << constante << "^" << i+1 <<"=" << num << endl;
            i += 1;
        }
        else{
            num *= constante;
            cout << constante << "^" << i <<"=" << num << endl;
        }
    }

}

void ejercicio7() {
    cout << "Ejecutando el ejercicio 14..." << endl;
    int ascendente = 1;
    int descendente = 50;
    for(int i= 0; i<50; i ++){
        ascendente += i;
        descendente -= i;
        cout << ascendente << "  " << descendente << endl;
        ascendente = 1;
        descendente = 50;
    }
}
void ejercicio8() {
    cout << "Ejecutando el ejercicio 16..." << endl;
    int i = 0;
    int num = 0;
    int contador = 0;
    int promedio = 0;
    while(i<1){
        cout << "Ingrese un numero" << endl;
        cin >> num;
        contador += 1;
        promedio += num;
        if(num==0){
            if(contador==0){
                cout<<"no ingresaste numeros";
            }
            else{
                promedio = promedio/(contador-1);
                cout << "El promedio de los numeros son" << promedio;
                i += 1;
            }
        }
    }
}

void ejercicio9() {
    cout << "Ejecutando el ejercicio 18..." << endl;
    int num = 0;
    cout << "Ingrese un número: ";
    cin >> num;
    int raiz = 1;
    while (raiz * raiz <= num) {
        raiz++;
    }
    raiz--;
    if (raiz * raiz == num) {
        cout << num << " es un cuadrado perfecto";
    } else {
        cout << num << " NO es un cuadrado perfecto";
    }
}

void ejercicio10() {
    cout << "Ejecutando el ejercicio 20..." << endl;
    int  num = 0;
    cout << "Ingresa el numero: " << endl;
    cin >> num;
    int aux = num;
    int inverso = 0;
    while(aux>0){
        int digito = aux % 10;
        inverso = inverso * 10 + digito;
        aux = aux/10;
    }
    if(inverso == num){
        cout << num << " es palindromo" << endl;
    }
    else {
        cout << num << " no es palindromo" << endl;
    }
}
void ejercicio11() {
    cout << "Ejecutando el ejercicio 22..." << endl;
}

void ejercicio12() {
    cout << "Ejecutando el ejercicio 24..." << endl;
}

void ejercicio13() {
    cout << "Ejecutando el ejercicio 26..." << endl;
}
void ejercicio14() {
    cout << "Ejecutando el ejercicio 28..." << endl;
}

void ejercicio15() {
    cout << "Ejecutando el ejercicio 30..." << endl;
}


int main() {
    int opcion; // Variable para almacenar la opción del usuario
    cout << "Ingrese una opción : ";
            cin >> opcion; // Leer la opción del usuario
    switch (opcion) { // Usar un switch para ejecutar la función correspondiente
    case 1:
        ejercicio1();
        break;
    case 2:
        ejercicio2();
        break;
    case 3:
        ejercicio3();
        break;
    case 4:
        ejercicio4();
        break;
    case 5:
        ejercicio5();
        break;
    case 6:
        ejercicio6();
        break;
    case 7:
        ejercicio7();
        break;
    case 8:
        ejercicio8();
        break;
    case 9:
        ejercicio9();
        break;
    case 10:
        ejercicio10();
        break;
    case 11:
        ejercicio11();
        break;
    case 12:
        ejercicio12();
        break;
    case 13:
        ejercicio13();
        break;
    case 14:
        ejercicio14();
        break;
    case 15:
        ejercicio15();
        break;
    default:
        cout << "Opción inválida" << endl;
            break;
    }
    return 0;
}
