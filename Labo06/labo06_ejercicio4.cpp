#include<iostream>
#include<vector>

using namespace std;

void llenar_arreglo(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        cout << "Ingrese el valor en la posición " << i << ": ";cin >> arr[i];
    }
}

void sumar_arreglos(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3){
    for (int i = 0; i < arr1.size(); i++){
        arr3[i] = arr1[i] + arr2[i];
    }
}

void mostrar_arreglo(vector<int> &arr){
    cout << "El arreglo a mostrar es: \n";
    for (int i = 0; i < arr.size(); i++){
        cout << "arreglo[" << i << "]: " << arr[i] << '\n';
    }
}

int main(){
    int t;
    cout << "Ingrese el tamaño del primer arreglo: "; cin >> t;

    vector<int> arreglo1(t), arreglo2(t), arreglo_sum(t);
    llenar_arreglo(arreglo1);
    llenar_arreglo(arreglo2);
    sumar_arreglos(arreglo1, arreglo2, arreglo_sum);
    mostrar_arreglo(arreglo_sum);

    return 0;
}