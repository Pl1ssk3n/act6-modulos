#pragma once
void iniciarvidas(float vidacartas[]);

void Mostrarvidas(float vidacartas[]);
// si pero eso lo tratan como diferente las funciones, mira te explico sencillo
float calculavidamaxima(float vidacartas[]);

float calculavidaminima(float vidacartas[]);

float calculavidapromedio(float vidacartas[]);

void danyarpordebajode(float vidacartas[], float cantvida, float danoapli);

void danyarporencimade(float vidacartas[], float cant, float danoapli);

int contarpordebajode(float vidacartas[], float cantvida);

int contarporencimade(float vidacartas[], float cantvida);

int contarigualesa(float vidacartas[], float cantvida);

int buscartriomaximo(float vidacartas[]);

void danyarigualesa(float vidacartas[], float cantvida, float danoapli);

int numsorteo();

void intercambiarvidas(float vidacartas[], int posicion1seleccionada, int posicion2seleccionada);

void DanyarCercanas(float vidas[], int posicion, int distancia, int danyo);