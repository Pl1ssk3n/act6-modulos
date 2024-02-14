#ifndef _VIDAS_HPP_
#define _VIDAS_HPP_

void iniciarvidas(float vidacartas[]);

void Mostrarvidas(float vidacartas[]);

void Mostrarvidas2(float vidacartas2[]);

float calculavidamaxima(float vidacartas[]);

float calculavidaminima(float vidacartas[]);

float calculavidapromedio(float vidacartas[]);//se puede usar para ver si las cartas estan muertas, si esto = 0 todas muertas

void danyarpordebajode (float vidacartas[], float cantvida, float danoapli);

void danyarporencimade(float vidacartas[], float cant, float danoapli);

int contarpordebajode(float vidacartas[], float cantvida);

int contarporencimade(float vidacartas[], float cantvida);

int contarigualesa(float vidacartas[], float cantvida);//se puede usar para ver si las cartas estan muertas

int buscartriomaximo(float vidacartas[]);

void danyarigualesa(float vidacartas[], float cantvida, float danoapli);

int numsorteo();

void intercambiarvidas(float vidacartas[], int posicion1seleccionada, int posicion2seleccionada);

//void intercambiarvidas2(float vidacartas2[], int posicion1seleccionada, int posicion2seleccionada);

#endif