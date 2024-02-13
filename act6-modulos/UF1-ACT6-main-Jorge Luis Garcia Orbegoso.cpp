#include <stdio.h>
#include "vidas.hpp"
#include "tipos.hpp"
#include <stdlib.h>
#include <time.h>

int opcion;

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

void main()
{	
	srand(time(NULL));
	calculavidapromedio(vidacartas);
	turno = numsorteo();
	opcion = -1;
	IniciarTipos(tipos);
	while(opcion != 0)
	{
		printf("************************************************\n");
		printf("cartas jugador 1:\n");
		Mostrarvidas(vidacartas);
		MostrarTipos(tipos);
		printf("\n************************************************\n");
		printf("cartas jugador 2:\n");
		Mostrarvidas2(vidacartas2);
		MostrarTipos2(tipos2);
		printf("\n************************************************\n");
		printf("sorteo de turno\n");
		printf("0 = Empieza jugador 1\n");
		printf("1 = Empieza jugador 2\n");
		printf("Empieza = %d\n", turno);
		printf("************************************************\n");
		printf("01.-IntercambiarPosiciones......................\n");
		printf("13.-IntercambiarTipos...........................\n");
		printf("02.-CalcularVidaMaxima..........................\n");
		printf("03.-CalcularVidaMinima..........................\n");
		printf("04.-CalcularVidaPromedio........................\n");
		printf("05.-DanyarCartasPorDebajoDe.....................\n");
		printf("06.-DanyarCartasPorEncimaDe.....................\n");
		printf("07.-DanyarCartasIgualesA........................\n");
		printf("08.-ContarCartasPorDebajoDe.....................\n");
		printf("09.-ContarCartasPorEncimaDe.....................\n");
		printf("10.-ContarCartasIgualesA........................\n");
		printf("11.-DanyarCartasCercanas........................\n");
		printf("12.-BuscarTrioMaximo............................\n");
		printf("0.-Salir........................................\n");
		printf("************************************************\n");
		scanf("%d", &opcion);

		if(opcion == 1)
		{
			printf("intercambiar posiciones \nposicion 1 del 0 al 9?\n");
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
		}
		
		//Prueba de intercambio tipos
		else if(opcion == 13)
		{
			printf("intercambiar posiciones \nposicion 1 del 0 al 9?\n");
			scanf("%d", &posicion1seleccionada);
			printf("posicion 2 del 0 a 9?\n");
			scanf("%d", &posicion2seleccionada);
			printf("posicion 1 original %d\n", tipos[posicion1seleccionada]);
			printf("posicion 2 original %d\n", tipos[posicion2seleccionada]);
			IntercambiarTipos(tipos, posicion1seleccionada, posicion2seleccionada);
			
		}

		else if(opcion == 2)
		{			

			vidamaxima = calculavidamaxima(vidacartas);
			
			printf("tu vida maxima es %.2f \n", vidamaxima);
			indice = 0;
		}

		else if(opcion == 3)
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
		}	
	}
}


//By Plissken