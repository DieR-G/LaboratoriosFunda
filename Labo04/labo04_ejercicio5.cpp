#include<iostream>
#include<string>

using namespace std;

int main(){
    string palabra;
    cout << "Ingrese una palabra: "; cin >> palabra;
    
    if(palabra.front() == palabra.back())
        cout << "La palabra inicia y termina con la misma letra" << endl;
    else
        cout << "La palabra no inicia o no termina con la misma letra" << endl;
    
    return 0;
}