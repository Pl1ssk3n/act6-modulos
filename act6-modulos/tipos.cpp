#include <stdio.h>
#include "tipos.hpp"
#include <stdlib.h>
#include <time.h>

void IniciarTipos(int tipos[])
{
	int indice = 5;
	int randoom;
	while(indice < 10)
	{
		tipos[indice] = rand()%7 + 1;
		indice += 1;
	}
	indice = 0;
}

void MostrarTipos(int tipos[])
{
	int indice = 0;
	printf("\n");	
	while(indice < 10)
	{
		printf("  %d   ", tipos[indice]);
		indice += 1;
	}
}

void MostrarTipos2(int tipos2[])
{
	int indice = 0;
	printf("\n");	
	while(indice < 10)
	{
		printf("  %d   ", tipos2[indice]);
		indice += 1;
	}
}

void IntercambiarTipos(int tipos[], int posicion1seleccionada, int posicion2seleccionada)
{
	float a;
	float b;
	int t;
	t = 0;
	a = tipos[posicion1seleccionada];
	b = tipos[posicion2seleccionada];
	t = a;
	a = b;
	b = t;
	tipos[posicion2seleccionada] = b;
	tipos[posicion1seleccionada] = a;
	printf("posicion 1 nueva %.2f\n", a);
	printf("posicion 2 nueva %.2f\n", b);
}	










