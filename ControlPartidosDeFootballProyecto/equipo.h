#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
#include <string>
using namespace std;

class Equipo {
private:
    string nombre;
    int jugados;
    int ganados;
    int perdidos;
    int empatados;
    int puntos;
public:
    Equipo(string nombre);
    void actualizarEstadisticas(int golesFavor, int golesContra);
    void calcularPuntos();
    string getNombre() const;
    int getPuntos() const;
    int getJugados() const;
    int getGanados() const;
    int getPerdidos() const;
    int getEmpatados() const;
    double getPorcentaje() const;
    void mostrarDatos() const;
};

#endif
