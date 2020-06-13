#include<iostream>
#include<iomanip>

using namespace std;

//Prototipos
void iterar_menu();
void jugar();

int main(){
    
    system("clear");
    iterar_menu();

    return 0;
}

//Función que repetirá el menú hasta que el usuario decida salir
void iterar_menu(){
    char opc;
    //Bucle de estado de juego
    do{
        //Limpia la pantalla (Solo funciona en terminales bash)
        system("clear");
        //Mensaje de bienvenida y entrada del usuario
        cout << "Bievenido al programa\nIngrese una opción:\n1-Jugar\n2-Salir\n";
        cin >> opc;
        switch(opc){
            //Si el usuario decide jugar
            case '1':
                system("clear");
                jugar();
                break;
            //Si el usuario decide salir
            case '2':
                cout << "Gracias por usar el programa!" << endl;
                break;
            //El usuario ingresa un valor incorrecto
            default:
                cout << "El valor ingresado no es correcto.\n";
                opc = '1';
                //Equivalente al comando "pause" (solo funciona en terminales bash)
                system("read -p \"Pulse una tecla para continuar...\"");
        }
    }while(opc == '1');
}
void jugar(){
    //Variables de juego
    int intentos = 5;
    int num;
    int respuesta = 50;
    cout << "A continuación tendrá 5 intentos para intentar adivinar el número mágico\n";
    //Bucle para 5 intentos
    for(int i = 1; i <= intentos; i++){
        //El intento actual está en la variable i
        cout << "Intento " << i << "\n";
        cout << "Ingrese un número: "; cin >> num;
        //Verificación si el número es mayor, menor o igual
        if(num > respuesta){
            cout << "Prueba un número más pequeño!\n";
        }
        else if(num < respuesta){
            cout << "Prueba un número más grande!\n";
        }
        else{
            //Si el número es igual da un mensaje de felicitaciones y termina el juego volviendo a la función que itera el menú
            cout << "Felicidades! Adivinaste el número\n";
            system("read -p \"Pulse una tecla para continuar...\"");
            return;
        }
    }
    //Llegar hasta acá significa que se cumplieron los 5 intentos
    cout << "Se han agotado los intentos! Gracias por jugar.\n";
    system("read -p \"Pulse una tecla para continuar...\"");
}