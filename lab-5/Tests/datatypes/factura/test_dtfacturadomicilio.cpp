// #include "../../doctest.h"
// #include "../../../datatypes/Factura/DtFactura.h"
// #include "../../../datatypes/Factura/DtFacturaDomicilio.h"
// #include "../../../datatypes/Consumido/DtConsumido.h"
// #include "../../../datatypes/Fecha/DtFecha.h"
// #include "../../../datatypes/Hora/DtHora.h"
// #include "../../../enums/Transporte.h"
// #include "../../../ICollection/collections/OrderedDictionary.h"
// #include "../../../ICollection/interfaces/IKey.h"
// #include <iostream>
// using namespace std;

// TEST_CASE("Test DtFactura - Constructor and Getters")
// {
//      DtConsumido *consumido = new DtConsumido("Pizza", 2, 15.50);
//      DtConsumido *consumido2 = new DtConsumido("Bebida", 1, 5.00);
//      DtHora *hora = new DtHora(12, 30, 0);
//      DtFecha *fecha = new DtFecha(1, 1, 2023);
//      // Adaptar el constructor para usar un array de productos en vez de IDictionary*
//      // Ajusta los argumentos según el constructor real de DtFacturaDomicilio
//      // Crear un IDictionary* y agregar los productos
//      OrderedDictionary *productosDict = new OrderedDictionary();
//      productosDict->add((IKey *)consumido, consumido);
//      productosDict->add((IKey *)consumido2, consumido2);
//      // Crear la factura de domicilio

//      DtFacturaDomicilio *facturaDomicilio = new DtFacturaDomicilio(
//          1001, *fecha, *hora, productosDict, 20.50, 10, 30.00, 3.00, std::string("Juan Perez"), Transporte::Moto
//      );

//      CHECK(facturaDomicilio->getCodigoVenta() == 1001);
//      CHECK(facturaDomicilio->getFecha().getDia() == 1);
//      CHECK(facturaDomicilio->getFecha().getMes() == 1);
//      CHECK(facturaDomicilio->getFecha().getAnio() == 2023);
//      CHECK(facturaDomicilio->getHora().getHora() == 12);
//      CHECK(facturaDomicilio->getHora().getMinuto() == 30);
//      CHECK(facturaDomicilio->getHora().getSegundo() == 0);
//      CHECK(facturaDomicilio->getSubtotal() == 20.50);
//      CHECK(facturaDomicilio->getDescuento() == 10);
//      CHECK(facturaDomicilio->getMontoTotal() == 30.00);
//      CHECK(facturaDomicilio->getIvaTotal() == 3.00);
//      CHECK(facturaDomicilio->getNombreRepartidor() == "Juan Perez");
//      CHECK(facturaDomicilio->getTransporte() == Transporte::Moto);
//      // Imprimir la factura para verificar la salida
//      cout << "Factura Domicilio: " << endl;
//      cout << "Codigo Venta: " << facturaDomicilio->getCodigoVenta() << endl;
//      cout << "Fecha: " << facturaDomicilio->getFecha().getDia() << "/"
//           << facturaDomicilio->getFecha().getMes() << "/"
//           << facturaDomicilio->getFecha().getAnio() << endl;
//      cout << "Hora: " << facturaDomicilio->getHora().getHora() << ":"
//           << facturaDomicilio->getHora().getMinuto() << ":"
//           << facturaDomicilio->getHora().getSegundo() << endl;
//      cout << "Productos: " << endl;
//      cout << "Subtotal: " << facturaDomicilio->getSubtotal() << endl;
//      cout << "Descuento: " << facturaDomicilio->getDescuento() << "%" << endl;
//      cout << "Monto Total: " << facturaDomicilio->getMontoTotal() << endl;
//      cout << "IVA Total: " << facturaDomicilio->getIvaTotal() << endl;
//      cout << "Nombre Repartidor: " << facturaDomicilio->getNombreRepartidor() << endl;
//      cout << "Transporte: " << (facturaDomicilio->getTransporte() == Transporte::Moto ? "Moto" : "Otro") << endl;
// }