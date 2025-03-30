#include "Torneo.h"

int main() {
    srand(time(0));
    char respuesta;
    do {
        vector<string> nombres;
        cout << "Ingrese los nombres de los 6 equipos:\n";
        for (int i = 0; i < 6; i++) {
            string nombre;
            cout << "Equipo " << i + 1 << ": ";
            cin >> nombre;
            nombres.push_back(nombre);
        }

        Torneo torneo(nombres);
        torneo.jugarPartidos();
        torneo.mostrarResultados();
        torneo.mostrarTabla();

        cout << "\n¿Desea generar otro campeonato? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');

    return 0;
}
