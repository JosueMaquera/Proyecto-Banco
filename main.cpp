#include <iostream>
#include <string>
#include "structs.h"
using namespace std;

bool Existedni(string dni);
int buscarPersona(string dni);
void registrarPersona();
void agregarCuenta();
void mostrarPersona();
void gestionarMovimiento();
void historialMovimientos();

Persona personas[100];
int totalPersonas = 0;

int main() {
    int opcion;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Registrar persona\n";
        cout << "2. Agregar cuenta\n";
        cout << "3. Mostrar persona\n";
        cout << "4. Realizar movimiento\n";
        cout << "5. Historial de movimientos\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: registrarPersona(); break;
            case 2: agregarCuenta(); break;
            case 3: mostrarPersona(); break;
            case 4: gestionarMovimiento(); break;
            case 5: historialMovimientos(); break;
            case 6: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while(opcion != 6);

    return 0;
}

bool Existedni(string dni) {
    for (int i = 0; i < totalPersonas; i++) {
        if (personas[i].dni == dni) {
            return true;
        }
    }
    return false;
}

int buscarPersona(string dni) {
    for (int i = 0; i < totalPersonas; i++) {
        if (personas[i].dni == dni) {
            return i;
        }
    }
    return -1;
}

void registrarPersona() {
    if (totalPersonas >= 100) {
        cout << "No se pueden registrar más personas." << endl;
        return;
    }

    string dni;
    cout << "Ingrese el DNI: ";
    cin >> dni;

    if (Existedni(dni)) {
        cout << "Ese DNI ya está registrado." << endl;
        return;
    }

    cin.ignore();
    cout << "Nombre: ";
    getline(cin, personas[totalPersonas].nombre);
    personas[totalPersonas].dni = dni;
    personas[totalPersonas].cantidadCuentas = 0;
    totalPersonas++;

    cout << "Persona registrada correctamente." << endl;
}

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

void mostrarPersona() {
    string dni;
    cout << "DNI de la persona: ";
    cin >> dni;

    int a = buscarPersona(dni);
    if (a == -1) {
        cout << "Persona no encontrada." << endl;
        return;
    }

    Persona p = personas[a];
    cout << "Nombre: " << p.nombre << endl;
    cout << "DNI: " << p.dni << endl;
    cout << "Cuentas:" << endl;
    for (int i = 0; i < p.cantidadCuentas; i++) {
        cout << "  Cuenta " << i + 1 << ": " << p.cuentas[i].numeroCuenta
             << " | Saldo: " << p.cuentas[i].saldo << endl;
    }
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
