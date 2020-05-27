#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libCoresSom.h"
#include <time.h>

char senha[11],c;
int a;
main ()
{
	inicio:
	system("cls");
	system ("mode 38,20");
	gotoxy(5,5);
   	printf("Senha:");
	a = 0;
	do
	{
		fflush(stdin);
    	c = getch();
        if(isprint(c))  /*Analisa se o valor da variável c é imprimivel*/
		{       
	        senha[a]=c; /*Se for, armazena o caractere*/
	        a++;
	        
	        printf("*"); /*imprime o * Anterisco*/
        }
        else if(c==8 && a) /*8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0*/
		{     
           senha[a]='\0';
           a--;
           printf("\b \b"); /*Apagando o caractere digitado*/
        }
    }
	while(c!=13); /*13 é o valor de ENTER na tabela ASCII */
    
    if(!strncmp(senha,"mcdonald123",11))
    {
    	system("cls");
    	printf("\n\n\n\n\n\n\n          Seja Bem-vindo!");
    	printf("\n\n\n           Entrando");
    	sleep(1);
    	printf(".");
    	sleep(1);
    	printf(".");
    	sleep(1);
    	printf(".");
    	sleep(1);
    	system("menu");
	}
	else
	{
		system("cls");
    	printf("\n\n\n\n\n\n\n          Senha incorreta!");
		getch();
		goto inicio;
	}
}

	
	
