#include<iostream>

using namespace std;

bool esBisiesto(const int &n){
    //Si el año ingresado es múltiplo de 400 o es múltiplo de 4 pero no múltiplo de 100 entonces es bisiesto
    if( !( n % 400 ) )
        return true;
    if( !( n % 4 ) && ( n % 100 ) )
        return true;
    //En caso de no cumplirse ninguna condición anterior el año no es bisiesto
    return false;
}

int main(){
    int y;
    //Ingreso del dato
    cout << "Ingrese el año: "; cin >> y;
    //Validación de si es bisiesto o no
    if(esBisiesto(y))
        cout << "Es bisiesto!" << endl;
    else
        cout << "No es bisiesto!" << endl;
    
    return 0;
}