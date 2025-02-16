#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Introduzca tres enteros distintos de cero: ";
    cin >> a >> b >> c;

    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
        cout << "Estos valores pueden ser los lados de un triangulo recto." << endl;
    } else {
        cout << "Estos valores no pueden ser los lados de un triangulo recto." << endl;
    }

    return 0;
}
