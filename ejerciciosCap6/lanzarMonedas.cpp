#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int tirar() {
    return rand() % 2;
}

int main() {
    srand(time(0)); //numeros aleatorios
    int caras = 0, cruces = 0;

    for (int i = 0; i < 100; i++) {
        int resultado = tirar();
        if (resultado == 0) {
            cout << "Cara" << endl;
            caras++;
        } else {
            cout << "Cruz" << endl;
            cruces++;
        }
    }

    cout << "\nResultados:" << endl;
    cout << "Caras: " << caras << endl;
    cout << "Cruces: " << cruces << endl;

    return 0;
}
