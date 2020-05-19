#include<iostream>

using namespace std;

int main(){
    int num;
    cout << "Ingrese un numero para saber si es par: "; cin >> num;

    if( num & 1 )
        cout << "Es impar" << endl;
    else
        cout << "Es par" << endl;
        
    return 0;
}