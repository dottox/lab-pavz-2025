#include "../../doctest.h"
#include "../../../clases/Venta/VentaLocal.h"
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

TEST_CASE("VentaLocal: agregarProducto y generarFactura") {
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
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar productos a la venta
    venta.agregarProducto(plato1, 2); // 2 Pizzas
    venta.agregarProducto(plato2, 1); // 1 Ensalada
    
    CHECK(venta.getCantidadProductos() == 3);
    
    // Generar factura local
    DtFacturaLocal factura = venta.generarFactura("Juan");
    
    CHECK(factura.getFactura().getCodigo() == venta.getCodigo());
    CHECK(factura.getFactura().getSubtotal() == doctest::Approx(250.0f * 2 + 120.0f * 1));
    
    // Verificar que la venta está facturada
}


TEST_CASE("VentaLocal: mostrarFacturaLocal") {
    // Crear productos
    Plato* plato1 = new Plato(DtPlato(const_cast<char*>("P001"), "Pizza Margherita", 250.0f));
    Plato* plato2 = new Plato(DtPlato(const_cast<char*>("P002"), "Ensalada César", 120.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar productos a la venta
    venta.agregarProducto(plato1, 2); // 2 Pizzas
    venta.agregarProducto(plato2, 1); // 1 Ensalada
    
    // Mostrar factura local
    DtFacturaLocal factura = venta.mostrarFacturaLocal();
    
    CHECK(factura.getFactura().getCodigo() == venta.getCodigo());
    CHECK(factura.getFactura().getSubtotal() == doctest::Approx(250.0f * 2 + 120.0f * 1));
    
    // Limpiar memoria
    delete plato1;
    delete plato2;
}

TEST_CASE("VentaLocal: mostrarFacturaDomicilio") {
    // Crear productos
    Plato* plato1 = new Plato(DtPlato(const_cast<char*>("P003"), "Sushi Variado", 300.0f));
    Plato* plato2 = new Plato(DtPlato(const_cast<char*>("P004"), "Tacos de Pescado", 200.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar productos a la venta
    venta.agregarProducto(plato1, 2); // 2 Sushi Variados
    venta.agregarProducto(plato2, 1); // 1 Taco de Pescado
    
    // Mostrar factura de domicilio
    DtFacturaDomicilio factura = venta.mostrarFacturaDomicilio();
    
    CHECK(factura.getFactura().getCodigo() == venta.getCodigo());
    CHECK(factura.getFactura().getSubtotal() == doctest::Approx(300.0f * 2 + 200.0f * 1));
    
    // Limpiar memoria
    delete plato1;
    delete plato2;
}

TEST_CASE("VentaLocal: agregarProducto con cantidad negativa") {
    // Crear producto
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P005"), "Tortilla Española", 180.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Intentar agregar producto con cantidad negativa
    CHECK_THROWS_AS(venta.agregarProducto(plato, -1), std::invalid_argument);
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: generarFactura sin productos") {
    // Crear venta local
    VentaLocal venta;
    
    // Intentar generar factura sin productos
    CHECK_THROWS_AS(venta.generarFactura("Juan"), std::invalid_argument);
}

TEST_CASE("VentaLocal: generarFactura con venta ya facturada") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P006"), "Paella Valenciana", 250.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar producto
    venta.agregarProducto(plato, 1);
    
    // Generar factura
    DtFacturaLocal factura = venta.generarFactura("Carlos");
    
    // Intentar generar factura nuevamente
    CHECK_THROWS_AS(venta.generarFactura("Carlos"), std::logic_error);
    
    delete plato; // Liberar memoria del plato
}



TEST_CASE("VentaLocal: Destructor") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P007"), "Tortilla Española", 180.0f));
    
    // Crear venta local
    VentaLocal* venta = new VentaLocal();
    
    // Agregar producto
    venta->agregarProducto(plato, 1);
    
    // Verificar que la venta se destruya correctamente
    delete venta; // Esto debería liberar la memoria de la venta y sus productos
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: agregarProducto con producto nulo") {
    // Crear venta local
    VentaLocal venta;
    
    // Intentar agregar producto nulo
    CHECK_THROWS_AS(venta.agregarProducto(nullptr, 1), std::invalid_argument);
}

TEST_CASE("VentaLocal: mostrarFacturaLocal sin productos") {
    // Crear venta local
    VentaLocal venta;
    
    // Intentar mostrar factura local sin productos
    CHECK_THROWS_AS(venta.mostrarFacturaLocal(), std::invalid_argument);
}

TEST_CASE("VentaLocal: mostrarFacturaDomicilio sin productos") {
    // Crear venta local
    VentaLocal venta;
    
    // Intentar mostrar factura de domicilio sin productos
    CHECK_THROWS_AS(venta.mostrarFacturaDomicilio(), std::invalid_argument);
}

TEST_CASE("VentaLocal: mostrarFacturaLocal con venta ya facturada") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P008"), "Sushi Variado", 300.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar producto
    venta.agregarProducto(plato, 1);
    
    // Generar factura
    DtFacturaLocal factura = venta.generarFactura("Ana");
    
    // Intentar mostrar factura local nuevamente
    CHECK_NOTHROW(venta.mostrarFacturaLocal());
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: mostrarFacturaDomicilio con venta ya facturada") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P009"), "Brownie con Helado", 180.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar producto
    venta.agregarProducto(plato, 1);
    
    // Generar factura
    DtFacturaLocal factura = venta.generarFactura("Laura");
    
    // Intentar mostrar factura de domicilio nuevamente
    CHECK_NOTHROW(venta.mostrarFacturaDomicilio());
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: Setters con valores inválidos") {
    // Crear venta local
    VentaLocal venta;
    
    // Intentar establecer un descuento negativo
    CHECK_THROWS_AS(venta.agregarPorcentaje(-10), std::invalid_argument);
    
    // Intentar agregar producto nulo
    CHECK_THROWS_AS(venta.agregarProducto(nullptr, 1), std::invalid_argument);
    
    // Intentar generar factura sin productos
    CHECK_THROWS_AS(venta.generarFactura("Juan"), std::invalid_argument);
}

