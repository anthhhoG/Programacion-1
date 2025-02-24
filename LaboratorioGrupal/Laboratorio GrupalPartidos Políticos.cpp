#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

//variables contantes
#define VOTOS_AFILIADOS 50
#define RONDAS 5

//prototipos
void llamarCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(vector<vector<vector<int>>> &matriz, int numeroCandidatos, int ronda);
void contarVotos(vector<vector<vector<int>>> &matriz, vector<vector<int>> &conteo, int numeroCandidatos);
void imprimirResultados(vector<vector<int>> &conteo, vector<string> &nombre);
void determinarGanadorYPerdedor(vector<vector<int>> &conteo, vector<string> &nombre);
void imprimirMatrizLinea();

// main
int main() {
    srand(getpid());
    llamarCiclo();
    return 0;
}

void llamarCiclo() {
    static int vecesEjecucion = 0;
    char opcion;
    bool repetir = true;
    int numeroCandidatos;

    cout << "Ingrese cantidad de candidatos " << endl;
    cin >> numeroCandidatos;
    cin.ignore();

    vector<vector<vector<int>>> matriz(numeroCandidatos, vector<vector<int>>(RONDAS, vector<int>(VOTOS_AFILIADOS)));
    vector<vector<int>> conteoVotos(numeroCandidatos, vector<int>(RONDAS, 0));
    vector<string> nombresCandidatos(numeroCandidatos);

    cout << "Ingrese los nombres de los candidatos:\n";
    int i;
    for ( i = 0; i < numeroCandidatos; i++) {
        cout << "Candidato " << i + 1 << ": ";
        getline(cin, nombresCandidatos[i]);
    }

    do {

        system("cls");
        cout << "\n*** Votaciones de partidos Politicos ***" << endl << endl;

        int ronda;
        for (ronda = 0; ronda < RONDAS; ronda++) {

            llenarMatriz(matriz, numeroCandidatos, ronda);
            contarVotos(matriz, conteoVotos, numeroCandidatos);
        }
        imprimirResultados(conteoVotos, nombresCandidatos);
        determinarGanadorYPerdedor(conteoVotos, nombresCandidatos);


        cout << "Ingresar n/s para salir o repetir las votaciones" << endl;
        cin >> opcion;
        repetir = (opcion == 's' || opcion == 'S');
        vecesEjecucion++;

    } while (repetir);
}

int busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

void llenarMatriz(vector<vector<vector<int>>> &matriz, int numeroCandidatos, int ronda) {
    int y, x;

    // Inicializar la matriz en ceros para la ronda actual
    for (y = 0; y < numeroCandidatos; y++) {
        fill(matriz[y][ronda].begin(), matriz[y][ronda].end(), 0);
    }

    // Asignar 50 votos aleatorios a diferentes candidatos
    for (int i = 0; i < VOTOS_AFILIADOS; i++) {
        int candidato = busquedaAleatorios(0, numeroCandidatos - 1);
        matriz[candidato][ronda][i] = 1;
    }
}

void contarVotos(vector<vector<vector<int>>> &matriz, vector<vector<int>> &conteo, int numeroCandidatos) {
    int y, x, ronda;
    for (y = 0; y < numeroCandidatos; y++) {
        for (ronda = 0; ronda < RONDAS; ronda++) {
            conteo[y][ronda] = 0;
            for (x = 0; x < VOTOS_AFILIADOS; x++) {
                conteo[y][ronda] += matriz[y][ronda][x];
            }
        }
    }
}

void imprimirMatrizLinea() {
    int x;
    cout << "+--------";
    for (x = 0; x <= RONDAS; x++) {
        cout << "+---------";
    }
    cout << "+\n";
}

void imprimirResultados(vector<vector<int>> &conteo, vector<string> &nombre) {
    size_t i;
    vector<int>totalVotos(nombre.size(), 0);

    for (i = 0; i < nombre.size(); i++){
        for (int ronda = 0; ronda < RONDAS; ronda++){
            totalVotos[i] += conteo[i][ronda];
        }
    }

    cout << "\nResultados de la votacion\n" << endl;
    cout << "Candidato   Ronda 1   Ronda 2   Ronda 3   Ronda 4   Ronda 5   Total" << endl;
    imprimirMatrizLinea();
    for (i = 0; i < nombre.size(); i++) {
        cout << "!" << setw(8) << nombre[i] << "!";
        for (int ronda = 0; ronda < RONDAS; ronda++) {
            cout << setw(8) << conteo[i][ronda] << " !";
        }
        cout << setw(8) << totalVotos[i] << " !";
        cout << endl;
        imprimirMatrizLinea();
    }

}


void determinarGanadorYPerdedor(vector<vector<int>> &conteo, vector<string> &nombre){

    size_t i;
    int ronda;
    vector<int>totalVotos(nombre.size(), 0);

    for (i = 0; i < nombre.size(); i++){
        for (ronda = 0; ronda < RONDAS; ronda++){
            totalVotos[i] += conteo[i][ronda];
        }
    }

    int maxVotos = totalVotos[0], minVotos = totalVotos[0];
    string ganador = nombre[0], perdedor = nombre[0];

    for (i = 1; i < nombre.size(); i++){
        if (totalVotos[i] > maxVotos){
            maxVotos = totalVotos[i];
            ganador = nombre[i];
        }
        if (totalVotos[i] < minVotos){
            minVotos = totalVotos[i];
            perdedor = nombre[i];
        }
    }
    cout << "\nEl candidato con mas votos es: " << ganador << " con " << maxVotos << " votos." << endl;
    cout << "El candidato con menos votos es: " << perdedor << " con " << minVotos << " votos.\n" << endl;

}

