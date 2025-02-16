#include <iostream>
#include <iomanip> // Para formatear la salida

int main() {
    double kilometrosTotales = 0.0;
    double litrosTotales = 0.0;
    int kilometros, litros;

    std::cout << "Escriba los kilometros usados (-1 para salir): ";
    std::cin >> kilometros;

    while (kilometros != -1) {
        std::cout << "Escriba los litros: ";
        std::cin >> litros;

        double kpl = static_cast<double>(kilometros) / litros;
        kilometrosTotales += kilometros;
        litrosTotales += litros;
        double kplTotal = kilometrosTotales / litrosTotales;

        std::cout << std::fixed << std::setprecision(6);
        std::cout << "KPL en este reabastecimiento: " << kpl << std::endl;
        std::cout << "Total KPL: " << kplTotal << std::endl;

        std::cout << "Escriba los kilometros usados (-1 para salir): ";
        std::cin >> kilometros;
    }

    return 0;
}
