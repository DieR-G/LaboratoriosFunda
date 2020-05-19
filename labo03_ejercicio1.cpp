#include<iostream>

using namespace std;

int main(){
    int num1, num2, num3;
    float promedio;
    cout << "Ingrese el numero 1: "; 
    cin >> num1;
    
    cout << "Ingrese el numero 2: "; 
    cin >> num2;

    cout << "Ingrese el numero 3: "; 
    cin >> num3;

    promedio = (float)(num1+num2+num3) / 3;

    cout << "El promedio es: " << promedio << endl;
    
    return 0;
}