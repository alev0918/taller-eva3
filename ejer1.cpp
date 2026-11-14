#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

// esta funcion la usaremos para saber si un numero
//  es primo(hola profesor JAJAJA)
// ademas va a tener el ciclo para comprobar con 
// sus divisores si es primo
bool esPrimo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    srand(time(0)); // aqui se inicia una semilla para asegurarnos
    // que siempre que usemos el programa salgan numeros ramdom y diferentes 
    int n;
    cout << "Ingrese el tamano n de la matriz cuadrada: ";
    cin >> n;

    int M[50][50]; // pedimos en numero o tamaño de la matriz y la 
    //llena con numeros del 0 al 50
    cout << "\na) Matriz generada:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = rand() % 51; // Números de 0 a 50
            cout << setw(4) << M[i][j];
        }
        cout << endl;
    }
    // ya aqui imprimio esa matriz, con sus numeros y ordenandola de forma cuadrada :v
    int sumaDiagPrincipal = 0, sumaDiagSecundaria = 0;
    cout << "\nb) Diagonal principal: ";
    for (int i = 0; i < n; i++) {
        cout << M[i][i] << " ";
        sumaDiagPrincipal += M[i][i];
    }
    cout << "| Suma: " << sumaDiagPrincipal << endl;
    cout << "   Diagonal secundaria: ";
    for (int i = 0; i < n; i++) {
        cout << M[i][n - 1 - i] << " ";
        sumaDiagSecundaria += M[i][n - 1 - i];
    }
    cout << "| Suma: " << sumaDiagSecundaria << endl;
// bueno aqui basicamente sacamos los numeros y los suma desde 
//la diagonal principal de la matriz
    
    int vecFila[50], vecCol[50], vecSumaCuadrados[50];
    cout << "\nc) Vector suma de cuadrados (1ra fila^2 + ultima col^2): ";
    for (int i = 0; i < n; i++) {
        vecFila[i] = M[0][i];
        vecCol[i] = M[i][n - 1];
        vecSumaCuadrados[i] = (vecFila[i] * vecFila[i]) + (vecCol[i] * vecCol[i]);
        cout << vecSumaCuadrados[i] << " ";
    }
    cout << endl;
//aqui toma la primera y ultima fila eleva cada uno de los numeritos al cuadrado 
// y los suma en el vector resultante (profe usted sabia que tenemos una chsite con 
// con los vectores, por el vector proyector y proyectarse como buenos migajeros JAJAJAJAJ)

    int primos = 0, pares = 0, impares = 0, div3 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (esPrimo(M[i][j])) primos++;
            if (M[i][j] % 2 == 0) pares++;
            else impares++;
            if (M[i][j] % 3 == 0) div3++;
        }
    }
    cout << "\nd) Cantidad de primos: " << primos << endl;
    cout << "e) Pares: " << pares << " | Impares: " << impares << " | Divisibles por 3: " << div3 << endl;
// aqui recorre toda la matriz mirando y revisando cuales son primos, pares
// tambin si son impares o divisibles entre 3 

    int sumaCol[50];
    const double PI = acos(-1.0); // Valor exacto de PI usando <cmath>
    cout << "\nf) Tabla Suma Columna (X) vs Seno en Radianes (Y):" << endl;
    cout << "   Columna (X)\tSeno (Y)" << endl;
    for (int j = 0; j < n; j++) {
        sumaCol[j] = 0;
        for (int i = 0; i < n; i++) {
            sumaCol[j] += M[i][j];
        }
        double radianes = sumaCol[j] * (PI / 180.0); // Conversión grados a radianes
        double seno = sin(radianes);
        cout << "   " << sumaCol[j] << "\t\t" << fixed << setprecision(4) << seno << endl;
    }
// aqui basicamente recorremos la matriz por columnas fijando la columna j 
// y sumando sus filas. Una vez tenemos el total de la columna, 
// utilizamos PI y la formula para transformar el num a rad
//  y metiendolo dentro de la funcion senoo
    
    int vec1D[2500];
    int k = 0;
    double sumaTotal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vec1D[k] = M[i][j];
            sumaTotal += vec1D[k];
            k++;
        }
    }
    double promedio = sumaTotal / (n * n);
    cout << "\ng) Promedio general: " << setprecision(2) << promedio << endl;
    cout << "   Vector 1D dividido por el promedio: ";
    for (int i = 0; i < k; i++) {
        cout << (vec1D[i] / promedio) << " ";
    }
    cout << endl;

    return 0;
}
// ya para acabar aplanamos la matriz 2D en un vector unidimensional 
// usando'k' que aumenta en cada paso, y guardamos en la suma total 
//para sacar el promedio general. 
// al final dividimos cada num del vector entre ese promedio. y fin