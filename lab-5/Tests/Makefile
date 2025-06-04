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

all: tests

#*******************INICIO LIBS**********************
ICollectible.o: 
	g++ -c "../ICollection/interfaces/ICollectible.cpp"

ICollection.o:
	g++ -c "../ICollection/interfaces/ICollection.cpp"

IDictionary.o:
	g++ -c "../ICollection/interfaces/IDictionary.cpp"

IIterator.o:
	g++ -c "../ICollection/interfaces/IIterator.cpp"

IKey.o:
	g++ -c "../ICollection/interfaces/IKey.cpp"

OrderedKey.o: IKey.o
	g++ -c "../ICollection/interfaces/OrderedKey.cpp"

Integer.o: ICollectible.o OrderedKey.o
	g++ -c "../ICollection/Integer.cpp"

String.o: ICollectible.o OrderedKey.o
	g++ -c "../ICollection/String.cpp"

List.o: ICollection.o
	g++ -c "../ICollection/collections/List.cpp"

ListIterator.o: IIterator.o
	g++ -c "../ICollection/collections/ListIterator.cpp"

ListNode.o:
	g++ -c "../ICollection/collections/ListNode.cpp"

OrderedDictionary.o: IDictionary.o
	g++ -c "../ICollection/collections/OrderedDictionary.cpp"

OrderedDictionaryEntry.o:
	g++ -c "../ICollection/collections/OrderedDictionaryEntry.cpp"

#********************FIN LIBS**********************


#*******************INICIO UTILS**********************
utils/funciones.o: ../utils/funciones.cpp
	g++ -c ../utils/funciones.cpp -o utils/funciones.o

utils/utils.o: ../utils/utils.cpp
	g++ -c ../utils/utils.cpp -o utils/utils.o

main_test.o: main_test.cpp
	g++ -c main_test.cpp -o main_test.o

utils/test_funciones.o: utils/test_funciones.cpp
	g++ -c utils/test_funciones.cpp -o utils/test_funciones.o

utils/test_utils.o: utils/test_utils.cpp
	g++ -c utils/test_utils.cpp -o utils/test_utils.o
#*******************FIN UTILS**********************
#*******************INICIO DATATYPES**********************
#---------INICIO DT ASIGNACION-----------------
dtAsignacion.o: ../datatypes/Asignacion/DtAsignacion.cpp
	g++ -c ../datatypes/Asignacion/DtAsignacion.cpp -o dtAsignacion.o

test_dtasignacion.o: datatypes/asignacion/test_dtasignacion.cpp
	g++ -c datatypes/asignacion/test_dtasignacion.cpp -o test_dtasignacion.o
#---------FIN DT ASIGNACION-----------------
#----------INICIO DT DIRECCION-----------------
#INICIO DT DIRECCION
dtDireccion.o: ../datatypes/Direccion/DtDireccion.cpp
	g++ -c ../datatypes/Direccion/DtDireccion.cpp -o dtDireccion.o

test_dtdireccion.o: datatypes/direccion/test_dtdireccion.cpp
	g++ -c datatypes/direccion/test_dtdireccion.cpp -o test_dtdireccion.o
#FIN DT DIRECCION

#INICIO DT DIRECCION APTO
dtDireccionApto.o: ../datatypes/Direccion/DtDireccionApto.cpp
	g++ -c ../datatypes/Direccion/DtDireccionApto.cpp -o dtDireccionApto.o
test_dtdireccionapto.o: datatypes/direccion/test_dtdireccionapto.cpp
	g++ -c datatypes/direccion/test_dtdireccionapto.cpp -o test_dtdireccionapto.o
#FIN DT DIRECICON APTO

#INICIO DT DIRECCION CASA

dtDireccionCasa.o: ../datatypes/Direccion/DtDireccionCasa.cpp
	g++ -c ../datatypes/Direccion/DtDireccionCasa.cpp -o dtDireccionCasa.o
test_dtdireccioncasa.o: datatypes/direccion/test_dtdireccioncasa.cpp
	g++ -c datatypes/direccion/test_dtdireccioncasa.cpp -o test_dtdireccioncasa.o

