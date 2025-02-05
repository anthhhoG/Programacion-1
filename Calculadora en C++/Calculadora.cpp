#include <iostream>
using namespace std;

int main() {
    int opcionActual;
    double primerNumero, segundoNumero, resultado;

    do {
        cout << "Seleccione el tipo de operacion que desea realizar:" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Salir" << endl;
        cin >> opcionActual;

        if (opcionActual >= 1 && opcionActual <= 4) {
            cout << "Ingrese el primer numero: ";
            cin >> primerNumero;
            cout << "Ingrese el segundo numero: ";
            cin >> segundoNumero;
        }

        switch (opcionActual) {
            case 1:
                resultado = primerNumero + segundoNumero;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 2:
                resultado = primerNumero - segundoNumero;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 3:
                resultado = primerNumero * segundoNumero;
                cout << "El resultado es: " << resultado << endl;
                break;
            case 4:
                if (segundoNumero != 0) {
                    resultado = primerNumero / segundoNumero;
                    cout << "El resultado es: " << resultado << endl;
                } else {
                    cout << "No se puede dividir entre cero." << endl;
                }
                break;
            case 5:
                cout << "Calculadora cerrada exitosamente!" << endl;
                break;
            default:
                cout << "Por favor, selecciona una opcion del menu disponible." << endl;
        }

    } while (opcionActual != 5);

    return 0;
}
