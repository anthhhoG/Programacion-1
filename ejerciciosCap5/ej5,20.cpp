#include <iostream>
using namespace std;

int main() {
    cout << "Triples de Pitagoras (lado1, lado2, hipotenusa) no mayores a 500:" << endl;

    for (int lado1 = 1; lado1 <= 500; ++lado1) {
        for (int lado2 = 1; lado2 <= 500; ++lado2) {
            for (int hipotenusa = 1; hipotenusa <= 500; ++hipotenusa) {
                if (lado1 * lado1 + lado2 * lado2 == hipotenusa * hipotenusa) {
                    cout << "(" << lado1 << ", " << lado2 << ", " << hipotenusa << ")" << endl;
                }
            }
        }
    }

    return 0;
}
