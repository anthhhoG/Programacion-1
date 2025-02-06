#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    // Variables
    float pesoEnLibras, pesoEnKilogramos, alturaEnPulgadas, alturaEnMetros, indiceMasaCorporal;
    int opcionSeleccionada;
    char salidaMenu;

    // Inicia el ciclo
    do
    {
        system("cls");
        // Reiniciar valores
        opcionSeleccionada = 0;
        indiceMasaCorporal = 0;

        cout << "Calculadora de Indice de Masa Corporal (BMI)" << endl;
        // Menu de opciones
        cout << "1. Calcular BMI en libras y pulgadas" << endl;
        cout << "2. Calcular BMI en kilogramos y metros" << endl;
        cout << "   Opcion: ";
        cin >> opcionSeleccionada;

        // Estructuras condicionales
        if (opcionSeleccionada == 1 || opcionSeleccionada == 2)
        {
            if (opcionSeleccionada == 1)
            {
                cout << "Ingrese su peso en libras: ";
                cin >> pesoEnLibras;
                cout << "Ingrese su altura en pulgadas: ";
                cin >> alturaEnPulgadas;
                indiceMasaCorporal = (pesoEnLibras * 703) / (alturaEnPulgadas * alturaEnPulgadas);
            }
            else if (opcionSeleccionada == 2)
            {
                cout << "Ingrese su peso en kilogramos: ";
                cin >> pesoEnKilogramos;
                cout << "Ingrese su altura en metros: ";
                cin >> alturaEnMetros;
                indiceMasaCorporal = pesoEnKilogramos / (alturaEnMetros * alturaEnMetros);
            }

            // Mostrar el resultado del BMI
            cout << "Su BMI es: " << indiceMasaCorporal << endl;

            // Determinar la categoría del BMI
            if (indiceMasaCorporal < 18.5)
                cout << "Categoria: Bajo peso" << endl;
            else if (indiceMasaCorporal >= 18.5 && indiceMasaCorporal <= 24.9)
                cout << "Categoria: Normal" << endl;
            else if (indiceMasaCorporal >= 25 && indiceMasaCorporal <= 29.9)
                cout << "Categoria: Sobrepeso" << endl;
            else
                cout << "Categoria: Obeso" << endl;
        }
        else
        {
            cout << "Error: Opcion no valida" << endl;
        }

        // Preguntar si desea realizar otra operación
        cout << "Desea realizar otra operacion? (Si=S / No=N): ";
        cin >> salidaMenu;
    } while (salidaMenu == 's' || salidaMenu == 'S');

    return 0;
}
