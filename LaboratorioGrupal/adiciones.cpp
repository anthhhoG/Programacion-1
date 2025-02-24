#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

// Almacenar datos de equipo
struct Equipo {
    string nombre;
    int jugados = 0;
    int ganados = 0;
    int perdidos = 0;
    int empatados = 0;
    int puntos = 0;
};

// Generar goles aleatorios
int generarGoles() {
    return rand() % 11;
}

// Ordenar equipos por puntos
void ordenarEquipos(Equipo equipos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (equipos[j].puntos < equipos[j + 1].puntos) {
                swap(equipos[j], equipos[j + 1]);
            }
        }
    }
}

// Imprimir tabla de posiciones
void imprimirTabla(Equipo equipos[], int n) {
    cout << "\nTabla de POSICIONES:\n";
    cout << setfill('-') << setw(90) << "-" << "\n";
    cout << setfill(' ');
    cout << left
         << "| " << setw(15) << "Equipo"
         << "| " << setw(8)  << "JUGADOS"
         << "| " << setw(8)  << "GANADOS"
         << "| " << setw(8)  << "PERDIDOS"
         << "| " << setw(9)  << "EMPATADOS"
         << "| " << setw(8)  << "PUNTOS" << " |\n";
    cout << setfill('-') << setw(90) << "-" << "\n";
    cout << setfill(' ');

    for (int i = 0; i < n; i++) {
        cout << left
             << "| " << setw(15) << equipos[i].nombre
             << "| " << setw(8)  << equipos[i].jugados
             << "| " << setw(8)  << equipos[i].ganados
             << "| " << setw(8)  << equipos[i].perdidos
             << "| " << setw(9)  << equipos[i].empatados
             << "| " << setw(8)  << equipos[i].puntos << " |\n";
        cout << setfill('-') << setw(90) << "-" << "\n";
        cout << setfill(' ');
    }
}

// Imprimir resultados de partidos
void imprimirResultados(Equipo equipos[], int ida[6][6], int vuelta[6][6]) {
    cout << "\nResultados PARTIDOS IDA:\n";
    cout << setfill('-') << setw(60) << "-" << "\n";
    cout << setfill(' ');
    cout << left
         << "| " << setw(15) << "Local"
         << "| " << setw(15) << "Visitante"
         << "| " << setw(15) << "Resultado" << " |\n";
    cout << setfill('-') << setw(60) << "-" << "\n";
    cout << setfill(' ');

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            string resultado = to_string(ida[i][j]) + "-" + to_string(ida[j][i]);
            cout << left
                 << "| " << setw(15) << equipos[i].nombre
                 << "| " << setw(15) << equipos[j].nombre
                 << "| " << setw(15) << resultado << " |\n";
        }
    }
    cout << setfill('-') << setw(60) << "-" << "\n";

    cout << "\nResultados PARTIDOS VUELTA:\n";
    cout << setfill('-') << setw(60) << "-" << "\n";
    cout << setfill(' ');
    cout << left
         << "| " << setw(15) << "Local"
         << "| " << setw(15) << "Visitante"
         << "| " << setw(15) << "Resultado" << " |\n";
    cout << setfill('-') << setw(60) << "-" << "\n";
    cout << setfill(' ');

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            string resultado = to_string(vuelta[j][i]) + "-" + to_string(vuelta[i][j]);
            cout << left
                 << "| " << setw(15) << equipos[j].nombre
                 << "| " << setw(15) << equipos[i].nombre
                 << "| " << setw(15) << resultado << " |\n";
        }
    }
    cout << setfill('-') << setw(60) << "-" << "\n";
}

int main() {
    srand(time(0));

    Equipo equipos[6];
    int ida[6][6] = {0};    // Matriz para partidos de ida
    int vuelta[6][6] = {0}; // Matriz para partidos de vuelta

    // Ingreso de los nombres
    cout << "Ingrese los nombres de los 6 equipos:\n";
    for (int i = 0; i < 6; i++) {
        cout << "Equipo " << i + 1 << ": ";
        cin >> equipos[i].nombre;
    }

    // Generar partidos de ida
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            int golesLocalIda = generarGoles();
            int golesVisitanteIda = generarGoles();
            ida[i][j] = golesLocalIda;
            ida[j][i] = golesVisitanteIda;

            equipos[i].jugados++;
            equipos[j].jugados++;

            if (golesLocalIda > golesVisitanteIda) {
                equipos[i].ganados++;
                equipos[j].perdidos++;
            } else if (golesLocalIda < golesVisitanteIda) {
                equipos[j].ganados++;
                equipos[i].perdidos++;
            } else {
                equipos[i].empatados++;
                equipos[j].empatados++;
            }
        }
    }

    // Generar partidos de vuelta
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            int golesLocalVuelta = generarGoles();
            int golesVisitanteVuelta = generarGoles();
            vuelta[i][j] = golesLocalVuelta;
            vuelta[j][i] = golesVisitanteVuelta;

            equipos[i].jugados++;
            equipos[j].jugados++;

            if (golesLocalVuelta > golesVisitanteVuelta) {
                equipos[i].ganados++;
                equipos[j].perdidos++;
            } else if (golesLocalVuelta < golesVisitanteVuelta) {
                equipos[j].ganados++;
                equipos[i].perdidos++;
            } else {
                equipos[i].empatados++;
                equipos[j].empatados++;
            }
        }
    }

    // Calcular puntos
    for (int i = 0; i < 6; i++) {
        equipos[i].puntos = (equipos[i].ganados * 3) + equipos[i].empatados;
    }

    // Ordenar por puntos
    ordenarEquipos(equipos, 6);

    // Imprimir resultados
    imprimirTabla(equipos, 6);
    imprimirResultados(equipos, ida, vuelta);

    cout << "\nEl equipo GANADOR es: " << equipos[0].nombre << endl;
    cout << "El equipo que BAJA CATEGORIA es: " << equipos[5].nombre << endl;

    // Opción de repetir
    char respuesta;
    cout << "\n¿Desea volver a generar otro campeonato? (s/n): ";
    cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S') {
        main();
    }

    return 0;
}
