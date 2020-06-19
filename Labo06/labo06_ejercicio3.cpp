#include<iostream>
#include<cmath>

using namespace std;

float* ingresar_arreglo(int t){
    float *arr = new float[t];
    for (int i = 0; i < t; i++){
        cout << "Ingrese la medida número " << i + 1 << ": "; cin>> arr[i];
    }
    return arr;
}

float promedio(float arreglo[], int t){
    float sum = 0;
    for (int i = 0; i < t; i++){
        sum += arreglo[i];
    }
    return sum / t;
}

float incerteza(float arreglo[], int t){
    float x_promedio = promedio(arreglo,t);
    float sum_incertezas = 0;
    for (int i = 0; i < t; i++){
        sum_incertezas += (arreglo[i] - x_promedio) * (arreglo[i] - x_promedio);   
    }
    return sqrt(sum_incertezas/(t-1));
}

int main(){
    int t;

    cout << "Ingrese el total de medidas tomadas: "; cin >> t;

    float *arr = ingresar_arreglo(t);

    cout << "La incerteza de los datos es: " << incerteza(arr,t) << endl;

    delete [] arr;

    return 0;
}