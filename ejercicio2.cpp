#include<iostream>

using namespace std;

int main(){
    float radio, perimetro, area;
    const float pi = 3.1415926535897932;
    cout << "Ingrese el valor del radio: ";
    cin >> radio;
    area = pi * radio * radio;
    perimetro = 2 * pi * radio;
    cout << "\nEl area es: " << area << '\n';
    cout << "El perimetro es: " << perimetro << endl;
    return 0;    
}