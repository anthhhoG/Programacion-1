#include <iostream>
 using namespace std;
 int segundosDesdeLas12(int horas, int minutos, int segundos){

if(horas == 12) horas = 0;
return (horas * 3600) + (minutos * 60) + segundos;

}
int diferenciaEnSegundos(int h1, int m1, int s1, int h2, int m2, int s2){
 int tiempo1 = segundosDesdeLas12(h1, m1, s1);
 int tiempo2 = segundosDesdeLas12(h2, m2, s2);
 return abs(tiempo2 - tiempo1);
}
int main(){
    int h1, m1, s1, h2, m2, s2;
    cout << "Ingrese la primera hora (hh mm ss): ";
    cin >> h1 >> m1 >> s1;
    cout << "Ingrese la segunda hora (hh mm ss): ";
    cin >> h2 >> m2 >> s2;
    cout << "Diferencia en segundos: " << diferenciaEnSegundos(h1, m1, s1, h2, m2, s2) << endl;
}
