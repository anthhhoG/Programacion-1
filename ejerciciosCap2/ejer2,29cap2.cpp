#include <iostream>
using namespace std;

int main() {
    cout << "entero\tcuadrado\tcubo" << endl;

    for (int i = 0; i <= 10; ++i) {
        int cuadrado = i * i;
        int cubo = i * i * i;
        cout << i << "\t" << cuadrado << "\t\t" << cubo << endl;
    }

    return 0;
}
