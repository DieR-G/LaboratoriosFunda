#include <iostream>

using namespace std;

int mcd(int,int);

int main(){
    int num1, num2;
    //Se solicitan los datos
    cout << "Ingrese el numero mayor: "; cin >> num1;
    cout << "Ingrese el numero menor: "; cin >> num2;
    //Se muestra el MCD haciendo la llamada a la función respectiva
    cout << "El MCD de ambos numeros es: " << mcd(num1,num2);

    return 0;
}

//Función para calcular el máximo común divisor según el método de Euclides (de forma iterativa)
//a es el número mayor y b es el menor
int mcd(int a, int b){
    //Variable residuo que contiene el resto de la división de a y b
    int residuo = a % b;
    
    //Mientras el residuo sea distinto de 0
    while(residuo){
        //El número mayor para a ser el menor
        a = b;
        //El número menor pasa a ser el residuo de la división de a y b
        b = residuo;
        //Se vuelve a calcular el residuo. Cuando este llegue a cero 
        //el bucle termina y el máximo común divisor se encuentra en el número menor
        residuo = a % b;
    }
    //Se devuelve el número menor como MCD
    return b;
}