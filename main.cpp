#include<iostream>
#include<string>
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
    int numeroCuenta;
    Movimiento movimientos[100];
    int cantidadMovimientos;
};

struct Persona {
    int dni;
    string nombre;
    Cuenta cuentas[100];
    int cantidadCuentas;
};

int main() {
    
    return 0;
}