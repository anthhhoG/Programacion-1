#include <iostream>
using namespace std;

void imprimirCuadrado(int lado, char caracterRelleno){
    for (int i = 0; i < lado; i ++){
        for (int j = 0; j < lado; j++){
            cout << caracterRelleno;
        }
        cout << endl;
    }
}
int main(){
    int lado;
    char caracter;
    cout << "Ingrese el tamanio del lado del cuadrado: ";
    cin  >> lado;
    cout << "Ingrese el caracter del relleno: ";
    cin >> caracter;
    cout << endl << "Cuadrado generado:" << endl;
    imprimirCuadrado(lado, caracter);
}
