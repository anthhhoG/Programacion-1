#include <iostream>
using namespace std;

int main() {
    int binario;
    int decimal = 0;
    int valorPosicional = 1;

    cout << "Introduzca un numero binario: ";
    cin >> binario;

    while (binario > 0) {
        int digito = binario % 10;
        decimal += digito * valorPosicional;
        valorPosicional *= 2;
        binario /= 10;
    }

    cout << "El equivalente decimal es: " << decimal << endl;

    return 0;
}
