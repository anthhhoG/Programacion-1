//modificacion librerías Kev L. 26/03/2025
#include "resultados.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

resultados::resultados(){}

//ctor;
void resultados::imprimirMatrizLinea() {
    cout << "+--------";
    for (int x = 0; x <= RONDAS; x++) {
        cout << "+---------";
    }
    cout << "+\n";
}

void resultados::contarVotos(const std::vector<std::vector<std::vector<int>>> &matrizVotos, std::vector<std::vector<int>> &conteo, int numeroCandidatos) {
    for (int y = 0; y < numeroCandidatos; y++) {
        for (int ronda = 0; ronda < RONDAS; ronda++) {
            conteo[y][ronda] = 0;
            for (int x = 0; x < VOTOS_AFILIADOS; x++) {
                conteo[y][ronda] += matrizVotos[y][ronda][x];
            }
        }
    }
}

void resultados::imprimirResultados(std::vector<std::vector<int>> &conteo, std::vector<std::string> &nombre) {
    std::vector<int> totalVotos(nombre.size(), 0);
    for (size_t i = 0; i < nombre.size(); i++) {
        for (int ronda = 0; ronda < RONDAS; ronda++) {
            totalVotos[i] += conteo[i][ronda];
        }
    }
    cout << "\nResultados de la votacion\n" << endl;
    cout << "Candidato   Ronda 1   Ronda 2   Ronda 3   Ronda 4   Ronda 5   Total" << endl;
    imprimirMatrizLinea();
    for (size_t i = 0; i < nombre.size(); i++) {
        cout << "!" << setw(8) << nombre[i] << "!";
        for (int ronda = 0; ronda < RONDAS; ronda++) {
            cout << setw(8) << conteo[i][ronda] << " !";
        }
        cout << setw(8) << totalVotos[i] << " !\n";
        imprimirMatrizLinea();
    }
}

void resultados::determinarGanadorYPerdedor(vector<vector<int>> &conteo, vector<string> &nombre) {
    vector<int> totalVotos(nombre.size(), 0);
    for (size_t i = 0; i < nombre.size(); i++) {
        for (int ronda = 0; ronda < RONDAS; ronda++) {
            totalVotos[i] += conteo[i][ronda];
        }
    }
    int maxVotos = totalVotos[0], minVotos = totalVotos[0];
    string ganador = nombre[0], perdedor = nombre[0];
    for (size_t i = 1; i < nombre.size(); i++) {
        if (totalVotos[i] > maxVotos) {
            maxVotos = totalVotos[i];
            ganador = nombre[i];
        }
        if (totalVotos[i] < minVotos) {
            minVotos = totalVotos[i];
            perdedor = nombre[i];
        }
    }
    cout << "\nEl candidato con mas votos es: " << ganador << " con " << maxVotos << " votos." << endl;
    cout << "El candidato con menos votos es: " << perdedor << " con " << minVotos << " votos.\n" << endl;
}

resultados::~resultados() {}
