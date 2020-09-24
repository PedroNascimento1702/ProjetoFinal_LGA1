#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "libCoresSom.h"

struct pagamentos
{   
	int codpgto;
	char  formapgto[256];
    float   valorpgto;
} pagamento;


FILE * arqPagamento;

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
		printf("					LEVE									\n");
		
		printf("----------------------------------------------------------------------------------------------------\n");
		
		
		
		arqPagamento = fopen ("pagamentos.dat", "r");
				
		if (arqPagamento == NULL) 
		{ 
			fprintf(stderr, "\nError opening file\n"); 
			exit (1); 
		}
		
		while(fread(&pagamento, sizeof(struct pagamentos), 1, arqPagamento)) 
		{
			if(pagamento.codpgto == codVenda)
			{
				printf("\n PEDIDO PAGO COM ");
				
				if (strcmp (pagamento.formapgto, "Dinheiro") == 0)
					textcolor(2,4);
				if(strcmp (pagamento.formapgto, "Cheque") == 0)
					textcolor(9,4);
				if(strcmp (pagamento.formapgto, "Cartao de Credito/Debito") == 0)
					textcolor(13,4);
					
				printf("%s",pagamento.formapgto);
				textcolor(14,4);
			}
		}	
		fclose(arqPagamento);
		printf("\n\n  Venda finalizada! Pressione qualquer tecla para voltar ao menu principal.");
		getch();
		
		system("menu");		
}

	
	
