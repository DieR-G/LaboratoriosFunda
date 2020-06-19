#include<iostream>

using namespace std;

int* ingresar_arreglo(int t){
    int *arr = new int[t];
    for (int i = 0; i < t; i++){
        cout << "Ingrese el valor " << i + 1 << " del arreglo: "; cin>> arr[i];
    }
    return arr;
}

void mostrar_promedio(int arr[], int t){
    float sum, prom;
    for (int i = 0; i < t; i++)
    {
        sum += arr[i];
    }
    prom = sum / t;
    cout << "El promedio del arreglo es: " << prom << endl;
}

int main(){
    int t;
    cout << "Ingrese la dimensión del arreglo: "; cin >> t;
    int *arreglo = ingresar_arreglo(t);
    mostrar_promedio(arreglo, t);
    
    delete [] arreglo;
    
    return 0;
}