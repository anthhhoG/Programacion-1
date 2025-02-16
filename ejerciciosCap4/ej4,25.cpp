#include <iostream>
using namespace std;

int main() {
    int lado;

    cout << "Introduzca el tamano del lado del cuadrado (1-20): ";
    cin >> lado;

    if (lado < 1 || lado > 20) {
        cout << "El tamaño del lado debe estar entre 1 y 20." << endl;
        return 1;
    }

    for (int fila = 1; fila <= lado; fila++) {
        for (int columna = 1; columna <= lado; columna++) {
            if (fila == 1 || fila == lado || columna == 1 || columna == lado) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
