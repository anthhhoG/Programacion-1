#include <iostream>
#include <string>

class LibroCalificaciones {
public:
    explicit LibroCalificaciones(std::string nombreCurso, std::string nombreInstructor)
        : curso(nombreCurso), instructor(nombreInstructor) {}

    void establecerNombreCurso(std::string nombre) {
        curso = nombre;
    }

    std::string obtenerNombreCurso() const {
        return curso;
    }

    void establecerNombreInstructor(std::string nombre) {
        instructor = nombre;
    }

    std::string obtenerNombreInstructor() const {
        return instructor;
    }

    void mostrarMensaje() const {
        std::cout << "Bienvenido al libro de calificaciones para\n" << obtenerNombreCurso() << std::endl;
        std::cout << "Este curso es presentado por: " << obtenerNombreInstructor() << std::endl;
    }

private:
    std::string curso;
    std::string instructor;
};

int main() {
    LibroCalificaciones libro("Programacion I", "Ing. Esduardo Del Aguila");
    libro.mostrarMensaje();
    return 0;
}
