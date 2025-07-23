#include <iostream>
#include <string>
#include "structs.h"
#include "persona.h"
#include "cuenta.h"

using namespace std;

extern Persona personas[100];
extern int totalPersonas;

void agregarCuenta() {
    string dni;
    cout << "DNI de la persona: ";
    cin >> dni;

    int reem = buscarPersona(dni);
    if (reem == -1) {
        cout << "Persona no encontrada." << endl;
        return;
    }

    if (personas[reem].cantidadCuentas >= 3) {
        cout << "Ya tiene el máximo de cuentas." << endl;
        return;
    }

    Cuenta nueva;
    cout << "Numero de cuenta: ";
    cin >> nueva.numeroCuenta;
    cout << "Saldo inicial: ";
    cin >> nueva.saldo;
    nueva.cantidadMovimientos = 0;

    personas[reem].cuentas[personas[reem].cantidadCuentas++] = nueva;
    cout << "Cuenta agregada correctamente." << endl;
}

void gestionarMovimiento() {
    string dni;
    cout << "DNI de la persona: ";
    cin >> dni;

    int indicePersona = buscarPersona(dni);
    if (indicePersona == -1) {
        cout << "Persona no encontrada." << endl;
        return;
    }

    Persona& p = personas[indicePersona];

    if (p.cantidadCuentas == 0) {
        cout << "Esta persona no tiene cuentas registradas." << endl;
        return;
    }

    cout << "Seleccione una cuenta: " << endl;
    for (int i = 0; i < p.cantidadCuentas; i++) {
        cout << i + 1 << ". " << p.cuentas[i].numeroCuenta << endl;
    }

    int indiceCuenta;
    cout << "Ingrese opcion: ";
    cin >> indiceCuenta;
    indiceCuenta -= 1;

    if (indiceCuenta < 0 || indiceCuenta >= p.cantidadCuentas) {
        cout << "Cuenta invalida." << endl;
        return;
    }

    Cuenta& cuenta = p.cuentas[indiceCuenta];

    Movimiento nuevo;

    cin.ignore();
    cout << "Ingrese tipo (por ejemplo: deposito, retiro): ";
    getline(cin, nuevo.operacion.tipo);

    cout << "Ingrese el monto del " << nuevo.operacion.tipo << ": ";
    cin >> nuevo.monto;

    cin.ignore();
    cout << "Ingrese canal (por ejemplo: app, ventanilla): ";
    getline(cin, nuevo.operacion.canal);

    if (nuevo.operacion.tipo == "deposito") {
        cuenta.saldo += nuevo.monto;
    } else if (nuevo.operacion.tipo == "retiro") {
        if (nuevo.monto > cuenta.saldo) {
            cout << "Saldo insuficiente." << endl;
            return;
        }
        cuenta.saldo -= nuevo.monto;
    } else {
        cout << "Tipo de operacion no valida." << endl;
        return;
    }

    nuevo.operacion.idOperacion = cuenta.cantidadMovimientos + 1;
    cuenta.movimientos[cuenta.cantidadMovimientos++] = nuevo;

    cout << "Movimiento registrado correctamente." << endl;
}

void historialMovimientos() {
    string dni;
    cout << "DNI de la persona: ";
    cin >> dni;

    int indicePersona = buscarPersona(dni);
    if (indicePersona == -1) {
        cout << "Persona no encontrada." << endl;
        return;
    } 

    Persona& p = personas[indicePersona];
    if (p.cantidadCuentas == 0) {
        cout << "Esta persona no tiene cuentas registradas." << endl;
        return;
    }

    cout << "Seleccione una cuenta: " << endl;
    for (int i = 0; i < p.cantidadCuentas; i++) {
        cout << i + 1 << ". " << p.cuentas[i].numeroCuenta << endl;
    }

    int indiceCuenta;
    cout << "Ingrese opcion: ";
    cin >> indiceCuenta;
    indiceCuenta -= 1;

    if (indiceCuenta < 0 || indiceCuenta >= p.cantidadCuentas) {
        cout << "Cuenta invalida." << endl; 
        return;
    }

    Cuenta& cuenta = p.cuentas[indiceCuenta];

    if (cuenta.cantidadMovimientos == 0) {
        cout << "No hay movimientos registrados." << endl;
        return;
    }

    cout << "Movimientos registrados en la cuenta " << cuenta.numeroCuenta << ":" << endl;
    for (int i = 0; i < cuenta.cantidadMovimientos; i++) {
        Movimiento& m = cuenta.movimientos[i];
        cout << "  ID: " << m.operacion.idOperacion
             << " | Tipo: " << m.operacion.tipo
             << " | Canal: " << m.operacion.canal
             << " | Monto: " << m.monto << endl;
    }
}
