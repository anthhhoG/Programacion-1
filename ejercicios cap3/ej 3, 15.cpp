#include <iostream>
using namespace std;

class Fecha {
private:
    int mes;
    int dia;
    int anio;

public:
    Fecha(int m, int d, int a) {
        establecerMes(m);
        establecerDia(d);
        establecerAnio(a);
    }

    void establecerMes(int m) {
        mes = (m >= 1 && m <= 12) ? m : 1;
    }

    void establecerDia(int d) {
        dia = d;
    }

    void establecerAnio(int a) {
        anio = a;
    }

    int obtenerMes() const {
        return mes;
    }

    int obtenerDia() const {
        return dia;
    }

    int obtenerAnio() const {
        return anio;
    }

    void mostrarFecha() const {
        cout << mes << "/" << dia << "/" << anio << endl;
    }
};

int main() {
    Fecha fecha1(2, 28, 2025);
    cout << "Fecha 1: ";
    fecha1.mostrarFecha();

    Fecha fecha2(13, 5, 2024);
    cout << "Fecha 2 (mes invalido): ";
    fecha2.mostrarFecha();

    fecha2.establecerMes(10);
    cout << "Fecha 2 (mes corregido): ";
    fecha2.mostrarFecha();

    fecha1.establecerDia(15);
    fecha1.establecerAnio(2024);
    cout << "Fecha 1 (actualizada): ";
    fecha1.mostrarFecha();

    return 0;
}

