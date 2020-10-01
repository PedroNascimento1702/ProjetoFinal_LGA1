#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

typedef struct 
{   
	int   CodProduto;
    char   NomeProduto[256];
    float   CustProduto;
} produtos;

typedef struct 
{   
	int CodVenda;
	int   CodProduto;
    int   Qtde;
} pedidos;

typedef struct
{   
	int codpgto;
	char  formapgto[256];
    float   valorpgto;
} pagamentos;


typedef struct
{   
	int Codpgto;
	char Numcartao[16];
} cartoes;


typedef struct 
{   
	int   CodVenda;
    int   removido;
} filas;

FILE * arqProdutos;
FILE * arqPedidos;
FILE * arqPagamentos;
FILE * arqCartoes;
FILE * arqFila;
FILE * arqRecibo;

produtos listaProdutos[500];
pedidos listaPedidos[500];
filas listaFila[500];
pagamentos listaPagamentos[500];

int itens_pedido = 0,contagemFila = 0;

void cabecalho(char titulo[50])
{
	system ("color 4E");
	system ("mode 100,30");
	printf("____________________________________________________________________________________________________\n");
	printf("                                  Mickey & Donald Drive Thru                                        \n");
	printf("____________________________________________________________________________________________________\n");
	printf("					  %s												\n",titulo);
	printf("----------------------------------------------------------------------------------------------------\n");
}

int retornaNovoCodProduto()
{
	arqProdutos = fopen ("produtos.dat", "r"); 
	if (arqProdutos == NULL) 
	{ 
		printf("\nNão foi possível abrir um arquivo\n\n"); 
		getch();
		system("produtos");
	}
	int codproduto = 0;	
	produtos produto;
	while(fread(&produto, sizeof(produto), 1, arqProdutos)) 
	{
		if(codproduto == 0)	
			codproduto = produto.CodProduto;
		else
		{
			if(produto.CodProduto > codproduto)
			{
				codproduto = produto.CodProduto;
			}
		}		
	}
	codproduto++;
	fclose(arqProdutos);
	return codproduto;
}

int CadastraProduto(produtos produto)
{
	arqProdutos = fopen("produtos.dat","a");
	if (arqProdutos == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("produtos");
	} 	
			    
	fwrite(&produto, sizeof(produto), 1, arqProdutos); 
	
	if(fwrite != 0)  
	{
		fclose (arqProdutos); 
		return 	1; 	
	}		 
	else
	{
		fclose (arqProdutos); 
		return 0;	
	}						
}

void ListaProdutos()
{
	arqProdutos = fopen ("produtos.dat", "r"); 
	if (arqProdutos == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		system("produtos");
	} 
	printf("\n\n Listar produtos");
	produtos produto;
	while(fread(&produto, sizeof(produto), 1, arqProdutos)) 
		printf ("\n\n    Codigo: %i \n    Nome: %s \n    Valor: R$%.2f", produto.CodProduto, produto.NomeProduto, produto.CustProduto); 
			  
	fclose (arqProdutos); 
}

