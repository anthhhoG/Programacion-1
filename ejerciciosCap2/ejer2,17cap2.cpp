#include <iostream>

int main() {
    // a) Usando una instrucción con un operador de inserción de flujos
    std::cout << "1 2 3 4" << std::endl;

    // b) Usando una instrucción con cuatro operadores de inserción de flujos
    std::cout << 1 << " " << 2 << " " << 3 << " " << 4 << std::endl;

    // c) Usando cuatro instrucciones
    std::cout << 1 << " ";
    std::cout << 2 << " ";
    std::cout << 3 << " ";
    std::cout << 4 << std::endl;

    return 0;
}
