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

FILE * arq;
char a;

main ()
{
	inicio:
	system("cls");
	system ("color 4E");
	system ("mode 100,30");
	printf("____________________________________________________________________________________________________\n");
	printf("                                  Mickey & Donald Drive Thru                                        \n");
	printf("____________________________________________________________________________________________________\n");
	printf("					  PRODUTOS												\n");
	
	
	printf("\n\n c - Cadastro de produtos \n l - Lista de produtos\n v - voltar ao menu \n ");
	fflush(stdin);
	a = getch();
	
	switch(a)
	{
		case 'c':
			printf("\n\n Cadastrar produto");
			printf("\n\n    Codigo do produto: "); fflush(stdin); scanf("%i",&produto.CodProduto);
			printf("\n    Nome do produto: "); fflush(stdin); scanf("%s",&produto.NomeProduto);
			printf("\n    Valor do produto: "); fflush(stdin); scanf("%f",&produto.CustProduto);
			
			arq = fopen("produtos.dat","a");
				if (arq == NULL) 
			    { 
			        fprintf(stderr, "\nNão foi possível abrir o arquivo\n"); 
			        getch();
			        goto inicio;
			    } 	
			    
			    fwrite(&produto, sizeof(struct produtos), 1, arq); 
			    
			    if(fwrite != 0)  
			        printf("\n  Salvo com sucesso !\n  Aperte qualquer tecla para voltar..."); 
			    else 
			        printf("\n  Ocorreu um erro ao salvar !\n  Aperte qualquer tecla para voltar..."); 
			  
			    fclose (arq); 
			    
			    getch();
			    goto inicio;
			break;
		case 'l':
			arq = fopen ("produtos.dat", "r"); 
			    if (arq == NULL) 
			    { 
			        fprintf(stderr, "\nError opening file\n"); 
			        exit (1); 
			    } 
			    printf("\n\n Listar produtos");
			    // read file contents till end of file 
			    while(fread(&produto, sizeof(struct produtos), 1, arq)) 
			        printf ("\n\n    Codigo: %i \n    Nome: %s \n    Valor: R$%.2f", produto.CodProduto, produto.NomeProduto, produto.CustProduto); 
			  
			    fclose (arq); 
			    printf("\n\n Consulta concluida! \n Aperte qualquer tecla para voltar...");
				getch();
				goto inicio;
			break;
		case 'v':
			system("menu");
			break;
	}
	
}

	
	
