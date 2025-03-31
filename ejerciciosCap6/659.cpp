#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

int generarNumero(int nivel) {
    int limite_superior = pow(10, nivel); //powwww
    return rand() % (limite_superior - 1) + 1;
}

void imprimirComentario(bool correcto) {
    default_random_engine motor(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> intAleatorio(1, 4);
    unsigned int numero = intAleatorio(motor);

    if (correcto) {
        switch (numero) {
            case 1: cout << "Muy bien!" << endl; break;
            case 2: cout << "¡Buen trabajo! Nítido" << endl; break;
            case 3: cout << "Sigue así" << endl; break;
            case 4: cout << "Excelente!" << endl; break;
        }
    } else {
        switch (numero) {
            case 1: cout << "No. Por favor intenta de nuevo" << endl; break;
            case 2: cout << "Incorrecto. No te rindas" << endl; break;
            case 3: cout << "Intentalo otra vez" << endl; break;
            case 4: cout << "Sigue practicando" << endl; break;
        }
    }
}

int main() {
    srand(time(0)); // Inicializar generador de números aleatorios
    int nivel, respuestas_correctas = 0;
    const int total_preguntas = 10;

    cout << "Bienvenido al programa de multiplicacion asistida" << endl;
    cout << "Ingrese el nivel de dificultad (1, 2, 3, ...): ";
    cin >> nivel;

    for (int i = 0; i < total_preguntas; i++) {
        int num1 = generarNumero(nivel);
        int num2 = generarNumero(nivel);
        int respuesta_correcta = num1 * num2;
        int respuesta_usuario;

        cout << "¿Cuanto es " << num1 << " x " << num2 << "? ";
        cin >> respuesta_usuario;

        if (respuesta_usuario == respuesta_correcta) {
            imprimirComentario(true);
            respuestas_correctas++;
        } else {
            cout << "Incorrecto. La respuesta correcta es " << respuesta_correcta << "." << endl;
            imprimirComentario(false);
        }
    }

    float porcentaje = (respuestas_correctas / (float)total_preguntas) * 100;
    cout << "Tu porcentaje de aciertos es: " << porcentaje << "%" << endl;

    if (porcentaje < 75) {
        cout << "Por favor pida ayuda adicional a su profesor." << endl;
    } else {
        cout << "¡Felicidades, está listo para pasar al siguiente nivel!" << endl;
    }

    return 0;
}
