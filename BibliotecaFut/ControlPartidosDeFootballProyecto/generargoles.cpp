#include "GenerarGoles.h"

int GenerarGoles::generar() {
    return rand() % 11;
}

// Torneo.h
#ifndef TORNEO_H
#define TORNEO_H

#include "Equipo.h"
#include "GenerarGoles.h"
#include <vector>
using namespace std;

class Torneo {
private:
    vector<Equipo> equipos;
public:
    Torneo(vector<string> nombresEquipos);
    void jugarPartidos();
    void mostrarTabla();
};

#endif