#FIN DT DIRECCION CASA
#----------FIN DT DIRECCION-----------------
#----------INICIO DT CLIENTE-----------------
dtCliente.o: ../datatypes/Cliente/DtCliente.cpp
	g++ -c ../datatypes/Cliente/DtCliente.cpp -o dtCliente.o

test_dtcliente.o: datatypes/cliente/test_dtcliente.cpp
	g++ -c datatypes/cliente/test_dtcliente.cpp -o test_dtcliente.o
#----------FIN DT CLIENTE--------------------
#----------INICIO DT CONSUMIDO-----------------
dtConsumido.o: ../datatypes/Consumido/DtConsumido.cpp
	g++ -c ../datatypes/Consumido/DtConsumido.cpp -o dtConsumido.o
test_dtconsumido.o: datatypes/consumido/test_dtconsumido.cpp
	g++ -c datatypes/consumido/test_dtconsumido.cpp -o test_dtconsumido.o
#---------FIN DT CONSUMIDO-----------------	
#----------INICIO DT FECHA-----------------
dtFecha.o: ../datatypes/Fecha/DtFecha.cpp
	g++ -c ../datatypes/Fecha/DtFecha.cpp -o dtFecha.o

test_dtfecha.o: datatypes/fecha/test_dtfecha.cpp
	g++ -c datatypes/fecha/test_dtfecha.cpp -o test_dtfecha.o
#----------FIN DT FECHA-----------------
#----------INICIO DT HORA-----------------
dtHora.o: ../datatypes/Hora/DtHora.cpp
	g++ -c ../datatypes/Hora/DtHora.cpp -o dtHora.o

test_dthora.o: datatypes/hora/test_dthora.cpp
	g++ -c datatypes/hora/test_dthora.cpp -o test_dthora.o
#----------FIN DT HORA-----------------
#----------INICIO DT FACTURA-----------------
#DT FACTURA
dtFactura.o: ../datatypes/Factura/DtFactura.cpp
	g++ -c ../datatypes/Factura/DtFactura.cpp -o dtFactura.o
test_dtfactura.o: datatypes/factura/test_dtfactura.cpp
	g++ -c datatypes/factura/test_dtfactura.cpp -o test_dtfactura.o
#FIN DT FACTURA
#DT FACTURA LOCAL
dtFacturaLocal.o: ../datatypes/Factura/DtFacturaLocal.cpp
	g++ -c ../datatypes/Factura/DtFacturaLocal.cpp -o dtFacturaLocal.o
test_dtfacturalocal.o: datatypes/factura/test_dtfacturalocal.cpp
	g++ -c datatypes/factura/test_dtfacturalocal.cpp -o test_dtfacturalocal.o
#FIN DT FACTURA LOCAL
#DT FACTURA DOMICILIO
dtFacturaDomicilio.o: ../datatypes/Factura/DtFacturaDomicilio.cpp
	g++ -c ../datatypes/Factura/DtFacturaDomicilio.cpp -o dtFacturaDomicilio.o
test_dtfacturadomicilio.o: datatypes/factura/test_dtfacturadomicilio.cpp
	g++ -c datatypes/factura/test_dtfacturadomicilio.cpp -o test_dtfacturadomicilio.o
#FIN DT FACTURA DOMICILIO
#----------FIN DT FACTURA-----------------
#----------INICIO DT PRODUCTOS-----------------
#DT PRODUCTO
dtProducto.o: ../datatypes/Producto/DtProducto.cpp
	g++ -c ../datatypes/Producto/DtProducto.cpp -o dtProducto.o
test_dtproducto.o: datatypes/producto/test_dtproducto.cpp
	g++ -c datatypes/producto/test_dtproducto.cpp -o test_dtproducto.o
#FIN DT PRODUCTO
#DT MENU
dtMenu.o: ../datatypes/Producto/DtMenu.cpp
	g++ -c ../datatypes/Producto/DtMenu.cpp -o dtMenu.o
