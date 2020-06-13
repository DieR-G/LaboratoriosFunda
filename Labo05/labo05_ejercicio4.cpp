#include<iostream>
#include<iomanip>

using namespace std;
//Prototipos de funciones

//Función que valida si un año es bisiesto
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
    //Se solicitan los datos
    cout << "Ingrese el dia: "; cin >> day;
    cout << "Ingrese el mes: "; cin >> month;
    cout << "Ingrese el año: "; cin >> year;
    //Llamada a función con los datos previamente ingresados
    diaDespues(day,month,year);

    return 0;
}

//Función para calcular el día después de la fecha ingresada
void diaDespues( int dd,  int mm, int aa ){
    //Validación que sean fechas positivas o mayores que 1
    if(dd < 1 || mm < 1 || aa < 0){
        cout << "Error de digitacion" << endl;
        return;
    }
    //Validación que no se ingrese una mayor cantidad de días en el mes correspondiente
    if(dd > diasPorMes(mm,aa)){
        cout << "Error de digitacion" << endl;
        return;
    }
    //Si no hay problema en las fechas se procede a calcular el día después
    else{
        //Si es el último día de febrero el mes pasa a ser marzo y el día pasa a ser 1
        if(mm == 2 && dd == diasPorMes(mm,aa)){
            dd = 1;
            mm = 3;
        }
        //Caso contrario se añade un día y se hacen los ajustes necesarios
        else{
            dd++;
            mm += dd/diasPorMes(mm,aa);
            aa += mm/12;

            mm %= 12;
            dd %= diasPorMes(mm,aa);
        }
    }
    //Se muestra la fecha con formato dd/mm/yyyy
    cout << "La fecha luego de 1 dia es:\n";
    cout << setw(2) << setfill('0') << dd;
    cout << "/";
    cout << setw(2) << setfill('0') << mm;
    cout << "/" << aa << endl;
    
}
//Función que devuelve la cantidad de días de un mes según el año
int diasPorMes(const int &mes, const int &yy){
    switch(mes){
        //Meses con 30 días
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        //Meses con 31 días
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        //Días de febrero en función de si el año es bisiesto
        case 2:
            if(esBisiesto(yy))
                return 29;
            else
                return 28;
        //Si se ingresó un mes inexistente devuelve -1
        default:
            return -1;
    }
}