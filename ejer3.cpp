//Vamos con el ejercicio 3 siiii :)

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));//Esto es para que los numeros aleatorios cambien en cada ejecucion//
    int n;
    cout << "Ingrese la cantidad de elementos n: ";
    cin >> n;
    
    //Aqui vamos a guardadar el vector original y otro para los que solo pasen el filtro 
    int v[100], mayores[100];
    double suma = 0;

    cout << "Vector generado: ";
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 11;
        suma += v[i];
        cout << v[i] << " ";
    }
    cout << endl;

    //Ahora vamos a calcular el promedio y preparar el contador 
    double media = suma / n;
    int cantMayores = 0;

    //Con esto vamo a buscar cuales n son mayores qu la media y los apartamos 
    for (int i = 0; i < n; i++) {
        if (v[i] > media) {
            mayores[cantMayores] = v[i];
            cantMayores++;
        }
    }

    // Aqui ordenamos la lista de numeros de menor a mayor 
    for (int i = 0; i < cantMayores - 1; i++) {
        for (int j = 0; j < cantMayores - i - 1; j++) {
            if (mayores[j] > mayores[j + 1]) {
                int aux = mayores[j];
                mayores[j] = mayores[j + 1];
                mayores[j + 1] = aux;
            }
        }
    }
    //Ya paara terminar imprimimos la media y la lisyta ya ordenada
    cout << "Media: " << media << endl;
    cout << "Elementos mayores que la media (ordenados): ";
    for (int i = 0; i < cantMayores; i++) {
        cout << mayores[i] << " ";
    }
    cout << endl;

    return 0;
}