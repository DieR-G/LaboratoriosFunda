#include <iostream>
#include <iomanip>

using namespace std;

void segundoDespues(int,int,int);

int main(){
    int hh, mm, ss;

    cout << "Ingrese la hora(modo 24 horas): "; cin >> hh;
    cout << "Ingrese los minutos: "; cin >> mm;
    cout << "Ingrese los segundos: "; cin >> ss;

    segundoDespues(hh,mm,ss);

    return 0;
}

void segundoDespues(int hh, int mm, int ss){
    if((hh > 23) || (mm > 59) || (ss > 59)){
        cout << "La hora ingresada no es adecuada." << endl;
        return;
    }
    ss++;
    mm += ss/60;
    hh += mm/60;

    ss %= 60;
    mm %= 60;
    hh %= 24;

    cout << "La hora despues de 1 segundo es:\n";
    cout << setw(2) << setfill('0') << hh;
    cout << ':';
    cout << setw(2) << setfill('0') << mm;
    cout << ':';
    cout << setw(2) << setfill('0') << ss;
}