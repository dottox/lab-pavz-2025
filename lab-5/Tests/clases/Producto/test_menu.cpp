#include "../../doctest.h"
#include "../../../clases/Producto/Producto.h"
#include "../../../clases/Producto/Menu.h"
#include "../../../clases/Producto/Plato.h"
#include "../../../datatypes/Producto/DtProducto.h"
#include "../../../datatypes/Producto/DtMenu.h"
#include "../../../datatypes/Producto/DtPlato.h"
#include "../../../enums/TipoProducto.h"
#include "../../../ICollection/interfaces/ICollectible.h"
#include "../../../ICollection/collections/OrderedDictionary.h"
#include "../../../ICollection/interfaces/IKey.h"
#include <iostream>
using namespace std;

TEST_CASE("Menu: Constructor y getters"){
    DtMenu dtMenu(const_cast<char*>("M001"), "Menu del Dia");
    Menu menu(dtMenu);

    CHECK(menu.getCodigo() == "M001");
    CHECK(menu.getDescripcion() == "Menu del Dia");
    CHECK(menu.getTipo() == TipoProducto::TipoMenu);
    CHECK(menu.getPrecio() == doctest::Approx(0.0f)); // Precio inicial es 0.0f
    CHECK(menu.esVacio() == true); // Debería estar vacío al inicio

    // Verificar que no haya platos en el menú
    ICollection *platos = menu.getPlatos();
    CHECK(platos->getSize() == 0);
}

TEST_CASE("Menu: Destructor"){
    DtMenu dtMenu(const_cast<char*>("M002"), "Menu Especial");
    Menu *menu = new Menu(dtMenu);

    // Verificar que el destructor no cause fugas de memoria
    delete menu;
}

TEST_CASE("Menu: Añadir plato y actualizar precio"){
    DtMenu dtMenu(const_cast<char*>("M003"), "Menu Gourmet");
    Menu menu(dtMenu);

    // Crear un plato
    DtPlato dtPlato(const_cast<char*>("P001"), "Sopa de Mariscos", 200.0f);
    Plato *plato = new Plato(dtPlato);

    // Añadir el plato al menú
    menu.anadirPlato(plato, 1);
    
    // Verificar que el plato se haya añadido correctamente
    ICollection *platos = menu.getPlatos();
    CHECK(platos->getSize() == 1);
    
    // Verificar que el precio del menú se actualice correctamente
    menu.actualizarPrecio();
    CHECK(menu.getPrecio() == doctest::Approx(200.0f));

    delete plato; // Liberar memoria del plato
}

TEST_CASE("Menu: Añadir plato con cantidad negativa"){
    DtMenu dtMenu(const_cast<char*>("M004"), "Menu de Prueba");
    Menu menu(dtMenu);

    // Crear un plato
    DtPlato dtPlato(const_cast<char*>("P002"), "Ensalada Mixta", 150.0f);
    Plato *plato = new Plato(dtPlato);

    // Intentar añadir el plato con cantidad negativa
    CHECK_THROWS_AS(menu.anadirPlato(plato, -1), std::invalid_argument);

    delete plato; // Liberar memoria del plato
}

TEST_CASE("Menu: Añadir plato con código existente"){
    DtMenu dtMenu(const_cast<char*>("M005"), "Menu de Almuerzo");
    Menu menu(dtMenu);

    // Crear un plato
    DtPlato dtPlato(const_cast<char*>("P003"), "Pasta Alfredo", 180.0f);
    Plato *plato = new Plato(dtPlato);

    // Añadir el plato al menú
    menu.anadirPlato(plato, 2);
    
    // Intentar añadir el mismo plato nuevamente
    CHECK_NOTHROW(menu.anadirPlato(plato, 3)); // No debería lanzar excepción

    // Verificar que el precio se actualice correctamente
    menu.actualizarPrecio();
    CHECK(menu.getPrecio() == doctest::Approx(180.0f * 5)); // 2 + 3 = 5 platos

    delete plato; // Liberar memoria del plato
}

TEST_CASE("Menu: Obtener platos"){
    DtMenu dtMenu(const_cast<char*>("M006"), "Menu de Cena");
    Menu menu(dtMenu);

    // Crear varios platos
    DtPlato dtPlato1(const_cast<char*>("P004"), "Pizza Margarita", 220.0f);
    DtPlato dtPlato2(const_cast<char*>("P005"), "Tacos al Pastor", 150.0f);
    Plato *plato1 = new Plato(dtPlato1);
    Plato *plato2 = new Plato(dtPlato2);

    // Añadir los platos al menú
    menu.anadirPlato(plato1, 1);
    menu.anadirPlato(plato2, 2);

    // Verificar que se obtienen los platos correctamente
    ICollection *platos = menu.getPlatos();
    CHECK(platos->getSize() == 2);

    delete plato1; // Liberar memoria del primer plato
    delete plato2; // Liberar memoria del segundo plato
}

TEST_CASE("Menu: Es vacío"){
    DtMenu dtMenu(const_cast<char*>("M007"), "Menu de Desayuno");
    Menu menu(dtMenu);

    // Verificar que el menú esté vacío al inicio
    CHECK(menu.esVacio() == true);

    // Crear un plato y añadirlo al menú
    DtPlato dtPlato(const_cast<char*>("P006"), "Tostadas Francesas", 120.0f);
    Plato *plato = new Plato(dtPlato);
    menu.anadirPlato(plato, 1);

    // Verificar que el menú ya no esté vacío
    CHECK(menu.esVacio() == false);

    delete plato; // Liberar memoria del plato
}

