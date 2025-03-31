#ifndef RESULTADOS_H
#define RESULTADOS_H

#include <vector>  // Agregado para evitar error con std::vector
#include <string>  // Para std::string
#include <iostream>
#include <matriz.h>

#define RONDAS 5
#define VOTOS_AFILIADOS 50

class resultados {
public:
    resultados();
    ~resultados();

    void imprimirMatrizLinea();
    void contarVotos(const std::vector<std::vector<std::vector<int>>> &matrizVotos, std::vector<std::vector<int>> &conteo, int numeroCandidatos);
    void imprimirResultados(std::vector<std::vector<int>> &conteo, std::vector<std::string> &nombre);
    void determinarGanadorYPerdedor(std::vector<std::vector<int>> &conteo, std::vector<std::string> &nombre);
};

#endif // RESULTADOS_H
