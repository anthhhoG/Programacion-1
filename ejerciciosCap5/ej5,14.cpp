#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int producto, cantidad;
    double total = 0.0;

    cout << "Ingrese el numero del producto (1-5) y la cantidad vendida (0 para terminar):" << endl;

    while (true) {
        cout << "Producto: ";
        cin >> producto;

        if (producto == 0) {
            break;
        }

        cout << "Cantidad vendida: ";
        cin >> cantidad;

        switch (producto) {
            case 1:
                total += cantidad * 2.98;
                break;
            case 2:
                total += cantidad * 4.50;
                break;
            case 3:
                total += cantidad * 9.98;
                break;
            case 4:
                total += cantidad * 4.49;
                break;
            case 5:
                total += cantidad * 6.87;
                break;
            default:
                cout << "Numero de producto invalido. Intente de nuevo." << endl;
                break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "El valor total de ventas es: $" << total << endl;

    return 0;
}
