#include <iostream>
#include <iomanip>

using namespace std;

// Recibe una afilita de numeros y su numero total de datos y suma los elementos S
int sumarFila(const int fila[], int columnas) {
    int suma = 0;
    for (int j = 0; j < columnas; j++) {
        suma += fila[j];
    }
    return suma;
}

int main() {
    int m, pA, pB, q;

    // veo que sean de igual dimension las 2 matrices
    do {
        cout << "Ingrese dimensiones de A (filas columnas): ";
        cin >> m >> pA;
        cout << "Ingrese dimensiones de B (filas columnas): ";
        cin >> pB >> q;

        if (pA != pB) {
            cout << "Error: las columnas de A (" << pA << ") deben ser iguales a las filas de B (" << pB << "). Intente de nuevo.\n\n";
        }
    } while (pA != pB); // se repite hasta q me la des biSn

    int A[50][50], B[50][50], C[50][50]; //solo podemos hacer matrices hasta 50x50, igual eso es muy grande

    // Pido la info
    cout << "\nIngrese elementos de la matriz A (" << m << "x" << pA << "):" << endl; //ahi te muestro el tamaño de A
    for (int i = 0; i < m; i++) { //i es numero de fila, j de columna
        for (int j = 0; j < pA; j++) {
            cin >> A[i][j]; //numerin de esa posicion
        }
    }

    cout << "\nIngrese elementos de la matriz B (" << pB << "x" << q << "):" << endl;
    for (int i = 0; i < pB; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j]; //lo mismo
        }
    }

    //  C = A x B, multiplico fila de A por columna de B y sumo
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {  //posiciones de la matriz c
            C[i][j] = 0; //inicializo la posicion d c
            for (int k = 0; k < pA; k++) { //recorro 
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatriz A:" << endl; //muestro las matrices con espacios ahi 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < pA; j++) cout << setw(4) << A[i][j]; 
        cout << endl; //otra filita 
    }

    cout << "\nMatriz B:" << endl;
    for (int i = 0; i < pB; i++) {
        for (int j = 0; j < q; j++) cout << setw(4) << B[i][j];
        cout << endl;
    }

    cout << "\nMatriz Producto C = A x B:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) cout << setw(5) << C[i][j];
        cout << endl;
    }

    // uso la funcioncita de suma 
    cout << "\nSuma de cada fila de la matriz C:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "Fila " << i << ": " << sumarFila(C[i], q) << endl;
    }

    return 0;
}
