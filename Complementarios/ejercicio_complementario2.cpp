#include<iostream>
#include<cmath>

using namespace std;

unsigned int enteroRevertido(int inicial){
    unsigned int result = 0;
    unsigned short digits = ceil(log10(inicial));

    do{
        result += (inicial % 10) * pow(10,digits - 1);
        inicial /= 10;
        digits--;
    }while(digits >= 1);

    return result;
}

int main(){
    unsigned int num;
    
    cout << "Ingrese un numero positivo: ";
    cin >> num;

    cout << "El numero invertido es: " << enteroRevertido(num) << endl;

    return 0;
}