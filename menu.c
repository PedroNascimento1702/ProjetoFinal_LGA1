#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libCoresSom.h"
#include <time.h>

char a;
main ()
{
	inicio:
	system("cls");
	system ("color 4E");
	system ("mode 100,30");
	printf("____________________________________________________________________________________________________\n");
	printf("                                  Mickey & Donald Drive Thru                                        \n");
	printf("____________________________________________________________________________________________________\n");
	printf("| Produtos (1) | Vender (2) | Fila de espera (3) | Consultar vendas (4) | Logout (5) | Fechar (6) | ");
	gotoxy(20,13);
	system("logo");
	system("relogio");
	gotoxy(2,8);
	
	a = getch();
	
	switch(a)
	{
		case '1':
			system("produtos");
			break;
		case '2':
			system("venda");
			break;
		case '3':
			printf("fila");
			getch();
			break;
		case '4':
			printf("consultar");
			getch();
			break;
		case '5':
			system("cls");
				system ("color 4E");
			printf("Saindo");
			sleep(1);
	    	printf(".");
	    	sleep(1);
	    	printf(".");
	    	sleep(1);
	    	printf(".");
	    	sleep(1);
			system("splash");
			break;
		case '6':
			system("cls");
			printf("Fechando");
				system ("color 4E");
			sleep(1);
	    	printf(".");
	    	sleep(1);
	    	printf(".");
	    	sleep(1);
	    	printf(".");
	    	sleep(1);
			break;
		default:
			printf("inv�lido");
			getch();
			goto inicio;
			break;	
	}
}

	
	