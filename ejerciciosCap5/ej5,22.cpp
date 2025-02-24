#include <iostream>
using namespace std;

int main() {
    int x = 10, y = 3;
    int a = 5, b = 5, g = 10;
    int i = 3, j = 7;

    // Caso a)
    bool originalA = !(x < 5) && !(y >= 7);
    bool deMorganA = !(x < 5 || y >= 7);
    cout << "Caso a):" << endl;
    cout << "Original: " << originalA << endl;
    cout << "De Morgan: " << deMorganA << endl;
    cout << "Equivalente: " << (originalA == deMorganA) << endl << endl;

    // Caso b)
    bool originalB = !(a == b) || !(g != 5);
    bool deMorganB = !(a == b && g != 5);
    cout << "Caso b):" << endl;
    cout << "Original: " << originalB << endl;
    cout << "De Morgan: " << deMorganB << endl;
    cout << "Equivalente: " << (originalB == deMorganB) << endl << endl;

    // Caso c)
    bool originalC = !((x <= 8) && (y > 4));
    bool deMorganC = !(x <= 8) || !(y > 4);
    cout << "Caso c):" << endl;
    cout << "Original: " << originalC << endl;
    cout << "De Morgan: " << deMorganC << endl;
    cout << "Equivalente: " << (originalC == deMorganC) << endl << endl;

    // Caso d)
    bool originalD = !((i > 4) || (j <= 6));
    bool deMorganD = !(i > 4) && !(j <= 6);
    cout << "Caso d):" << endl;
    cout << "Original: " << originalD << endl;
    cout << "De Morgan: " << deMorganD << endl;
    cout << "Equivalente: " << (originalD == deMorganD) << endl << endl;

    return 0;
}
