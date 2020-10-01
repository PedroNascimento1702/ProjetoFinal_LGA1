#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libCoresSom.h"
#include "util.h"
#include <time.h>

FILE * arq;
FILE * arqPedidos;
int c;
char a;

main ()
{
	c = 0;
	int cod = 0;
	cod = retornaNovoCodVenda();
	pedidos pedido;
	do
	{	
		char titulo[15];	
		sprintf(titulo,"%s %d","VENDA",cod);
		cabecalho(titulo);
		printf("Cardapio\n");
						
		MostraMenu();
		
		if(c > 0)
		{
			printf("                            Produtos selecionados:");
			int i;
			for(i=0;i<c;i++)
			{
				printf("\n                            Cod: %i|Qtde: %i",listaPedidos[i].CodProduto,listaPedidos[i].Qtde);
			}
			printf("\n\n");
		}
		
		
		
		pedido.CodVenda = cod;
		
		printf("\n Insira o codigo do produto para selecionar\n "); fflush(stdin); scanf("%i",&pedido.CodProduto);
		
		printf("\n Produto selecionado. Insira a quantidade\n "); fflush(stdin); scanf("%i",&pedido.Qtde);
		
	
		listaPedidos[c] = pedido;
		c++;
		
		printf("\nAdicionar mais itens ao pedido? (n - nao | qualquer tecla-sim)\n "); a = getche();
	}
	while(a != 'n');
	
	CadastraVenda(c);
	
	system("cls");
	cabecalho("VENDA");
	
	printf(" Pedido salvo.\n Itens do pedido: \n");
	
	MostraPedido(c);
	
	getch();

	char codigoVenda[30];	
	sprintf(codigoVenda,"%s%d","pagamento -v ",cod);	
	system(codigoVenda);
}

	
	
