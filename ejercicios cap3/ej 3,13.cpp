#include <iostream>
#include <string>
using namespace std;

class Factura {
private:
    string numeroPieza;
    string descripcionPieza;
    int cantidad;
    int precioPorArticulo;

public:
    Factura(string numPieza, string descPieza, int cant, int precio) {
        numeroPieza = numPieza;
        descripcionPieza = descPieza;
        establecerCantidad(cant);
        establecerPrecioPorArticulo(precio);
    }

    void establecerNumeroPieza(string numPieza) {
        numeroPieza = numPieza;
    }

    void establecerDescripcionPieza(string descPieza) {
        descripcionPieza = descPieza;
    }

    void establecerCantidad(int cant) {
        cantidad = (cant > 0) ? cant : 0;
    }

    void establecerPrecioPorArticulo(int precio) {
        precioPorArticulo = (precio > 0) ? precio : 0;
    }

    string obtenerNumeroPieza() const {
        return numeroPieza;
    }

    string obtenerDescripcionPieza() const {
        return descripcionPieza;
    }

    int obtenerCantidad() const {
        return cantidad;
    }

    int obtenerPrecioPorArticulo() const {
        return precioPorArticulo;
    }

    int obtenerMontoFactura() const {
        return cantidad * precioPorArticulo;
    }
};

int main() {
    Factura factura1("12345", "Martillo de carpintero", 2, 1500);

    cout << "Numero de pieza: " << factura1.obtenerNumeroPieza() << endl;
    cout << "Descripcion: " << factura1.obtenerDescripcionPieza() << endl;
    cout << "Cantidad: " << factura1.obtenerCantidad() << endl;
    cout << "Precio por articulo: $" << factura1.obtenerPrecioPorArticulo() << endl;
    cout << "Monto de la factura: $" << factura1.obtenerMontoFactura() << endl;

    cout << "\n";

    factura1.establecerCantidad(5);
    factura1.establecerPrecioPorArticulo(1200);

    cout << "Numero de pieza: " << factura1.obtenerNumeroPieza() << endl;
    cout << "Descripcion: " << factura1.obtenerDescripcionPieza() << endl;
    cout << "Cantidad: " << factura1.obtenerCantidad() << endl;
    cout << "Precio por articulo: $" << factura1.obtenerPrecioPorArticulo() << endl;
    cout << "Monto de la factura: $" << factura1.obtenerMontoFactura() << endl;

    cout << "\n";

    Factura factura2("67890", "Destornillador", -5, -100);
    cout << "Numero de pieza: " << factura2.obtenerNumeroPieza() << endl;
    cout << "Descripcion: " << factura2.obtenerDescripcionPieza() << endl;
    cout << "Cantidad: " << factura2.obtenerCantidad() << endl;
    cout << "Precio por articulo: $" << factura2.obtenerPrecioPorArticulo() << endl;
    cout << "Monto de la factura: $" << factura2.obtenerMontoFactura() << endl;

    return 0;
}
