#include <iostream>
#include <limits>

int main() {
    int contador = 0;
    int numero;
    int mayor1 = std::numeric_limits<int>::min();
    int mayor2 = std::numeric_limits<int>::min();

    std::cout << "Ingrese 10 numeros para encontrar los dos mas grandes:" << std::endl;

    while (contador < 10) {
        std::cout << "Ingrese el numero " << (contador + 1) << ": ";
        std::cin >> numero;

        if (numero > mayor1) {
            mayor2 = mayor1;
            mayor1 = numero;
        } else if (numero > mayor2) {
            mayor2 = numero;
        }

        contador++;
    }

    std::cout << "El numero mas grande es: " << mayor1 << std::endl;
    std::cout << "El segundo numero mas grande es: " << mayor2 << std::endl;

    return 0;
}
