#include<iostream>
#include<iomanip>

using namespace std;

//Prototipos
void recibir_empleado(int actual);
void mostrar_salario(int h_n, int h_e);
void imprimir(int h1, int h2, long double ss, long double afp, long double renta, long double s1, long double s2);

int main(){
    //Variable que representa los empleados totales
    int n;
    //Se solicita el dato al usuario
    cout << "Bienvenido al programa para calcular el salario real.\nIngrese el número de empleados para trabajar: "; cin >> n;
    //Se realizan n iteraciones según el número de empleados
    for(int i = 1; i <= n; i++){
        //Se llama al procedimiento según cada empleado
        recibir_empleado(i);
    }
    //Mensaje de despedida
    cout << "¡Gracias por usar el programa!" << endl;

    return 0; 
}

//Función para tomar los datos del empleado
void recibir_empleado(int actual){
    //Variables para representar las horas trabajadas
    int h_normales, h_extras;
    //Limpia la pantalla (esto solo funciona en terminales bash, para cmd utilícese cls)
    system("clear");

    cout << "Empleado " << actual << ":\n";//Empleado del que se reciben los datos
    cout << "Ingrese las horas normales trabajadas: "; cin >> h_normales;
    cout << "Ingrese las horas extras trabajadas: "; cin >> h_extras;
    //Muestra el salario a partir de las horas trabajadas
    mostrar_salario(h_normales,h_extras);
}

//Función para mostrar y calcular el salario de un empleado
void mostrar_salario(int h_n, int h_e){
    /* Variables donde se van guardando los cálculos del salario
    Y los respectivos descuentos */
    long double salario = h_n * 1.75 + h_e * 2.5;
    long double seguro = salario * 0.04;
    long double afp = salario * 0.0625;
    long double renta = (salario > 500) ? salario * 0.1 : 0;
    long double salario_real = salario - (seguro+afp+renta);

    //Imprime con formato todos los datos anteriormente calculados
    imprimir(h_n,h_e,seguro,afp,renta,salario, salario_real);
    //Equivalente al "pause" de cmd. (Solo funciona con terminales bash)
    system("read -p \"Pulse una tecla para continuar...\"");
    system("clear");
}

//Función para imprimir en formato tabla los datos
void imprimir(int h1, int h2, long double ss, long double afp, long double renta, long double s1, long double s2){
    //Imprime una línea de "-"
    cout << setfill('-') << setw(104) << '-' << endl;

    //Cabecera de la tabla
    cout << "| Horas normales ";
    cout << "| Horas extras ";
    cout << "| Seguro social ";
    cout << "| AFP       ";
    cout << "| Renta     ";
    cout << "| Salario total ";
    cout << "| Salario real |" << endl;

    cout << setfill('-') << setw(104) << '-' << endl;
    
    //Datos de la tabla justificados a la izquierda
    cout << "| " << setfill(' ') <<setw(15) << left << h1;
    cout << "| " << setfill(' ') <<setw(13) << left << h2;
    cout << "| $" << setfill(' ') <<setw(13) << fixed << setprecision(2) << left << ss;
    cout << "| $" << setfill(' ') <<setw(9) << left << afp;
    cout << "| $" << setfill(' ') <<setw(9) << left << renta;
    cout << "| $" << setfill(' ') <<setw(13) << left << s1;
    cout << "| $" << setfill(' ') <<setw(11) << left << s2;
    cout << " |\n";

    //Línea de cierre
    cout << setfill('-') << setw(104) << '-' << endl;
}