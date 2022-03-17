#include <stdio.h>
#include "libreria.h"


main ()
{
ttablero tablero;
tablero.game=INGAME;
clearscreen();
menu(&tablero);
poner_cero(&tablero);
poner_bomba(&tablero);
while (tablero.game==INGAME)
{
	mostrar(tablero);
	cambiar_estado(&tablero);
	comprobacion(&tablero);
}
	if(tablero.game==WIN)
	{
		case_win (&tablero);
		mostrar(tablero);
		printf("Ganaste");
	}else if (tablero.game==LOSE)
	 {
		 case_lose(&tablero);
		 mostrar(tablero);
		 printf ("\nBOOOOOOOOOOOM!\n");
	 }
}
