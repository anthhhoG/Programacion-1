#include <iostream>
#include <limits>

int main() {
    int contador = 0;
    int numero;
    int mayor = std::numeric_limits<int>::min();

    std::cout << "Ingrese 10 numeros para encontrar el mayor:" << std::endl;

    while (contador < 10) {
        std::cout << "Ingrese el numero " << (contador + 1) << ": ";
        std::cin >> numero;

        if (numero > mayor) {
            mayor = numero;
        }

        contador++;
    }

    std::cout << "El numero mas grande es: " << mayor << std::endl;

    return 0;
}
