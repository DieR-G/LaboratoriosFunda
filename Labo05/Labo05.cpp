#include<iostream>
#include<iomanip>
using namespace std;

//Prototipos
int mcd(int,int);
void ejercicio1();

void segundoDespues(int,int,int);
void ejercicio2();

bool esBisiesto(const int &);
void ejercicio3();

void diaDespues(int, int, int);
int diasPorMes(const int &, const int &);
void ejercicio4();

int main(){
    int opc = 0;
    cout << "Guía 5 de laboratorio.\n";
    do{
        cout << "Ingrese un número según el ejercicio a revisar:\n";
        cout << "1-Ejercicio1\n2-Ejercicio2\n3-Ejercicio3\n4-Ejercicio4\n0-Salir\n";
        cin >> opc;
        system("clear");
        switch (opc)
        {
        case 1:
            ejercicio1();
            break;
        case 2:
            ejercicio2();
            break;
        case 3:
            ejercicio3();
            break;
        case 4:
            ejercicio4();
            break;
        case 0:
            cout << "Gracias por usar el programa" << endl;
            break;
        default:
            cout << "Número ingresado fuera del rango" << endl;
            break;
        }
    }while(opc != 0);

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

void ejercicio1(){
    int num1, num2;
    //Se solicitan los datos
    cout << "Ingrese el numero mayor: "; cin >> num1;
    cout << "Ingrese el numero menor: "; cin >> num2;
    //Se muestra el MCD haciendo la llamada a la función respectiva
    cout << "El MCD de ambos numeros es: " << mcd(num1,num2) << endl;
}

void segundoDespues(int hh, int mm, int ss){
    //Validación que los datos ingresados en la hora sean válidos
    if((hh > 23) || (mm > 59) || (ss > 59) || (hh < 0) || (mm < 0) || (ss < 0) ){
        cout << "La hora ingresada no es adecuada." << endl;
        return;
    }
    //Se agrega un segundo y se realizan los ajustes respectivos
    ss++;
    mm += ss/60;
    hh += mm/60;
    //El residuo del excedente de 60 o de 24 se toma como el nuevo valor una vez agregado un segundo
    ss %= 60;
    mm %= 60;
    hh %= 24;
    //Se muestra la hora con formado hh:mm:ss
    cout << "La hora despues de 1 segundo es:\n";
    cout << setw(2) << setfill('0') << hh;
    cout << ':';
    cout << setw(2) << setfill('0') << mm;
    cout << ':';
    cout << setw(2) << setfill('0') << ss << endl;
}

void ejercicio2(){
    int hh, mm, ss;
    //Se piden los datos
    cout << "Ingrese la hora(modo 24 horas): "; cin >> hh;
    cout << "Ingrese los minutos: "; cin >> mm;
    cout << "Ingrese los segundos: "; cin >> ss;
    //Llamada a la función
    segundoDespues(hh,mm,ss);
}

bool esBisiesto(const int &n){
    //Si el año ingresado es múltiplo de 400 o es múltiplo de 4 pero no múltiplo de 100 entonces es bisiesto
    if( !( n % 400 ) )
        return true;
    if( !( n % 4 ) && ( n % 100 ) )
        return true;
    //En caso de no cumplirse ninguna condición anterior el año no es bisiesto
    return false;
}

void ejercicio3(){
    int y;
    //Ingreso del dato
    cout << "Ingrese el año: "; cin >> y;
    //Validación de si es bisiesto o no
    if(esBisiesto(y))
        cout << "Es bisiesto!" << endl;
    else
        cout << "No es bisiesto!" << endl;
}

//Función para calcular el día después de la fecha ingresada
void diaDespues( int dd,  int mm, int aa ){
    //Validación que sean fechas positivas o mayores que 1
    if(dd < 1 || mm < 1 || aa < 0){
        cout << "Error de digitacion" << endl;
        return;
    }
    //Validación que no se ingrese una mayor cantidad de días en el mes correspondiente
    if(dd > diasPorMes(mm,aa)){
        cout << "Error de digitacion" << endl;
        return;
    }
    //Si no hay problema en las fechas se procede a calcular el día después
    else{
        //Si es el último día del mes se cambia al siguiente
        if(dd == diasPorMes(mm,aa)){
            dd = 1;
            mm += 1;
        }
        else{
            dd++;
        }

        //Se verifica si se llegó a final de año
        if(mm == 13){
            aa++;
            mm = 1;
        }
    }
    //Se muestra la fecha con formato dd/mm/yyyy
    cout << "La fecha luego de 1 dia es:\n";
    cout << setw(2) << setfill('0') << dd;
    cout << "/";
    cout << setw(2) << setfill('0') << mm;
    cout << "/" << aa << endl;
    
}

//Función que devuelve la cantidad de días de un mes según el año
int diasPorMes(const int &mes, const int &yy){
    switch(mes){
        //Meses con 30 días
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        //Meses con 31 días
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        //Días de febrero en función de si el año es bisiesto
        case 2:
            if(esBisiesto(yy))
                return 29;
            else
                return 28;
        //Si se ingresó un mes inexistente devuelve -1
        default:
            return -1;
    }
}

void ejercicio4(){
    int day, month, year;
    //Se solicitan los datos
    cout << "Ingrese el dia: "; cin >> day;
    cout << "Ingrese el mes: "; cin >> month;
    cout << "Ingrese el año: "; cin >> year;
    //Llamada a función con los datos previamente ingresados
    diaDespues(day,month,year);
}