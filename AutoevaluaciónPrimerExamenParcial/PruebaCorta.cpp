// autoevaluacion Primer Parcial

#include <iostream>

using namespace std;

const int numAlumnos = 5;

void ingresarNotas(float notas[numAlumnos][4]) {
    for (int i = 0; i < numAlumnos; i++) {
        cout << "Ingrese las notas del alumno numero: " << i + 1 << endl;
        cout << "1P (20 pts): ";
        cin >> notas[i][0];
        cout << "2P (25 pts): ";
        cin >> notas[i][1];
        cout << "ACT (20 pts): ";
        cin >> notas[i][2];
        cout << "EF (35 pts): ";
        cin >> notas[i][3];
    }
}

void calcularNotasFinales(float notas[numAlumnos][4], float notaFinal[numAlumnos]) {
    for (int i = 0; i < numAlumnos; i++) {
        notaFinal[i] = notas[i][0] + notas[i][1] + notas[i][2] + notas[i][3];
    }
}

void calcularPorcentajes(float notaFinal[numAlumnos], float porcentajes[numAlumnos]) {
    for (int i = 0; i < numAlumnos; i++) {
        porcentajes[i] = (notaFinal[i] / 100) * 100;
    }
}

void mostrarResultados(float notaFinal[numAlumnos], float porcentajes[numAlumnos]) {
    cout << "\nResultados finales:" << endl;
    cout << "+--------------------------------------------+" << endl;
    for (int i = 0; i < numAlumnos; i++) {
        cout << "| Alumno " << i + 1 << " | NotaFinal: " << notaFinal[i] << " | Porcentaje: " << porcentajes[i] << "% |" << endl;
        cout << "+--------------------------------------------+" << endl;
    }
}

int main() {
    float notas[numAlumnos][4];
    float notaFinal[numAlumnos];
    float porcentajes[numAlumnos];

    ingresarNotas(notas);
    calcularNotasFinales(notas, notaFinal);
    calcularPorcentajes(notaFinal, porcentajes);
    mostrarResultados(notaFinal, porcentajes);

    return 0;
}
