#pragma once

class utils {
  private:
    utils() = default; // Constructor privado para evitar instanciación

  public:
    static int generarNumeroEmpleado();
    static int generarNumeroFactura();
    static int generarNumeroMesa();
    static int generarNumeroVenta();
};