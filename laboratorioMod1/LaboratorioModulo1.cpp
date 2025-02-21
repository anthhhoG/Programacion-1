// Laboratorio Modulo 1
// Control sobre los partidos politicos
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

//  número aleatorio
int generarVotoAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// muestra la tabla de resultados de votos
void mostrarTabla(const vector<string>& candidatos, const vector<vector<int>>& votos) {
    cout << "\nTabla de resultados:\n";
    cout << "Candidato\tRonda 1\tRonda 2\tRonda 3\tRonda 4\tRonda 5\tTotal\n";

    // mostrar sus votos
    for (size_t i = 0; i < candidatos.size(); i++) {
        cout << candidatos[i] << "\t";
        int total = 0;   // total de votos

        // Recorre rondas
        for (int j = 0; j < 5; j++) {
            cout << votos[i][j] << "\t";
            total += votos[i][j];         // Suma votos al total del candidato
        }
        cout << total << endl;  // total de votos del candidato
    }
}

// calcula y muestra los resultados
void calcularResultados(const vector<string>& candidatos, const vector<vector<int>>& votos) {
    vector<int> totales(candidatos.size(), 0);  // Vector para almacenar el total de votos de cada candidato

    // Suma votos de cada ronda para cada candidato
    for (size_t i = 0; i < candidatos.size(); i++) {
        for (int j = 0; j < 5; j++) {
            totales[i] += votos[i][j];
        }
    }

    // almacena los índices del ganador y el perdedor
    int indiceGanador = 0, indicePerdedor = 0;

    // Busca al candidato con más votos y menos votos
    for (size_t i = 1; i < candidatos.size(); i++) {
        if (totales[i] > totales[indiceGanador]) {
            indiceGanador = i;  // Actualiza el índice del ganador
        }
        if (totales[i] < totales[indicePerdedor]) {
            indicePerdedor = i;  // Actualiza el índice del perdedor
        }
    }

    // Muestra el resultado final
    cout << "\nEl ganador es: " << candidatos[indiceGanador] << " con " << totales[indiceGanador] << " votos.\n";
    cout << "El candidato con menos votos es: " << candidatos[indicePerdedor] << " con " << totales[indicePerdedor] << " votos.\n";
}

// Función principal
int main() {
    srand(time(0));  // semilla para números aleatorios

    vector<string> candidatos;  // Vector para los nombres de los candidatos
    vector<vector<int>> votos;  // Matriz para los votos de cada ronda
    int numCandidatos;

    // pide el número de candidatos
    cout << "Ingrese el numero de candidatos: ";
    cin >> numCandidatos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpia el buffer de entrada

    // Solicita el nombre de cada candidato y despues al vector
    for (int i = 0; i < numCandidatos; i++) {
        string nombre;
        cout << "Ingrese el nombre del candidato " << i + 1 << ": ";
        getline(cin, nombre);       // Lee el nombre
        candidatos.push_back(nombre);  // Añade el nombre
    }

    // Inicializa la matriz de votos
    votos.resize(numCandidatos, vector<int>(5, 0));

    // Simula la votación
    for (int ronda = 0; ronda < 5; ronda++) {
        for (int afiliado = 0; afiliado < 50; afiliado++) {
            int voto = generarVotoAleatorio(0, numCandidatos - 1);  // Genera un voto
            votos[voto][ronda]++;  // Aumenta el voto
        }
    }

    // Muestra resultados
    mostrarTabla(candidatos, votos);

    // muestra los resultados finales
    calcularResultados(candidatos, votos);

    char opcion;
    cout << "Desea realizar otra eleccion? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        main();
    } else {
        cout << "Programa finalizado.\n";
    }

    return 0;
}
