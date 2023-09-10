#include <iostream>
using namespace std;
void ejercicio1() {
      cout << "Ejecutando el ejercicio 2.. \n";
    int denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
     int cantidad=0;
    cout << "Ingrese la cantidad de dinero deseada: " << endl;
    cin >> cantidad;

    cout << "Para completar la cantidad deseada se necesita: " << endl;

    for (int i = 0; i < 10; i++) {
        int numero = cantidad / denominaciones[i];
        cout << denominaciones[i] << " : " << numero << "\n";
        cantidad = cantidad % denominaciones[i];
    }

    if (cantidad > 0) {
        cout << "Faltante: " << cantidad << "\n";
    }

}
void ejercicio2() {
      cout << "Ejecutando el ejercicio 4.. \n";
    int num1, num2;
    int horas1, horas2, minutos1, minutos2;
    cout << "ingresa los dos formatos de tiempo"<< endl;
    cin >> num1;
    cin >> num2;
    horas1 = num1 / 100;
    horas2 = num2 / 100;
    minutos1 = num1 % 100;
    minutos2 = num2%100;
     if(minutos1 > 60 || minutos2 >60){
        cout << "formato incorrecto";
    }
    else {
        int horasnuevas = horas1+horas2;
        int minutosnuevos = minutos1+minutos2;
        if(minutosnuevos > 60){
            int masH = minutosnuevos / 60;
            horasnuevas += masH;
            minutosnuevos = minutosnuevos % 60;
        }
        cout << "lo nuevo es " << horasnuevas << ":" << minutosnuevos;
    }
    }
void ejercicio3() {
      cout << "Ejecutando el ejercicio 6.. \n";
    double num1;
      cout << "Ingrese el numero de elementos a utilizar: " <<endl;
    double sumatoria;
    double factorial = 1;
    cin >> num1;

    for(int i=0; i <= num1; i++){
        double denominador = i;
        if(denominador != 0){
            factorial = 1;
            for(int e=1; e < denominador; e++){
                factorial *= e;
        }
         denominador = factorial;
        sumatoria += 1/denominador;
        }
    }
    cout << sumatoria;
}
void ejercicio4() {
      cout << "Ejecutando el ejercicio 8.. \n";
    cout << "Ingrese los valores de a, b y c: ";
    int a, b, c;
    cin >> a >> b >> c;
    int suma = 0;
    for (int i = 1; i < c; i++) {
        if(i%a==0 || i%b==0){
        suma += i;
        }
    }
    cout << "La suma de los múltiplos de " << a << " y " << b << " menores que " << c << " es:" << endl;
        if(a % b == 0 || b%a == 0){
            if(a < b){
                bool primero_a = true;
                for (int j = 1; j < c; j++) {
                if (j % a == 0)
                    if (primero_a) {
                        cout << j;
                        primero_a = false;
                    }
                    else {
                        // Si no es el primer múltiplo de a, imprimir m1k
                        cout << " + " << j;
                    }
        }
        }
            else{
                bool primero_a = true;
                for (int j = 1; j < c; j++) {
                if (j % b == 0)
                    if (primero_a) {
                        cout << j;
                        primero_a = false;
                    }
                    else {
                        // Si no es el primer múltiplo de a, imprimir m1k
                        cout << " + " << j;
                    }

            }
    }

        }
        else{
            bool primero_a = true;
            for (int i = 1; i < c; i++) {
             if (i % a == 0 ) {
                if (primero_a) {
                 cout << i;
                 primero_a = false;
            }
                else {
                    cout << " + " << i;
            }
            }
        }
            cout << " + ";
            bool primero_b = true;
            for (int j = 1; j < c; j++) {
                if (j % b == 0 && j % a != 0) {
                     if (primero_b) {
                         cout << j;
                        primero_b = false;
            }
                else {
                    cout << " + " << j;
            }
            }
            }
}
        cout << " = " << suma;

}
void ejercicio5() {
     cout << "Ejecutando el ejercicio 10.. \n";
    int num;
    int primo;
    int n = 2;
    int contador = 0;
    cout << "ingrea el n primo: " <<endl;
        cin >> num;
     while(contador <= num){
            int divisible = 0;
            for (int i = 2; i < n; i++) {
            // Si el número es divisible por i, no es primo
            if (n % i == 0) {
                divisible += 1;
            }
            else if(divisible==0){
                contador += 1;
                primo = n;
            }

        }
        n += 1;

}
     cout << "El primo numero 4 es: "<<primo;
}

void ejercicio6() {
      cout << "Ejecutando el ejercicio 12.. \n";
      int n;
      int maximo;
      cout << "ingrea el numero primo: " <<endl;
      cin >> n;
      int num = n;
      for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                cout << n;
            }
            maximo = i;
        }
      }
      if (n > 1) {
        maximo = n;
      }
      cout <<"el mayor factor primo de " <<num<< maximo;
}
bool es_palindromo(int n){
      int invertido = 0;
      int original = n;
      while (n > 0) {
        invertido = invertido * 10 + n % 10;
        n /= 10;
      }
      return invertido == original;
}
void ejercicio7() {
      cout << "Ejecutando el ejercicio 14.. \n";
      int maximo = 0;
      int factor1 = 0;
      int factor2 = 0;
      for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int producto = i * j;
            if (producto > maximo && es_palindromo(producto)) {
                maximo = producto;
                factor1 = i;
                factor2 = j;
            }
        }
      }
      cout << "El número palíndromo más grande que se puede obtener como una multiplicación de números de 3 dígitos es:" << endl;
          cout << factor1 << "*" << factor2 << "=" << maximo << endl;


}

int longitud_collatz(int n) {
          int longitud = 1;
          while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = 3 * n + 1;
        }
        longitud += 1;
          }
          return longitud;
}

int semilla_maxima(int k) {
          int semilla = 0;
              int maxima = 0;
          for (int i = 1; i < k; i++) {
        int longitud = longitud_collatz(i);
        if (longitud > maxima) {
            semilla = i;
            maxima = longitud;
        }
          }
          return semilla;
}

void imprimir_serie_maxima(int k) {
          int semilla = semilla_maxima(k);
          int longitud = longitud_collatz(semilla);
          cout << "La serie más larga es con la semilla: " << semilla << ", teniendo " << longitud << " términos." << endl;
                  cout << "La serie es: ";
          int numero = semilla;
          while (numero > 1) {
        cout << numero << ", ";
        if (numero % 2 == 0) {
            numero /= 2;
        }
        else {
            numero = 3 * numero + 1;
        }
          }
          cout << "1";
}
void ejercicio8() {
          cout << "Ejecutando el ejercicio 16.. \n";
          int k;
          cout << "ingrese el numero: ";
          cin >> k;
                  imprimir_serie_maxima(k);


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
    default:
        cout << "Opción inválida" << endl;
            break;
    }
    return 0;
}
