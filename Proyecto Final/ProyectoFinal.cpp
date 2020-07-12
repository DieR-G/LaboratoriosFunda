#include<iostream>
#include<iomanip>
using namespace std;
//Estructura para guardar los productos
const int longCad = 20;
struct costoPorArticulo{
    char nombreArticulo[longCad + 1];
    int cantidad;
    float precio;
    float costoPorArticulo;
};

//Prototipos
void leerProductos(costoPorArticulo *articulos, const int tam);
void calcularCosto(costoPorArticulo *articulos, const int tam);
void mostrarArticulos(costoPorArticulo *articulos, const int tam);
void mostrarTotal(costoPorArticulo *articulos, const int tam);

int main(){
    int numArticulos = 0;
    //Validación para recibir únicamente cantidades positivas
    do{
        cout << "Bienvenido/a al programa.\nIngrese la cantidad de artículos a comprar: "; 
        cin >> numArticulos;
    }while(numArticulos <= 0);
    
    //Se declara el total de artículos como un arreglo dinámico de la dimensión que ingresó el usuario
    costoPorArticulo *factura = new costoPorArticulo[numArticulos];
    
    leerProductos(factura, numArticulos);
    calcularCosto(factura,numArticulos);
    mostrarArticulos(factura, numArticulos);
    mostrarTotal(factura, numArticulos);
    //Se libera la memoria donde se almacenaron los artículos
    delete [] factura;
    return 0;
}

//Función para leer los datos de cada producto
void leerProductos(costoPorArticulo *articulos, int tam){
    for(int i = 0; i < tam; i++){
        cout << "\nIngrese los datos del producto " << i + 1 << " \n";
        cout << "Nombre del artículo: "; 
        //Se utiliza el ignore para borrar el caracter '\n' que quedó en el búfer por la entrada anterior
        cin.ignore();
        cin.getline(articulos[i].nombreArticulo, 20);
        
        do{
            cout << "Cantidad del artículo: "; 
            cin >> articulos[i].cantidad;
        } while (articulos[i].cantidad <= 0);
        
        do{
            cout << "Precio del artículo: $"; 
            cin >> articulos[i].precio;
        } while (articulos[i].precio <= 0.0f);
        
        cout << '\n';
    }
    
}

//Función para obtener el costo total según la cantidad de artículos y su precio
void calcularCosto(costoPorArticulo *articulos, int tam){
    for(int i = 0; i < tam; i++)
        articulos[i].costoPorArticulo = (float)articulos[i].cantidad * articulos[i].precio;
}

void mostrarArticulos(costoPorArticulo *articulos, const int tam){
    //Cabecera de la tabla
    cout << "┌─────┬─────────────────────┬──────────┬────────────┬────────────────┐\n";
    cout << "│ n°  │ Nombre del producto │ Cantidad │   Precio   │ Valor de venta │\n";
    cout << "├─────┼─────────────────────┼──────────┼────────────┼────────────────┤\n";
    
    //Se muestra cada dato del producto manteniendo el formato de tabla
    //left/rigth definen la alineación que va a tener el texto en esa línea
    //setfill establece el caracter de relleno
    //setw establece el ancho mínimo que debe tener cada línea, si el ancho 
    //es menor rellena lo que falte con el caracter especificado en setfill
    //fixed y setprecision(2) hacen que se muestren los números flotantes siempre con 2 decimales
    for(int i = 0; i < tam; i++){
        cout << "│ ";
        cout << setfill(' ') << left << setw(4) << i+ 1;

        cout << "│ ";
        cout << left << setw(20) << setfill(' ') << articulos[i].nombreArticulo;

        cout << "│ ";
        cout << right << setw(8) << setfill(' ') << articulos[i].cantidad;

        cout << " │ $";
        cout << right << setw(9) << setfill(' ') << setprecision(2) << fixed << articulos[i].precio;

        cout << " │ $";
        cout << right << setw(13) << setfill(' ') << setprecision(2) << fixed << articulos[i].costoPorArticulo;
        cout << " │\n";

        //Se verifica si no es el último producto para mantener el formato de la tabla 
        if(i != tam - 1)
            cout << "├─────┼─────────────────────┼──────────┼────────────┼────────────────┤\n";
        else
            cout << "├─────┴─────────┬───────────┴──────────┴────────────┴────────────────┤\n";
    }
}

//Función que calcula y muestra el total de los artículos
void mostrarTotal(costoPorArticulo *articulos, const int tam){
    float total = 0.0f;
    for(int i = 0; i < tam; i++){
        total += articulos[i].costoPorArticulo; 
    }
    //Muestra el total a pagar con formato
    cout << "│ Total a pagar │";
    cout<< " $ ";
    cout << fixed << setprecision(2) << right << setw(48) << setfill(' ') << total;
    cout << " │\n";
    //Pie de la tabla
    cout << "└───────────────┴────────────────────────────────────────────────────┘\n";
}
