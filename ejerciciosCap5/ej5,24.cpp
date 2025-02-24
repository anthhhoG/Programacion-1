#include <iostream>
using namespace std;

int main() {
    int filas;

    // Solicitar al usuario un número impar en el rango de 1 a 19
    do {
        cout << "Ingrese un numero impar entre 1 y 19: ";
        cin >> filas;
    } while (filas < 1 || filas > 19 || filas % 2 == 0);

    int mitad = filas / 2 + 1;

    // Parte superior del rombo
    for (int i = 1; i <= mitad; ++i) {
        for (int j = 1; j <= mitad - i; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    // Parte inferior del rombo
    for (int i = mitad - 1; i >= 1; --i) {
        for (int j = 1; j <= mitad - i; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
