#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;


    x = fabs(7.5);
    cout << "a) " << x << endl;


    x = floor(7.5);
    cout << "b) " << x << endl;


    x = fabs(0.0);
    cout << "c) " << x << endl;


    x = ceil(0.0);
    cout << "d) " << x << endl;


    x = fabs(-6.4);
    cout << "e) " << x << endl;


    x = ceil(-6.4);
    cout << "f) " << x << endl;


    x = ceil(-fabs(-8 + floor(-5.5)));
    cout << "g) " << x << endl;

    return 0;
}

