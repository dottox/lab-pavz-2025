#include "../../doctest.h"
#include "../../../clases/Factura/Factura.h"
#include "../../../datatypes/Factura/DtFactura.h"
#include "../../../datatypes/Consumido/DtConsumido.h"
#include "../../../datatypes/Fecha/DtFecha.h"
#include "../../../datatypes/Hora/DtHora.h"
#include "../../../ICollection/collections/OrderedDictionary.h"

TEST_CASE("Factura se construye correctamente desde DtFactura") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

    Factura factura(dto);

    CHECK(factura.getCodigo() == 1234);
    CHECK(factura.getCodigoVenta() == 987);
    CHECK(factura.getFecha() == fecha);
    CHECK(factura.getHora() == hora);
    CHECK(factura.getSubtotal() == doctest::Approx(1000.0f));
    CHECK(factura.getDescuento() == 10);
    CHECK(factura.getMontoTotal() == doctest::Approx(900.0f));
    CHECK(factura.getIvaTotal() == doctest::Approx(180.0f));
    CHECK(factura.getProductos() == productos);

    delete productos;
}

TEST_CASE("Factura getters devuelven valores correctos") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

    Factura factura(dto);

    CHECK(factura.getCodigo() == 1234);
    CHECK(factura.getCodigoVenta() == 987);
    CHECK(factura.getFecha() == fecha);
    CHECK(factura.getHora() == hora);
    CHECK(factura.getSubtotal() == doctest::Approx(1000.0f));
    CHECK(factura.getDescuento() == 10);
    CHECK(factura.getMontoTotal() == doctest::Approx(900.0f));
    CHECK(factura.getIvaTotal() == doctest::Approx(180.0f));
    CHECK(factura.getProductos() == productos);

    delete productos;
}

TEST_CASE("Factura destructor libera recursos correctamente") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

    Factura *factura = new Factura(dto);
    delete factura; // Verifica que no haya fugas de memoria
}

TEST_CASE("Factura con productos consumidos") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    productos->add((IKey*)new DtConsumido("Producto1", 2, 0), new DtConsumido("Producto1", 2, 0));
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

    Factura factura(dto);

    CHECK(factura.getProductos()->getSize() == 1);
    CHECK(factura.getProductos()->find((IKey*)new DtConsumido("Producto1", 2, 0)) != nullptr);

    delete productos;
}

TEST_CASE("Factura con productos vacíos") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

    Factura factura(dto);

    CHECK(factura.getProductos()->getSize() == 0);

    delete productos;
}

TEST_CASE("Factura con descuento cero") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 0, 1000.0f, 200.0f);

    Factura factura(dto);

    CHECK(factura.getDescuento() == 0);
    CHECK(factura.getMontoTotal() == doctest::Approx(1000.0f));
    CHECK(factura.getIvaTotal() == doctest::Approx(200.0f));

    delete productos;
}

TEST_CASE("Factura con descuento máximo") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 100, 0.0f, 200.0f);

    Factura factura(dto);

    CHECK(factura.getDescuento() == 100);
    CHECK(factura.getMontoTotal() == doctest::Approx(0.0f));
    CHECK(factura.getIvaTotal() == doctest::Approx(200.0f));

    delete productos;
}

TEST_CASE("Factura con productos nulos") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = nullptr; // Simulando un caso donde no hay productos

    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

    CHECK_THROWS_AS(Factura factura(dto), std::invalid_argument); // Debería lanzar una excepción
}

TEST_CASE("Factura con fecha inválida") {
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    
    // Fecha inválida (mes 13)
    CHECK_THROWS_AS(DtFecha fecha(2025, 13, 14), std::invalid_argument);
    
    // Fecha válida
    DtFecha fecha(2025, 6, 14);
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

    Factura factura(dto);

    CHECK(factura.getFecha() == fecha);

    delete productos;
}

