#include "../../doctest.h"
#include "../../../clases/Venta/VentaDomicilio.h"
#include "../../../datatypes/Producto/DtProducto.h"
#include "../../../datatypes/Producto/DtPlato.h"
#include "../../../datatypes/Producto/DtMenu.h"
#include "../../../datatypes/Factura/DtFactura.h"
#include "../../../datatypes/Factura/DtFacturaLocal.h"
#include "../../../datatypes/Consumido/DtConsumido.h"
#include "../../../datatypes/Fecha/DtFecha.h"
#include "../../../datatypes/Hora/DtHora.h"
#include "../../../clases/Producto/Producto.h"
#include "../../../clases/Producto/Menu.h"
#include "../../../clases/Producto/Plato.h"
#include "../../../clases/Factura/Factura.h"
#include "../../../clases/Factura/FacturaLocal.h"
#include "../../../clases/Factura/FacturaDomicilio.h"
#include "../../../datatypes/Factura/DtFacturaDomicilio.h"
#include "../../../enums/Transporte.h"
#include "../../../enums/TipoProducto.h"
#include "../../../ICollection/interfaces/ICollectible.h"
#include "../../../ICollection/collections/OrderedDictionary.h"
#include "../../../ICollection/interfaces/IKey.h"
#include <iostream>
using namespace std;


TEST_CASE("VentaDomicilio: agregarProducto y generarFactura") {
    // Crear productos
    Plato* plato1 = new Plato(DtPlato(const_cast<char*>("P001"), "Pizza Margherita", 250.0f));
    Plato* plato2 = new Plato(DtPlato(const_cast<char*>("P002"), "Ensalada César", 120.0f));
    
    // Verificar que los productos se hayan creado correctamente
    CHECK(plato1->getCodigo() == "P001");
    CHECK(plato1->getDescripcion() == "Pizza Margherita");
    CHECK(plato1->getPrecio() == doctest::Approx(250.0f));
    CHECK(plato2->getCodigo() == "P002");
    CHECK(plato2->getDescripcion() == "Ensalada César");
    CHECK(plato2->getPrecio() == doctest::Approx(120.0f));
    
    // Verificar que los tipos sean correctos
    CHECK(plato1->getTipo() == TipoProducto::TipoPlato);
    CHECK(plato2->getTipo() == TipoProducto::TipoPlato);
    
    // Verificar que los productos sean instancias de Producto
    CHECK(dynamic_cast<Producto*>(plato1) != nullptr);
    CHECK(dynamic_cast<Producto*>(plato2) != nullptr);
    // Crear VentaDomicilio
    DtDireccion direccion("Calle Falsa", 123, "Entre A y B");
    DtCliente* cliente = new DtCliente("Juan Perez", "099123456", direccion);
    VentaDomicilio* venta = new VentaDomicilio(cliente);

    // Agregar productos a la venta
    venta->agregarProducto(plato1, 2); // 2 Pizzas
    venta->agregarProducto(plato2, 1); // 1 Ensalada

    CHECK(venta->getCantidadProductos() == 3);
    // Generar factura de domicilio
    DtFacturaDomicilio factura = venta->mostrarFacturaDomicilio();
    CHECK(factura.getFactura().getCodigo() == venta->getCodigo());
    CHECK(factura.getFactura().getSubtotal() == doctest::Approx(250.0f * 2 + 120.0f * 1));

    delete plato1; // Liberar memoria del plato
    delete plato2; // Liberar memoria del plato
    delete venta; // Liberar memoria de la venta
    delete cliente; // Liberar memoria del cliente
}

TEST_CASE("VentaDomicilio: mostrarFacturaDomicilio") {
    // Crear productos
    Plato* plato1 = new Plato(DtPlato(const_cast<char*>("P003"), "Sushi Variado", 300.0f));
    Plato* plato2 = new Plato(DtPlato(const_cast<char*>("P004"), "Tacos de Pescado", 200.0f));

    // Crear VentaDomicilio
    DtDireccion direccion("Avenida Siempre Viva", 742, "Frente al parque");
    DtCliente* cliente = new DtCliente("Maria Lopez", "0987654321", direccion);
    VentaDomicilio venta(cliente);

    // Agregar productos a la venta
    venta.agregarProducto(plato1, 2); // 2 Sushi Variados
    venta.agregarProducto(plato2, 1); // 1 Taco de Pescado

    // Mostrar factura de domicilio
    DtFacturaDomicilio factura = venta.mostrarFacturaDomicilio();

    CHECK(factura.getFactura().getCodigo() == venta.getCodigo());
    CHECK(factura.getFactura().getSubtotal() == doctest::Approx(300.0f * 2 + 200.0f * 1));

    delete plato1; // Liberar memoria del plato
    delete plato2; // Liberar memoria del plato
}

