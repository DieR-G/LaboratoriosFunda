#include<iostream>
#include<algorithm>

using namespace std;

int ocurrencias(int num1, int digito){
    int total;
    string aux = to_string(num1);
    total = count(aux.begin(), aux.end(), '0' + digito);
    return total;
}

int main(){
    int cantidad, digito;
    
    cout << "Ingrese una cantidad: "; cin >> cantidad;
    cout << "\nIngrese un digito a buscar en la cantidad: "; cin >> digito;
    cout << "\nEl total de ocurrencias del digito es de: " << ocurrencias(cantidad,digito) << endl;
    
    return 0;
}