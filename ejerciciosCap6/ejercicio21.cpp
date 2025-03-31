#include <iostream>
using namespace std;
bool esPar(int numero){
    return numero % 2 == 0;
}
int main(){
    int numero;
    cout << "Ingrese numeros enteros (Ingrese 0 para salir):" << endl;
    while (true){
        cout << "Numero: ";
        cin >> numero;
        if(numero == 0) break;
        if(esPar(numero))
            cout << numero << " es par." << endl;
        else
            cout << numero << " es impar." << endl;
    }
}
