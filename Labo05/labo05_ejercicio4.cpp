#include<iostream>
#include<iomanip>

using namespace std;

bool esBisiesto(const int &n){
    if( !( n % 400 ) )
        return true;
    if( !( n % 4 ) && ( n % 100 ) )
        return true;
    
    return false;
}

void diaDespues(int, int, int);

int diasPorMes(const int &, const int &);

int main(){
    int day, month, year;

    cout << "Ingrese el dia: "; cin >> day;
    cout << "Ingrese el mes: "; cin >> month;
    cout << "Ingrese el año: "; cin >> year;

    diaDespues(day,month,year);

    return 0;
}

void diaDespues( int dd,  int mm, int aa ){
    if(dd < 1 || mm < 1 || aa < 0){
        cout << "Error de digitacion" << endl;
        return;
    }
        
    if(dd > diasPorMes(mm,aa)){
        cout << "Error de digitacion" << endl;
        return;
    }
    else{
        if(mm == 2 && dd == diasPorMes(mm,aa)){
            dd = 1;
            mm = 3;
        }
        else{
            dd++;
            mm += dd/diasPorMes(mm,aa);
            aa += mm/12;

            mm %= 12;
            dd %= diasPorMes(mm,aa);
        }
    }

    cout << "La fecha luego de 1 dia es:\n";
    cout << setw(2) << setfill('0') << dd;
    cout << "/";
    cout << setw(2) << setfill('0') << mm;
    cout << "/" << aa << endl;
    
}

int diasPorMes(const int &mes, const int &yy){
    switch(mes){
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            if(esBisiesto(yy))
                return 29;
            else
                return 28;
        default:
            return -1;
    }
}