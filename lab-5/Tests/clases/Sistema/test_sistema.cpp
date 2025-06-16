#include "../../doctest.h"
#include "../../../clases/Sistema/Sistema.h"
#include <iostream>
using namespace std;
// /**
//  *  // ###### --------------- Alta producto ---------------  #######
//     /*
//      * @brief El sistema guarda temporalmente el tipo de producto a crear.
//      * @param tipoProducto --> TipoProducto (Plato o Menu).
//      */
//     void seleccionarTipoProducto(TipoProducto);

//     /**
//      * @brief Crea un menu y lo guarda temporalmente en una variable del sistema.
//      * @param DtMenu --> Datos del menu a crear.
//      */
//     void crearMenu(DtMenu);

//     /**
//      * @brief Crea un plato y lo guarda temporalmente en una variable del sistema.
//      * @param DtPlato --> Datos del plato a crear.
//      */
//     void crearPlato(DtPlato);

//     /**
//      * @brief Lista todos los platos del sistema
//      * @return ICollection* --> Set<DtPlato>.
//      */
//     ICollection *obtenerPlatos();

//     /**
//      * @brief Añade un plato a un menu.
//      * @param codigo --> Codigo del plato a añadir.
//      * @param cantidad --> Cantidad de platos a añadir al menu.
//      * @note El sistema ya guarda en una variable el menu al que se le añadira el plato.
//      */
//     void anadirPlatoAMenu(char *, int);

//     /**
//      * @brief Crea el producto y lo guarda en el sistema.
//      */
//     void darAltaProducto();

//     /**
//      * @brief Cancela la creacion del producto.
//      */
//     void cancelarAltaProducto();

//     // ####### --------------- Alta producto --------------- #######

// */

TEST_CASE("Alta Producto") {
    
    ISistema *sistema = Sistema::getInstance();
    //Imprimir cada plato
    
    // Seleccionar tipo de producto
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);

    
    // Crear un plato
    DtPlato plato("Pasta", "Deliciosa pasta con salsa de tomate", 10.0);
    sistema->crearPlato(plato);
    
    // Obtener platos
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Platos obtenidos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 3);

    //Crear 2 platos mas
    DtPlato plato2("Plato", "Pizza con queso", 12.0);
    DtPlato plato3("Plato", "Ensalada fresca", 8.0);

    platos->add(new DtPlato(plato2));
    platos->add(new DtPlato(plato3));

    CHECK(platos->getSize() == 5);

    //Recorrer cada plato y verificar su tipo
    IIterator *it=platos->getIterator();
    while(it->hasCurrent()){
        DtPlato *p= (DtPlato * )it->getCurrent();
        CHECK(p->getTipo() == TipoProducto::TipoPlato);
        it->next();
    }

    //Ahora creamos un menu
    sistema->seleccionarTipoProducto(TipoProducto::TipoMenu);
    // Crear un menu
    sistema->crearMenu(DtMenu("Menu Especial", "Un menu especial con varios platos"));
    //Listar platos
    ICollection *platosMenu = sistema->obtenerPlatos();

    CHECK(platosMenu->getSize() == 3); // 3 platos +

    //Recorrer cada plato y, ponerlo en el menu

    it=platosMenu->getIterator();
    while(it->hasCurrent()){
        DtPlato *p= (DtPlato * )it->getCurrent();
        if(p->getTipo() == TipoProducto::TipoPlato){
            //Anadir al menu
            sistema->anadirPlatoAMenu(p->getCodigo(), 1);
        }
        it->next();

    }
    delete it;

    // Verificar que el menu tiene los platos añadidos
    ICollection *platosDelMenu = sistema->obtenerPlatos();
    CHECK(platosDelMenu->getSize() == 3); // 3 platos 
    //Recorrer cada plato del menu y verificar que estan en el menu
    it = platosDelMenu->getIterator();
    while (it->hasCurrent()) {
        DtPlato *p = (DtPlato *)it->getCurrent();
        if (p->getTipo() == TipoProducto::TipoMenu) {
            // Verificar que el menu tiene los platos añadidos
            CHECK(p->getCodigo() == "Menu Especial");
        }
        it->next();
    }

    sistema->darAltaProducto(); // Dar de alta el producto

    // Verificar que el producto fue dado de alta
    ICollection *productos = sistema->obtenerPlatos();
    CHECK(productos->getSize() == 3); // 3 platos
    it = productos->getIterator();
    while (it->hasCurrent()) {
        DtPlato *p = (DtPlato *)it->getCurrent();
        if (p->getTipo() == TipoProducto::TipoMenu) {
            // Verificar que el menu tiene los platos añadidos
            CHECK(p->getCodigo() == "Menu Especial");
        }
        if( p->getTipo() == TipoProducto::TipoPlato) {
            // Verificar que los platos fueron dados de alta
            CHECK(p->getDescripcion() != "");
        }
         // Imprimir cada plato
        it->next();
    }
    // Limpiar memoria
    delete it;
}

