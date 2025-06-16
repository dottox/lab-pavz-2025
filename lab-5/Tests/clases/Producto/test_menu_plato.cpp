#include "../../doctest.h"
#include "../../../clases/Producto/Producto.h"
#include "../../../clases/Producto/Menu.h"
#include "../../../clases/Producto/Plato.h"
#include "../../../clases/Empleado/Mozo.h"
#include "../../../clases/Empleado/Empleado.h"

#include "../../../datatypes/Producto/DtProducto.h"
#include "../../../datatypes/Producto/DtMenu.h"
#include "../../../datatypes/Producto/DtPlato.h"
#include "../../../enums/TipoProducto.h"
#include "../../../ICollection/interfaces/ICollectible.h"
#include "../../../ICollection/collections/OrderedDictionary.h"
#include "../../../ICollection/interfaces/IKey.h"

#include <iostream>
using namespace std;

TEST_CASE("MenuPlato: Constructor y getters") {
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

TEST_CASE("Menu: Destructor") {
    DtMenu dtMenu(const_cast<char*>("M002"), "Menu Especial");
    Menu *menu = new Menu(dtMenu);

    // Verificar que el destructor no cause fugas de memoria
    delete menu;
}

TEST_CASE("Menu: Añadir plato y actualizar precio") {
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

TEST_CASE("Menu: Añadir plato con cantidad negativa") {
    DtMenu dtMenu(const_cast<char*>("M004"), "Menu de Almuerzo");
    Menu menu(dtMenu);

    // Crear un plato
    DtPlato dtPlato(const_cast<char*>("P002"), "Ensalada César", 150.0f);
    Plato *plato = new Plato(dtPlato);

    // Intentar añadir el plato con una cantidad negativa
    CHECK_THROWS_AS(menu.anadirPlato(plato, -1), std::invalid_argument);

    delete plato; // Liberar memoria del plato
}
TEST_CASE("Menu: Añadir plato existente") {
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

TEST_CASE("Menu: Añadir plato con código existente") {
    DtMenu dtMenu(const_cast<char*>("M006"), "Menu de Cena");
    Menu menu(dtMenu);

    // Crear un plato
    DtPlato dtPlato(const_cast<char*>("P004"), "Pizza Margarita", 220.0f);
    Plato *plato = new Plato(dtPlato);

    // Añadir el plato al menú
    menu.anadirPlato(plato, 1);
    
    // Intentar añadir el mismo plato nuevamente
    CHECK_NOTHROW(menu.anadirPlato(plato, 2)); // No debería lanzar excepción

    // Verificar que el precio se actualice correctamente
    menu.actualizarPrecio();
    CHECK(menu.getPrecio() == doctest::Approx(220.0f * 3)); // 1 + 2 = 3 platos

    delete plato; // Liberar memoria del plato
}

TEST_CASE("Menu: Obtener platos") {
    DtMenu dtMenu(const_cast<char*>("M007"), "Menu de Cena");
    Menu menu(dtMenu);

    // Crear varios platos
    DtPlato dtPlato1(const_cast<char*>("P005"), "Tacos de Pollo", 150.0f);
    Plato *plato1 = new Plato(dtPlato1);
    DtPlato dtPlato2(const_cast<char*>("P006"), "Burrito Vegetariano", 180.0f);
    Plato *plato2 = new Plato(dtPlato2);

    // Añadir los platos al menú
    menu.anadirPlato(plato1, 2);
    menu.anadirPlato(plato2, 3);

    // Verificar que se hayan añadido correctamente
    ICollection *platos = menu.getPlatos();
    CHECK(platos->getSize() == 2);

    delete plato1; // Liberar memoria del primer plato
    delete plato2; // Liberar memoria del segundo plato
}

TEST_CASE("Menu: Es vacío") {
    DtMenu dtMenu(const_cast<char*>("M008"), "Menu de Desayuno");
    Menu menu(dtMenu);

    // Verificar que el menú esté vacío al inicio
    CHECK(menu.esVacio() == true);

    // Crear un plato y añadirlo al menú
    DtPlato dtPlato(const_cast<char*>("P007"), "Tostadas Francesas", 120.0f);
    Plato *plato = new Plato(dtPlato);
    menu.anadirPlato(plato, 1);

    // Verificar que el menú ya no esté vacío
    CHECK(menu.esVacio() == false);

    delete plato; // Liberar memoria del plato
}

TEST_CASE("Menu: Obtener instancia de Menu") {
    DtMenu dtMenu(const_cast<char*>("M009"), "Menu de Almuerzo");
    Menu menu(dtMenu);

    CHECK(menu.getCodigo() == "M009"); // Verifica que getCodigo retorne el código del menú
    CHECK(menu.getDescripcion() == "Menu de Almuerzo"); // Verifica que getDescripcion retorne la descripción del menú

    // Verificar que el tipo sea TipoMenu
    CHECK(menu.getTipo() == TipoProducto::TipoMenu);
}

TEST_CASE("Menu: Setters con valores inválidos") {
    DtMenu dtMenu(const_cast<char*>("M010"), "Menu de Cena");
    Menu menu(dtMenu);

    // Intentar establecer un precio negativo
    CHECK_THROWS_AS(menu.setPrecio(-50.0f), std::invalid_argument);
}

TEST_CASE("Menu: Setters con venta en curso") {
    DtMenu dtMenu(const_cast<char*>("M011"), "Menu de Fiesta");
    Menu menu(dtMenu);

    // Crear un plato
    DtPlato dtPlato(const_cast<char*>("P008"), "Paella", 250.0f);
    Plato *plato = new Plato(dtPlato);

    // Añadir el plato al menú
    menu.anadirPlato(plato, 1);
    
    // Verificar que se pueda cambiar el precio mientras hay una venta en curso
    menu.setPrecio(300.0f);
    CHECK(menu.getPrecio() == doctest::Approx(300.0f));

    delete plato; // Liberar memoria del plato
}




