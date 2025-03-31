#include <iostream>
using namespace std;

void torresHanoi(int discos, int agujaOrigen, int agujaDestino, int agujaTemp) {
    if (discos == 1) {
        cout << agujaOrigen << " → " << agujaDestino << endl;
    } else {
        torresHanoi(discos - 1, agujaOrigen, agujaTemp, agujaDestino);
        cout << agujaOrigen << " → " << agujaDestino << endl;
        torresHanoi(discos - 1, agujaTemp, agujaDestino, agujaOrigen);
    }
}

int main() {
    int discos;
    cout << "Ingrese el numero de discos: ";
    cin >> discos;

    cout << "Solucion para " << discos << " discos:" << endl;
    torresHanoi(discos, 1, 3, 2);

    return 0;
}
