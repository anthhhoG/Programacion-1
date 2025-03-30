#include "Equipo.h"

Equipo::Equipo(string nombre) : nombre(nombre), jugados(0), ganados(0), perdidos(0), empatados(0), puntos(0) {}

void Equipo::actualizarEstadisticas(int golesFavor, int golesContra) {
    jugados++;
    if (golesFavor > golesContra) {
        ganados++;
    } else if (golesFavor < golesContra) {
        perdidos++;
    } else {
        empatados++;
    }
    calcularPuntos();
}

void Equipo::calcularPuntos() {
    puntos = (ganados * 3) + empatados;
}

string Equipo::getNombre() const {
    return nombre;
}

int Equipo::getPuntos() const {
    return puntos;
}

int Equipo::getJugados() const { return jugados; }
int Equipo::getGanados() const { return ganados; }
int Equipo::getPerdidos() const { return perdidos; }
int Equipo::getEmpatados() const { return empatados; }

double Equipo::getPorcentaje() const {
    return (jugados > 0) ? (static_cast<double>(puntos) / (jugados * 3)) * 100 : 0.0;
}

void Equipo::mostrarDatos() const {
    cout << nombre << " | Jugados: " << jugados << " | Ganados: " << ganados
         << " | Perdidos: " << perdidos << " | Empatados: " << empatados
         << " | Puntos: " << puntos << " | % Rendimiento: " << getPorcentaje() << "%" << endl;
}
