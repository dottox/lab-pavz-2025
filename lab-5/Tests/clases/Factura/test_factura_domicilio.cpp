#include "../../doctest.h"
#include "../../../clases/Factura/FacturaDomicilio.h"
#include "../../../datatypes/Factura/DtFacturaDomicilio.h"
#include "../../../datatypes/Consumido/DtConsumido.h"
#include "../../../datatypes/Fecha/DtFecha.h"
#include "../../../datatypes/Hora/DtHora.h"
#include "../../../ICollection/collections/OrderedDictionary.h"
#include "../../../enums/Transporte.h"
using namespace std;

TEST_CASE("FacturaDomicilio: Constructor y getters")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    productos->add((IKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));
    DtFacturaDomicilio dto(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta);
    FacturaDomicilio factura(dto);
    CHECK(factura.getCodigo() == 1);
    CHECK(factura.getFecha() == fecha);
    CHECK(factura.getHora() == hora);
    CHECK(factura.getProductos()->getSize() == 1);
    CHECK(factura.getSubtotal() == doctest::Approx(100.0f));
    CHECK(factura.getDescuento() == 10);
    CHECK(factura.getMontoTotal() == doctest::Approx(90.0f));
    CHECK(factura.getIvaTotal() == doctest::Approx(18.0f));
    CHECK(factura.getNombreRepartidor() == "Repartidor Pepe");
    CHECK(factura.getTransporte() == Transporte::Bicicleta);

    // Verificar que los productos sean correctos
    IDictionary *productosFactura = factura.getProductos();
    IIterator *it = productosFactura->getIterator();
    int count = 0;
    while (it->hasCurrent())
    {
        ICollectible *current = it->getCurrent();
        DtConsumido *consumido = dynamic_cast<DtConsumido *>(current);
        if (consumido)
        {
            CHECK(consumido->getDescripcion() == "Pizza");
            CHECK(consumido->getCantidad() == 1);
            CHECK(consumido->getPrecio() == doctest::Approx(10.0f));
            count++;
        }
        it->next();
    }
    CHECK(count == 1);
    delete it;
}

TEST_CASE("FacturaDomicilio: Destructor")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    productos->add((IKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));
    DtFacturaDomicilio dto(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta);
    FacturaDomicilio *factura = new FacturaDomicilio(dto);
    delete factura; // Verificar que no haya fugas de memoria
}

TEST_CASE("FacturaDomicilio: Productos vacíos")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    DtFacturaDomicilio dto(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta);
    FacturaDomicilio factura(dto);
    CHECK(factura.getProductos()->getSize() == 0);
    delete productos;
}

TEST_CASE("FacturaDomicilio: Transporte inválido")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    productos->add((IKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));
    CHECK_THROWS_AS(DtFacturaDomicilio dto(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", (Transporte)999), std::invalid_argument);
    delete productos;
}

TEST_CASE("FacturaDomicilio: Datos inválidos")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    CHECK_THROWS_AS(DtFacturaDomicilio dto(0, fecha, hora, productos, -100.0f, -10, -90.0f, -18.0f, "Repartidor Pepe", Transporte::Bicicleta), std::invalid_argument);
    delete productos;
}

TEST_CASE("FacturaDomicilio: Datos nulos")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    CHECK_THROWS_AS(DtFacturaDomicilio dto(1, fecha, hora, nullptr, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta), std::invalid_argument);
    delete productos;
}

TEST_CASE("FacturaDomicilio: Datos de factura")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    productos->add((IKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));
    DtFacturaDomicilio dto(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta);
    FacturaDomicilio factura(dto);

    DtFacturaDomicilio datos = factura.getDatos();

    CHECK(datos.getCodigoVenta() == 1);
    CHECK(datos.getFecha() == fecha);
    CHECK(datos.getHora() == hora);
    CHECK(datos.getProductos()->getSize() == 1);
    CHECK(datos.getSubtotal() == doctest::Approx(100.0f));
    CHECK(datos.getDescuento() == 10);
    CHECK(datos.getMontoTotal() == doctest::Approx(90.0f));
    CHECK(datos.getIvaTotal() == doctest::Approx(18.0f));
    CHECK(datos.getNombreRepartidor() == "Repartidor Pepe");
    CHECK(datos.getTransporte() == Transporte::Bicicleta);

    delete productos;
}

TEST_CASE("FacturaDomicilio: Productos con datos inválidos")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    CHECK_THROWS_AS(productos->add((IKey *)new DtConsumido("", -1, -10.0f), new DtConsumido("", -1, -10.0f)), std::invalid_argument);
    delete productos;
}

TEST_CASE("FacturaDomicilio: Productos con datos nulos")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    CHECK_THROWS_AS(productos->add(nullptr, nullptr), std::invalid_argument);
    delete productos;
}

TEST_CASE("FacturaDomicilio: Productos con datos duplicados")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    productos->add((IKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));
    CHECK_THROWS_AS(productos->add((IKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f)), std::invalid_argument);
    delete productos;
}

TEST_CASE("FacturaDomicilio: Productos con datos de tipo correcto")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    productos->add((IKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));
    CHECK_NOTHROW(productos->add((IKey *)new DtConsumido("Ensalada", 2, 5.0f), new DtConsumido("Ensalada", 2, 5.0f)));
    delete productos;
}

TEST_CASE("FacturaDomicilio: getDatos con productos nulos")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    DtFacturaDomicilio dto(1, fecha, hora, nullptr, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta);
    FacturaDomicilio factura(dto);
    CHECK_THROWS_AS(factura.getDatos(), std::invalid_argument);
}

TEST_CASE("FacturaDomicilio: getDatos con productos vacíos")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    DtFacturaDomicilio dto(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta);
    FacturaDomicilio factura(dto);
    CHECK_NOTHROW(factura.getDatos());
    delete productos;
}

TEST_CASE("FacturaDomicilio: getDatos con productos de tipo correcto")
{
    DtFecha fecha(1, 1, 2023);
    DtHora hora(12, 0, 0);
    OrderedDictionary *productos = new OrderedDictionary();
    productos->add((IKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));
    DtFacturaDomicilio dto(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta);
    FacturaDomicilio factura(dto);
    CHECK_NOTHROW(factura.getDatos());
    delete productos;
}
