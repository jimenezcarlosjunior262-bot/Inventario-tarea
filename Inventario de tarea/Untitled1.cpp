#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

// =====================================================
// CLASE PRODUCT
// Contiene nombre, precio y cantidad
// =====================================================
class Product
{
public:
    string name;
    double price;
    int quantity;

    // Constructor
    Product(string n, double p, int q)
    {
        name = n;
        price = p;
        quantity = q;
    }
};

// =====================================================
// FUNCION PARA MOSTRAR UN PRODUCTO
// =====================================================
void MostrarProducto(const Product& producto)
{
    cout << left
         << setw(15) << producto.name
         << setw(12) << fixed << setprecision(2) << producto.price
         << setw(10) << producto.quantity
         << endl;
}

// =====================================================
// FUNCION PARA ORDENAR LOS PRODUCTOS POR PRECIO
// DE MENOR A MAYOR
// =====================================================
void OrdenarPorPrecio(vector<Product>& productos)
{
    sort(productos.begin(), productos.end(),
        [](const Product& a, const Product& b)
        {
            return a.price < b.price;
        });
}

// =====================================================
// FUNCION PARA BUSCAR UN PRODUCTO POR NOMBRE
// =====================================================
int BuscarProducto(const vector<Product>& productos, string nombre)
{
    for (int i = 0; i < productos.size(); i++)
    {
        if (productos[i].name == nombre)
        {
            return i;
        }
    }

    return -1;
}

// =====================================================
// FUNCION RECURSIVA
// CALCULA EL TOTAL DE UNIDADES DISPONIBLES
// =====================================================
int CalcularTotalRecursivo(const vector<Product>& productos, int indice)
{
    // CASO BASE
    if (indice >= productos.size())
    {
        return 0;
    }

    // LLAMADA RECURSIVA
    return productos[indice].quantity +
           CalcularTotalRecursivo(productos, indice + 1);
}

// =====================================================
// PROGRAMA PRINCIPAL
// =====================================================
int main()
{
    // Crear lista de productos
    vector<Product> productos;

    // =================================================
    // REGISTRO DE PRODUCTOS
    // =================================================
    productos.push_back(Product("Arroz", 50.00, 10));
    productos.push_back(Product("Leche", 75.00, 5));
    productos.push_back(Product("Pan", 40.00, 20));
    productos.push_back(Product("Aceite", 120.00, 8));

    // =================================================
    // MOSTRAR PRODUCTOS ORIGINALES
    // =================================================
    cout << "==============================================" << endl;
    cout << "          SISTEMA DE INVENTARIO" << endl;
    cout << "==============================================" << endl;

    cout << endl;
    cout << "PRODUCTOS REGISTRADOS:" << endl;
    cout << "----------------------------------------------" << endl;

    cout << left
         << setw(15) << "Producto"
         << setw(12) << "Precio"
         << setw(10) << "Cantidad"
         << endl;

    cout << "----------------------------------------------" << endl;

    for (const Product& producto : productos)
    {
        MostrarProducto(producto);
    }

    // =================================================
    // ORDENAR POR PRECIO ASCENDENTE
    // =================================================
    OrdenarPorPrecio(productos);

    cout << endl;
    cout << "PRODUCTOS ORDENADOS POR PRECIO ASCENDENTE:" << endl;
    cout << "----------------------------------------------" << endl;

    cout << left
         << setw(15) << "Producto"
         << setw(12) << "Precio"
         << setw(10) << "Cantidad"
         << endl;

    cout << "----------------------------------------------" << endl;

    for (const Product& producto : productos)
    {
        MostrarProducto(producto);
    }

    // =================================================
    // BUSCAR PRODUCTO POR NOMBRE
    // =================================================
    string nombreBuscado;

    cout << endl;
    cout << "==============================================" << endl;
    cout << "BUSCAR PRODUCTO" << endl;
    cout << "==============================================" << endl;

    cout << "Escriba el nombre del producto: ";
    cin >> nombreBuscado;

    int posicion = BuscarProducto(productos, nombreBuscado);

    if (posicion != -1)
    {
        cout << endl;
        cout << "PRODUCTO ENCONTRADO:" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Nombre:   " << productos[posicion].name << endl;
        cout << "Precio:   $" << fixed << setprecision(2)
             << productos[posicion].price << endl;
        cout << "Cantidad: " << productos[posicion].quantity << endl;
    }
    else
    {
        cout << endl;
        cout << "Producto no encontrado." << endl;
    }

    // =================================================
    // CALCULAR TOTAL MEDIANTE RECURSIVIDAD
    // =================================================
    int totalUnidades = CalcularTotalRecursivo(productos, 0);

    cout << endl;
    cout << "==============================================" << endl;
    cout << "TOTAL DE UNIDADES DISPONIBLES" << endl;
    cout << "==============================================" << endl;

    cout << "Total de unidades: " << totalUnidades << endl;

    cout << endl;
    cout << "==============================================" << endl;
    cout << "          FIN DEL PROGRAMA" << endl;
    cout << "==============================================" << endl;

    return 0;
}