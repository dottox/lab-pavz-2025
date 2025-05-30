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

INCLUDES = -Idatatypes -Iclases -Iclases/Empleado -Iclases/Repartidor -Iclases/Mesa -Iclases/Mozo

all: programa

programa: main.o dtCliente.o Plato.o Menu.o MenuPlato.o dtFecha.o dtConsumido.o dtHora.o FacturaLocal.o FacturaDomicilio.o Factura.o Producto.o VentaLocal.o VentaDomicilio.o Venta.o  ProductoVenta.o dtFacturaLocal.o dtFacturaDomicilio.o dtFactura.o dtRepartidor.o dtInfoProducto.o dtMenu.o dtPlato.o dtProducto.o  dtDireccionApto.o dtDireccion.o Cliente.o Mesa.o Mozo.o Repartidor.o Empleado.o
	g++ $^ -o programa

main.o:
	g++ -c main.cpp


FacturaLocal.o: Factura.o 
	g++ -c "clases/Factura/FacturaLocal.cpp"

FacturaDomicilio.o: Factura.o
	g++ -c "clases/Factura/FacturaDomicilio.cpp"

Factura.o: dtConsumido.o dtFecha.o dtHora.o
	g++ -c "clases/Factura/Factura.cpp"

VentaLocal.o: Venta.o
	g++ -c "clases/Venta/VentaLocal.cpp"

VentaDomicilio.o: Venta.o
	g++ -c "clases/Venta/VentaDomicilio.cpp"

Venta.o: Producto.o
	g++ -c "clases/Venta/Venta.cpp"

Plato.o: Producto.o
	g++ -c "clases/Producto/Plato.cpp"

Menu.o: Plato.o Producto.o
	g++ -c "clases/Producto/Menu.cpp"

MenuPlato.o: Plato.o Menu.o
	g++ -c "clases/MenuPlato/MenuPlato.cpp"

Producto.o: 
	g++ -c "clases/Producto/Producto.cpp"

dtFacturaLocal.o: dtFactura.o
	g++ -c "datatypes/Factura/dtFacturaLocal.cpp"

dtFacturaDomicilio.o: dtFactura.o
	g++ -c "datatypes/Factura/dtFacturaDomicilio.cpp"

dtFactura.o: dtConsumido.o dtFecha.o dtHora.o
	g++ -c "datatypes/Factura/dtFactura.cpp"

dtRepartidor.o: 
	g++ -c "datatypes/Repartidor/dtRepartidor.cpp"

dtInfoProducto.o: dtProducto.o
	g++ -c "datatypes/InfoProducto/dtInfoProducto.cpp"

dtMenu.o: dtProducto.o
	g++ -c "datatypes/Producto/dtMenu.cpp"

dtPlato.o: dtProducto.o
	g++ -c "datatypes/Producto/dtPlato.cpp"

dtProducto.o:
	g++ -c "datatypes/Producto/dtProducto.cpp"

dtConsumido.o:
	g++ -c "datatypes/Consumido/dtConsumido.cpp"

dtDireccionApto.o:
	g++ -c  "datatypes/Direccion/dtDireccionApto.cpp"

dtDireccion.o:
	g++ -c  "datatypes/Direccion/dtDireccion.cpp"

dtFecha.o:
	g++ -c  "datatypes/Fecha/dtFecha.cpp"

dtHora.o:
	g++ -c  "datatypes/Hora/dtHora.cpp"

dtCliente.o: dtDireccion.o
	g++  -c "datatypes/Cliente/dtCliente.cpp"

Cliente.o: dtCliente.o dtDireccion.o
	g++  -c "clases/Cliente/Cliente.cpp"

Mesa.o: 
	g++  -c "clases/Mesa/Mesa.cpp"

Mozo.o: Empleado.o 
	g++  -c "clases/Mozo/Mozo.cpp"

Repartidor.o: Empleado.o
	g++  -c "clases/Repartidor/Repartidor.cpp"

ProductoVenta.o: Producto.o Venta.o
	g++  -c "clases/ProductoVenta/ProductoVenta.cpp"

Empleado.o:
	g++  -c "clases/Empleado/Empleado.cpp"

clean:
	$(DELETE) *.o programa*

run: clean all
	./programa
	$(MAKE) clean
	
