#include <iostream>

using namespace std;

#include "clases/Empleado/Empleado.h"
#include "clases/Mozo/Mozo.h"
#include "clases/Repartidor/Repartidor.h"
#include "clases/Cliente/Cliente.h"
#include "datatypes/Cliente/dtCliente.h"
#include "datatypes/Direccion/dtDireccion.h"
#include "clases/Mesa/Mesa.h"
#include "clases/Producto/Producto.h"
#include "clases/Producto/Plato.h"
#include "clases/Producto/Menu.h"
#include "clases/Venta/Venta.h"
#include "clases/Factura/Factura.h"
#include "clases/Producto/Producto.h"
#include "clases/ProductoVenta/ProductoVenta.h"
#include "clases/MenuPlato/MenuPlato.h"

int main()
{
    cout << "-- Creando objetos --" << endl;

    Mozo *mz1 = new Mozo(1, "Carlos Lopez");
    Mozo *mz2 = new Mozo(2, "Ana Perez");
    Repartidor *rp1 = new Repartidor(1, "Luis Gomez", Bicicleta);
    Repartidor *rp2 = new Repartidor(2, "Maria Sanchez", Auto);
    dtDireccion direccion = dtDireccion("Avenida Siempre Viva", 742, "Entre Calle Falsa y Calle Verdadera");
    dtCliente cliente = dtCliente("Pedro Ramirez", "123456789", direccion);
    Cliente *cl1 = new Cliente(cliente);
    Mesa *mesa1 = new Mesa(1);
    Mesa *mesa2 = new Mesa(2);
    Plato *plato1 = new Plato("P001", "Ensalada Cesar", 150.0);
    Plato *plato2 = new Plato("P002", "Pizza Margherita", 200.0);
    Plato *plato3 = new Plato("P003", "Sopa de Verduras", 100.0);
    Plato **platos = new Plato *[2];
    platos[0] = plato1;
    platos[1] = plato2;
    platos[2] = plato3;
    Producto **productos = new Producto *[2];
    productos[0] = plato1;
    productos[1] = plato2;
    productos[2] = plato3;
    Menu *menu1 = new Menu("M001", "Menu del Dia", 300.0, platos);
    Venta *venta1 = new Venta(2, 350, 10, productos, 3);
    Venta *venta2 = new Venta(3, 500, 20, productos, 3);
    ProductoVenta *productoVenta1 = new ProductoVenta(venta1, plato1, 2);
    ProductoVenta *productoVenta2 = new ProductoVenta(venta2, plato2, 1);
    MenuPlato *menuPlato1 = new MenuPlato(plato1, menu1, 3);
    cout << "-- Objetos creados --" << endl;
    return 0;
}