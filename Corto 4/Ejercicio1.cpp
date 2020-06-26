#include<iostream>

using namespace std;

//Función para codificar cada letra que se pase como argumento
char codificarLetra(char letra){
    //Valida según el valor de la letra y devuelve un número acorde al código murciélago
    switch (letra){
            case 'm':
            case 'M':
                return '0';
            case 'u':
            case 'U':
                return '1';
            case 'r':
            case 'R':
                return '2';
            case 'c':
            case 'C':
                return '3';
            case 'i':
            case 'I':
                return '4';
            case 'e':
            case 'E':
                return '5';
            case 'l':
            case 'L':
                return '6';
            case 'a':
            case 'A':
                return '7';
            case 'g':
            case 'G':
                return '8';
            case 'o':
            case 'O':
                return '9';
            //Si no es ninguna letra de la palabra murciélago no se realiza la modificación
            default:
                return letra;
        }
}

int main(){
    char frase[256];
    //La función getline permite recibir una entrada que incluya espacios
    cout << "Ingrese una frase a codificar: "; cin.getline(frase,256);

    //Se recorre todo el arreglo. El valor \0 indica que se ha llegado a la última posición
    for(int i = 0; frase[i] != '\0' ;i++){
        //Se codifica cada letra de la frase
        frase[i] = codificarLetra(frase[i]);
    }
    cout << "La nueva frase codificada es: " << frase << endl;
    return 0;
}