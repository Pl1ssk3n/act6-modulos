#include <stdio.h>
#include "vidas.h"
#include <stdlib.h>
#include <time.h>

void iniciarvidas(float vidacartas[])
{
	int indice = 0;
	while (indice < 10)
	{
		vidacartas[indice] = 100;
		indice += 1;
	}
	indice = 0;
}


void Mostrarvidas(float vidacartas[])
{

	int indice = 0;
	while (indice < 10)
	{
		printf("%.2f ", vidacartas[indice]);
		indice += 1;
	}
}

float calculavidamaxima(float vidacartas[])
{
	int indice = 0;
	float vidamaxima;
	vidamaxima = vidacartas[0];
	while (indice < 10)
	{
		if (vidacartas[indice] > vidamaxima)
		{
			vidamaxima = vidacartas[indice];
		}

		indice += 1;
	}
	indice = 0;
	return vidamaxima;
}

float calculavidaminima(float vidacartas[])
{
	int indice = 0;
	float vidaminima;
	vidaminima = vidacartas[0];
	while (indice < 10)
	{
		if (vidacartas[indice] < vidaminima && vidaminima >= 0)
		{
			vidaminima = vidacartas[indice];
		}

		indice += 1;
	}
	indice = 0;
	return vidaminima;
}

float calculavidapromedio(float vidacartas[])
{
	int indice = 0;
	float sumaprom = 0;
	float promedio;
	int sumacasillas;
	while (indice < 10)
	{
		sumaprom += vidacartas[indice];
		indice += 1;
	}
	sumacasillas = 10;
	promedio = sumaprom / sumacasillas;
	indice = 0;
	return promedio;
}

void danyarpordebajode(float vidacartas[], float cantvida, float danoapli)
{
	int indidano = 0;
	while (indidano < 10)
	{
		if (vidacartas[indidano] < cantvida)
		{
			vidacartas[indidano] = vidacartas[indidano] - danoapli;
		}
		indidano += 1;
	}
	indidano = 0;
}

void danyarporencimade(float vidacartas[], float cantvida, float danoapli)
{
	int indidano = 0;
	while (indidano < 10)
	{
		if (vidacartas[indidano] > cantvida)
		{
			vidacartas[indidano] = vidacartas[indidano] - danoapli;
		}
		indidano += 1;
	}
	indidano = 0;
}

int contarpordebajode(float vidacartas[], float cantvida)
{
	int indidano = 0;
	int conteodebajo = 0;
	while (indidano < 10)
	{
		if (vidacartas[indidano] < cantvida)
		{
			conteodebajo += 1;
		}
		indidano += 1;
	}
	indidano = 0;
	return conteodebajo;
}

int contarporencimade(float vidacartas[], float cantvida)
{
	int indidano = 0;
	int conteodencima = 0;
	while (indidano < 10)
	{
		if (vidacartas[indidano] > cantvida)
		{
			conteodencima += 1;
		}
		indidano += 1;
	}
	indidano = 0;
	return conteodencima;
}

int contarigualesa(float vidacartas[], float cantvida)
{
	int indidano = 0;
	int conteoiguales = 0;
	while (indidano < 10)
	{
		if (vidacartas[indidano] == cantvida)
		{
			conteoiguales += 1;
		}
		indidano += 1;
	}
	indidano = 0;
	return conteoiguales;
}

int buscartriomaximo(float vidacartas[])
{
	int indice = 0;
	int sumatrio;
	int maxtrio = 0;
	int numeroindicetrio;
	while (indice < 8)
	{
		sumatrio = vidacartas[indice] + vidacartas[indice + 1] + vidacartas[indice + 2];
		if (sumatrio > maxtrio)
		{
			maxtrio = sumatrio;
			numeroindicetrio = indice + 1;
			indice += 1;
		}
		indice += 1;
	}
	indice = 0;
	return numeroindicetrio;
}

void danyarigualesa(float vidacartas[], float cantvida, float danoapli)
{
	int indidano = 0;
	while (indidano < 10)
	{
		if (vidacartas[indidano] == cantvida)
		{
			vidacartas[indidano] = vidacartas[indidano] - danoapli;
		}
		indidano += 1;
	}
	indidano = 0;
}

int numsorteo()
{
	int randoom;
	randoom = rand() % 2;

	return randoom;
}

void intercambiarvidas(float vidacartas[], int posicion1seleccionada, int posicion2seleccionada)
{
	float a;
	float b;
	int t;
	t = 0;
	a = vidacartas[posicion1seleccionada];
	b = vidacartas[posicion2seleccionada];
	t = a;
	a = b;
	b = t;
	vidacartas[posicion2seleccionada] = b;
	vidacartas[posicion1seleccionada] = a;
	printf("posicion 1 nueva %.2f\n", a);
	printf("posicion 2 nueva %.2f\n", b);
}
									
void DanyarCercanas(float vidas[], int posicion, int distancia, int danyo)
{
	while (posicion <= distancia)
	{
		vidas[posicion] -= danyo;
		posicion+= 1;
	}
}