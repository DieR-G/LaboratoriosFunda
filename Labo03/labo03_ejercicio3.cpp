#include<iostream>
#include<cmath>
using namespace std;

int main(){
    float x1, x2, a, b, c, discriminante;
    cout << "Ingrese seguidos los valores de a, b y c:\n";
    cin >> a >> b >> c;
    discriminante = b*b-4*a*c;
    if(discriminante < 0){
        cout << "La ecuacion no tiene raices reales." << endl;
    }
    else{
        x1 = (-b + sqrt(discriminante))/2;
        x2 = (-b - sqrt(discriminante))/2;
        cout << "El valor de x1 es: " << x1 << endl;
        cout << "El valor de x2 es: " << x2 << endl;
    }
    
    return 0;
}
