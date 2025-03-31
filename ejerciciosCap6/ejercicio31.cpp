#include <iostream>

using namespace std;

int mcd(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int main() {
    int numeroUno, numeroDos;

    cout << "Ingrese dos numeros enteros: ";
    cin >> numeroUno >> numeroDos;

    cout << "El maximo comun divisor de " << numeroUno << " y " << numeroDos << " es: " << mcd(numeroUno, numeroDos) << endl;

    return 0;
}