TEST_CASE("Cancelar Alta Producto") {
    ISistema *sistema = Sistema::getInstance();
    
    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);
    
    // Crear un plato
    cout << "Creando un plato..." << endl;
    DtPlato plato("Pasta", "Deliciosa pasta con salsa de tomate", 10.0);
    sistema->crearPlato(plato);
    
    // Cancelar alta de producto
    cout << "Cancelando alta de producto..." << endl;
    sistema->cancelarAltaProducto();
    
    // Verificar que no hay productos en el sistema
    cout << "Platos obtenidos tras cancelar alta: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Tamaño de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 3);
    CHECK_THROWS(sistema->darAltaProducto()); // Verificar que no se puede dar de alta un producto sin crear uno
    

}

TEST_CASE("Alta Producto con Datos Nulos") {
    ISistema *sistema = Sistema::getInstance();
    
    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);
    
    // Intentar crear un plato con datos nulos
    cout << "Intentando crear un plato con datos nulos..." << endl;
    CHECK_THROWS(sistema->crearPlato(DtPlato(nullptr, "", 0.0)));
    
    // Verificar que no hay productos en el sistema
    cout << "Platos obtenidos tras intentar crear un plato nulo: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Tamaño de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 3);
    

}

TEST_CASE("Alta Producto con Datos Inválidos") {
    ISistema *sistema = Sistema::getInstance();
    
    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);
    
    // Intentar crear un plato con datos inválidos
    cout << "Intentando crear un plato con datos inválidos..." << endl;
    CHECK_THROWS(sistema->crearPlato(DtPlato("Pasta", "", -10.0)));
    
    // Verificar que no hay productos en el sistema
    cout << "Platos obtenidos tras intentar crear un plato inválido: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Tamaño de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 3);
    

}

TEST_CASE("Alta Producto con Datos Válidos") {
    ISistema *sistema = Sistema::getInstance();
    
    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);
    
    // Crear un plato con datos válidos
    cout << "Creando un plato con datos válidos..." << endl;
    DtPlato plato("Pasta", "Deliciosa pasta con salsa de tomate", 10.0);
    sistema->crearPlato(plato);
    
    // Verificar que el plato fue creado correctamente
    cout << "Platos obtenidos tras crear un plato válido: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    platos->add(new DtPlato(plato)); // Agregar el plato creado a la colección
    cout << "Tamaño de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 4); // 3 platos + 1 nuevo
    
    IIterator *it = platos->getIterator();
    while (it->hasCurrent()) {
        DtPlato *p = (DtPlato *)it->getCurrent();
        if (p->getCodigo() == "Pasta") {
            CHECK(p->getDescripcion() == "Deliciosa pasta con salsa de tomate");
            CHECK(p->getPrecio() == 10.0);
        }
        it->next();
    }
    
    delete it; // Liberar memoria del iterador

}

TEST_CASE("Alta Producto con Datos Repetidos") {
    ISistema *sistema = Sistema::getInstance();
    
    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);
    
    // Crear un plato con datos válidos
    cout << "Creando un plato con datos válidos..." << endl;
    DtPlato plato("Pasta", "Deliciosa pasta con salsa de tomate", 10.0);
    sistema->crearPlato(plato);
    
    // Intentar crear el mismo plato nuevamente
    cout << "Intentando crear el mismo plato nuevamente..." << endl;
    CHECK_NOTHROW(sistema->crearPlato(plato)); // No debería lanzar excepción
    
    // Verificar que el plato no se haya duplicado
    cout << "Platos obtenidos tras intentar crear un plato repetido: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    platos->add(new DtPlato(plato)); // Agregar el plato creado a la colección
    cout << "Tamaño de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 4); // 3 platos + 1 nuevo
    
    IIterator *it = platos->getIterator();
    while (it->hasCurrent()) {
        DtPlato *p = (DtPlato *)it->getCurrent();
        if (p->getCodigo() == "Pasta") {
            CHECK(p->getDescripcion() == "Deliciosa pasta con salsa de tomate");
            CHECK(p->getPrecio() == 10.0);
        }
        it->next();
    }
    
    delete it; // Liberar memoria del iterador

}


