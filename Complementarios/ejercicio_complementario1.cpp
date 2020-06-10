#include<iostream>
#include<iomanip>

using namespace std;

template<typename T>
void imprimirBonito( T args ){
    cout << setw(10) << left << setfill(' ') << args;
}

int main(){
    int n, aux, s = 1000;
    cout << "Ingrese un numero positivo no mayor a 9999\n";
    cin >> n;
    cout << "El numero tiene:\n";
    
    imprimirBonito("millares");
    imprimirBonito("centenas");
    imprimirBonito("decenas");
    imprimirBonito("unidades");
    cout << "\n";

    if( n > 9999 || n < 1)
        return 1;

    do{
        aux = (n - n % s) / s;
        imprimirBonito(aux);
        n = n % s;
        s /= 10;
    }while(s >= 1);

    return 0;
}