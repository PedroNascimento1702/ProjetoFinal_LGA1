#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libCoresSom.h"
#include <time.h>

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

 struct produtos
{   
	int   CodProduto;
    char   NomeProduto[256];
    float   CustProduto;
} produto;

 struct pagamentos
{   
	int codpgto;
	char  formapgto[256];
    float   valorpgto;
} pagamento;

 struct pedidos
{   
	int CodVenda;
	int   CodProduto;
    int   Qtde;
} pedido;

 struct cartoes
{   
	int Codpgto;
	char Numcartao[16];
} cartao;

FILE * arqProdutos;
FILE * arqPedidos;
FILE * arqPagamentos;
FILE * arqCartoes;

int c,i,itens = 0;
char a,formaPagamento[100];
float total;

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
		printf("					PAGAMENTO									\n");
		
		printf("----------------------------------------------------------------------------------------------------\n");
		
		
		
		arqPedidos = fopen ("pedidos.dat", "r");
				
		if (arqPedidos == NULL) 
		{ 
			fprintf(stderr, "\nError opening file\n"); 
			exit (1); 
		}
		
		printf("\nVenda %i",codVenda);
		printf("\nItens:");
		total = 0;
		while(fread(&pedido, sizeof(struct pedidos), 1, arqPedidos)) 
		{
			if(pedido.CodVenda == codVenda)
			{
				arqProdutos = fopen ("produtos.dat", "r"); 
				if (arqProdutos == NULL) 
				{ 
					fprintf(stderr, "\nError opening file\n"); 
					exit (1); 
				}
				while(fread(&produto, sizeof(struct produtos), 1, arqProdutos)) 
				{
					if(produto.CodProduto==pedido.CodProduto)
					{
						total += produto.CustProduto * pedido.Qtde;
						itens += pedido.Qtde;
						printf("\n	Produto: %s     Valor Unid.: %.2f     Qtde: %i    Valor: %.2f",produto.NomeProduto,produto.CustProduto,pedido.Qtde,produto.CustProduto * pedido.Qtde);
					}
				}
				fclose (arqProdutos); 
			}													
		}
		fclose (arqPedidos); 
		printf("\n	                                                 Total : %.2f",total);
		
		printf("\n\n\n Selecione a forma de pagamento \n 1 - Cartao de Credito/Debito   2 - Dinheiro   3 - Cheque\n ");
		char choise = getche();
		
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
					cartao.Numcartao[i] = "*";
				}
				
				arqCartoes = fopen ("cartoes.dat", "a");
				if (arqCartoes == NULL) 
				{ 
					fprintf(stderr, "\nError opening file\n"); 
					exit (1); 
				}
				fwrite(&cartao, sizeof(struct cartoes), 1, arqCartoes); 
				fclose (arqCartoes); 
				
				break;
			case '2':
				strcpy(formaPagamento,"Dinheiro");
				break;
			case '3':
				strcpy(formaPagamento,"Cheque");
				break;
		}
		pagamento.codpgto = codVenda;
		strcpy(pagamento.formapgto,formaPagamento);
		
		pagamento.valorpgto = total;
		
		arqPagamentos = fopen ("pagamentos.dat", "a");
		if (arqPagamentos == NULL) 
		{ 
			fprintf(stderr, "\nError opening file\n"); 
			exit (1); 
		}
		fwrite(&pagamento, sizeof(struct pagamentos), 1, arqPagamentos); 
		fclose (arqPagamentos); 
		
		if(itens > 3)
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

	
	
