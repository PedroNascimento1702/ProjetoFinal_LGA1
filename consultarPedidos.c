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

 struct pedidos
{   
	int CodVenda;
	int   CodProduto;
    int   Qtde;
} pedido;

 struct pagamentos
{   
	int codpgto;
	char  formapgto[256];
    float   valorpgto;
} pagamento;

struct produtos listaProdutos[500];
struct pedidos listaPedidos[500];
struct pagamentos listaPagamentos[500];

FILE * arqProdutos;
FILE * arqPedidos;
FILE * arqPagamentos;

char a;
int contagemPedidos = 0,contagemProdutos = 0,i;

main ()
{
	system("cls");
	system ("color 4E");
	system ("mode 100,100");
	printf("____________________________________________________________________________________________________\n");
	printf("                                  Mickey & Donald Drive Thru                                        \n");
	printf("____________________________________________________________________________________________________\n");
	printf("		                LISTA DE VENDAS CONCLUIDAS											\n");
	
	
	arqProdutos = fopen ("produtos.dat", "r"); 
	arqPedidos = fopen ("pedidos.dat", "r");
	//arqPagamentos = fopen ("pagamentos.dat", "r");
			   
	if (arqProdutos == NULL) 
	{ 
		fprintf(stderr, "\nError opening file\n"); 
		exit (1); 
	}
	if (arqPedidos == NULL) 
	{ 
		fprintf(stderr, "\nError opening file\n"); 
		exit (1); 
	}
	
	while(fread(&produto, sizeof(struct produtos), 1, arqProdutos)) 
	{
		listaProdutos[contagemProdutos] = produto;
		contagemProdutos++;		
	}	
	
	int CodigoVendaAnterior = 0;	
	float Total = 0;
		
	while(fread(&pedido, sizeof(struct pedidos), 1, arqPedidos)) 
	{
		if(CodigoVendaAnterior == 0)
		{
			printf("\nVenda %i",pedido.CodVenda);
			printf("\nItens:");
			CodigoVendaAnterior = pedido.CodVenda;
		}
		
		for(i=0;i<contagemProdutos;i++)
		{
			if(listaProdutos[i].CodProduto == pedido.CodProduto)
				produto = listaProdutos[i];
		}
		
		if(pedido.CodVenda == CodigoVendaAnterior)	
		{
				
			Total += produto.CustProduto * pedido.Qtde;
			printf("\n	Produto: %s     Valor Unid.: %.2f     Qtde: %i    Valor: %.2f",produto.NomeProduto,produto.CustProduto,pedido.Qtde,produto.CustProduto * pedido.Qtde);
			
			
		}
		else
		{
			
			fclose (arqPagamentos); 
			printf("\n	                                                 Total : %.2f",Total);
			Total = 0;
			CodigoVendaAnterior = pedido.CodVenda;
			printf("\n\nVenda %i",pedido.CodVenda);
			printf("\nItens:");
			
			for(i=0;i<contagemProdutos;i++)
			{
				if(listaProdutos[i].CodProduto == pedido.CodProduto)
					produto = listaProdutos[i];
			}
			Total += produto.CustProduto * pedido.Qtde;
			printf("\n	Produto: %s     Valor Unid.: %.2f     Qtde: %i    Valor: %.2f",produto.NomeProduto,produto.CustProduto,pedido.Qtde,produto.CustProduto * pedido.Qtde);
		}
				
	}
	printf("\n	                                                 Total : %.2f",Total);
	
	
	
	
	fclose (arqProdutos); 
	fclose (arqPedidos); 	
	printf("\n\n Consulta concluida! \n Aperte qualquer tecla para sair...");
		
	getch();
	system("menu");		
}

	
	
