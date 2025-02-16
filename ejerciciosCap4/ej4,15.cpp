#include <iostream>
#include <iomanip> // Para formatear la salida

int main() {
    double ventas;

    std::cout << "Introduzca las ventas en dolares (-1 para salir): ";
    std::cin >> ventas;

    while (ventas != -1) {
        double ingresos = 200.0 + (0.09 * ventas);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "El salario es: $" << ingresos << std::endl;

        std::cout << "Introduzca las ventas en dolares (-1 para salir): ";
        std::cin >> ventas;
    }

    return 0;
}
