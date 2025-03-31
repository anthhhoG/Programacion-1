#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    cout << "Numero del inciso a: "<<2 + (rand()%5) * 2 <<endl;
    cout << "Numero del inciso b: " << 3+ (rand() % 5) * 2 <<endl;
    cout << "Numero del inciso c: "<<6 + (rand() % 5) * 4 <<endl;
}
