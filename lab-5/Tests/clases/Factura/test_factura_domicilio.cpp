// #include "../../doctest.h"
// #include "../../../clases/Factura/FacturaDomicilio.h"
// #include "../../../datatypes/Factura/DtFacturaDomicilio.h"
// #include "../../../datatypes/Consumido/DtConsumido.h"
// #include "../../../datatypes/Fecha/DtFecha.h"
// #include "../../../datatypes/Hora/DtHora.h"
// #include "../../../ICollection/collections/OrderedDictionary.h"
// #include "../../../enums/Transporte.h"
// using namespace std;


// TEST_CASE("FacturaDomicilio: Destructor")
// {
//     DtFecha fecha(1, 1, 2023);
//     DtHora hora(12, 0, 0);
//     OrderedDictionary *productos = new OrderedDictionary();
//     productos->add((OrderedKey *)new DtConsumido("Pizza", 1, 10.0f), new DtConsumido("Pizza", 1, 10.0f));
//     DtFacturaDomicilio dto(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta);
//     FacturaDomicilio *factura = new FacturaDomicilio(dto);
//     delete factura; // Verificar que no haya fugas de memoria
// }

// TEST_CASE("FacturaDomicilio: Productos vacíos")
// {
//     DtFecha fecha(1, 1, 2023);
//     DtHora hora(12, 0, 0);
//     OrderedDictionary *productos = new OrderedDictionary();
//     DtFacturaDomicilio dto(1, fecha, hora, productos, 100.0f, 10, 90.0f, 18.0f, "Repartidor Pepe", Transporte::Bicicleta);
//     FacturaDomicilio factura(dto);
//     CHECK(factura.getProductos()->getSize() == 0);
//     delete productos;
// }
