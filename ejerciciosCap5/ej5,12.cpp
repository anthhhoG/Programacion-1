#include <iostream>
using namespace std;

int main() {
    int n = 10; // Número de filas

    // Patrón (a)
    cout << "A)" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;

    // Patrón (b)
    cout << "B)" << endl;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;

    // Patrón (c)
    cout << "C)" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cout << ' ';
        }
        for (int k = i; k <= n; k++) {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;

    // Patrón (d)
    cout << "D)" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            cout << ' ';
        }
        for (int k = 1; k <= i; k++) {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
