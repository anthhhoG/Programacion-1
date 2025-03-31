#include <iostream>
#include <random>


using namespace std;


void imprimirComentario();

void imprimirComentario() {

    default_random_engine motor(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> intAleatorio(1, 4); //esta en el libro


    unsigned int numero = intAleatorio(motor);


    switch (numero) {
        case 1:
            cout << "Muy bien!" << endl;
            break;
        case 2:
            cout << "no. Por favor intenta de nuevo" << endl;
            break;
        case 3:
            cout << "¡Buen trabajo!! nitido" << endl;
            break;
        case 4:
            cout << "No te rindas" << endl;
            break;
        default:
            cout << "Sigue asi " << endl;
            break;
    }
}

int main() {
    imprimirComentario();
    return 0;
}
