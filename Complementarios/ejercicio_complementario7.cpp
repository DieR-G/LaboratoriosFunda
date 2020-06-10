#include <iostream>

using namespace std;

bool esDivisible(const int &m, const int &n){
    return !(m % n);
}

int main(){
    int m, n;
    cout << "Ingrese el numero m: "; cin >> m;
    cout << "Ingrese el numero n: "; cin >> n;
    
    if(esDivisible(m,n)){
        cout << "Los numeros son divisibles" << endl;
    }
    else{
        cout << "Los numeros no son divisibles" << endl;
    }

    return 0;

}