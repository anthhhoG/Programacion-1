#include <iostream>
using namespace std;

unsigned long fibonacci(unsigned long n) {
    if (n == 0 || n == 1) {
        return n;
    }

    unsigned long a = 0, b = 1, c;
    for (unsigned long i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    for (unsigned int contador = 0; contador <= 10; ++contador) {
        cout << "fibonacci(" << contador << ") = " << fibonacci(contador) << endl;
    }

    cout << "\nfibonacci(20) = " << fibonacci(20) << endl;
    cout << "fibonacci(30) = " << fibonacci(30) << endl;
    cout << "fibonacci(35) = " << fibonacci(35) << endl;

    return 0;
}