TEST_CASE("VentaLocal: Setters con venta en curso") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P010"), "Sushi Variado", 350.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar producto
    venta.agregarProducto(plato, 2);
    
    // Verificar que se pueda cambiar el subtotal mientras hay una venta en curso
    venta.setSubtotal(500.0f);
    CHECK(venta.getSubtotal() == doctest::Approx(500.0f));
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: Setters con venta facturada") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P011"), "Ceviche", 300.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar producto
    venta.agregarProducto(plato, 1);
    
    // Generar factura
    DtFacturaLocal factura = venta.generarFactura("Carlos");
    
    // Intentar cambiar el subtotal después de la facturación
    CHECK_THROWS_AS(venta.setSubtotal(600.0f), std::logic_error);
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: Destructor") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P012"), "Tacos de Pescado", 200.0f));
    
    // Crear venta local
    VentaLocal* venta = new VentaLocal();
    
    // Agregar producto
    venta->agregarProducto(plato, 1);
    
    // Verificar que la venta se destruya correctamente
    delete venta; // Esto debería liberar la memoria de la venta y sus productos
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: agregarProducto con producto nulo") {
    // Crear venta local
    VentaLocal venta;
    
    // Intentar agregar producto nulo
    CHECK_THROWS_AS(venta.agregarProducto(nullptr, 1), std::invalid_argument);
}

TEST_CASE("VentaLocal: mostrarFacturaLocal sin productos") {
    // Crear venta local
    VentaLocal venta;
    
    // Intentar mostrar factura local sin productos
    CHECK_THROWS_AS(venta.mostrarFacturaLocal(), std::invalid_argument);
}

TEST_CASE("VentaLocal: mostrarFacturaDomicilio sin productos") {
    // Crear venta local
    VentaLocal venta;
    
    // Intentar mostrar factura de domicilio sin productos
    CHECK_THROWS_AS(venta.mostrarFacturaDomicilio(), std::invalid_argument);
}

TEST_CASE("VentaLocal: mostrarFacturaLocal con venta ya facturada") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P013"), "Sushi Variado", 300.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar producto
    venta.agregarProducto(plato, 1);
    
    // Generar factura
    DtFacturaLocal factura = venta.generarFactura("Ana");
    
    // Intentar mostrar factura local nuevamente
    CHECK_NOTHROW(venta.mostrarFacturaLocal());
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: mostrarFacturaDomicilio con venta ya facturada") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P014"), "Brownie con Helado", 180.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar producto
    venta.agregarProducto(plato, 1);
    
    // Generar factura
    DtFacturaLocal factura = venta.generarFactura("Laura");
    
    // Intentar mostrar factura de domicilio nuevamente
    CHECK_NOTHROW(venta.mostrarFacturaDomicilio());
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: Setters con valores inválidos") {
    // Crear venta local
    VentaLocal venta;
    
    // Intentar establecer un descuento negativo
    CHECK_THROWS_AS(venta.agregarPorcentaje(-10), std::invalid_argument);
    
    // Intentar agregar producto nulo
    CHECK_THROWS_AS(venta.agregarProducto(nullptr, 1), std::invalid_argument);
    
    // Intentar generar factura sin productos
    CHECK_THROWS_AS(venta.generarFactura("Juan"), std::invalid_argument);
}

TEST_CASE("VentaLocal: Setters con venta en curso") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P015"), "Sushi Variado", 350.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar producto
    venta.agregarProducto(plato, 2);
    
    // Verificar que se pueda cambiar el subtotal mientras hay una venta en curso
    venta.setSubtotal(500.0f);
    CHECK(venta.getSubtotal() == doctest::Approx(500.0f));
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: Setters con venta facturada") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P016"), "Ceviche", 300.0f));
    
    // Crear venta local
    VentaLocal venta;
    
    // Agregar producto
    venta.agregarProducto(plato, 1);
    
    // Generar factura
    DtFacturaLocal factura = venta.generarFactura("Carlos");
    
    // Intentar cambiar el subtotal después de la facturación
    CHECK_THROWS_AS(venta.setSubtotal(600.0f), std::logic_error);
    
    delete plato; // Liberar memoria del plato
}

TEST_CASE("VentaLocal: Destructor") {
    // Crear productos
    Plato* plato = new Plato(DtPlato(const_cast<char*>("P017"), "Tacos de Pescado", 200.0f));
    
    // Crear venta local
    VentaLocal* venta = new VentaLocal();
    
    // Agregar producto
    venta->agregarProducto(plato, 1);
    
    // Verificar que la venta se destruya correctamente
    delete venta; // Esto debería liberar la memoria de la venta y sus productos
    
    delete plato; // Liberar memoria del plato
}
