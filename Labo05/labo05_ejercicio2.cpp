#include <iostream>
#include <iomanip>

using namespace std;
//Prototipo de función
void segundoDespues(int,int,int);

int main(){
    int hh, mm, ss;
    //Se piden los datos
    cout << "Ingrese la hora(modo 24 horas): "; cin >> hh;
    cout << "Ingrese los minutos: "; cin >> mm;
    cout << "Ingrese los segundos: "; cin >> ss;
    //Llamada a la función
    segundoDespues(hh,mm,ss);

    return 0;
}

void segundoDespues(int hh, int mm, int ss){
    //Validación que los datos ingresados en la hora sean válidos
    if((hh > 23) || (mm > 59) || (ss > 59) || (hh < 0) || (mm > 0) || (ss < 0) ){
        cout << "La hora ingresada no es adecuada." << endl;
        return;
    }
    //Se agrega un segundo y se realizan los ajustes respectivos
    ss++;
    mm += ss/60;
    hh += mm/60;
    //El residuo del excedente de 60 o de 24 se toma como el nuevo valor una vez agregado un segundo
    ss %= 60;
    mm %= 60;
    hh %= 24;
    //Se muestra la hora con formado hh:mm:ss
    cout << "La hora despues de 1 segundo es:\n";
    cout << setw(2) << setfill('0') << hh;
    cout << ':';
    cout << setw(2) << setfill('0') << mm;
    cout << ':';
    cout << setw(2) << setfill('0') << ss;
}