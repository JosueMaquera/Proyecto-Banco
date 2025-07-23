#include <iostream>
#include "persona.h"
#include "cuenta.h"

using namespace std;

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
