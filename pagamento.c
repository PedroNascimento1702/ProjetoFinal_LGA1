#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libCoresSom.h"
#include "util.h"
#include <time.h>


int c,i,itens = 0;
char a,formaPagamento[100];


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
		cabecalho("PAGAMENTO");
		
		float total = ConsultaPedido(codVenda);
		
		
		printf("\n\n\n Selecione a forma de pagamento \n 1 - Cartao de Credito/Debito   2 - Dinheiro   3 - Cheque\n ");
		char choise = getche();
		pagamentos pagamento;
		cartoes cartao;
		pagamento.codpgto = codVenda;
		cartao.Codpgto = codVenda;
		switch(choise)
		{
			case '1':
				strcpy(formaPagamento,"Cartao de Credito/Debito");
				do
				{
					printf("\nInsira o numero do cartao: ");
					scanf("%s",&cartao.Numcartao);
					if((int)strlen(cartao.Numcartao) != 16)
						printf("\nCartao Invalido!");
				}
				while((int)strlen(cartao.Numcartao) != 16);
				
				int i;
				for(i=4;i<=11;i++)
				{
					cartao.Numcartao[i] = 42;
				}
				
				CadastraCartao(cartao);
				break;
			case '2':
				strcpy(formaPagamento,"Dinheiro");
				break;
			case '3':
				strcpy(formaPagamento,"Cheque");
				break;
		}
		
		
		strcpy(pagamento.formapgto,formaPagamento);	
		pagamento.valorpgto = total;
		
		CadastraPagamento(pagamento);
		
		if(itens_pedido > 3)
		{
			printf("\n\nPagamento concluido. \n\nPor ter mais de 3 itens, o pedido vai ser encaminhado para a fila de espera.\n\nPressione qualquer tecla para prosseguir...");
			getch();
			
			char codigoVendaFila[30];	
			sprintf(codigoVendaFila,"%s%d","fila -v ",codVenda);			
			system(codigoVendaFila);
		}
		else
		{
			printf("\n\nPagamento concluido. \n\nPressione qualquer tecla para prosseguir...");
						
			char codigoVenda[30];	
			sprintf(codigoVenda,"%s%d","leve -v ",codVenda);			
			system(codigoVenda);
		}	
		getch();				
}

	
	
