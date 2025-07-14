#include<iostream>
#include<string>
#include "structs.h"
using namespace std;

bool Existedni(string dni);
int buscarPersona(string dni);
void registrarPersona();
void agregarCuenta();
void mostrarPersona();

Persona personas[100];
int totalPersonas = 0;
