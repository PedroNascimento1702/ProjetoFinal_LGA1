/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include "libCoresSom.h"
#include <time.h>
/* Corpo do programa */
int main()
{
  struct tm *data_hora_atual;     
  time_t segundos;
	 
		time(&segundos);   		   
		data_hora_atual = localtime(&segundos);  
		gotoxy(100,30);			  
		printf("%02d/%02d/%d",data_hora_atual->tm_mday,data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900);//hora   
		
	return 0;
}
