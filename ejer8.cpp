//Gestión de calificaciones (0.0 a 5.0) para n estudiantes y m asignaturas.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cout << "Ingrese numero de estudiantes (n): ";
    cin >> n;
    cout << "Ingrese numero de asignaturas (m): ";
    cin >> m;

    double notas[50][50]; //hasta 50 estudiantes con 50 asignaturay asi, j es asignatura

    // rango 0.0 a 5.0
    for (int i = 0; i < n; i++) {
        cout << "\nNotas del estudiante " << i << ":" << endl;
        for (int j = 0; j < m; j++) {
            do {
                cout << "  Asignatura " << j << " (0.0 - 5.0): ";
                cin >> notas[i][j];
                if (notas[i][j] < 0.0 || notas[i][j] > 5.0) {
                    cout << "  Nota invalida. Debe estar entre 0.0 y 5.0." << endl;
                }
            } while (notas[i][j] < 0.0 || notas[i][j] > 5.0); //dame las notas bien w
        }
    }

    double promEstudiantes[50];
    double promAsignaturas[50];

    //  Promedio de cada estudiante (por filas)
    for (int i = 0; i < n; i++) {
        double suma = 0;
        for (int j = 0; j < m; j++) {
            suma += notas[i][j];
        }
        promEstudiantes[i] = suma / m;
    }

    //Promedio de cada asignatura (por columnas) 1D
    for (int j = 0; j < m; j++) {
        double suma = 0;
        for (int i = 0; i < n; i++) {
            suma += notas[i][j];
        }
        promAsignaturas[j] = suma / n;
    }

    cout << fixed << setprecision(2); //hasta 2 decimales apenas
    cout << "\n--- Promedios por Estudiante ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Estudiante [" << i << "]: " << promEstudiantes[i] << endl;
    }

    cout << "\n--- Promedios por Asignatura ---" << endl;
    for (int j = 0; j < m; j++) {
        cout << "Asignatura [" << j << "]: " << promAsignaturas[j] << endl;
    }

    // Estudiante con promedio más alto y asignatura con promedio más bajo
    int idxMejorEst = 0;
    for (int i = 1; i < n; i++) {
        if (promEstudiantes[i] > promEstudiantes[idxMejorEst]) { //merodeamos commparando de primero a ultimo
            idxMejorEst = i;
        }
    }

    int idxPeorAsig = 0;
    for (int j = 1; j < m; j++) {
        if (promAsignaturas[j] < promAsignaturas[idxPeorAsig]) {
            idxPeorAsig = j;
        }
    }

    cout << "\n--- Resultados Destacados ---" << endl;
    cout << "Estudiante con promedio mas alto: Indice [" << idxMejorEst 
         << "] con promedio de " << promEstudiantes[idxMejorEst] << endl;
    cout << "Asignatura con promedio mas bajo: Indice [" << idxPeorAsig 
         << "] con promedio de " << promAsignaturas[idxPeorAsig] << endl;

    return 0;
}
