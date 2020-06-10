#include <iostream>

using namespace std;

int mcd(int,int);

int main(){
    int num1, num2;
    cout << "Ingrese el numero mayor: "; cin >> num1;
    cout << "Ingrese el numero menor: "; cin >> num2;

    cout << "El MCD de ambos numeros es: " << mcd(num1,num2);

    return 0;
}

int mcd(int a, int b){
    int residuo = a % b;
    
    while(residuo){
        a = b;
        b = residuo;
        residuo = a % b;
    }

    return b;
}