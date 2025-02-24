#include <iostream>
using namespace std;

int main() {
    int cantidad;
    int numero;
    int menor;

    cout << "Ingrese la cantidad de enteros que desea comparar: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "La cantidad debe ser mayor que 0." << endl;
        return 1;
    }

    cout << "Ingrese " << cantidad << " enteros: ";
    cin >> numero;
    menor = numero;

    for (int i = 1; i < cantidad; ++i) {
        cin >> numero;
        if (numero < menor) {
            menor = numero;
        }
    }

    cout << "El entero mas pequeno es: " << menor << endl;

    return 0;
}
