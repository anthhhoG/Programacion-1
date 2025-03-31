#include <iostream>
#include <cmath>
using namespace std;

bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool esPrimoOptimizado(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cout << "Numeros primos entre 2 y 10,000 (metodo no optimizado):" <<endl;
    for (int i = 2; i <= 10000; i++) {
        if (esPrimo(i)) {
            cout << i << " ";
        }
    }

    cout << "\n\nNumeros primos entre 2 y 10,000 (metodo optimizado):"<<endl;
    for (int i = 2; i <= 10000; i++) {
        if (esPrimoOptimizado(i)) {
            cout << i << " ";
        }
    }
}
