#include<iostream>
#include<vector>
// #include<algorithm>
// #include<utility>

using namespace std;

void llenar_arreglo(vector<int> &arr){
    //Itera por todo el arreglo solicitando un valor por cada posición.
    //Al utilizarse vectores no es necesario pasar la dimensión del arreglo como argumento
    for (int i = 0; i < arr.size(); i++){
        cout << "Ingrese el valor en la posición " << i << ": ";cin >> arr[i];
    }
}

int contar_num(vector<int> &arr, int num){
    int conteo = 0;
    //Función que itera sobre el arreglo
    //y si encuentra un valor igual al buscado
    //añade 1 a la suma, de lo contrario añade 0.
    for (int i = 0; i < arr.size(); i++){
        conteo += (arr[i] == num) ? 1 : 0;
    }
    //Retorna el valor de veces que aparece dicho número
    return conteo; 

    //Algunas alternativas a este ejercicio utilizando funciones de la librería estándar

    /* sort(arr.begin(),arr.end());
    auto limites = equal_range(arr.begin(),arr.end(),num);
    return limites.second - limites.first; */

    // return count(arr.begin(),arr.end(),num);
}

int main(){
    //variables a utilizar donde
    //t es el tamaño, num el valor a buscar y total las veces que aparece
    int t, num, total;
    cout << "Ingrese la dimensión del arreglo: "; cin >> t;

    vector<int> arreglo(t);

    //Llamada a la función para llenar el arreglo
    llenar_arreglo(arreglo);

    cout << "Ingrese el valor a contar en el arreglo: "; cin >> num;

    //Llamada a la función para contar el número de veces que aparece el valor indicado
    total = contar_num(arreglo,num);

    cout << "El valor se repite " << total << " veces en el arreglo" << endl;

    return 0;
}