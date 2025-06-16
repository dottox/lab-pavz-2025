// #include "../../doctest.h"
// #include "../../../clases/Venta/Venta.h"
// #include "../../../datatypes/Producto/DtProducto.h"
// #include "../../../datatypes/Producto/DtPlato.h"
// #include "../../../datatypes/Producto/DtMenu.h"
// #include "../../../datatypes/Factura/DtFactura.h"
// #include "../../../datatypes/Factura/DtFacturaLocal.h"
// #include "../../../datatypes/Consumido/DtConsumido.h"
// #include "../../../datatypes/Fecha/DtFecha.h"
// #include "../../../datatypes/Hora/DtHora.h"
// #include "../../../clases/Producto/Producto.h"
// #include "../../../clases/Producto/Menu.h"
// #include "../../../clases/Producto/Plato.h"
// #include "../../../clases/Factura/Factura.h"
// #include "../../../clases/Factura/FacturaLocal.h"
// #include "../../../clases/Factura/FacturaDomicilio.h"
// #include "../../../datatypes/Factura/DtFacturaDomicilio.h"
// #include "../../../enums/Transporte.h"
// #include "../../../enums/TipoProducto.h"
// #include "../../../ICollection/interfaces/ICollectible.h"
// #include "../../../ICollection/collections/OrderedDictionary.h"
// #include "../../../ICollection/interfaces/IKey.h"
// #include <iostream>
// using namespace std;

// TEST_CASE("Venta: agregarProducto y generarFactura") {
//     // Crear productos
//     Plato* plato1 = new Plato(DtPlato(const_cast<char*>("P001"), "Pizza Margherita", 250.0f));
//     Plato* plato2 = new Plato(DtPlato(const_cast<char*>("P002"), "Ensalada César", 120.0f));
//     // Verificar que los productos se hayan creado correctamente
//     CHECK(std::string(plato1->getCodigo()) == "P001");
//     CHECK(plato1->getDescripcion() == "Pizza Margherita");
//     CHECK(plato1->getPrecio() == doctest::Approx(250.0f));
//     CHECK(std::string(plato2->getCodigo()) == "P002");
//     CHECK(plato2->getDescripcion() == "Ensalada César");
//     CHECK(plato2->getPrecio() == doctest::Approx(120.0f));
//     // Verificar que los tipos sean correctos
//     CHECK(plato1->getTipo() == TipoProducto::TipoPlato);
//     CHECK(plato2->getTipo() == TipoProducto::TipoPlato);
//     // Verificar que los productos sean instancias de Producto
//     CHECK(dynamic_cast<Producto*>(plato1) != nullptr);
//     CHECK(dynamic_cast<Producto*>(plato2) != nullptr);
    

//     // Crear venta
//     Venta venta;

//     // Agregar productos
//     venta.agregarProducto(plato1, 2);
//     venta.agregarProducto(plato2, 1);

//     CHECK(venta.getCantidadProductos() == 3);

//     // Generar factura local
//     DtFacturaLocal factura = venta.generarFactura("Juan");

//     CHECK(factura.getFactura().getCodigo() == venta.getCodigo());
//     CHECK(factura.getFactura().getSubtotal() == doctest::Approx(250.0f * 2 + 120.0f * 1));

//     // Verificar que la venta está facturada
//     CHECK(venta.estaFacturada() == true);

//     // Limpiar memoria
//     delete plato1;
//     delete plato2;
// }

// TEST_CASE("Venta: mostrarFacturaLocal") {
//     // Crear productos
//     Plato* plato1 = new Plato(DtPlato(const_cast<char*>("P003"), "Sopa de Mariscos", 200.0f));
//     Plato* plato2 = new Plato(DtPlato(const_cast<char*>("P004"), "Tacos de Pollo", 150.0f));

//     // Crear venta
//     Venta venta;

//     // Agregar productos
//     venta.agregarProducto(plato1, 1);
//     venta.agregarProducto(plato2, 3);

//     // Mostrar factura local
//     DtFacturaLocal factura = venta.mostrarFacturaLocal();

//     CHECK(factura.getFactura().getCodigo() == venta.getCodigo());
//     CHECK(factura.getFactura().getSubtotal() == doctest::Approx(200.0f * 1 + 150.0f * 3));

//     // Limpiar memoria
//     delete plato1;
//     delete plato2;
// }
// TEST_CASE("Venta: mostrarFacturaDomicilio") {
//     // Crear productos
//     Plato* plato1 = new Plato(DtPlato(const_cast<char*>("P005"), "Hamburguesa Clásica", 300.0f));
//     Plato* plato2 = new Plato(DtPlato(const_cast<char*>("P006"), "Papas Fritas", 100.0f));

//     // Crear venta
//     Venta venta;

//     // Agregar productos
//     venta.agregarProducto(plato1, 2);
//     venta.agregarProducto(plato2, 1);

//     // Mostrar factura de domicilio
//     DtFacturaDomicilio factura = venta.mostrarFacturaDomicilio();

//     CHECK(factura.getFactura().getCodigo() == venta.getCodigo());
//     CHECK(factura.getFactura().getSubtotal() == doctest::Approx(300.0f * 2 + 100.0f * 1));

//     // Limpiar memoria
//     delete plato1;
//     delete plato2;
// }


// TEST_CASE("Venta: agregarProducto con cantidad negativa") {
//     // Crear producto
//     Plato* plato = new Plato(DtPlato(const_cast<char*>("P007"), "Tortilla Española", 180.0f));

//     // Crear venta
//     Venta venta;

//     // Intentar agregar producto con cantidad negativa
//     CHECK_THROWS_AS(venta.agregarProducto(plato, -1), std::invalid_argument);

//     // Limpiar memoria
//     delete plato;
// }