TEST_CASE("Factura con hora inválida") {
    DtFecha fecha(2025, 6, 14);
    
    // Hora inválida (hora 25)
    CHECK_THROWS_AS(DtHora hora(25, 30, 0), std::invalid_argument);
    
    // Hora válida
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

    Factura factura(dto);

    CHECK(factura.getHora() == hora);

    delete productos;
}

TEST_CASE("Factura con descuento negativo") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    
    // Descuento negativo
    CHECK_THROWS_AS(DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, -10, 900.0f, 180.0f), std::invalid_argument);
    
    // Descuento válido
    DtFactura dtoValido(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);
    Factura factura(dtoValido);

    CHECK(factura.getDescuento() == 10);

    delete productos;
}

TEST_CASE("Factura con monto total negativo") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    
    // Monto total negativo
    CHECK_THROWS_AS(DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, -900.0f, 180.0f), std::invalid_argument);
    
    // Monto total válido
    DtFactura dtoValido(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);
    Factura factura(dtoValido);

    CHECK(factura.getMontoTotal() == doctest::Approx(900.0f));

    delete productos;
}

TEST_CASE("Factura con IVA total negativo") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    
    // IVA total negativo
    CHECK_THROWS_AS(DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, -180.0f), std::invalid_argument);
    
    // IVA total válido
    DtFactura dtoValido(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);
    Factura factura(dtoValido);

    CHECK(factura.getIvaTotal() == doctest::Approx(180.0f));

    delete productos;
}

TEST_CASE("Factura con productos duplicados") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    productos->add((IKey*)new DtConsumido("Producto1", 2, 0), new DtConsumido("Producto1", 2, 0));
    productos->add((IKey*)new DtConsumido("Producto2", 3, 0), new DtConsumido("Producto2", 3, 0));
    
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

    Factura factura(dto);

    CHECK(factura.getProductos()->getSize() == 2); // Debería contar los productos únicos

    delete productos;
}

TEST_CASE("Factura con productos vacíos y descuento cero") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 0, 1000.0f, 200.0f);

    Factura factura(dto);

    CHECK(factura.getProductos()->getSize() == 0);
    CHECK(factura.getDescuento() == 0);
    CHECK(factura.getMontoTotal() == doctest::Approx(1000.0f));
    CHECK(factura.getIvaTotal() == doctest::Approx(200.0f));

    delete productos;
}

TEST_CASE("Factura con productos y descuento máximo") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    productos->add((IKey*)new DtConsumido("Producto1", 2, 2), new DtConsumido("Producto1", 2, 2));
    
    DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 100, 0.0f, 200.0f);

    Factura factura(dto);

    CHECK(factura.getProductos()->getSize() == 1);
    CHECK(factura.getDescuento() == 100);
    CHECK(factura.getMontoTotal() == doctest::Approx(0.0f));
    CHECK(factura.getIvaTotal() == doctest::Approx(200.0f));

    delete productos;
}

TEST_CASE("Factura con productos y descuento negativo") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    productos->add((IKey*)new DtConsumido("Producto1", 2,7), new DtConsumido("Producto1", 2,5));
    
    // Descuento negativo
    CHECK_THROWS_AS(DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, -10, 900.0f, 180.0f), std::invalid_argument);
    
    // Descuento válido
    DtFactura dtoValido(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);
    Factura factura(dtoValido);

    CHECK(factura.getDescuento() == 10);

    delete productos;
}

TEST_CASE("Factura con productos y monto total negativo") {
    DtFecha fecha(2025, 6, 14);
    DtHora hora(15, 30, 0);
    IDictionary *productos = new OrderedDictionary();
    productos->add((IKey*)new DtConsumido("Producto1", 2,7), new DtConsumido("Producto1", 2,5));
    
    // Monto total negativo
    CHECK_THROWS_AS(DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, -900.0f, 180.0f), std::invalid_argument);
    
    // Monto total válido
    DtFactura dtoValido(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);
    Factura factura(dtoValido);

    CHECK(factura.getMontoTotal() == doctest::Approx(900.0f));

    delete productos;
}
