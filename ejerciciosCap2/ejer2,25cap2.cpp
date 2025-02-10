#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "Introduzca dos enteros: ";
    cin >> num1 >> num2;

    if (num2 != 0 && num1 % num2 == 0) {
        cout << num1 << " es multiplo de " << num2 << endl;
    } else {
        cout << num1 << " no es multiplo de " << num2 << endl;
    }

    return 0;
}
