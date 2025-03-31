#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>

#define RONDAS 5
#define VOTOS_AFILIADOS 50
using namespace std;

class matriz
{
    public:
        std::vector<std::vector<std::vector<int>>> matrizVotos;
        matriz();
        int busquedaAleatorios(int minimo, int maximo);
        void llenarMatriz(std::vector<std::vector<std::vector<int>>> &matriz, int numeroCandidatos, int ronda);
        ~matriz();



};

#endif // MATRIZ_H
