#include<iostream>
#include<cctype>

using namespace std;

int main(){
    int n, vocales = 0;
    char aux;
    cout << "Ingrese el numero de caracteres: "; cin >> n;
    
    while(n--){
        cout << "Ingrese un caracter: "; 
        cin >> aux;
        switch(tolower(aux)){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vocales++;
                break;
        }
    }

    cout << "El numero de vocales ingresadas es de: " << vocales << endl;

    return 0;
}