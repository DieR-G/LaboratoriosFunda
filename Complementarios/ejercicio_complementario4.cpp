#include<iostream>
#include<cctype>

using namespace std;

int vocalesIngresadas();

int main(){
    int total = vocalesIngresadas();
    cout << "\nEl numero de vocales ingresadas es de: " << total;
}

int vocalesIngresadas(){
    int vocales = 0;
    char aux;
    cout << "Ingrese varios caracteres (Crtl + Z y Enter para salir):\n";
    while(cin >> aux){
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
    cin.clear();
    return vocales;
}