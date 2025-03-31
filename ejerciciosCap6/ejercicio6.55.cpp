#include <iostream>

enum class TipoCuenta { AHORROS, CHEQUES, INVERSION };

int main() {
    TipoCuenta cuenta = TipoCuenta::AHORROS;

    switch (cuenta) {
        case TipoCuenta::AHORROS:
            std::cout << "Cuenta de ahorros seleccionada.\n";
            break;
        case TipoCuenta::CHEQUES:
            std::cout << "Cuenta de cheques seleccionada.\n";
            break;
        case TipoCuenta::INVERSION:
            std::cout << "Cuenta de inversión seleccionada.\n";
            break;
    }

    return 0;
}
