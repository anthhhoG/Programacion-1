// Laboratorio Modulo 1
// Control sobre los partidos politicos
#include <iostream>   // Librerias usadas para el programa
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

// Función que genera un número aleatorio entre min y max
int generarVotoAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Función que muestra la tabla de resultados de votos por candidato
void mostrarTabla(const vector<string>& candidatos, const vector<vector<int>>& votos) {
    cout << "\nTabla de resultados:\n";
    cout << "Candidato\tRonda 1\tRonda 2\tRonda 3\tRonda 4\tRonda 5\tTotal\n";

    // Recorre cada candidato para mostrar sus votos
    for (size_t i = 0; i < candidatos.size(); i++) {
        cout << candidatos[i] << "\t";
        int total = 0;  // Variable para almacenar el total de votos por candidato

        // Recorre las 5 rondas de votación para el candidato actual
        for (int j = 0; j < 5; j++) {
            cout << votos[i][j] << "\t";  // Muestra los votos en la ronda j
            total += votos[i][j];         // Suma los votos al total del candidato
        }
        cout << total << endl;  // Muestra el total de votos del candidato
    }
}

// Función que calcula y muestra los resultados finales de la elección
void calcularResultados(const vector<string>& candidatos, const vector<vector<int>>& votos) {
    vector<int> totales(candidatos.size(), 0);  // Vector para almacenar el total de votos de cada candidato

    // Suma los votos de cada ronda para cada candidato
    for (size_t i = 0; i < candidatos.size(); i++) {
        for (int j = 0; j < 5; j++) {
            totales[i] += votos[i][j];
        }
    }

    // Variables para almacenar los índices del ganador y el perdedor
    int indiceGanador = 0, indicePerdedor = 0;

    // Busca al candidato con más votos (ganador) y al de menos votos (perdedor)
    for (size_t i = 1; i < candidatos.size(); i++) {
        if (totales[i] > totales[indiceGanador]) {
            indiceGanador = i;  // Actualiza el índice del ganador
        }
        if (totales[i] < totales[indicePerdedor]) {
            indicePerdedor = i;  // Actualiza el índice del perdedor
        }
    }

    // Muestra el resultado final de la elección
    cout << "\nEl ganador es: " << candidatos[indiceGanador] << " con " << totales[indiceGanador] << " votos.\n";
    cout << "El candidato con menos votos es: " << candidatos[indicePerdedor] << " con " << totales[indicePerdedor] << " votos.\n";
}

// Función principal del programa
int main() {
    srand(time(0));  // Inicializa la semilla para números aleatorios

    vector<string> candidatos;  // Vector para almacenar los nombres de los candidatos
    vector<vector<int>> votos;  // Matriz para almacenar los votos de cada ronda
    int numCandidatos;

    // Solicita al usuario el número de candidatos
    cout << "Ingrese el numero de candidatos: ";
    cin >> numCandidatos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpia el buffer de entrada

    // Solicita al usuario el nombre de cada candidato y los guarda en el vector
    for (int i = 0; i < numCandidatos; i++) {
        string nombre;
        cout << "Ingrese el nombre del candidato " << i + 1 << ": ";
        getline(cin, nombre);       // Lee el nombre completo del candidato
        candidatos.push_back(nombre);  // Añade el nombre al vector de candidatos
    }

    // Inicializa la matriz de votos con ceros (numCandidatos x 5 rondas)
    votos.resize(numCandidatos, vector<int>(5, 0));

    // Simula la votación para 5 rondas y 50 afiliados por ronda
    for (int ronda = 0; ronda < 5; ronda++) {
        for (int afiliado = 0; afiliado < 50; afiliado++) {
            int voto = generarVotoAleatorio(0, numCandidatos - 1);  // Genera un voto aleatorio
            votos[voto][ronda]++;  // Aumenta el voto al candidato correspondiente
        }
    }

    // Muestra la tabla de resultados de votos
    mostrarTabla(candidatos, votos);

    // Calcula y muestra los resultados finales
    calcularResultados(candidatos, votos);

    // Pregunta si el usuario desea realizar otra elección
    char opcion;
    cout << "Desea realizar otra eleccion? (s/n): ";
    cin >> opcion;

    // Si el usuario elige 's' o 'S', llama a main() para reiniciar el proceso
    if (opcion == 's' || opcion == 'S') {
        main();
    } else {
        cout << "Programa finalizado.\n";  // Finaliza el programa si elige cualquier otra opción
    }

    return 0;
}
