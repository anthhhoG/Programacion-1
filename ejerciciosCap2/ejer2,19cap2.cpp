#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;

    cout << "Introduzca tres enteros distintos: ";
    cin >> num1 >> num2 >> num3;

    int suma = num1 + num2 + num3;

    double promedio = static_cast<double>(suma) / 3;

    int producto = num1 * num2 * num3;

    int menor = num1;
    if (num2 < menor) menor = num2;
    if (num3 < menor) menor = num3;

    int mayor = num1;
    if (num2 > mayor) mayor = num2;
    if (num3 > mayor) mayor = num3;

    cout << "La suma es " << suma << endl;
    cout << "El promedio es " << promedio << endl;
    cout << "El producto es " << producto << endl;
    cout << "El menor es " << menor << endl;
    cout << "El mayor es " << mayor << endl;

    return 0;
}
