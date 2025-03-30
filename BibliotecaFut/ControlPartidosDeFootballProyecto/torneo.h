#ifndef TORNEO_H
#define TORNEO_H

#include "Equipo.h"
#include "GenerarGoles.h"
#include <vector>
using namespace std;

class Torneo {
private:
    vector<Equipo> equipos;
    int ida[6][6];
    int vuelta[6][6];
public:
    Torneo(vector<string> nombresEquipos);
    void jugarPartidos();
    void mostrarTabla();
    void mostrarResultados();
};

#endif
