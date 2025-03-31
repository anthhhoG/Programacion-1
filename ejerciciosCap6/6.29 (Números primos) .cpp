#include <iostream>
#include <cmath>
using namespace std;

// Funci�n para determinar si un n�mero es primo
bool esPrimo(int num) {
    if (num < 2) return false;
    if (num == 2) return true; // 2 es primo
    if (num % 2 == 0) return false; // Los n�meros pares mayores a 2 no son primos

    int limite = sqrt(num);
    for (int i = 3; i <= limite; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int contador = 0;

    cout << "Numeros primos entre 2 y 10,000:" << endl;
    for (int i = 2; i <= 10000; i++) {
        if (esPrimo(i)) {
            cout << i << " ";
            contador++;
        }
    }
    cout << "\nTotal de numeros primos encontrados: " << contador << endl;

    return 0;
}
