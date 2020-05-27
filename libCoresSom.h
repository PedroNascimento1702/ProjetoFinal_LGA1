//#include <iostream>
#include <windows.h>
/*             0     1    2     3   4      5      6      7         8  */
typedef enum{BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,   /* nome das cores */
LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE} COLORS;
/*  9         10         11        12        13         14    15 */

static int __BACKGROUND = 1/*BLACK*/;/*pode ser o numero ou o nome da cor*/
static int __FOREGROUND = LIGHTGRAY;

void textcolor (int letras, int fundo){/*para mudar a cor de fundo mude o background*/
    __FOREGROUND = letras;
    __BACKGROUND = fundo;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (__BACKGROUND << 4));
}
                  /* y = linha de 0 a 24 , x = coluna de 0 a 80 */
void gotoxy(int x, int y){/*imprimir na linha e coluna desejada */
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int som(int f){
    Beep(f,150);/* primeiro a frquência depois o tempo de duração do som */
    return 0;
}
