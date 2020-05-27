/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include "libCoresSom.h"
#include <time.h>
/* Corpo do programa */
int main()
{
	system ("color 4E");
	system ("cls");
	system ("mode 38,20");
	
	system("logo");
	
	textcolor (YELLOW,RED);	printf("\n\n\n      Mickey & Donald Drive Thru");
    gotoxy(19,25);
    Beep(261,175);
	Beep(293,175);
	Beep(0,175);
	Beep(311,175);
	Beep(0,175);
	Beep(466,70);
	Beep(523,175);
	Beep(0,175);
	Beep(466,500);
	sleep(1);
	system("cls");
	 system("login");
	return 0;
}
