#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "libCoresSom.h"
#include "util.h"

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
		cabecalho("LEVE");
			
		ConsultarVenda(codVenda);
		
		char NomeArquivoVenda[30];	
		sprintf(NomeArquivoVenda,"%s%d%s","notepad Recibos/ReciboVenda",codVenda,".txt");
	
		system(NomeArquivoVenda);
		printf("\n\n  Venda finalizada! Pressione qualquer tecla para voltar ao menu principal.");
		getch();
		
		system("menu");		
}

	
	
