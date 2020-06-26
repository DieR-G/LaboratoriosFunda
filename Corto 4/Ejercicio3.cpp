#include<iostream>
#include<iomanip>

using namespace std;

//Prototipos de funciones
void dibujarEncabezado();
void llenarMatrizNotas(float** boleta, int estudiantes);
void desplegarResultados(float** boleta, int estudiantes);

int main(){
    //Se ingresa la cantidad de estudiantes
    int n = 0;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    //Como la cantidad de estudiantes no es fija
    //sino que depende del valor ingresado por el usuario,
    //la matriz de notas debe ser dinámica
    //por lo que es necesario declarar un puntero a un puntero
    float **notas;

    //notas va a guardar un puntero
    //a la dirección del inicio de
    //un arreglo de punteros, dicho
    //arreglo en memoria se vería como
    //arreglo[0] -> punteroFloat
    //arreglo[1] -> punteroFloat
    //arreglo[2] -> punteroFloat
    //arreglo[3] -> punteroFloat
    //arreglo[4] -> punteroFloat
    notas = new float* [n];

    //Se inicializa cada puntero
    //del arreglo de punteros
    //como un arreglo de flotantes,
    //en memoria se vería como:
    //notas[i] = [numf][numf][numf][numf][numf]
    for (int i = 0; i < n; i++)
        notas[i] = new float[5];

    //Ahora que ya se tiene definida la nueva matriz
    //de n x 5 ya se puede realizar el cálculo de notas

    //Se reciben los datos y se despliegan
    llenarMatrizNotas(notas, n);
    desplegarResultados(notas, n);
    
    //Como la matriz fue creada con memoria dinámica
    //es necesario liberarla una vez fue utilizada
    //para evitar fugas de memoria.
    //Primero se borra cada arreglo de punteros 
    //contenido en la posición notas[i]
    for (int i = 0; i < n; i++)
        delete [] notas[i];
    //Una vez todos estos arreglos de flotantes fueron borrados
    //solo queda borrar el arreglo de punteros de la memoria
    delete[] notas;

    return 0;
}

//Función para llenar la matriz de notas.
//Recibe la matriz y la cantidad de estudiantes
void llenarMatrizNotas(float** boleta, int estudiantes) {
    for (int i = 0; i < estudiantes; i++) {
        for (int j = 0; j < 5; j++) {
            //Se solicita la nota i de cada estudiante j
            cout << "Ingrese la nota " << j + 1 << " del estudiante " << i + 1 << " : ";
            cin >> boleta[i][j];
        }
        cout << '\n';
    }
}

//Función para mostrar los resultados con formato
void desplegarResultados(float** boleta, int estudiantes) {
    //Variable auxiliar para calcular la nota de cada estudiante
    float notaAux = 0;

    //Dibuja el encabezado de la tabla
    dibujarEncabezado();
    
    for (int i = 0; i < estudiantes; i++) {
        //Se muestra el estudiante i
        cout << "║";
        cout  << setfill(' ') <<setw(7) << right << i + 1;
        cout << setfill(' ') << setw(6) << ' ';
        cout << "║";

        for (int j = 0; j < 5; j++) {
            //Se realiza una suma ponderada de cada nota y se muestra el valor de la nota actual
            notaAux += boleta[i][j] * 0.2;
            cout << fixed << setfill(' ') << setw(7) << right <<  setprecision(2) << boleta[i][j] << " ║";
        }
        //Al final la suma total de las ponderaciones representaría
        //el 100% de la nota final
        cout << setw(4) << setfill(' ') << ' ';
        cout << setw(9) << setfill(' ') << left << setprecision(2) << fixed << notaAux;
        cout << "║ ";
        //Se verifica si la nota es menor que 6
        if(notaAux < 6.0f){
            //En caso de serlo el estudiante se muestra como reprobado
            cout << "Reprobado\n";
        }
        else{
            //De lo contrario se muestra como aprobado
            cout << "Aprobado\n";
        }

        //Se verifica si no es el último estudiante para mantener el formato de la tabla
        if(i != estudiantes - 1)
            cout << "╠═════════════╬════════╬════════╬════════╬════════╬════════╬═════════════╣\n";
        //Se inicializa de nuevo la variable auxiliar para los siguientes estudiantes
        notaAux = 0;
    }

    cout << "╚═════════════╩════════╩════════╩════════╩════════╩════════╩═════════════╝";

}

void dibujarEncabezado() {
    cout << "╔═════════════╦════════╦════════╦════════╦════════╦════════╦═════════════╗\n";
    cout << "║ Estudiante: ║ nota 1 ║ nota 2 ║ nota 3 ║ nota 4 ║ nota 5 ║ Nota Final: ║\n";
    cout << "╠═════════════╬════════╬════════╬════════╬════════╬════════╬═════════════╣\n";
}