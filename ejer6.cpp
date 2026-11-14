/*
 * Taller/Evaluación 3 - Arreglos y Matrices
 * Ejercicio 6
 *
 * Enunciado:
 *   Escribir un programa en C++ que lea una matriz de m x n enteros y:
 *   a) Encuentre el elemento máximo y el mínimo, indicando la fila y la
 *      columna en la que se encuentra cada uno.
 *   b) Intercambie la fila que contiene el máximo con la fila que contiene
 *      el mínimo y muestre la matriz resultante.
 *   c) Calcule la transpuesta de la matriz y la almacene en una nueva matriz.
 *      Imprima ambas matrices (la original con filas intercambiadas y la
 *      transpuesta) de forma legible.
 *
 * Procedimiento:
 *   a) Se toma el primer elemento [0][0] como máximo y mínimo inicial y se
 *      recorre toda la matriz. Si aparece un número mayor que el máximo actual
 *      (o menor que el mínimo actual), se actualiza el valor y se guardan su
 *      fila y su columna. Si el valor se repite, se reporta la primera vez
 *      que aparece.
 *   b) Para intercambiar dos filas se recorren sus columnas y se cambian los
 *      elementos uno a uno usando una variable auxiliar. Si el máximo y el
 *      mínimo están en la misma fila, no hay nada que intercambiar.
 *   c) La transpuesta de una matriz m x n es una matriz n x m donde
 *      transpuesta[j][i] = matriz[i][j] (las filas pasan a ser columnas).
 *      Se calcula a partir de la matriz que ya tiene las filas intercambiadas.
 *
 * Compilar:  g++ -std=c++17 ejercicio6.cpp -o ejercicio6
 */

#include <iostream>
#include <vector>
#include <iomanip>   // para setw (imprimir las matrices alineadas)

using namespace std;

// Función para imprimir cualquier matriz de forma ordenada.
// Recibe la matriz por referencia constante (const &) para no copiarla
// y para asegurar que la función no la modifica.
void imprimirMatriz(const vector<vector<int>>& mat) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            cout << setw(6) << mat[i][j];
        }
        cout << "\n";
    }
}

int main() {
    int m, n;

    // ---------- Lectura de datos ----------
    cout << "Ingrese el numero de filas (m): ";
    cin >> m;
    while (m <= 0) {
        cout << "Debe ser un entero positivo. Ingrese m de nuevo: ";
        cin >> m;
    }

    cout << "Ingrese el numero de columnas (n): ";
    cin >> n;
    while (n <= 0) {
        cout << "Debe ser un entero positivo. Ingrese n de nuevo: ";
        cin >> n;
    }

    // Matriz de m filas y n columnas
    vector<vector<int>> matriz(m, vector<int>(n));

    cout << "\nIngrese los elementos de la matriz:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "\nMatriz original:\n";
    imprimirMatriz(matriz);

    // ---------- a) Máximo y mínimo con su posición ----------
    int maximo = matriz[0][0], filaMax = 0, colMax = 0;
    int minimo = matriz[0][0], filaMin = 0, colMin = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
                filaMax = i;
                colMax = j;
            }
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                filaMin = i;
                colMin = j;
            }
        }
    }

    cout << "\na) Elemento maximo: " << maximo
         << "  (fila " << filaMax << ", columna " << colMax << ")\n";
    cout << "   Elemento minimo: " << minimo
         << "  (fila " << filaMin << ", columna " << colMin << ")\n";
    cout << "   (Las filas y columnas se cuentan desde 0)\n";

    // ---------- b) Intercambiar la fila del máximo con la del mínimo ----------
    if (filaMax == filaMin) {
        cout << "\nb) El maximo y el minimo estan en la misma fila ("
             << filaMax << "), por lo que no hay filas que intercambiar.\n";
    } else {
        for (int j = 0; j < n; j++) {
            int aux = matriz[filaMax][j];          // se guarda el valor de la fila del máximo
            matriz[filaMax][j] = matriz[filaMin][j];
            matriz[filaMin][j] = aux;
        }
        cout << "\nb) Se intercambiaron la fila " << filaMax
             << " y la fila " << filaMin << ".\n";
    }

    cout << "\nMatriz con filas intercambiadas (" << m << " x " << n << "):\n";
    imprimirMatriz(matriz);

    // ---------- c) Transpuesta (se guarda en una matriz nueva de n x m) ----------
    vector<vector<int>> transpuesta(n, vector<int>(m));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    cout << "\nc) Matriz transpuesta (" << n << " x " << m << "):\n";
    imprimirMatriz(transpuesta);

    return 0;
}