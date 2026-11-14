/*
 * Taller 3 - Arreglos y Matrices
 * Ejercicio 5
 *
 * Enunciado:
 *   Construir un programa en C++ que determine si una matriz cuadrada ingresada
 *   es triangular superior, triangular inferior o es una matriz diagonal.
 *   El programa debe trabajar con matrices de tamaño n x n.
 *
 * Procedimiento:
 *   - Se lee n y luego los n*n elementos de la matriz.
 *   - Una matriz es TRIANGULAR SUPERIOR si todos los elementos que están
 *     DEBAJO de la diagonal principal (posiciones donde i > j) son cero.
 *   - Una matriz es TRIANGULAR INFERIOR si todos los elementos que están
 *     ENCIMA de la diagonal principal (posiciones donde i < j) son cero.
 *   - Una matriz es DIAGONAL si es triangular superior y triangular inferior
 *     al mismo tiempo, es decir, todo lo que está fuera de la diagonal es cero.
 *   - Se recorre la matriz una sola vez con dos ciclos for. Se usan dos
 *     variables booleanas que empiezan en true y se vuelven false en cuanto
 *     se encuentra un elemento distinto de cero en la zona que debería ser cero.
 *
 * Compilar:  g++ -std=c++17 ejercicio5.cpp -o ejercicio5
 */

#include <iostream>
#include <vector>
#include <iomanip>   // para setw (imprimir la matriz alineada)

using namespace std;

int main() {
    int n;

    // 1. Leer el tamaño de la matriz (se valida que sea positivo)
    cout << "Ingrese el tamano n de la matriz cuadrada (n x n): ";
    cin >> n;
    while (n <= 0) {
        cout << "El tamano debe ser un entero positivo. Ingrese n de nuevo: ";
        cin >> n;
    }

    // 2. Crear la matriz de n x n usando un vector de vectores
    vector<vector<int>> matriz(n, vector<int>(n));

    // 3. Leer los elementos de la matriz posición por posición
    cout << "\nIngrese los elementos de la matriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // 4. Mostrar la matriz ingresada
    cout << "\nMatriz ingresada:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(6) << matriz[i][j];
        }
        cout << "\n";
    }

    // 5. Revisar las condiciones.
    //    Se asume al inicio que sí cumple ambas, y se busca un "contraejemplo".
    bool esTriangularSuperior = true;
    bool esTriangularInferior = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j && matriz[i][j] != 0) {
                // Hay un número distinto de cero debajo de la diagonal
                esTriangularSuperior = false;
            }
            if (i < j && matriz[i][j] != 0) {
                // Hay un número distinto de cero encima de la diagonal
                esTriangularInferior = false;
            }
        }
    }

    // Diagonal = cumple las dos condiciones a la vez
    bool esDiagonal = esTriangularSuperior && esTriangularInferior;

    // 6. Mostrar el resultado
    cout << "\nResultado:\n";
    if (esDiagonal) {
        cout << "La matriz es DIAGONAL.\n";
        cout << "(Toda matriz diagonal tambien es triangular superior e inferior a la vez).\n";
    } else if (esTriangularSuperior) {
        cout << "La matriz es TRIANGULAR SUPERIOR.\n";
    } else if (esTriangularInferior) {
        cout << "La matriz es TRIANGULAR INFERIOR.\n";
    } else {
        cout << "La matriz NO es triangular superior, ni triangular inferior, ni diagonal.\n";
    }

    return 0;
}