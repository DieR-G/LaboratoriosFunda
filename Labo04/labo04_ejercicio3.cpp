#include<iostream>

using namespace std;

int main(){
    int num;
    
    cout << "Ingrese un numero para saber si es:\npositivo\nnegativo\ncero\n";
    cin >> num;

    if(num > 0)
        cout << "Es positivo." << endl;

    if(num < 0) 
        cout << "Es negativo." << endl;

    if(num == 0)
        cout << "Es cero." << endl;

    return 0;
}