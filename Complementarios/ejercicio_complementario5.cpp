#include<iostream>
#include<iomanip>

using namespace std;

template<typename T>
void imprimirBonito( T args ){
    cout << setw(15) << left << setfill(' ') << args;
}

int main(){
    unsigned int num, sum = 0, cantidad = 0;
    float promedio;
    cout << "Ingrese varios enteros (0 para salir):\n";
    do{
        cin >> num;
        sum += num;
        cantidad++;
    }while(num != 0);
    
    cantidad--;
    
    if(cantidad > 0)
        promedio = sum / cantidad;
    
    imprimirBonito("Suma:");
    imprimirBonito("Cantidad:");
    imprimirBonito("Promedio:");
    
    cout << '\n';
    
    imprimirBonito(sum);
    imprimirBonito(cantidad);
    imprimirBonito(promedio);

    return 0;

}