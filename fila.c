#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libCoresSom.h"
#include <time.h>

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

 struct filas
{   
	int   CodVenda;
    int   removido;
} fila;

struct filas listaFila[500];

FILE * arqFila;

main (int argc, char **argv)
{
		int contParam, codVenda = 0;
		//corre cada paramatro passado
		for(contParam = 0; contParam < argc; contParam++)
		{
			//se o parametro passado for -i ele executa isso
			if(!strcmp(argv[contParam],"-v"))
			{
		        //armazena na variavel local o valor passado
		        //que seria o paramatro + 1
		        codVenda = atoi(argv[contParam + 1]); //pega o proximo valor
		        contParam += 1; //checa outro parametro desconsiderando
		                         //o proprio valor como parametro
		    }
	   }	 
		system("cls");
		system ("color 4E");
		system ("mode 100,30");
		printf("____________________________________________________________________________________________________\n");
		printf("                                  Mickey & Donald Drive Thru                                        \n");
		printf("____________________________________________________________________________________________________\n");
		printf("					FILA DE ESPERA									\n");
		
		printf("----------------------------------------------------------------------------------------------------\n");
		
		
		
		arqFila = fopen ("fila.dat", "r");
				
		if (arqFila == NULL) 
		{ 
			fprintf(stderr, "\nError opening file\n"); 
			exit (1); 
		}
		
		int contagemFila = 0;
		
		while(fread(&fila, sizeof(struct filas), 1, arqFila)) 
		{
			listaFila[contagemFila] = fila;
			contagemFila++;		
		}
		
		fclose(arqFila);
		
		if(codVenda > 0)
		{
			fila.CodVenda = codVenda;
			fila.removido = 0;
			listaFila[contagemFila] =fila;
			
			arqFila = fopen ("fila.dat", "a");
				
			if (arqFila == NULL) 
			{ 
				fprintf(stderr, "\nError opening file\n"); 
				exit (1); 
			}
			
			fwrite(&fila, sizeof(struct filas), 1, arqFila); 
			
			fclose(arqFila);
		}
		
		printf("\nPedidos em espera: (Organizados em codigos da venda)\n\n");
		
		int i,col=0,primeiroFila=-1;
		
		for(i=0;i<=contagemFila;i++)
		{
			if(listaFila[i].removido == 0 && listaFila[i].CodVenda != 0)
			{
				switch(col)
				{
					case 0: printf("\n%i (Primeiro da Fila) %c ",listaFila[i].CodVenda,174);col+=2;primeiroFila=i; break;		
					case 1: printf("%i %c ",listaFila[i].CodVenda,174);col++; break;						
					case 2: printf("%i %c ",listaFila[i].CodVenda,174);col++; break;						
					case 3: printf("%i %c ",listaFila[i].CodVenda,174);col++; break;						
					case 4: printf("%i %c ",listaFila[i].CodVenda,174);col=1; break;	
				}
			}
		}
		printf("\b\b ");
		
		if(primeiroFila== -1)
			printf("\n\nNenhum pedido na fila de espera!");
			
		char c;
		printf("\n\n\nPressione 'R' para remover o primeiro da fila ou 'S' para sair ");
		
		do
		{
			c = getch();
		}
		while(c != 'R' && c != 'S');
		
		if(c == 'S')
		{
			exit(0);
		}
		
		if(c == 'R')
		{
			listaFila[primeiroFila].removido = 1;
			
			arqFila = fopen ("fila.dat", "w");
				
			if (arqFila == NULL) 
			{ 
				fprintf(stderr, "\nError opening file\n"); 
				exit (1); 
			}
			
			for(i=0;i<=contagemFila;i++)
			{
				fwrite(&listaFila[i], sizeof(struct filas), 1, arqFila); 
			}
		
			fclose(arqFila);

			char codigoVenda[30];	
			sprintf(codigoVenda,"%s%d","leve -v ",listaFila[primeiroFila].CodVenda);			
			system(codigoVenda);
		}				
}

	
	
