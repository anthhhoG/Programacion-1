#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

int main() {
    cout << "Decimal" << setw(10) << "Binario" << setw(10) << "Octal" << setw(15) << "Hexadecimal" << endl;

    for (int i = 1; i <= 256; ++i) {
        cout << dec << setw(7) << i;
        cout << setw(10) << bitset<9>(i).to_string().substr(bitset<9>(i).to_string().find('1'));
        cout << oct << setw(10) << i;
        cout << hex << setw(10) << i << endl;
    }

    return 0;
}
