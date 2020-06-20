#include<iostream>
#include<vector>

using namespace std;

//Llena el arreglo con los primeros 100 valores impares
//Como se utiliza un vector no es necesario pasar el tamaño como argumento
void llenar(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        arr[i] = 2*i + 1;
    }
}
//Imprime desde el último hasta el primer elemento
void imprimir_reversa(vector<int> &arr){
    for (int i = arr.size() - 1; i >= 0; i--){
        cout << "El valor en la posición " << i + 1<< " es: " << arr[i] << '\n';
    }
}

int main(){
    //Arreglo para almacenar 100 valores
    vector<int> impares(100);
    //Llena el arreglo con números impares
    llenar(impares);
    //Imprime el arreglo desde el último hasta el primer elemento
    imprimir_reversa(impares);
    return 0;
}