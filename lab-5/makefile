OS := $(shell uname -s)

ifeq ($(findstring MINGW,$(OS)),MINGW)
    DELETE := rm -f
else ifeq ($(findstring MSYS,$(OS)),MSYS)
    DELETE := rm -f
else ifeq ($(OS),Linux)
    DELETE := rm -f
else ifeq ($(OS),Darwin)
    DELETE := rm -f
else
    DELETE := rm -f  
endif

all: programa

programa: ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o Integer.o String.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o  ISistema.o utils.o DtCliente.o Plato.o Menu.o MenuPlato.o DtFecha.o DtConsumido.o DtHora.o DtFacturaLocal.o DtFacturaDomicilio.o DtFactura.o FacturaLocal.o FacturaDomicilio.o Factura.o DtInforme.o Producto.o ProductoVenta.o  VentaLocal.o VentaDomicilio.o Venta.o DtInfoProducto.o DtMenu.o DtPlato.o DtProducto.o  DtDireccionApto.o DtDireccionCasa.o DtDireccion.o Cliente.o Mesa.o Mozo.o Repartidor.o Empleado.o Sistema.o Factory.o main.o
	g++ $^ -o programa 

ICollectible.o: 
	g++ -c "ICollection/interfaces/ICollectible.cpp"

ICollection.o:
	g++ -c "ICollection/interfaces/ICollection.cpp"

IDictionary.o:
	g++ -c "ICollection/interfaces/IDictionary.cpp"

IIterator.o:
	g++ -c "ICollection/interfaces/IIterator.cpp"

IKey.o:
	g++ -c "ICollection/interfaces/IKey.cpp"

OrderedKey.o: IKey.o
	g++ -c "ICollection/interfaces/OrderedKey.cpp"

Integer.o: ICollectible.o OrderedKey.o
	g++ -c "ICollection/Integer.cpp"

String.o: ICollectible.o OrderedKey.o
	g++ -c "ICollection/String.cpp"

List.o: ICollection.o
	g++ -c "ICollection/collections/List.cpp"

ListIterator.o: IIterator.o
	g++ -c "ICollection/collections/ListIterator.cpp"

ListNode.o:
	g++ -c "ICollection/collections/ListNode.cpp"

OrderedDictionary.o: IDictionary.o
	g++ -c "ICollection/collections/OrderedDictionary.cpp"

OrderedDictionaryEntry.o:
	g++ -c "ICollection/collections/OrderedDictionaryEntry.cpp"

main.o:
	g++ -c main.cpp

utils.o: 
	g++ -c "utils/utils.cpp"

Sistema.o: ISistema.o 
	g++ -c "clases/Sistema/Sistema.cpp"

ISistema.o: 
	g++ -c "clases/Sistema/ISistema.cpp"

Factory.o: ISistema.o Sistema.o
	g++ -c "clases/Factory/Factory.cpp"

FacturaLocal.o: Factura.o 
	g++ -c "clases/Factura/FacturaLocal.cpp"

FacturaDomicilio.o: Factura.o
	g++ -c "clases/Factura/FacturaDomicilio.cpp"

Factura.o: DtConsumido.o DtFecha.o DtHora.o DtFactura.o
	g++ -c "clases/Factura/Factura.cpp"

VentaLocal.o: Venta.o
	g++ -c "clases/Venta/VentaLocal.cpp"

VentaDomicilio.o: Venta.o
	g++ -c "clases/Venta/VentaDomicilio.cpp"

Venta.o: Producto.o Factura.o
	g++ -c "clases/Venta/Venta.cpp"

Plato.o: Producto.o
	g++ -c "clases/Producto/Plato.cpp"

Menu.o: Plato.o Producto.o
	g++ -c "clases/Producto/Menu.cpp"

MenuPlato.o: Plato.o Menu.o
	g++ -c "clases/Producto/MenuPlato.cpp"

Producto.o: 
	g++ -c "clases/Producto/Producto.cpp"

DtFacturaLocal.o: DtFactura.o
	g++ -c "datatypes/Factura/DtFacturaLocal.cpp"

DtFacturaDomicilio.o: DtFactura.o
	g++ -c "datatypes/Factura/DtFacturaDomicilio.cpp"

DtFactura.o: DtConsumido.o DtFecha.o DtHora.o
	g++ -c "datatypes/Factura/DtFactura.cpp"

DtInforme.o: 
	g++ -c "datatypes/Informe/DtInforme.cpp"

DtInfoProducto.o: DtProducto.o
	g++ -c "datatypes/InfoProducto/DtInfoProducto.cpp"

DtMenu.o: DtProducto.o
	g++ -c "datatypes/Producto/DtMenu.cpp"

DtPlato.o: DtProducto.o
	g++ -c "datatypes/Producto/DtPlato.cpp"

DtProducto.o:
	g++ -c "datatypes/Producto/DtProducto.cpp"

DtConsumido.o:
	g++ -c "datatypes/Consumido/DtConsumido.cpp"

DtDireccionApto.o: DtDireccion.o
	g++ -c  "datatypes/Direccion/DtDireccionApto.cpp"

DtDireccionCasa.o: DtDireccion.o
	g++ -c  "datatypes/Direccion/DtDireccionCasa.cpp"

DtDireccion.o:
	g++ -c  "datatypes/Direccion/DtDireccion.cpp"

DtFecha.o:
	g++ -c  "datatypes/Fecha/DtFecha.cpp"

DtHora.o:
	g++ -c  "datatypes/Hora/DtHora.cpp"

DtCliente.o: DtDireccion.o
	g++ -c "datatypes/Cliente/DtCliente.cpp"

Cliente.o: DtCliente.o DtDireccion.o
	g++  -c "clases/Cliente/Cliente.cpp"

Mesa.o: 
	g++  -c "clases/Mesa/Mesa.cpp"

Mozo.o: Empleado.o 
	g++  -c "clases/Empleado/Mozo.cpp"

Repartidor.o: Empleado.o
	g++  -c "clases/Empleado/Repartidor.cpp"

ProductoVenta.o: Producto.o Venta.o
	g++  -c "clases/ProductoVenta/ProductoVenta.cpp"

Empleado.o:
	g++  -c "clases/Empleado/Empleado.cpp"

clean:
	$(DELETE) *.o programa*

run: clean all
	./programa
	$(MAKE) clean
