#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libCoresSom.h"
#include "util.h"
#include <time.h>

char a;

main ()
{
	inicio:
	system("cls");
	cabecalho("PRODUTOS");
	
	printf("\n\n c - Cadastro de produtos \n l - Lista de produtos\n v - voltar ao menu \n ");
	fflush(stdin);
	a = getch();
	
	switch(a)
	{
		case 'c':
			printf("\n\n Cadastrar produto");
			
			produtos produto;
			produto.CodProduto = retornaNovoCodProduto();
			printf("\n    Nome do produto: "); fflush(stdin); scanf("%s",&produto.NomeProduto);
			printf("\n    Valor do produto: "); fflush(stdin); scanf("%f",&produto.CustProduto);			
			    
			if(CadastraProduto(produto) != 0)  
				printf("\n  Salvo com sucesso !\n  Aperte qualquer tecla para voltar..."); 
			else 
				printf("\n  Ocorreu um erro ao salvar !\n  Aperte qualquer tecla para voltar..."); 

			getch();
			goto inicio;
			break;
		case 'l':
			ListaProdutos();				
			printf("\n\n Consulta concluida! \n Aperte qualquer tecla para voltar...");
			getch();
			goto inicio;
			break;
		case 'v':
			system("menu");
			break;
	}
	
}

	
	
