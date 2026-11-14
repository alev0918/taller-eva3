#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
// profe sera que usted se da cuenta quien hizo cada ejercicio por la forma de escribir?
//ya ya le voy a explixar el codigo :'c
using namespace std;

int main() {
 // aqui inicamos la semilla aleatoria para que cuando corramos el programa
// nos salgan números diferentes en cada prueba
    srand(time(0));
    
    int n;
    cout << "Ingrese la cantidad de elementos n: ";
    cin >> n;
    
// aqui validamos que N tuviera un valor adecuado y no pasara el vector
// luego llenamos el vector original con números ramdom (entre 1 y 100)
    if (n <= 0 || n > 100) {
        cout << "Error: El tamaño debe estar entre 1 y 100." << endl;
        return 1;
    }
    
    int vectorOriginal[100];
    double suma = 0;
    
//mientras vamos sumando cada valor para tener el total acumulado de todos

    cout << "\nVector original generado: " << endl;
    for (int i = 0; i < n; i++) {
        vectorOriginal[i] = rand() % 100 + 1; 
        cout << vectorOriginal[i] << " ";
        suma += vectorOriginal[i]; 
        // sumamos y guadarmos para sacar el promedio despyes
    }
    cout << endl;
    
// y calculamos el promedio dividiendo la suma total entre n
// ademas usamos double para no perder decimales :D
    double media = suma / n;
    cout << fixed << setprecision(2);
    cout << "\nLa media (promedio) de los elementos es: " << media << endl;
    
// ahora vamos a crear el segundo vector para filtrar y guardar
// solo los elementos mayores a al promedio que sacamos y eso
    int vectorMayores[100];
    int contadorMayores = 0; // esto llevará cuenta de cuántos cumplieron los requesistos (para ser VIP)
    
    for (int i = 0; i < n; i++) {
        if (vectorOriginal[i] > media) {
            vectorMayores[contadorMayores] = vectorOriginal[i];
            contadorMayores++; // aumentamos para saber cuantos complen la condicion y poderlos imprimir
            // y guardar en el segun vec los mayores al promedio
        }
    }
    
    // y con esto motramos el resultado del vector
    cout << "Elementos mayores que la media (" << contadorMayores << " en total): ";
    if (contadorMayores == 0) {
        cout << "Ninguno";
    } else {
        for (int i = 0; i < contadorMayores; i++) {
            cout << vectorMayores[i] << " ";
        }
    }
    cout << endl;

    return 0;
}