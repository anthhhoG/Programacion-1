#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int montoPrincipal;
    int tasaInteres;
    int anos;
    int montoEnCentavos;

    cout << "Ingrese el monto principal (en centavos): ";
    cin >> montoPrincipal;

    cout << "Ingrese la tasa de interes (en porcentaje, sin el signo %): ";
    cin >> tasaInteres;

    cout << "Ingrese el numero de anos: ";
    cin >> anos;

    montoEnCentavos = montoPrincipal * pow(100 + tasaInteres, anos) / pow(100, anos);

    int dolares = montoEnCentavos / 100;
    int centavos = montoEnCentavos % 100;

    cout << "El monto en deposito es: $" << dolares << "." << setw(2) << setfill('0') << centavos << endl;

    return 0;
}
