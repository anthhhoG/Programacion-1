#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y;
    char continuar;

    do {
        cout << "Ingrese un numero: ";
        cin >> x;
        y = floor(x + 0.5);
        cout << "Numero original: " << x << ", Redondeado: " << y << endl;
        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    return 0;
}

