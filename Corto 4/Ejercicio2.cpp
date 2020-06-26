#include<iostream>
#include<iomanip>

using namespace std;
//Cantidad de alumnos para obtener su media
const short tEstudiantes = 25;

//Prototipos de funciones
float calcularMedia(float estaturas[]);
void contarSegunMedia(float estaturas[], float media);

int main(){
    //Se declara un arreglo que va a almacenar tantas estaturas como alumnos
    //se hayan definido
    float estaturaAlumnos[tEstudiantes];

    //Se lee la estatura de cada alumno
    cout << "Ingrese la estatura de los alumnos(en metros):\n";
    for(int i = 0; i < tEstudiantes; i++){
        cout << "Estatura del alumno " << i + 1 << ": ";
        cin >> estaturaAlumnos[i];
    }

    //Se llama a la función encargada de contar la media
    //al mismo tiempo que se calcula la media de los alumnos
    contarSegunMedia( estaturaAlumnos, calcularMedia(estaturaAlumnos) );

    return 0;
}

//Función para calcular la media.
//Recibe un arreglo con las estaturas,
float calcularMedia(float estaturas[]){
    float media = 0;
    //Se suman todos los valores de estatura de cada alumno
    for(int i = 0; i < tEstudiantes; i++){
        media += estaturas[i];
    }
    //Se devuelve el valor de la suma entre la cantidad de estudiantes definida anteriormente
    return (media / tEstudiantes);
}

//Función para contar la media de los alumnos
void contarSegunMedia(float estaturas[], float media){
    int arribaMedia = 0, abajoMedia = 0, igualMedia = 0;
    //Se recorre todo el arreglo de estudiantes
    for(int i = 0; i < tEstudiantes; i++){
        //Se verifica si está
        //arriba de la media de estatura, debajo
        //de la media de estatura o si su estatura
        //es igual a la media
        if(estaturas[i] > media)
            arribaMedia++;
        else if (estaturas[i] < media)
            abajoMedia++;
        else
            igualMedia++;
    }

    //Se muestran los resultados del conteo
    cout << fixed << setprecision(2) << "\n\nLa media de estaturas es: " << media << "m \n";
    cout << "La cantidad de estudiantes con estatura arriba de la media es: " << arribaMedia << '\n';
    cout << "La cantidad de estudiantes con estatura abajo de la media es: " << abajoMedia << '\n';
    cout << "La cantidad de estudiantes con estatura igual a la media es: " << igualMedia << '\n';
    
}