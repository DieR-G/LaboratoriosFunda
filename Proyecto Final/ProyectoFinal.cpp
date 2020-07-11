#include<iostream>
#include<iomanip>

using namespace std;

const int longCad = 20;
//Estructura para guardar los productos
struct costoPorArticulo{
    char nombreArticulo[longCad + 1];
    int cantidad = 0;
    float precio = 0.0f;
    float costoPorArticulo = 0.0f;
};

//Prototipos
void leerProductos(costoPorArticulo *articulos, int t);
void calcularCosto(costoPorArticulo &articulo);
void mostrarArticulos(costoPorArticulo *articulos, const int t);
void mostrarTotal(costoPorArticulo *articulos, const int t);

int main(){
    int numArticulos = 0;
    cout << "Bienvenido/a al programa.\nIngrese la cantidad de artículos a comprar: "; 
    cin >> numArticulos;
    //Se declara el total de artículos como un arreglo dinámico de la dimensión que ingresó el usuario
    costoPorArticulo *factura = new costoPorArticulo[numArticulos];
    
    leerProductos(factura, numArticulos);
    mostrarArticulos(factura, numArticulos);
    mostrarTotal(factura, numArticulos);
    //Se libera la memoria donde se almacenaron los artículos
    delete [] factura;
    return 0;
}

//Función para leer los datos de cada producto
void leerProductos(costoPorArticulo *articulos, int t){
    for(int i = 0; i < t; i++){
        cout << "\nIngrese los datos del producto " << i + 1 << " \n";
        cout << "Nombre del artículo: "; 
        //Se utiliza el ignore para borrar el caracter '\n' que quedó en el buffer por la entrada anterior
        cin.ignore();
        cin.getline(articulos[i].nombreArticulo, 20);

        cout << "Cantidad del artículo: "; 
        cin >> articulos[i].cantidad;

        cout << "Precio del artículo: $"; 
        cin >> articulos[i].precio;

        cout << '\n';
        //Se calcula el costo total de cada artículo
        calcularCosto(articulos[i]);
    }
    
}

//Función para obtener el costo total según la cantidad de artículos y su precio
void calcularCosto(costoPorArticulo &articulo){
    articulo.costoPorArticulo = (float)articulo.cantidad * articulo.precio;
}

void mostrarArticulos(costoPorArticulo *articulos, const int t){
    //Cabecera de la tabla
    cout << "┌─────┬─────────────────────┬──────────┬────────────┬────────────────┐\n";
    cout << "│ n°  │ Nombre del producto │ Cantidad │   Precio   │ Valor de venta │\n";
    cout << "├─────┼─────────────────────┼──────────┼────────────┼────────────────┤\n";
    
    //Se muestra cada dato del producto manteniendo el formato de tabla
    for(int i = 0; i < t; i++){
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
        if(i != t - 1)
            cout << "├─────┼─────────────────────┼──────────┼────────────┼────────────────┤\n";
        else
            cout << "├─────┴─────────┬───────────┴──────────┴────────────┴────────────────┤\n";
    }
}

//Función que calcula y muestra el total de los artículos
void mostrarTotal(costoPorArticulo *articulos, const int t){
    float total = 0.0f;
    for(int i = 0; i < t; i++){
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