#include <iostream>
using namespace std;

template <class A>
A minimo(A n, A b) {
    return (n < b) ? n : b;
}

int main() {
    int entero = 5, enteroU = 3;
    cout << "El menor entre " << entero << " y " << enteroU << " es: " << minimo(entero, enteroU) << endl;

    char caracter = 'z', caracterU = 'a';
    cout << "El menor entre '" << caracter << "' y '" << caracterU << "' es: '" << minimo(caracter, caracterU) << "'" << endl;

    float floww = 6.5, floww2 = 6.49;
    cout << "El menor entre " << floww << " y " << floww2 << " es: " << minimo(floww, floww2) << endl;

    return 0;
}
