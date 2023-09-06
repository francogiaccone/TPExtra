/*Hacer un programa que gestione los datos de stock de una tienda de comestibles, la información a recoger será: nombre del producto, precio, cantidad en stock. 
La tienda no llega a disponer de mas de 100 productos distintos. El programa debe ser capaz de:

Dar de alta un producto nuevo.
Buscar un producto por su nombre.
Modificar el stock y precio de un producto dado.
Calcular y mostrar el monto total acumulado del stock */

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {

    struct Producto
    {
        char nombre[30];
        double precio;
        int stock;
    };

    struct Producto tienda[100];
    int indiceTienda = 0; 

    int opc;
    do
    {
        cout << "MENU TIENDA" << endl;

        cout << "1- Dar de alta un producto nuevo." << endl;
        cout << "2- Buscar un producto por su nombre." << endl;
        cout << "3- Modificar el stock y precio de un producto dado." << endl;
        cout << "4- Calcular y mostrar el monto total acumulado del stock." << endl;
        cout << "5- Salir" << endl;
        cin >> opc;
        fflush(stdin);

        switch (opc)
        {
        case 1:
        {
            if (indiceTienda == 99)
            {
                cout << "No se puede agregar mas productos, tienda llena" << endl;
                break;
            }
            char nombre[30];
            double precio;
            int stock;
            cout << "Ingrese el nombre del producto: ";
            cin.getline(nombre, 30, '\n');
            cout << "Ingrese el precio: ";
            cin >> precio;
            cout << "Ingrese el stock";
            cin >> stock;

            // crear producto y agregarlo a tienda
            struct Producto prod;
            strcpy(prod.nombre, nombre);
            prod.precio = precio;
            prod.stock = stock;

            tienda[indiceTienda++] = prod;
            break;
        }
        case 2:
        {
            char nombreBuscar[30];
            cout << "Ingrese el nombre a buscar: ";
            cin.getline(nombreBuscar, 30, '\n');

            bool flag = false;

            for (int i = 0; i < indiceTienda; i++)
            {
                if (strcmpi(tienda[i].nombre, nombreBuscar) == 0)
                {
                    cout << "Producto encontrado en la posicion " << i << endl;
                    cout << "Nombre: " << tienda[i].nombre << endl;
                    cout << "Precio: " << tienda[i].precio << endl;
                    cout << "Stock: " << tienda[i].stock << endl;
                    cout << endl;
                    flag = true;
                }
            }

            if (!flag)
            {
                cout << "No se encontró ningun producto " << nombreBuscar << endl;
            }

            break;
        }

        case 3:
        {
            char nombreProdModificado[30];
            cout << "Ingrese el nombre del producto a modificar: ";
            cin.getline(nombreProdModificado, 30, '\n');

            bool flag = false;
            for (int i = 0; i < indiceTienda; i++)
            {
                if (strcmpi(tienda[i].nombre, nombreProdModificado) == 0)
                {
                    flag = true;
                    cout << "Ingrese el nuevo precio: " << endl;
                    cin >> tienda[i].precio;

                    cout << "Ingrese el nuevo stock: " << endl;
                    cin >> tienda[i].stock;

                    cout << "Producto modificado correctamente." << endl;
                    break;
                }
            }

            if (!flag)
            {
                cout << "No se encontró ningun producto " << nombreProdModificado << endl;
            }
            break;
        }

        case 4:
        {
            double suma = 0;
            for (int i = 0; i < indiceTienda; i++)
            {
                suma += tienda[i].stock * tienda[i].precio;
            }

            cout << "El monto total de la tienda es: " << suma << endl;
            break;
        }

        case 5: 
        {
            cout << "Saliste del programa" << endl;
        }
        
        default:
        {
            cout << "Ingrese una opción correcta." << endl;
        }
        }
    } while (opc != 5);
    
    
    return 0;
}