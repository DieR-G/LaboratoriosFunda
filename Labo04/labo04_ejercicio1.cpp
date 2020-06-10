#include<iostream>

using namespace std;

int main(){
    int num1, num2;

    cout << "Ingrese dos numeros para saber si son divisibles\n";
    cout << "Ingrese el primer numero: "; cin>>num1;
    cout << "Ingrese el segundo numero: "; cin>>num2;

    if(num2 == 0){
        cerr << "No se puede realizar la operacion" << endl;
        return 1;
    }

    cout << "Los numeros ";
    
    if(num1%num2)
        cout << "no son divisibles." << endl;
    else
        cout << "son divisibles." << endl;
        
    return 0;
}