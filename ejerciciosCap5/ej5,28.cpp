#include <iostream>
using namespace std;

int main() {
    for (int dia = 1; dia <= 12; ++dia) {
        cout << "En el ";
        switch (dia) {
            case 1: cout << "primer"; break;
            case 2: cout << "segundo"; break;
            case 3: cout << "tercer"; break;
            case 4: cout << "cuarto"; break;
            case 5: cout << "quinto"; break;
            case 6: cout << "sexto"; break;
            case 7: cout << "septimo"; break;
            case 8: cout << "octavo"; break;
            case 9: cout << "noveno"; break;
            case 10: cout << "decimo"; break;
            case 11: cout << "undecimo"; break;
            case 12: cout << "duodecimo"; break;
        }
        cout << " dia de Navidad, mi amor me dio:" << endl;

        for (int regalo = dia; regalo >= 1; --regalo) {
            switch (regalo) {
                case 1:
                    if (dia == 1) {
                        cout << "Una perdiz en un peral." << endl;
                    } else {
                        cout << "Y una perdiz en un peral." << endl;
                    }
                    break;
                case 2: cout << "Dos tortolas," << endl; break;
                case 3: cout << "Tres gallinas francesas," << endl; break;
                case 4: cout << "Cuatro pajaros piando," << endl; break;
                case 5: cout << "Cinco anillos dorados," << endl; break;
                case 6: cout << "Seis ocas empollando," << endl; break;
                case 7: cout << "Siete cisnes nadando," << endl; break;
                case 8: cout << "Ocho sirvientas ordenando," << endl; break;
                case 9: cout << "Nueve damas bailando," << endl; break;
                case 10: cout << "Diez senores saltando," << endl; break;
                case 11: cout << "Once gaiteros tocando," << endl; break;
                case 12: cout << "Doce tamborileros tocando," << endl; break;
            }
        }
        cout << endl;
    }

    return 0;
}
