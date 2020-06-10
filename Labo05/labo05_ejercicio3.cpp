#include<iostream>

using namespace std;

bool esBisiesto(const int &n){
    if( !( n % 400 ) )
        return true;
    if( !( n % 4 ) && ( n % 100 ) )
        return true;
    
    return false;
}

int main(){
    int y;

    cout << "Ingrese el año: "; cin >> y;

    if(esBisiesto(y))
        cout << "Es bisiesto!" << endl;
    else
        cout << "No es bisiesto!" << endl;
    
    return 0;
}