#include <iostream>
#include <cmath>
using namespace std;
double hipotenusa(double ladoUno, double ladoDos){
    return sqrt(ladoUno * ladoUno + ladoDos * ladoDos);
}
int main(){
    double lados[][2] = {{3.0, 4.0}, {5.0, 12.0}, {8.0, 15.0}};
    for (int i = 0; i < 3; i++){
        double h = hipotenusa(lados[i][0], lados[i][1]);
        cout << "Triangulo" << i + 1 <<": Hipotenusa = " << h << endl;
    }
}
