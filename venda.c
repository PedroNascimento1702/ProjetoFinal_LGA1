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

struct produtos listaProdutos[500];
struct pedidos listaPedidos[500];
FILE * arq;
FILE * arqPedidos;
int c,i,CodVenda = 0;
char a;
float total;


int retornaNovoCodVenda()
{
	arqPedidos = fopen ("pedidos.dat", "r"); 
	if (arqPedidos == NULL) 
	{ 
		fprintf(stderr, "\nNão foi possível abrir um arquivo\n A venda será cancelada! \n"); 
		getch();
		system("venda");
	}
	
	while(fread(&pedido, sizeof(struct pedidos), 1, arqPedidos)) 
	{
		if(CodVenda == 0)	
			CodVenda = pedido.CodVenda;
		else
		{
			if(pedido.CodVenda > CodVenda)
			{
				CodVenda = pedido.CodVenda;
			}
		}		
	}

	CodVenda++;
	return CodVenda;
}

main ()
{
	c = 0;
	int cod = retornaNovoCodVenda();
	do
	{	
		//system("cls");
		system ("color 4E");
		system ("mode 100,30");
		printf("____________________________________________________________________________________________________\n");
		printf("                                  Mickey & Donald Drive Thru                                        \n");
		printf("____________________________________________________________________________________________________\n");
		printf("					  VENDA	%i									\n",cod);
		printf("----------------------------------------------------------------------------------------------------\n");
		printf("Cardapio\n");
		
			
		
		arq = fopen ("produtos.dat", "r"); 
		if (arq == NULL) 
		{ 
			fprintf(stderr, "\nNão foi possível abrir o arquivo\n"); 
			getch();
			system("venda");
		} 	
	
		printf("\n COD  -      NOME        -  VALOR  ");
	
		while(fread(&produto, sizeof(struct produtos), 1, arq)) 		
			printf ("\n %i    - %s      -  R$%.2f", produto.CodProduto, produto.NomeProduto, produto.CustProduto); 
		
							
		fclose(arq);
		printf("\n----------------------------------------------------------------------------------------------------\n");
		if(c > 0)
		{
			printf("                            Produtos selecionados:");
			for(i=0;i<c;i++)
			{
				printf("\n                            Cod: %i|Qtde: %i",listaPedidos[i].CodProduto,listaPedidos[i].Qtde);
			}
			printf("\n\n");
		}
		
		pedido.CodVenda = cod;
		
		printf(" Insira o codigo do produto para selecionar\n "); fflush(stdin); scanf("%i",&pedido.CodProduto);
		
		printf("\n Produto selecionado. Insira a quantidade\n "); fflush(stdin); scanf("%i",&pedido.Qtde);
		
	
		listaPedidos[c] = pedido;
		c++;
		
		printf("\nAdicionar mais itens ao pedido? (n - nao | qualquer tecla-sim)\n "); a = getche();
	}
	while(a != 'n');
	
	arqPedidos = fopen ("pedidos.dat", "a"); 
	if (arqPedidos == NULL) 
	{ 
		fprintf(stderr, "\nNão foi possível abrir um arquivo\n A venda será cancelada! \n"); 
		getch();
		system("venda");
	}		
	 
	for(i=0;i<c;i++)
	{
		fwrite(&listaPedidos[i], sizeof(struct pedidos), 1, arqPedidos); 		
	}
	
	fclose(arq);
	
	system("cls");
	system ("color 4E");
	system ("mode 100,30");
	printf("____________________________________________________________________________________________________\n");
	printf("                                  Mickey & Donald Drive Thru                                        \n");
	printf("____________________________________________________________________________________________________\n");
	printf("					  VENDA											\n");
		
	printf("----------------------------------------------------------------------------------------------------\n");
	
	printf(" Pedido salvo.\n Itens do pedido: \n");
	
	arq = fopen ("produtos.dat", "r"); 
	if (arq == NULL) 
	{ 
		fprintf(stderr, "\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("venda");
	} 
	total = 0;
	
	while(fread(&produto, sizeof(struct produtos), 1, arq)) 
	{
		for(i=0;i<c;i++)
		{
			if(produto.CodProduto == listaPedidos[i].CodProduto)
			{
				printf ("\n Cod - %i | Nome- %s | Valor - R$ %.2f | Quantidade - %i | Total parcial - R$%.2f", produto.CodProduto, produto.NomeProduto, produto.CustProduto,listaPedidos[i].Qtde,listaPedidos[i].Qtde * produto.CustProduto);
				total += listaPedidos[i].Qtde * produto.CustProduto;
			}
		}					 		
	}
		
	printf("\n\n Total do pedido: R$%.2f",total);
	printf("\n Prosseguir para pagamento (aperte qualquer tecla)");
	getch();
	fclose (arq); 
	fclose (arqPedidos); 
	system("pagamento");
}

	
	
