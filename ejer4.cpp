//No pares, sigue sigue!!! VAMOS A HORA CON EL EJRCICIO 4 :)
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Esta funcion la vamos a utilizaar para hacer el calculo mateematico del factorial 
int calcularFactorial(int num) {
    int fact = 1;
    // Multiplicamos en cadena desde el 1 hasta llegar al número
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact; //ahora devolvemos el rsultado final 
}

int main() {
    // e    sto es para que los numeros aleatorios cambien en cada ejecucion 
    srand(time(0));
    int n;
    cout << "Ingrese la cantidad de elementos n: ";
    cin >> n;

    int v[100];
    
    // recorremos para generar los números y calcular su factorial de una vez
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 11; // numero aleatorio entre 0 y 10

        // mostramos el valor guardado y usamos la función de arriba
        cout << "Elemento [" << i << "] = " << v[i] 
             << " -> Factorial = " << calcularFactorial(v[i]) << endl;
    }

    return 0;
}