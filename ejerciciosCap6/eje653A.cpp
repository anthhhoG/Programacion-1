#include <iostream>
#include <cstdlib>

using namespace std;

template <class A>
A suma(A numero1, A numero2, A numero3) {
    return numero1 + numero2 + numero3;
} // Se realiza el prototipo evitando el Tipo de dato

int main() {

    int numero1, numero2, numero3, resultado = 0;

    cout << "Ingrese 3 numeros seguidos: ";
    cin >> numero1 >> numero2 >> numero3;

    resultado = suma(numero1, numero2, numero3);

    cout << "\nLa suma de los numeros es: " << resultado << endl;

system("Pause");
return 0;
}



