//Modificaci�n 26/03/2025 Implementacion de librer�as kevin L. y modificaci�n de ciclo e instancias correctas de las clases
#include "ciclo.h"
#include "matriz.h"
#include "resultados.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <vector>

ciclo::ciclo():vecesEjecucion(0), repetir(true){}

    //ctor
    void ciclo::llamarCiclo() {
        opcion = ' ';
        repetir = true;
        int numeroCandidatos;

        matriz matriz;
        resultados resultados;

        cout << "Ingrese cantidad de candidatos " << endl;
        cin >> numeroCandidatos;
        cin.ignore();

        vector<vector<vector<int>>> matrizVotos(numeroCandidatos, vector<vector<int>>(RONDAS, vector<int>(VOTOS_AFILIADOS)));
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
                matriz.llenarMatriz(matrizVotos, numeroCandidatos, ronda);
            }
            resultados.contarVotos(matrizVotos, conteoVotos, numeroCandidatos);
            resultados.imprimirResultados(conteoVotos, nombresCandidatos);
            resultados.determinarGanadorYPerdedor(conteoVotos, nombresCandidatos);


            cout << "Ingresar n/s para salir o repetir las votaciones" << endl;
            cin >> opcion;
            repetir = (opcion == 's' || opcion == 'S');
            vecesEjecucion++;

        } while (repetir);
    }


ciclo::~ciclo()
{
    //dtor
}
