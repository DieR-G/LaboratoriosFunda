#include <iostream>

using namespace std;

int contarIntervalo(const int &,const int &,const int &);

int main(){
    int num1, num2, multiplo;

    cout << "Ingrese el primer numero: "; cin >> num1;
    cout << "Ingrese el segundo numero: "; cin >> num2;
    cout << "Ingrese el tercer numero: "; cin >> multiplo;

    cout << "La suma de los divisores del intervalo es: " << contarIntervalo(num1,num2,multiplo);

    return 0;
}

int contarIntervalo(const int &a, const int &b, const int &n){
    int sum = 0;
    for(int i = a; i <= b; i++){
        if(!(n%i)){
            sum += i;
        }
    }
    return sum;
}