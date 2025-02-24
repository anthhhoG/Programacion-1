#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Entero" << setw(15) << "Factorial" << endl;

    for (int i = 1; i <= 5; ++i) {
        long long factorial = 1;
        for (int j = 1; j <= i; ++j) {
            factorial *= j;
        }
        cout << setw(5) << i << setw(15) << factorial << endl;
    }

    return 0;
}
