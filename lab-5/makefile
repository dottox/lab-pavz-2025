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

OBJDIR := output

all: $(OBJDIR) programa

# Lista de objetos con ruta dentro de output/
OBJ := \
$(OBJDIR)/ICollectible.o \
$(OBJDIR)/ICollection.o \
$(OBJDIR)/IDictionary.o \
$(OBJDIR)/IIterator.o \
$(OBJDIR)/IKey.o \
$(OBJDIR)/OrderedKey.o \
$(OBJDIR)/Integer.o \
$(OBJDIR)/String.o \
$(OBJDIR)/List.o \
$(OBJDIR)/ListIterator.o \
$(OBJDIR)/ListNode.o \
$(OBJDIR)/OrderedDictionary.o \
$(OBJDIR)/OrderedDictionaryEntry.o \
$(OBJDIR)/ISistema.o \
$(OBJDIR)/utils.o \
$(OBJDIR)/DtCliente.o \
$(OBJDIR)/Plato.o \
$(OBJDIR)/Menu.o \
$(OBJDIR)/MenuPlato.o \
$(OBJDIR)/DtFecha.o \
$(OBJDIR)/DtConsumido.o \
$(OBJDIR)/DtHora.o \
$(OBJDIR)/DtFacturaLocal.o \
$(OBJDIR)/DtFacturaDomicilio.o \
$(OBJDIR)/DtFactura.o \
$(OBJDIR)/FacturaLocal.o \
$(OBJDIR)/FacturaDomicilio.o \
$(OBJDIR)/Factura.o \
$(OBJDIR)/DtInforme.o \
$(OBJDIR)/Producto.o \
$(OBJDIR)/ProductoVenta.o \
$(OBJDIR)/VentaLocal.o \
$(OBJDIR)/VentaDomicilio.o \
$(OBJDIR)/Venta.o \
$(OBJDIR)/DtInfoProducto.o \
$(OBJDIR)/DtMenu.o \
$(OBJDIR)/DtMesa.o \
$(OBJDIR)/DtAsignacion.o \
$(OBJDIR)/DtPlato.o \
$(OBJDIR)/DtProducto.o \
$(OBJDIR)/DtDireccionApto.o \
$(OBJDIR)/DtDireccion.o \
$(OBJDIR)/DtDireccionCasa.o \
$(OBJDIR)/DtPlato.o \
$(OBJDIR)/DtProducto.o \
$(OBJDIR)/DtDireccionApto.o \
$(OBJDIR)/DtDireccionCasa.o \
$(OBJDIR)/DtDireccion.o \
$(OBJDIR)/Cliente.o \
$(OBJDIR)/Mesa.o \
$(OBJDIR)/Mozo.o \
$(OBJDIR)/Repartidor.o \
$(OBJDIR)/Empleado.o \
$(OBJDIR)/Sistema.o \
$(OBJDIR)/Factory.o \
$(OBJDIR)/main.o

programa: $(OBJ)
	$(CXX) $^ -o $(OBJDIR)/programa

$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regla genérica para compilar .cpp a output/*.o
# Cada archivo fuente con su path original, el objeto se genera en output/
$(OBJDIR)/%.o: ICollection/interfaces/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: ICollection/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: ICollection/collections/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: utils/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Sistema/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Factory/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Factura/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Venta/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Producto/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/Factura/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/Informe/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/InfoProducto/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/Producto/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/Consumido/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/Direccion/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/Fecha/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/Hora/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/Cliente/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@
	
$(OBJDIR)/%.o: datatypes/Mesa/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: datatypes/Asignacion/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Cliente/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Mesa/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Empleado/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/ProductoVenta/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: main.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Cliente/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Mesa/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/Empleado/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: clases/ProductoVenta/%.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

$(OBJDIR)/%.o: main.cpp | $(OBJDIR)
	$(CXX) -c $< -o $@

clean:
	$(DELETE) $(OBJDIR)/*.o $(OBJDIR)/programa

run: all
	$(OBJDIR)/programa


	make clean

