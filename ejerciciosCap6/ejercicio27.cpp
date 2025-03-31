#include <iostream>
using namespace std;
double minimo(double a, double b, double c){
    return min(a, min(a, c));
}
int main(){
    double num1, num2, num3;
    cout << "Ingrese tres numeros de punto flotante: ";
    cin >> num1 >> num2 >> num3;
    cout << "El numero mas pequenio es: " << minimo(num1, num2, num3) << endl;
}
