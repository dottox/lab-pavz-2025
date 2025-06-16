// #include "../../doctest.h"
// #include "../../../datatypes/Factura/DtFactura.h"
// #include "../../../datatypes/Consumido/DtConsumido.h"
// #include "../../../datatypes/Fecha/DtFecha.h"
// #include "../../../datatypes/Hora/DtHora.h"
// #include "../../../datatypes/Factura/DtFacturaLocal.h"
// #include "../../../enums/Transporte.h"
// #include "../../../ICollection/collections/OrderedDictionary.h"
// #include "../../../ICollection/interfaces/IKey.h"

// #include <iostream>
// using namespace std;

// TEST_CASE("Test DtFactura - Constructor and Getters")
// {
//     DtConsumido *consumido = new DtConsumido("Pizza", 2, 15.50);
//     DtConsumido *consumido2 = new DtConsumido("Bebida", 1, 5.00);
//     DtHora *hora = new DtHora(12, 30, 0);
//     DtFecha *fecha = new DtFecha(1, 1, 2023);

//     // Adaptar el constructor para usar un array de productos en vez de IDictionary*
//     // Ajusta los argumentos según el constructor real de DtFacturaLocal
//     // Crear un IDictionary* y agregar los productos
//     OrderedDictionary *productosDict = new OrderedDictionary();
//     productosDict->add((IKey *)consumido, consumido);
//     productosDict->add((IKey *)consumido2, consumido2);
//     // Crear la factura local
//     DtFactura factura(1001, 0, *fecha, *hora, productosDict, 20.50, 10, 30.00, 3.00);
//     DtFacturaLocal *facturaLocal = new DtFacturaLocal(factura, "Juan Perez");
//     // Verificar los datos de la factura local
//     CHECK(facturaLocal->getCodigo() == 1001);   
//     CHECK(facturaLocal->getFecha() == *fecha);
//     CHECK(facturaLocal->getHora() == *hora);
//     CHECK(facturaLocal->getProductos()->getSize() == 2);
//     CHECK(facturaLocal->getSubtotal() == doctest::Approx(20.50));
//     CHECK(facturaLocal->getDescuento() == 10);
//     CHECK(facturaLocal->getMontoTotal() == doctest::Approx(30.00));
//     CHECK(facturaLocal->getIvaTotal() == doctest::Approx(3.00));
//     CHECK(facturaLocal->getNombreMozo() == "Juan Perez");
//     // Imprimir la factura para verificar la salida

//     delete facturaLocal;
//     delete productosDict;
//     delete fecha;
//     delete hora;
//     delete consumido;
//     delete consumido2;
    
// }
