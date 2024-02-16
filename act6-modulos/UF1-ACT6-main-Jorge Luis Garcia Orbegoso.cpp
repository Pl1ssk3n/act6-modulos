#include <stdio.h>
#include "vidas.hpp"
#include "tipos.hpp"
#include <stdlib.h>
#include <time.h>

int opcionmenu;

float vidacartas[10]={30, 67, 18, 90, 30, 12, 16, 83, 62, 15};

float vidacartas2[10]={30, 43, 52, 67, 34, 80, 75, 63, 40, 99};

int tipos [10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int tipos2 [10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int posicion1seleccionada;

int posicion2seleccionada;

//int t;

float a;

float b;

float vidamaxima;//

float vidaminima;//

float cantvida;//

float danoapli;//

int conteodebajo;//

int pos;//

int cantdano;//

int dist;//

float promedio;//

int conteodencima;//

int conteoiguales;//

int numeroindicetrio;//

int indice;

int randoom;

int turno;

int ataque;

void main()
{	
	srand(time(NULL));
	calculavidapromedio(vidacartas);
	turno = numsorteo();
	opcionmenu = -1;
	IniciarTipos(tipos);
	IniciarTipos2(tipos2);
	while(opcionmenu != 0)
	{
		printf("************************************************************\n");
		printf("cartas jugador 1:\n");
		Mostrarvidas(vidacartas);
		MostrarTipos(tipos);
		printf("\n************************************************************\n");
		printf("cartas jugador 2:\n");
		Mostrarvidas2(vidacartas2);
		MostrarTipos2(tipos2);
		printf("\n************************************************************\n");
		printf("sorteo de turno\n");
		printf("0 = Empieza jugador 1\n");
		printf("1 = Empieza jugador 2\n");
		printf("Empieza = %d\n", turno);
		printf("************************************************************\n");
		/*printf("13.-IntercambiarTipos...........................\n");
		//printf("02.-CalcularVidaMaxima..........................\n");
		//printf("03.-CalcularVidaMinima..........................\n");
		//printf("04.-CalcularVidaPromedio........................\n");
		//printf("05.-DanyarCartasPorDebajoDe.....................\n");
		//printf("06.-DanyarCartasPorEncimaDe.....................\n");
		printf("07.-DanyarCartasIgualesA........................\n");
		printf("08.-ContarCartasPorDebajoDe.....................\n");
		printf("09.-ContarCartasPorEncimaDe.....................\n");
		printf("10.-ContarCartasIgualesA........................\n");
		printf("11.-DanyarCartasCercanas........................\n");
		printf("12.-BuscarTrioMaximo............................\n");*/
		printf("1.-IntercambiarTipos y IntercambiarVidas....................\n");
		printf("2.-atacar...................................................\n");
		printf("0.-Salir....................................................\n");
		printf("************************************************************\n");
		scanf("%d", &opcionmenu);

		if(opcionmenu == 1)
		{
			switch(turno)
			{
				case 0:
				printf("intercambiar posiciones de las vidas \nposicion 1 del 0 al 9?\n");
				scanf("%d", &posicion1seleccionada);
				printf("posicion 2 del 0 a 9?\n");
				scanf("%d", &posicion2seleccionada);
				printf("posicion 1 original %.2f\n", vidacartas[posicion1seleccionada]);
				printf("posicion 2 original %.2f\n", vidacartas[posicion2seleccionada]);
				//t = 0;
				//a = vidacartas[posicion1seleccionada];
				//b = vidacartas[posicion2seleccionada];
				//t = a;
				//a = b;
				//b = t;
				//vidacartas[posicion2seleccionada] = b;
				//vidacartas[posicion1seleccionada] = a;
				intercambiarvidas(vidacartas, posicion1seleccionada, posicion2seleccionada);
				//printf("posicion 1 nueva %.2f\n", a);
				//printf("posicion 2 nueva %.2f\n", b);
				printf("intercambiar posiciones de los tipos de cartas \nposicion 1 del 0 al 9?\n");
				scanf("%d", &posicion1seleccionada);
				printf("posicion 2 del 0 a 9?\n");
				scanf("%d", &posicion2seleccionada);
				printf("posicion 1 original %d\n", tipos[posicion1seleccionada]);
				printf("posicion 2 original %d\n", tipos[posicion2seleccionada]);
				IntercambiarTipos(tipos, posicion1seleccionada, posicion2seleccionada);
				break;
				
				case 1:
				printf("intercambiar posiciones de las vidas \nposicion 1 del 0 al 9?\n");
				scanf("%d", &posicion1seleccionada);
				printf("posicion 2 del 0 a 9?\n");
				scanf("%d", &posicion2seleccionada);
				printf("posicion 1 original %.2f\n", vidacartas2[posicion1seleccionada]);
				printf("posicion 2 original %.2f\n", vidacartas2[posicion2seleccionada]);
				//t = 0;
				//a = vidacartas[posicion1seleccionada];
				//b = vidacartas[posicion2seleccionada];
				//t = a;
				//a = b;
				//b = t;
				//vidacartas[posicion2seleccionada] = b;
				//vidacartas[posicion1seleccionada] = a;
				intercambiarvidas(vidacartas2, posicion1seleccionada, posicion2seleccionada);
				//printf("posicion 1 nueva %.2f\n", a);
				//printf("posicion 2 nueva %.2f\n", b);
				printf("intercambiar posiciones de los tipos de cartas \nposicion 1 del 0 al 9?\n");
				scanf("%d", &posicion1seleccionada);
				printf("posicion 2 del 0 a 9?\n");
				scanf("%d", &posicion2seleccionada);
				printf("posicion 1 original %d\n", tipos2[posicion1seleccionada]);
				printf("posicion 2 original %d\n", tipos2[posicion2seleccionada]);
				IntercambiarTipos(tipos2, posicion1seleccionada, posicion2seleccionada);
				break;
				
			}
		}
		
		else if(opcionmenu == 2)
		{			

			//vidamaxima = calculavidamaxima(vidacartas);
			
			//printf("tu vida maxima es %.2f \n", vidamaxima);
			//indice = 0;
			//printf("ataca\n");
			printf("Que carta quieres usar?\n");
			printf("0.-SOLDIER.............................\n");
			printf("1.-KINGSLAYER..........................\n");
			printf("2.-SCAVENGER...........................\n");
			printf("3.-PREDATOR............................\n");
			printf("4.-DARWIN..............................\n");
			printf("5.-PLAGUE..............................\n");
			printf("6.-DOOM................................\n");
			printf("7.-WILDFIRE............................\n");
			scanf("%d", &ataque);
			switch(ataque)
			{
				case 0:
					int soldier;
					printf("A que soldier usaras para atacar?-> \n");
					scanf("%d", &soldier);
					int damage;
					damage = rand() % 5 + 1;
					printf("%d\n", damage);//prueba dmg
					if (turno == 0)
					{
						if (vidacartas[soldier] != 0)
						{
							vidacartas2[soldier] -= damage;
						}
						else
						{
							printf("Tu soldier esta muerto y no puede atacar\n");
						}
					}
					else
					{
						if (vidacartas2[soldier] != 0)
						{
							vidacartas[soldier] -= damage;
						}
						else
						{
							printf("Tu soldier esta muerto y no puede atacar\n");
						}
					}
				break;

				
				case 1:
					//if (turno == 0)
					//vidacartas2[soldier] -= damage;
					//else
					//vidacartas2[soldier] -= damage;
					//break;
					//printf("ataca1\n");
					//calcular vida maxima y danarlas si varias tienen la misma vida calculavidamaxima y danyarigualesa
					rand() %11 + 20;
					if (turno == 0)
					{
						
					}
					else
					{
						
					}
				break;
				
				case 2:
					//calcular vida maxima y danarlas si varias tienen la misma vida calculavidaminima y danyarigualesa
					rand() %11 + 20;
					if (turno == 0)
					{
						
					}
					else
					{
						
					}
					//printf("ataca2\n");
				break;
				
				case 3:
					// calculavidapromedio y danyarporencimade
					rand()%6 + 5;
					if (turno == 0)
					{
						
					}
					else
					{
						
					}
				//printf("ataca3\n");
				break;
				
				case 4:
					//calculavidapromedio y danyarpordebajode
					rand()%6 + 5;
					if (turno == 0)
					{
						
					}
					else
					{
						
					}
				//printf("ataca4\n");
				break;
				
				case 5:
					rand()%6 + 5;
					if (turno == 0)
					{
						
					}
					else
					{
						
					}
				//printf("ataca5\n");
				break;
				
				case 6:
					rand()%11 + 10;
					if (turno == 0)
					{
						
					}
					else
					{
						
					}
				//printf("ataca6\n");
				break;
				
				case 7:
					rand()%6 + 5;
					if (turno == 0)
					{
						
					}
					else
					{
						
					}
				//printf("ataca7\n");
				break;
			}
		}
		
		switch (turno)
		{
			case 0:
			turno += 1;
			break;
			
			case 1:
			turno -=1;
			break;
		}

		/*else if(opcion == 3)
		{
			vidaminima = calculavidaminima(vidacartas);
			
			printf("tu vida minima es %.2f \n", vidaminima);
			indice = 0;
		}

		else if(opcion == 4)
		{

			promedio = calculavidapromedio(vidacartas);
			
			printf("el promedio es %.2f \n", promedio);
			indice = 0;
		}

		else if(opcion == 5)
		{
			Mostrarvidas(vidacartas);
			
			printf("introduce cantidad de vida para buscar por debajo de esta\n");
			scanf("%f", &cantvida);
			printf("a esas cartas cuanto dano le haces?\n");
			scanf("%f", &danoapli);
			
			danyarpordebajode(vidacartas, cantvida, danoapli);
			
			Mostrarvidas(vidacartas);
		}

		else if(opcion == 6)
		{
			Mostrarvidas(vidacartas);
			
			printf("introduce cantidad de vida para buscar por encima de esta\n");
			scanf("%f", &cantvida);
			printf("a esas cartas cuanto dano le haces?\n");
			scanf("%f", &danoapli);

			danyarporencimade(vidacartas, cantvida, danoapli);
			
			Mostrarvidas(vidacartas);
		}

		if(opcion == 7)
		{
			Mostrarvidas(vidacartas);
			
			printf("introduce cantidad de vida para buscar por igual a la vida seleccionada\n");
			scanf("%f", &cantvida);
			printf("a esas cartas cuanto dano le haces?\n");
			scanf("%f", &danoapli);

			danyarigualesa(vidacartas, cantvida, danoapli);
			
			Mostrarvidas(vidacartas);
		}

		else if(opcion == 8)
		{
			Mostrarvidas(vidacartas);
			
			printf("introduce cantidad de vida para contar por debajo de esta\n");
			scanf("%f", &cantvida);

			conteodebajo = contarpordebajode(vidacartas, cantvida);
			
			printf("cantidad de cartas por debajo de la vida indicada: %d\n", conteodebajo);
		}

		else if(opcion == 9)
		{
			Mostrarvidas(vidacartas);
			
			printf("introduce cantidad de vida para contar por encima de esta\n");
			scanf("%f", &cantvida);

			conteodencima = contarporencimade(vidacartas, cantvida);
			
			printf("cantidad de cartas por encima de la vida indicada: %d\n", conteodencima);
		}

		else if(opcion == 10)
		{
			Mostrarvidas(vidacartas);
			
			printf("introduce cantidad de vida para contar que sea igual a la indicada\n");
			scanf("%f", &cantvida);

			conteoiguales = contarigualesa(vidacartas, cantvida);
			
			printf("cantidad de cartas iguales a la vida indicada: %d\n", conteoiguales);
		}

		else if(opcion == 11)
		{
			printf("en que posicion estas?");
			scanf("%d", &pos);
			printf("cuanto daño haces?");
			scanf("%d", &cantdano);
			printf("distancia a aplicar el daño por debjao de esta");
			scanf("%d", &dist);
		}

		else if(opcion == 12)
		{

			numeroindicetrio = buscartriomaximo(vidacartas);

			printf("el indice de la primera carta que muestar el trio maximo contiguo, es: %d\n", numeroindicetrio);
		}*/	
	}
}


//By Plissken