#include <iostream>
#include <string>
#include "structs.h"
#include "persona.h"

using namespace std;

extern Persona personas[100];
extern int totalPersonas;

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