TEST_CASE("VentaDomicilio: agregarProducto con cantidad negativa") {
    // Crear producto
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P005"), "Tortilla Española", 180.0f));

    // Crear VentaDomicilio
    DtDireccion direccion("Calle Mayor", 456, "Cerca del centro");
    DtCliente* cliente = new DtCliente("Carlos Ruiz", "0912345678", direccion);
    VentaDomicilio venta(cliente);

    // Intentar agregar producto con cantidad negativa
    CHECK_THROWS_AS(venta.agregarProducto(plato, -1), std::invalid_argument);

    delete plato; // Liberar memoria del plato
    delete cliente; // Liberar memoria del cliente
}

TEST_CASE("VentaDomicilio: generarFactura sin productos") {
    // Crear VentaDomicilio
    DtDireccion direccion("Calle Falsa", 123, "Entre A y B");
    DtCliente* cliente = new DtCliente("Ana Torres", "0987654321", direccion);
    VentaDomicilio venta(cliente);

    // Intentar generar factura sin productos
    CHECK_THROWS_AS(venta.mostrarFacturaDomicilio(), std::invalid_argument);

    delete cliente; // Liberar memoria del cliente
}

TEST_CASE("VentaDomicilio: generarFactura con venta ya facturada") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P006"), "Paella Valenciana", 250.0f));

    // Crear VentaDomicilio
    DtDireccion direccion("Calle del Mar", 789, "Junto a la playa");
    DtCliente* cliente = new DtCliente("Luis Garcia", "0912345678", direccion);
    VentaDomicilio venta(cliente);

    // Agregar producto
    venta.agregarProducto(plato, 1);

    // Generar factura
    venta.mostrarFacturaDomicilio();

    // Intentar generar factura nuevamente
    CHECK_THROWS_AS(venta.mostrarFacturaDomicilio(), std::logic_error);

    delete plato; // Liberar memoria del plato
    delete cliente; // Liberar memoria del cliente
}

TEST_CASE("VentaDomicilio: Destructor") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P007"), "Ceviche Peruano", 300.0f));

    // Crear VentaDomicilio
    DtDireccion direccion("Calle del Sol", 321, "Cerca del río");
    DtCliente* cliente = new DtCliente("Sofia Martinez", "0987654321", direccion);
    VentaDomicilio* venta = new VentaDomicilio(cliente);

    // Agregar producto
    venta->agregarProducto(plato, 2);

    // Verificar que la venta se destruya correctamente
    delete venta; // Esto debería liberar la memoria de la venta y sus productos

    delete plato; // Liberar memoria del plato
    delete cliente; // Liberar memoria del cliente
}

TEST_CASE("VentaDomicilio: Productos vacíos") {
    // Crear VentaDomicilio
    DtDireccion direccion("Calle del Bosque", 654, "Cerca del lago");
    DtCliente* cliente = new DtCliente("Pedro Sanchez", "0912345678", direccion);
    VentaDomicilio venta(cliente);

    // Verificar que la venta esté vacía
    CHECK(venta.getCantidadProductos() == 0);

    delete cliente; // Liberar memoria del cliente
}

TEST_CASE("VentaDomicilio: Datos inválidos") {
    // Intentar crear VentaDomicilio con datos nulos
    CHECK_THROWS_AS(VentaDomicilio(nullptr), std::invalid_argument);

    // Intentar crear DtCliente con datos inválidos
    DtDireccion direccion("", 0, "");
    CHECK_THROWS_AS(DtCliente("", "", direccion), std::invalid_argument);
}

TEST_CASE("VentaDomicilio: Datos nulos") {
    // Intentar crear VentaDomicilio con datos nulos
    CHECK_THROWS_AS(VentaDomicilio(nullptr), std::invalid_argument);

    // Intentar crear DtCliente con datos nulos
    DtDireccion direccion("", 0, "");
    CHECK_THROWS_AS(DtCliente("", "", direccion), std::invalid_argument);
}