// TEST_CASE("Venta: agregarProducto con producto nulo") {
//     // Crear venta
//     Venta venta;

//     // Intentar agregar producto nulo
//     CHECK_THROWS_AS(venta.agregarProducto(nullptr, 1), std::invalid_argument);
// }

// TEST_CASE("Venta: generarFactura sin productos") {
//     // Crear venta
//     Venta venta;

//     // Intentar generar factura sin productos
//     CHECK_THROWS_AS(venta.generarFactura("Juan"), std::invalid_argument);
// }

// TEST_CASE("Venta: generarFactura con venta ya facturada") {
//     // Crear productos
//     Plato* plato = new Plato(DtPlato(const_cast<char*>("P008"), "Sushi Variado", 350.0f));

//     // Crear venta
//     Venta venta;

//     // Agregar producto
//     venta.agregarProducto(plato, 2);

//     // Generar factura
//     venta.generarFactura("Ana");

//     // Intentar generar factura nuevamente
//     CHECK_THROWS_AS(venta.generarFactura("Ana"), std::logic_error);

//     // Limpiar memoria
//     delete plato;
// }

// TEST_CASE("Venta: mostrarFacturaLocal sin productos") {
//     // Crear venta
//     Venta venta;

//     // Intentar mostrar factura local sin productos
//     CHECK_THROWS_AS(venta.mostrarFacturaLocal(), std::invalid_argument);
// }

// TEST_CASE("Venta: mostrarFacturaDomicilio sin productos") {
//     // Crear venta
//     Venta venta;

//     // Intentar mostrar factura de domicilio sin productos
//     CHECK_THROWS_AS(venta.mostrarFacturaDomicilio(), std::invalid_argument);
// }

// TEST_CASE("Venta: mostrarFacturaLocal con venta ya facturada") {
//     // Crear productos
//     Plato* plato = new Plato(DtPlato(const_cast<char*>("P009"), "Tarta de Manzana", 220.0f));

//     // Crear venta
//     Venta venta;

//     // Agregar producto
//     venta.agregarProducto(plato, 1);

//     // Generar factura
//     venta.generarFactura("Carlos");

//     // Intentar mostrar factura local nuevamente
//     CHECK_NOTHROW(venta.mostrarFacturaLocal());

//     // Limpiar memoria
//     delete plato;
// }

// TEST_CASE("Venta: mostrarFacturaDomicilio con venta ya facturada") {
//     // Crear productos
//     Plato* plato = new Plato(DtPlato(const_cast<char*>("P010"), "Brownie con Helado", 180.0f));

//     // Crear venta
//     Venta venta;

//     // Agregar producto
//     venta.agregarProducto(plato, 1);

//     // Generar factura
//     venta.generarFactura("Laura");

//     // Intentar mostrar factura de domicilio nuevamente
//     CHECK_NOTHROW(venta.mostrarFacturaDomicilio());

//     // Limpiar memoria
//     delete plato;
// }

// TEST_CASE("Venta: Destructor") {
//     // Crear productos
//     Plato* plato = new Plato(DtPlato(const_cast<char*>("P011"), "Ceviche", 300.0f));

//     // Crear venta
//     Venta* venta = new Venta();

//     // Agregar producto
//     venta->agregarProducto(plato, 1);

//     // Verificar que la venta se haya creado correctamente
//     CHECK(venta->getCantidadProductos() == 1);

//     // Verificar que el destructor no cause fugas de memoria
//     delete venta;

//     // Limpiar memoria del plato
//     delete plato;
// }

// TEST_CASE("Venta: Setters con valores inválidos") {
//     // Crear venta
//     Venta venta;

//     // Intentar establecer un descuento negativo
//     CHECK_THROWS_AS(venta.agregarPorcentaje(-10), std::invalid_argument);

//     // Intentar establecer un descuento mayor a 100%
//     CHECK_THROWS_AS(venta.agregarPorcentaje(110), std::invalid_argument);
// }

// TEST_CASE("Venta: Setters con venta en curso") {
//     // Crear productos
//     Plato* plato = new Plato(DtPlato(const_cast<char*>("P012"), "Tacos de Pescado", 200.0f));

//     // Crear venta
//     Venta venta;

//     // Agregar producto
//     venta.agregarProducto(plato, 2);

//     // Verificar que se pueda cambiar el subtotal mientras hay una venta en curso
//     venta.setSubtotal(500.0f);
//     CHECK(venta.getSubtotal() == doctest::Approx(500.0f));

//     // Limpiar memoria
//     delete plato;
// }

// TEST_CASE("Venta: Setters con venta facturada") {
//     // Crear productos
//     Plato* plato = new Plato(DtPlato(const_cast<char*>("P013"), "Burrito Vegetariano", 180.0f));

//     // Crear venta
//     Venta venta;

//     // Agregar producto
//     venta.agregarProducto(plato, 1);

//     // Generar factura
//     venta.generarFactura("Miguel");

//     // Verificar que se pueda cambiar el subtotal después de la facturación
//     venta.setSubtotal(400.0f);
//     CHECK(venta.getSubtotal() == doctest::Approx(400.0f));

//     // Limpiar memoria
//     delete plato;
// }

// TEST_CASE("Venta: Setters con venta facturada y descuento") {
//     // Crear productos
//     Plato* plato = new Plato(DtPlato(const_cast<char*>("P014"), "Falafel", 150.0f));

//     // Crear venta
//     Venta venta;

//     // Agregar producto
//     venta.agregarProducto(plato, 3);

//     // Generar factura
//     venta.generarFactura("Sofía");

//     // Verificar que se pueda agregar un porcentaje de descuento después de la facturación
//     venta.agregarPorcentaje(10);
//     CHECK(venta.getDescuento() == 10);

//     // Limpiar memoria
//     delete plato;
// }

