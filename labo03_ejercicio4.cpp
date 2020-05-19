#include<iostream>
#include<string>

using namespace std;

int main(){
    string nombre;
    float precio;
    int cantidad;
    float total = 0;

    cout << "Ingrese el nombre del producto: "; cin>>nombre;
    cout << "Ingrese el precio del producto: "; cin >> precio;
    cout << "Ingrese la cantidad a comprar del producto: "; cin>>cantidad;

    total = precio * cantidad;

    cout << "El total de dinero gastado es de: $" << total << endl;

    return 0;
}