TEST_CASE("VentaDomicilio: Datos de cliente") {
    // Crear DtCliente
    DtDireccion direccion("Calle del Viento", 987, "Cerca del parque");
    DtCliente cliente("Elena Gomez", "0912345678", direccion);
    CHECK(cliente.getNombre() == "Elena Gomez");
    CHECK(cliente.getTelefono() == "0912345678");
    CHECK(cliente.getDireccion().getCalle() == "Calle del Viento");
    CHECK(cliente.getDireccion().getNumero() == 987);
    CHECK(cliente.getDireccion().getEntreCalles() == "Cerca del parque");
    // Verificar que se pueda crear VentaDomicilio con DtCliente
    VentaDomicilio venta(&cliente);
    CHECK(venta.getDatosCliente()->getNombre() == "Elena Gomez");
    CHECK(venta.getDatosCliente()->getTelefono() == "0912345678");
    CHECK(venta.getDatosCliente()->getDireccion().getCalle() == "Calle del Viento");
    CHECK(venta.getDatosCliente()->getDireccion().getNumero() == 987);
    CHECK(venta.getDatosCliente()->getDireccion().getEntreCalles() == "Cerca del parque");
    // Verificar que se pueda mostrar la factura de domicilio
    DtFacturaDomicilio factura = venta.mostrarFacturaDomicilio();

    // Verificar que se pueda liberar memoria correctamente
    delete venta.getDatosCliente(); // Liberar memoria del cliente
    delete &direccion; // Liberar memoria de la dirección
    delete &venta; // Liberar memoria de la venta
}
TEST_CASE("VentaDomicilio: getDatosCliente con datos nulos") {
    // Intentar obtener datos del cliente con datos nulos
    VentaDomicilio venta(nullptr);
    CHECK_THROWS_AS(venta.getDatosCliente(), std::invalid_argument);
}
TEST_CASE("VentaDomicilio: getDatosCliente con datos válidos") {
    // Crear DtCliente
    DtDireccion direccion("Calle del Mar", 123, "Cerca de la playa");
    DtCliente cliente("Laura Perez", "0912345678", direccion);
    
    // Crear VentaDomicilio
    VentaDomicilio venta(&cliente);
    
    // Verificar que se obtengan los datos del cliente correctamente
    CHECK(venta.getDatosCliente()->getNombre() == "Laura Perez");
    CHECK(venta.getDatosCliente()->getTelefono() == "0912345678");
    CHECK(venta.getDatosCliente()->getDireccion().getCalle() == "Calle del Mar");
    CHECK(venta.getDatosCliente()->getDireccion().getNumero() == 123);
    CHECK(venta.getDatosCliente()->getDireccion().getEntreCalles() == "Cerca de la playa");
}

TEST_CASE("VentaDomicilio: getDatosCliente con datos inválidos") {
    // Intentar obtener datos del cliente con datos inválidos
    DtDireccion direccion("", -1, "");
    DtCliente cliente("", "", direccion);
    
    // Crear VentaDomicilio
    VentaDomicilio venta(&cliente);
    
    // Verificar que se obtengan los datos del cliente correctamente
    CHECK(venta.getDatosCliente()->getNombre() == "");
    CHECK(venta.getDatosCliente()->getTelefono() == "");
    CHECK(venta.getDatosCliente()->getDireccion().getCalle() == "");
    CHECK(venta.getDatosCliente()->getDireccion().getNumero() == -1);
    CHECK(venta.getDatosCliente()->getDireccion().getEntreCalles() == "");
}

TEST_CASE("VentaDomicilio: getDatosCliente con datos nulos") {
    // Intentar obtener datos del cliente con datos nulos
    VentaDomicilio venta(nullptr);
    
    // Verificar que se lance una excepción al intentar obtener los datos del cliente
    CHECK_THROWS_AS(venta.getDatosCliente(), std::invalid_argument);
}

TEST_CASE("VentaDomicilio: getDatosCliente con datos válidos") {
    // Crear DtCliente
    DtDireccion direccion("Calle del Sol", 456, "Cerca del río");
    DtCliente cliente("Miguel Torres", "0912345678", direccion);
    
    // Crear VentaDomicilio
    VentaDomicilio venta(&cliente);
    
    // Verificar que se obtengan los datos del cliente correctamente
    CHECK(venta.getDatosCliente()->getNombre() == "Miguel Torres");
    CHECK(venta.getDatosCliente()->getTelefono() == "0912345678");
    CHECK(venta.getDatosCliente()->getDireccion().getCalle() == "Calle del Sol");
    CHECK(venta.getDatosCliente()->getDireccion().getNumero() == 456);
    CHECK(venta.getDatosCliente()->getDireccion().getEntreCalles() == "Cerca del río");
}

TEST_CASE("VentaDomicilio: getDatosCliente con datos inválidos") {
    // Intentar obtener datos del cliente con datos inválidos
    DtDireccion direccion("", -1, "");
    DtCliente cliente("", "", direccion);
    
    // Crear VentaDomicilio
    VentaDomicilio venta(&cliente);
    
    // Verificar que se obtengan los datos del cliente correctamente
    CHECK(venta.getDatosCliente()->getNombre() == "");
    CHECK(venta.getDatosCliente()->getTelefono() == "");
    CHECK(venta.getDatosCliente()->getDireccion().getCalle() == "");
    CHECK(venta.getDatosCliente()->getDireccion().getNumero() == -1);
    CHECK(venta.getDatosCliente()->getDireccion().getEntreCalles() == "");
}

TEST_CASE("VentaDomicilio: getDatosCliente con datos nulos") {
    // Intentar obtener datos del cliente con datos nulos
    VentaDomicilio venta(nullptr);
    
    // Verificar que se lance una excepción al intentar obtener los datos del cliente
    CHECK_THROWS_AS(venta.getDatosCliente(), std::invalid_argument);
}