int retornaNovoCodVenda()
{
	arqPedidos = fopen ("pedidos.dat", "r"); 
	if (arqPedidos == NULL) 
	{ 
		printf("\nNão foi possível abrir um arquivo\n A venda será cancelada! \n"); 
		getch();
		system("venda");
	}
	int CodVenda = 0;
	pedidos pedido;
	while(fread(&pedido, sizeof(pedido), 1, arqPedidos)) 
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

void MostraMenu()
{
	arqProdutos = fopen ("produtos.dat", "r"); 
	if (arqProdutos == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("venda");
	} 	
	
	printf("\n COD  -      NOME        -  VALOR  ");
	produtos produto;
	while(fread(&produto, sizeof(produto), 1, arqProdutos)) 		
		printf ("\n %i    - %s      -  R$%.2f", produto.CodProduto, produto.NomeProduto, produto.CustProduto); 
	
	printf("\n----------------------------------------------------------------------------------------------------\n");								
	fclose(arqProdutos);
}

void CadastraPedido(pedidos pedido)
{
	arqPedidos = fopen ("pedidos.dat", "a"); 
	if (arqPedidos == NULL) 
	{ 
		printf("\nNão foi possível abrir um arquivo\n A venda será cancelada! \n"); 
		getch();
		system("venda");
	}		
	 	 
	fwrite(&pedido, sizeof(pedido), 1, arqPedidos); 		
		
	fclose(arqPedidos);
}

void CadastraVenda(int qtde_pedidos)
{	
	int i;

	for(i=0;i<qtde_pedidos;i++)
	{
		CadastraPedido(listaPedidos[i]);
	}
}



void MostraPedido(int qtde_pedidos)
{
	arqProdutos = fopen ("produtos.dat", "r"); 
	if (arqProdutos == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("venda");
	} 
	float total = 0;
	produtos produto;
	while(fread(&produto, sizeof(produto), 1, arqProdutos)) 
	{
		int i;
		for(i=0;i<qtde_pedidos;i++)
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
	
	fclose(arqProdutos);
}

float ConsultaPedido(int codVenda)
{		
	arqPedidos = fopen ("pedidos.dat", "r");
	float Total = 0;			
	if (arqPedidos == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("venda");
	}
		
	printf("\nVenda %i",codVenda);
	printf("\nItens:");
	pedidos pedido;
	while(fread(&pedido, sizeof(pedido), 1, arqPedidos)) 
	{
		produtos produto;
		if(pedido.CodVenda == codVenda)
		{
			arqProdutos = fopen ("produtos.dat", "r"); 
			if (arqProdutos == NULL) 
			{ 
				printf("\nNão foi possível abrir o arquivo\n"); 
				getch();
				system("venda");
			}
			while(fread(&produto, sizeof(produto), 1, arqProdutos)) 
			{
				if(produto.CodProduto==pedido.CodProduto)
				{
					Total += produto.CustProduto * pedido.Qtde;
					itens_pedido += pedido.Qtde;
					printf("\n	Produto: %s     Valor Unid.: %.2f     Qtde: %i    Valor: %.2f",produto.NomeProduto,produto.CustProduto,pedido.Qtde,produto.CustProduto * pedido.Qtde);
				}
			}
			fclose (arqProdutos); 
		}													
	}
	fclose (arqPedidos); 
	printf("\n	                                                 Total : %.2f",Total);
	return Total;
}

void CadastraCartao(cartoes cartao)
{
	arqCartoes = fopen ("cartoes.dat", "a");
	if (arqCartoes == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("venda");
	}
	fwrite(&cartao, sizeof(cartao), 1, arqCartoes); 
	fclose (arqCartoes); 				
}

void CadastraPagamento(pagamentos pagamento)
{
	arqPagamentos = fopen ("pagamentos.dat", "a");
	if (arqPagamentos == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("venda");
	}
	fwrite(&pagamento, sizeof(pagamento), 1, arqPagamentos); 
	fclose (arqPagamentos); 
}

void ListarFila()
{
	arqFila = fopen ("fila.dat", "r");
				
	if (arqFila == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
		
	filas fila;
	while(fread(&fila, sizeof(fila), 1, arqFila)) 
	{
		listaFila[contagemFila] = fila;
		contagemFila++;		
	}
		
	fclose(arqFila);
}

void AdicionarPedidoAFila(int codVenda)
{
	filas fila;
	fila.CodVenda = codVenda;
	fila.removido = 0;
	listaFila[contagemFila] = fila;
			
	arqFila = fopen ("fila.dat", "a");
				
	if (arqFila == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
			
	fwrite(&fila, sizeof(fila), 1, arqFila); 
			
	fclose(arqFila);
}

void SalvarFila()
{
	arqFila = fopen ("fila.dat", "w");
				
	if (arqFila == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
	
	filas fila;	
	int i;	
	for(i=0;i<=contagemFila;i++)
	{
		fwrite(&listaFila[i], sizeof(fila), 1, arqFila); 
	}
		
	fclose(arqFila);
}

void ConsultarVenda(int codVenda)
{
	arqPagamentos = fopen ("pagamentos.dat", "r");
	if (arqPagamentos == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
	
	arqPedidos = fopen ("pedidos.dat", "r");
	if (arqPedidos == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
	arqCartoes = fopen ("cartoes.dat", "r");
	if (arqCartoes == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
	
	arqProdutos = fopen ("produtos.dat", "r");
	if (arqProdutos == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
	
	char NomeArquivoVenda[30];	
	sprintf(NomeArquivoVenda,"%s%d%s","Recibos/ReciboVenda",codVenda,".txt");			

  	/*ARQUIVO DE RECIBO*/
	arqRecibo = fopen (NomeArquivoVenda, "w");
	if (arqRecibo == NULL) 
	{ 
		printf("\nNão foi possível abrir o arquivo\n"); 
		getch();
		system("menu");
	}
	fprintf(arqRecibo,"==========================================");
	fprintf(arqRecibo,"\n======  Mickey & Donald Drive Thru  ======");
	fprintf(arqRecibo,"\n==========================================");
	fprintf(arqRecibo,"\n==============RECIBO DA VENDA=============");
	fprintf(arqRecibo,"\n==========================================");
	fprintf(arqRecibo,"\nITEM \t\t QTDE \t\t VALOR");
	/*ABRE E LE PRODUTOS E REGISTRA NO VETOR DE PRODUTOS*/
	produtos produto;
	
	while(fread(&produto, sizeof(produto), 1, arqProdutos)) 
	{
		listaProdutos[produto.CodProduto] = produto;
	}
	
	fclose(arqProdutos);
	
	/*ABRE E LE PEDIDO*/
	pedidos pedido;
	printf("\n PEDIDO ");
	while(fread(&pedido, sizeof(pedido), 1, arqPedidos)) 
	{
		if(pedido.CodVenda == codVenda)
		{
			printf("\n ITEM: %s \t QTDE: %i \t VALOR: R$%.2f",listaProdutos[pedido.CodProduto].NomeProduto,pedido.Qtde,listaProdutos[pedido.CodProduto].CustProduto);
			fprintf(arqRecibo,"\n%s \t %i \t\t R$%.2f",listaProdutos[pedido.CodProduto].NomeProduto,pedido.Qtde,listaProdutos[pedido.CodProduto].CustProduto);		
		}
	}
		
	/*ABRE E LE PAGAMENTO DO PEDIDO*/
	pagamentos pagamento;
	while(fread(&pagamento, sizeof(pagamento), 1, arqPagamentos)) 
	{
		if(pagamento.codpgto == codVenda)
		{
			printf("\n\n PEDIDO PAGO COM ");
			
			if (strcmp (pagamento.formapgto, "Dinheiro") == 0)
				textcolor(2,4);
			if(strcmp (pagamento.formapgto, "Cheque") == 0)
				textcolor(9,4);
			if(strcmp (pagamento.formapgto, "Cartao de Credito/Debito") == 0)
				textcolor(13,4);
					
			printf("%s",pagamento.formapgto);
			textcolor(14,4);
			
			printf("\n\n VALOR TOTAL PAGO R$%.2f",pagamento.valorpgto);
			
			fprintf(arqRecibo,"\n==========================================");
			fprintf(arqRecibo,"\nFORMA DE PAGAMENTO: %s",pagamento.formapgto);	
			fprintf(arqRecibo,"\nVALOR TOTAL PAGO: R$%.2f",pagamento.valorpgto);	
			fprintf(arqRecibo,"\n==========================================");
			if(strcmp(pagamento.formapgto,"Cartao de Credito/Debito") == 0)
			{
				cartoes cartao;
				while(fread(&cartao, sizeof(cartao), 1, arqCartoes)) 
				{
					if(cartao.Codpgto == codVenda)
					{
						printf("\n\n CARTAO : %s",cartao.Numcartao);					
					}
				}
			}
		}
	}	
	fclose(arqPagamentos);	
	fclose(arqPedidos);	
	fclose(arqCartoes);	
	fclose(arqRecibo);
}


