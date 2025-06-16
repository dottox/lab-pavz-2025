// #include "../../doctest.h"
// #include "../../../clases/Factura/Factura.h"
// #include "../../../datatypes/Factura/DtFactura.h"
// #include "../../../datatypes/Consumido/DtConsumido.h"
// #include "../../../datatypes/Fecha/DtFecha.h"
// #include "../../../datatypes/Hora/DtHora.h"
// #include "../../../ICollection/collections/OrderedDictionary.h"

// TEST_CASE("Factura destructor libera recursos correctamente")
// {
//     DtFecha fecha(14, 6, 2025);
//     DtHora hora(15, 30, 0);
//     IDictionary *productos = new OrderedDictionary();
//     DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

//     Factura *factura = new Factura(dto);
//     delete factura; // Verifica que no haya fugas de memoria
// }

// // TEST_CASE("Factura con productos consumidos")
// // {
// //     DtFecha fecha(14, 6, 2025);
// //     DtHora hora(15, 30, 0);
// //     IDictionary *productos = new OrderedDictionary();
// //     DtConsumido* dt = new DtConsumido("Pizza Margherita", 2, 250.0f);
// //     DtConsumido* dt2 = new DtConsumido("Pizza Margherita 2 ", 2, 250.0f);
// //     char* key = (char*)"P001";
// //     char* key2 = (char*)"P002";
// //     productos->add((IKey*)key, dt);
// //     productos->add((IKey*)key2, dt2);
// //     DtFactura dto(1234, 987, fecha, hora, productos, 1000.0f, 10, 900.0f, 180.0f);

// //     Factura factura(dto);
// //     delete productos;
// //     delete dt;
// //     delete dt2;
// // }


