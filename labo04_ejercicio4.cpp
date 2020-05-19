#include<iostream>
#include<string>

using namespace std;

int main(){
    string palabra;
    cout << "Ingrese una palabra: "; cin >> palabra;
    
    if(palabra.length() > 10)
        cout << "La palabra ingresada tiene mas de 10 caracteres." << endl;
    else
        cout << "La palabra ingresada tiene no tiene mas de 10 caracteres." << endl;    
        
    if(palabra.length() & 1)
        cout << "La palabra ingresada tiene una cantidad impar de caracteres" << endl;
    else
        cout << "La palabra ingresada tiene una cantidad par de caracteres." << endl;
    
    return 0;
}