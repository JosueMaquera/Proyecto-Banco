#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
using namespace std;

struct Operacion {
    int idOperacion;
    string canal;
    string tipo;    
};

struct Movimiento {
    float monto;  
    Operacion operacion;
};

struct Cuenta {
    float saldo;
    string numeroCuenta;
    Movimiento movimientos[100];
    int cantidadMovimientos;
};

struct Persona {
    string dni;
    string nombre;
    Cuenta cuentas[3];
    int cantidadCuentas = 0;
};

#endif