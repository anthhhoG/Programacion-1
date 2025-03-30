#include "Torneo.h"
#include <algorithm>
#include <iomanip>

Torneo::Torneo(vector<string> nombresEquipos) {
    for (const string &nombre : nombresEquipos) {
        equipos.push_back(Equipo(nombre));
    }
}

void Torneo::jugarPartidos() {
    for (size_t i = 0; i < equipos.size(); i++) {
        for (size_t j = i + 1; j < equipos.size(); j++) {
            int golesLocal = GenerarGoles::generar();
            int golesVisitante = GenerarGoles::generar();
            ida[i][j] = golesLocal;
            ida[j][i] = golesVisitante;
            equipos[i].actualizarEstadisticas(golesLocal, golesVisitante);
            equipos[j].actualizarEstadisticas(golesVisitante, golesLocal);

            int golesLocalVuelta = GenerarGoles::generar();
            int golesVisitanteVuelta = GenerarGoles::generar();
            vuelta[j][i] = golesLocalVuelta;
            vuelta[i][j] = golesVisitanteVuelta;
            equipos[i].actualizarEstadisticas(golesLocalVuelta, golesVisitanteVuelta);
            equipos[j].actualizarEstadisticas(golesVisitanteVuelta, golesLocalVuelta);
        }
    }
    sort(equipos.begin(), equipos.end(), [](const Equipo &a, const Equipo &b) {
        return a.getPuntos() > b.getPuntos();
    });
}

void Torneo::mostrarTabla() {
    cout << "\nTabla de POSICIONES:\n";
    cout << "--------------------------------------------\n";
    for (const auto &equipo : equipos) {
        equipo.mostrarDatos();
    }
}

void Torneo::mostrarResultados() {
    cout << "\nResultados Partidos IDA:\n";
    for (size_t i = 0; i < equipos.size(); i++) {
        for (size_t j = i + 1; j < equipos.size(); j++) {
            cout << equipos[i].getNombre() << " " << ida[i][j] << " - " << ida[j][i] << " " << equipos[j].getNombre() << endl;
        }
    }
    cout << "\nResultados Partidos VUELTA:\n";
    for (size_t i = 0; i < equipos.size(); i++) {
        for (size_t j = i + 1; j < equipos.size(); j++) {
            cout << equipos[j].getNombre() << " " << vuelta[j][i] << " - " << vuelta[i][j] << " " << equipos[i].getNombre() << endl;
        }
    }
}
