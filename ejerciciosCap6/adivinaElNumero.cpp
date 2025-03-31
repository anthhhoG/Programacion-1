#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void adivinarNumero() {
    srand(time(0));
    int numero = 1 + rand() % 1000;
    int intento, contador = 0;

    cout << "Adivine un numero entre 1 y 1000: ";

    do {
        cin >> intento;
        contador++;

        if (intento < numero) {
            cout << "Demasiado bajo. Intente de nuevo: ";
        } else if (intento > numero) {
            cout << "Demasiado alto. Intente de nuevo: ";
        }
    } while (intento != numero);

    cout << "\nFelicidades. Adivino el numero!" << endl;

    if (contador < 10) {
        cout << "O ya sabia usted el secreto, o tuvo suerte!" << endl;
    } else if (contador == 10) {
        cout << "Aja! Sabia usted el secreto!" << endl;
    } else {
        cout << "Deberia haberlo hecho mejor!" << endl;
    }

    cout << "El numero de intentos fue: " << contador << endl;
}

int main() {
    adivinarNumero();
    return 0;
}
