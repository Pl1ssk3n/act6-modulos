#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "vidas.h"
#include "tipos.h"


void scavenger(float vidas[], int dano)
{
	danyarigualesa(vidas, calculavidaminima(vidas), dano);// lo veo 
}

void intercambioMenu(int tipos[10], float vidas[10])
{
	int posicion1seleccionada, posicion2seleccionada;
	printf("intercambiar posiciones de las vidas \nposicion 1 del 0 al 9?\n");
	scanf_s("%d", &posicion1seleccionada);
	printf("posicion 2 del 0 a 9?\n");
	scanf_s("%d", &posicion2seleccionada);
	printf("posicion 1 original %.2f\n", vidas[posicion1seleccionada]);
	printf("posicion 2 original %.2f\n", vidas[posicion2seleccionada]);
	intercambiarvidas(vidas, posicion1seleccionada, posicion2seleccionada);
	printf("intercambiar posiciones de los tipos de cartas \nposicion 1 del 0 al 9?\n");
	scanf_s("%d", &posicion1seleccionada);
	printf("posicion 2 del 0 a 9?\n");
	scanf_s("%d", &posicion2seleccionada);
	printf("posicion 1 original %d\n", tipos[posicion1seleccionada]);
	printf("posicion 2 original %d\n", tipos[posicion2seleccionada]);
	IntercambiarTipos(tipos, posicion1seleccionada, posicion2seleccionada);
}



