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
	int   CodProduto;
    int   Qtde;
} pedido;

struct produtos listaProdutos[];
struct pedidos listaPedidos[];
FILE * arq;
int c,i;
char a;
float total;

main ()
{

		system("cls");
		system ("color 4E");
		system ("mode 100,30");
		printf("____________________________________________________________________________________________________\n");
		printf("                                  Mickey & Donald Drive Thru                                        \n");
		printf("____________________________________________________________________________________________________\n");
		printf("					PAGAMENTO									\n");
		
		printf("----------------------------------------------------------------------------------------------------\n");
		getch();
}

	
	
