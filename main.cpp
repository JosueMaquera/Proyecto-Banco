#include<iostream>
#include<string>
using namespace std;

struct Operacion {
    int numero_operacion;
    string canal;
    string tipo;
};

struct Persona {
    int dni;
    string nombre;
};

struct Movimientos {
    int cantidadMovimientos;
    float montoRetiro;
    Operacion operacion;
};

struct Cuenta {
    Persona datos;
    float saldo;
    int numeroCuenta;
    Movimientos movimiento[100];
    int cantidadMovimientos;
};

int main() {
    
    return 0;
}