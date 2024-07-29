#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "rlutil.h"

int main(){
	char respuesta;
	int ronda=1, localizacion1, localizacion2, disparo;
	SetConsoleOutputCP(65001);
	srand(time(NULL));
	printf("**************************************\n");
	printf("             WAR GAMES\n");
	printf("          by Álvaro Quero\n");
	printf("**************************************\n\n");
	printf("Start Simulation (y/n) ?: ");
	scanf("%c",&respuesta);

	if (respuesta=='y' || respuesta=='Y'){

		localizacion1 = 10 + rand()%(20-10+1);
		localizacion2 = 10 + rand()%(20-10+1);
		disparo = 10 + rand()%(20-10+1);

		// Posición del bot
		printf("Bot #1 - Location: %dx \n", localizacion1);
		Sleep(1000);
		printf("Bot #1 - Location: %dx \n", localizacion2);
		Sleep(1000);

		// ! Orden del juego
		do{
			setColor(GREEN);
			printf("[ROUND %02d] Bot #1 launch an attack on %dx \n", ronda, disparo);
			Sleep(1000);
			if (disparo==localizacion2){
				printf("[ROUND %02d] Enemy Bot killed! \n", ronda);
				Sleep(700);
				setColor(WHITE);
				printf("Victory for bot #1 \n");
				break;
			}else{
				setColor(GREEN);
				printf("[ROUND %02d] Enemy Bot Missed! \n", ronda);
				Sleep(700);
				setColor(RED);
				printf("[ROUND %02d] Bot #2 launch an attack on %dx \n", ronda, disparo);
				Sleep(700);
				if (disparo==localizacion1){
					printf("[ROUND %02d] Enemy Bot killed! \n", ronda);
					Sleep(700);
					printf("Victory for bot #2 \n");
					break;
				}else{
					setColor(RED);
					printf("[ROUND %02d] Enemy Bot Missed! \n", ronda);
				}
			}
			ronda++;
			disparo = 10 + rand()%(20-10+1);
		} while ((disparo!=localizacion1 && disparo!=localizacion2) || ronda<5);

		setColor(WHITE);

		if (ronda>5){
			printf("The only winning move is not to play\n");
		}else{
			printf("War just begun \n");
		}
		
		printf("Good bye my friend! \n");
		
		
	}else if (respuesta=='n' || respuesta=='N')	{
		printf("Good bye my friend! \n");
	}

	getch();
	return 0;
}