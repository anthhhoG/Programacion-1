#include <iostream>
using namespace std;

int main() {
    int suma = 0;
    int contador = 0;
    int numero;

    cout << "Ingrese una secuencia de enteros (9999 para terminar): " << endl;

    for (;;) {
        cin >> numero;

        if (numero == 9999) {
            break;
        }

        suma += numero;
        contador++;
    }

    if (contador > 0) {
        double promedio = static_cast<double>(suma) / contador;
        cout << "El promedio de los " << contador << " numeros ingresados es: " << promedio << endl;
    } else {
        cout << "No se ingresaron numeros validos." << endl;
    }

    return 0;
}
