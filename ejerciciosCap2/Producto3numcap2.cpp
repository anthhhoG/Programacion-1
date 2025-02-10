// Calcula el producto de tres enteros
 #include <iostream> // permite al programa realizar operaciones de entrada y salida
 using namespace std; // el programa usa nombres del std namespace

 // la función main empieza la ejecución del programa
 int main()
 {
   int x = 0; // primer entero a multiplicar
   int y = 0; // segundo entero a multiplicar
   int z = 0; // tercer entero a multiplicar
   int resultado = 0; // el producto de los tres enteros

   cout << "Escriba tres enteros: "; // pide los datos al usuario
   cin >> x >> y >> z; // lee tres enteros del usuario
   resultado = x * y * z; // multiplica los tres enteros; almacena el resultado
   cout << "El producto es " << resultado << endl; // imprime el resultado; fin de línea
 } // fin de la función main