test_dtmenu.o: datatypes/producto/test_dtmenu.cpp
	g++ -c datatypes/producto/test_dtmenu.cpp -o test_dtmenu.o
#FIN DT MENU
#DT PLATO
dtPlato.o: ../datatypes/Producto/DtPlato.cpp
	g++ -c ../datatypes/Producto/DtPlato.cpp -o dtPlato.o
test_dtplato.o: datatypes/producto/test_dtplato.cpp
	g++ -c datatypes/producto/test_dtplato.cpp -o test_dtplato.o
#FIN DT PLATO
#---------FIN DT PRODUCTOS-----------------
#----------INICIO DT MESA------------------
dtMesa.o: ../datatypes/Mesa/DtMesa.cpp
	g++ -c ../datatypes/Mesa/DtMesa.cpp -o dtMesa.o
test_dtmesa.o: datatypes/mesa/test_dtmesa.cpp
	g++ -c datatypes/mesa/test_dtmesa.cpp -o test_dtmesa.o
#----------FIN DT MESA------------------
#----------INICIO DT INFO PRODUCTO------------------
dtInfoProducto.o: ../datatypes/InfoProducto/DtInfoProducto.cpp
	g++ -c ../datatypes/InfoProducto/DtInfoProducto.cpp -o dtInfoProducto.o
test_dtinfoproducto.o: datatypes/infoproducto/test_dtinfoproducto.cpp
	g++ -c datatypes/infoproducto/test_dtinfoproducto.cpp -o test_dtinfoproducto.o
#----------FIN DT INFO PRODUCTO------------------
#********************FIN DATATYPES**********************

#*******************INICIO CLASES**********************
#Producto
Producto.o: ../clases/Producto/Producto.cpp
	g++ -c ../clases/Producto/Producto.cpp -o Producto.o
#Venta
Venta.o: ../clases/Venta/Venta.cpp
	g++ -c ../clases/Venta/Venta.cpp -o Venta.o
#******************FIN CLASES**********************


#*******************INICIO FINAL**********************
tests: utils/funciones.o utils/utils.o main_test.o utils/test_funciones.o utils/test_utils.o dtAsignacion.o test_dtasignacion.o dtDireccion.o test_dtdireccion.o dtCliente.o test_dtcliente.o dtConsumido.o test_dtconsumido.o dtDireccionApto.o test_dtdireccionapto.o dtDireccionCasa.o test_dtdireccioncasa.o dtFecha.o test_dtfecha.o dtHora.o test_dthora.o dtFactura.o test_dtfactura.o dtFacturaLocal.o test_dtfacturalocal.o dtFacturaDomicilio.o test_dtfacturadomicilio.o dtProducto.o test_dtproducto.o dtMenu.o test_dtmenu.o dtPlato.o test_dtplato.o dtMesa.o test_dtmesa.o dtInfoProducto.o test_dtinfoproducto.o ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o Integer.o String.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o Venta.o Producto.o
	g++ -o tests utils/funciones.o utils/utils.o main_test.o utils/test_funciones.o utils/test_utils.o dtAsignacion.o test_dtasignacion.o dtDireccion.o test_dtdireccion.o dtCliente.o test_dtcliente.o dtConsumido.o test_dtconsumido.o dtDireccionApto.o test_dtdireccionapto.o dtDireccionCasa.o test_dtdireccioncasa.o dtFecha.o test_dtfecha.o dtHora.o test_dthora.o dtFactura.o test_dtfactura.o dtFacturaLocal.o test_dtfacturalocal.o dtFacturaDomicilio.o test_dtfacturadomicilio.o dtProducto.o test_dtproducto.o dtMenu.o test_dtmenu.o dtPlato.o test_dtplato.o dtMesa.o test_dtmesa.o dtInfoProducto.o test_dtinfoproducto.o ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o Integer.o String.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o Venta.o Producto.o

#*******************FIN FINAL**********************

clean:
	$(DELETE) *.o utils/*.o tests

run: clean all
	./tests
	$(MAKE) clean