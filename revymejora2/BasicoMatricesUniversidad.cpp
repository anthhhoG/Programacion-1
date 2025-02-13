#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

#define NUMERO_ALUMNOS 5
#define NUMERO_MATERIAS 5
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], string alumnos[NUMERO_ALUMNOS], string nombreFacultad);
void resultadosFinales(int repeticionProceso, string mejorFacultad, float mejorFacultadPromedio, string alumnos[NUMERO_ALUMNOS],
                       float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1],
                       float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1],
                       float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1],
                       int &contadorIngenieria, int &contadorArquitectura, int &contadorAdministracion);

struct Estudiante {
    string nombre;
    float promedio;
    string facultad;
};

bool compararEstudiantes(const Estudiante &a, const Estudiante &b) {
    return a.promedio > b.promedio;
}

int main() {
    srand(getpid());
    llamaCiclo();
    return 0;
}

void llamaCiclo() {
    static int vecesEjecucion = 0;
    static int contadorIngenieria = 0;
    static int contadorArquitectura = 0;
    static int contadorAdministracion = 0;

    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    char opcion;
    bool repetir = true;
    float promedio_facultad_1, promedio_facultad_2, promedio_facultad_3;
    string alumnos[NUMERO_ALUMNOS] = {"Carlos", "Luis", "Maria", "Pedro", "Juan"};

    do {
        system("cls");
        promedio_facultad_1 = 0;
        promedio_facultad_2 = 0;
        promedio_facultad_3 = 0;

        cout << "*** Comparativo de Facultades ***" << endl << endl;
        llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria");
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");

        string mejorFacultad;
        float mejorFacultadPromedio;

        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3) {
            mejorFacultad = "Facultad de Ingenieria";
            mejorFacultadPromedio = promedio_facultad_1;
            contadorIngenieria++;
        } else if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3) {
            mejorFacultad = "Facultad de Arquitectura";
            mejorFacultadPromedio = promedio_facultad_2;
            contadorArquitectura++;
        } else if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1) {
            mejorFacultad = "Facultad de Administracion";
            mejorFacultadPromedio = promedio_facultad_3;
            contadorAdministracion++;
        } else {
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
        }

        // Llamamos a la función de resultados finales con los datos actualizados
        resultadosFinales(vecesEjecucion, mejorFacultad, mejorFacultadPromedio, alumnos,
                          matriz_facultad_1, matriz_facultad_2, matriz_facultad_3,
                          contadorIngenieria, contadorArquitectura, contadorAdministracion);

        vecesEjecucion++;
        cout << "\nNumero de veces que se ha ejecutado el ciclo: " << vecesEjecucion << endl;

        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        repetir = (opcion == 's');
    } while (repetir);
}

int busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]) {
    int y, x;
    for (y = 0; y < NUMERO_ALUMNOS; y++) {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_NOTAS; x++) {
            if (x == 0 || x == 3)
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            else if (x == 1)
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            else if (x == 2)
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
            calificacion = 0;
        }
        matriz[y][NUMERO_NOTAS] = suma;
    }
}

void imprimirMatrizLinea() {
    int x;
    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++) {
        cout << "+---------";
    }
    cout << "+\n";
}

float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], string alumnos[NUMERO_ALUMNOS], string nombreFacultad) {
    int y, x;
    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    string alumnoPromedioMayor = alumnos[0];
    string alumnoPromedioMenor = alumnos[0];
    cout << nombreFacultad << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    for (x = 0; x < NUMERO_NOTAS; x++) {
        cout << setw(9) << "Nota" << x + 1;
    }
    cout << setw(8) << "Total" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_ALUMNOS; y++) {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_NOTAS; x++) {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += matriz[y][NUMERO_NOTAS];
        if (promedio > promedioMayor) {
            promedioMayor = promedio;
            alumnoPromedioMayor = alumnos[y];
        } else if (promedio < promedioMenor) {
            promedioMenor = promedio;
            alumnoPromedioMenor = alumnos[y];
        }
        cout << setw(8) << promedio << endl;
    }
    imprimirMatrizLinea();
    promedioGeneral = totalGeneral / NUMERO_ALUMNOS;
    cout << "Promedio General de la Facultad es: " << promedioGeneral << endl;
    return promedioGeneral;
}

void resultadosFinales(int repeticionProceso, string mejorFacultad, float mejorFacultadPromedio, string alumnos[NUMERO_ALUMNOS],
                       float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1],
                       float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1],
                       float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1],
                       int &contadorIngenieria, int &contadorArquitectura, int &contadorAdministracion) {
    Estudiante estudiantes[NUMERO_ALUMNOS * 3]; // 3 facultades * 5 alumnos
    int index = 0;

    // Asignar los datos de la Facultad de Ingenieria
    for (int i = 0; i < NUMERO_ALUMNOS; i++) {
        estudiantes[index].nombre = alumnos[i];
        estudiantes[index].promedio = matriz_facultad_1[i][NUMERO_NOTAS];
        estudiantes[index].facultad = "Ingenieria";
        index++;
    }

    // Asignar los datos de la Facultad de Arquitectura
    for (int i = 0; i < NUMERO_ALUMNOS; i++) {
        estudiantes[index].nombre = alumnos[i];
        estudiantes[index].promedio = matriz_facultad_2[i][NUMERO_NOTAS];
        estudiantes[index].facultad = "Arquitectura";
        index++;
    }

    // Asignar los datos de la Facultad de Administracion
    for (int i = 0; i < NUMERO_ALUMNOS; i++) {
        estudiantes[index].nombre = alumnos[i];
        estudiantes[index].promedio = matriz_facultad_3[i][NUMERO_NOTAS];
        estudiantes[index].facultad = "Administracion";
        index++;
    }

    // Ordenar a los estudiantes por promedio (de mayor a menor)
    sort(estudiantes, estudiantes + (NUMERO_ALUMNOS * 3), compararEstudiantes);

    cout << "\n*** Resultados Finales ***\n";
    cout << "Iteracion: " << repeticionProceso << endl;
    cout << "Mejor Facultad: " << mejorFacultad << endl;
    cout << "Promedio de la Mejor Facultad: " << mejorFacultadPromedio << endl;

    // Mostrar los primeros tres estudiantes ordenados por promedio
    cout << "Top 3 estudiantes:\n";
    for (int i = 0; i < 3; i++) {
        cout << estudiantes[i].nombre << " (" << estudiantes[i].facultad << ") - Promedio: " << estudiantes[i].promedio << endl;
    }

    cout << "\nContadores de facultades:\n";
    cout << "Ingenieria: " << contadorIngenieria << endl;
    cout << "Arquitectura: " << contadorArquitectura << endl;
    cout << "Administracion: " << contadorAdministracion << endl;
}
