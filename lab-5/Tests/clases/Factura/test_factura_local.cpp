// #include "../../doctest.h"
// #include "../../../clases/Factura/FacturaLocal.h"
// #include "../../../datatypes/Factura/DtFacturaLocal.h"
// #include "../../../datatypes/Consumido/DtConsumido.h"
// #include "../../../datatypes/Fecha/DtFecha.h"
// #include "../../../datatypes/Hora/DtHora.h"
// #include "../../../ICollection/collections/OrderedDictionary.h"
// #include "../../../enums/Transporte.h"
// using namespace std;

// TEST_CASE("FacturaLocal: Constructor y getters")
// {
//     DtFecha fecha(1, 1, 2023);
//     DtHora hora(12, 0, 0);
//     OrderedDictionary *productos = new OrderedDictionary();
//     productos->add((OrderedKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));
//     DtFactura factura(1, 0, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f);
//     DtFacturaLocal factura2(factura, "Mozo Juan");
//     FacturaLocal dto(factura2);

//     CHECK(dto.getCodigo() == 1);
//     CHECK(dto.getFecha() == fecha);
//     CHECK(dto.getHora() == hora);
//     CHECK(dto.getProductos()->getSize() == 1);
//     CHECK(dto.getSubtotal() == doctest::Approx(100.0f));
//     CHECK(dto.getDescuento() == 10);
//     CHECK(dto.getMontoTotal() == doctest::Approx(90.0f));
//     CHECK(dto.getIvaTotal() == doctest::Approx(18.0f));
//     CHECK(dto.getNombreMozo() == "Mozo Juan");

//     // Verificar que los productos sean correctos
//     IDictionary *productosFactura = dto.getProductos();
//     IIterator *it = productosFactura->getIterator();
//     int count = 0;
//     while (it->hasCurrent())
//     {
//         ICollectible *current = it->getCurrent();
//         DtConsumido *consumido = dynamic_cast<DtConsumido *>(current);
//         if (consumido)
//         {
//             CHECK(consumido->getDescripcion() == "Pizza");
//             CHECK(consumido->getCantidad() == 1);
//             CHECK(consumido->getPrecio() == doctest::Approx(10.0f));
//             count++;
//         }
//         it->next();
//     }
//     CHECK(count == 1);
//     delete it;
// }

// TEST_CASE("FacturaLocal: Destructor")
// {
//     DtFecha fecha(1, 1, 2023);
//     DtHora hora(12, 0, 0);
//     OrderedDictionary *productos = new OrderedDictionary();
//     productos->add((OrderedKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));

//     {
//         DtFactura factura(1, 0, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f);
//         DtFacturaLocal factura2(factura, "Mozo Juan");
//         FacturaLocal dto(factura2);
//     }

//     delete productos;
// }



// TEST_CASE("FacturaLocal: Productos con datos nulos")
// {
//     DtFecha fecha(1, 1, 2023);
//     DtHora hora(12, 0, 0);
//     OrderedDictionary *productos = new OrderedDictionary();

//     CHECK_THROWS_AS(productos->add(nullptr, nullptr), std::invalid_argument);

//     delete productos;
// }

// TEST_CASE("FacturaLocal: Productos con datos duplicados")
// {
//     DtFecha fecha(1, 1, 2023);
//     DtHora hora(12, 0, 0);
//     OrderedDictionary *productos = new OrderedDictionary();
//     productos->add((OrderedKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));

//     CHECK_THROWS_AS(productos->add((OrderedKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f)), std::invalid_argument);

//     delete productos;
// }

// TEST_CASE("FacturaLocal: Productos con datos correctos")
// {
//     DtFecha fecha(1, 1, 2023);
//     DtHora hora(12, 0, 0);
//     OrderedDictionary *productos = new OrderedDictionary();
//     productos->add((OrderedKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));

//     CHECK_NOTHROW(productos->add((OrderedKey *)new DtConsumido("Ensalada", 2, 5.0f), new DtConsumido("Ensalada", 2, 5.0f)));

//     delete productos;
// }

// TEST_CASE("FacturaLocal: Transporte en DtFacturaDomicilio")
// {
//     DtFecha fecha(1, 1, 2023);
//     DtHora hora(12, 0, 0);
//     OrderedDictionary *productos = new OrderedDictionary();
//     productos->add((OrderedKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));

//     CHECK_NOTHROW({
//         DtFacturaDomicilio facturaDomicilio(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Juan", Transporte::Moto);
//     });

//     delete productos;
// }