int main()
{
	float vidacartas[10] = { 20, 67, 18, 90, 30, 12, 16, 83, 62, 15 };
	float vidacartas2[10] = { 20, 43, 52, 67, 34, 80, 75, 63, 40, 99 };
	
	int tipos[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int tipos2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	int opcion, conteodebajo, pos, cantdano, dist, conteodencima, conteoiguales, numeroindicetrio, indice, randoom, turno, opcionmenu, ataque;

	float vidamaxima, vidaminima, cantvida, danoapli, a, b, promedio;
	
	srand(time(NULL));
	calculavidapromedio(vidacartas);
	turno = numsorteo();
	opcionmenu = -1;
	IniciarTipos(tipos);
	IniciarTipos(tipos2);
	while (opcionmenu != 0)
	{
		printf("************************************************************\n");
		printf("cartas jugador 1:\n");
		Mostrarvidas(vidacartas);
		MostrarTipos(tipos);
		printf("\n************************************************************\n");
		printf("cartas jugador 2:\n");
		Mostrarvidas(vidacartas2);
		MostrarTipos(tipos2);
		printf("\n************************************************************\n");
		printf("sorteo de turno\n");
		printf("0 = Empieza jugador 1\n");
		printf("1 = Empieza jugador 2\n");
		printf("Empieza = %d\n", turno);
		printf("************************************************************\n");
		printf("1.-IntercambiarTipos y IntercambiarVidas....................\n");
		printf("2.-atacar...................................................\n");
		printf("0.-Salir....................................................\n");
		printf("************************************************************\n");
		scanf_s("%d", &opcionmenu);

		switch (opcionmenu)
		{

		case 1:
		{
			if (turno == 0) intercambioMenu(tipos, vidacartas);
			else intercambioMenu(tipos2, vidacartas2);
		}

		case 2:
		{

			printf("Que carta quieres usar?\n");
			printf("0.-SOLDIER.............................\n");
			printf("1.-KINGSLAYER..........................\n");
			printf("2.-SCAVENGER...........................\n");
			printf("3.-PREDATOR............................\n");
			printf("4.-DARWIN..............................\n");
			printf("5.-PLAGUE..............................\n");
			printf("6.-DOOM................................\n");
			printf("7.-WILDFIRE............................\n");
			scanf_s("%d", &ataque);
			switch (ataque)
			{
			case 0:
				int soldier;
				printf("A que soldier usaras para atacar?-> \n");
				scanf_s("%d", &soldier);
				danoapli = rand() % 5 + 1;
				if (turno == 0)
					if (vidacartas[soldier] < 0)vidacartas2[soldier] -= danoapli;
					else printf("Tu soldier eta muelto\n"); //
				else 
					if (vidacartas[soldier] < 0) vidacartas[soldier] -= danoapli;
					else printf("Tu soldier eta muelto\n");
				break;
			case 1:
				float carta_menos_vida;
				//esto cual es?¿
				/*
				* case2: rand() %11 + 20;
				*case3:rand()%6 + 5;
				*case4: rand()%6 + 5;
				*case5: rand()%6 + 5;
				*case6: rand()%11 + 10;
				*case7: rand()%6 + 5;
				*
				*/
				if (turno == 0)
				{
					danoapli = rand() % 11 + 20;
					danyarigualesa(vidacartas2, calculavidamaxima(vidacartas2), danoapli);//
				}
				else
				{
					danoapli = rand() % 11 + 20;
					danyarigualesa(vidacartas, calculavidamaxima(vidacartas), danoapli);
				}
				break;
			case 2:
				if (turno == 0)
				{
					danoapli = rand() % 11 + 20;
					danyarigualesa(vidacartas2, calculavidaminima(vidacartas2), danoapli);
				}
				else
				{
					danoapli = rand() % 11 + 20;
					danyarigualesa(vidacartas, calculavidaminima(vidacartas), danoapli);
				}
				break;
				
			case 3:
				if (turno == 0)
				{
					danoapli = rand() % 11 + 20;
					danyarporencimade(vidacartas2, calculavidapromedio(vidacartas2), danoapli);
				}
				else
				{
					danoapli = rand() % 11 + 20;
					danyarporencimade(vidacartas, calculavidapromedio(vidacartas), danoapli);
				}
			break;

			case 4:
				if (turno == 0)
				{
					danoapli = rand() % 11 + 20;
					danyarpordebajode(vidacartas2, calculavidapromedio(vidacartas2), danoapli);
				}
				else
				{
					danoapli = rand() % 11 + 20;
					danyarpordebajode(vidacartas, calculavidapromedio(vidacartas), danoapli);
				}
				break;
				
			case 5:
				int vida_max, vida_min;
				if (turno == 0)
				{
					vida_max = contarporencimade(vidacartas2, 50.0);
					vida_min = contarpordebajode(vidacartas2, 50.0);
					

				}
				else
				{
					vida_max = contarporencimade(vidacartas, 50.0);
					vida_min = contarpordebajode(vidacartas, 50.0);

				}
				break;

			case 6:
				if (turno == 0)
				{  //espera sientoo que se nos olvida algo
					danoapli = rand()%11 + 10;
					int index = buscartriomaximo(vidacartas2);
					DanyarCercanas(vidacartas2, index, index + 2, danoapli);//
				}
				else
				{
					danoapli = rand() % 11 + 10;
					int index = buscartriomaximo(vidacartas);
					DanyarCercanas(vidacartas, index, index + 2, danoapli);
				}
				break;

			case 7:
				if (turno == 0)
				{
					int wild_index;// 
					danoapli = rand()%6 + 5;
					for (int i = 0; i < 10; i++)
					{
						if (tipos[i] == 7)
						{
							wild_index = i;
							break;
						}
						std::cout << wild_index;
					}
					DanyarCercanas(vidacartas2, wild_index, wild_index - 2, danoapli);
				}
				else
				{
					int wild_index;// 
					danoapli = rand()%6 + 5;//dale
					for (int i = 0; i < 10; i++)
					{
						if (tipos2[i] == 7)
						{
							wild_index = i;
							break;
						}
					}
					DanyarCercanas(vidacartas, wild_index, wild_index - 2, 44);
				}
				break;
			}
		}

		switch (turno)
		{
		case 0:
			turno += 1;
			break;

		case 1:
			turno -= 1;
			break;
		}

		}
	}
}

//By Plissken