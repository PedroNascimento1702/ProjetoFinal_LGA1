#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libCoresSom.h"
#include "util.h"
#include <time.h>

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
		cabecalho("LISTA DE ESPERA");
					
		ListarFila();
		
		if(codVenda > 0)
		{
			AdicionarPedidoAFila(codVenda);
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
		printf("\n\n\nPressione 'r' para remover o primeiro da fila ou 's' para sair ");
		
		do
		{
			c = getch();
		}
		while(c != 'r' && c != 's');
		
		if(c == 's')
		{
			system("menu");
		}
		
		if(c == 'r')
		{
			listaFila[primeiroFila].removido = 1;
			
			SalvarFila();

			char codigoVenda[30];	
			sprintf(codigoVenda,"%s%d","leve -v ",listaFila[primeiroFila].CodVenda);			
			system(codigoVenda);
		}				
}

	
	
