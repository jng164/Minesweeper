#include <stdio.h>
#include "libreria.h"
#include "azar.h"
#include "colores.h"
#include "tiempo.h"


void  menu  (ttablero *tablero)
{
int opc,min;
 do{
  printf("1) Tablero 8x8    10 minas\n");
  printf("2) Tablero 16x16  40 minas\n");
  printf("3) Tablero 16x30  99 minas\n");
  printf("4) Tablero personalizado \n");
  printf("Que opcion eliges? [1-4]: ");
  scanf("%d%*c", &opc);
   switch(opc)
   { case 1:
          tablero->filas= 8;
          tablero->columnas = 8;
          tablero->nbombas = 10;
          break;
      case 2:
           tablero->filas = 16;
           tablero->columnas = 16;
           tablero->nbombas = 40;
           break;
      case 3:
          tablero->filas= 16;
           tablero->columnas= 30;
           tablero->nbombas = 99;
           break;
      case 4:
            do 
			{
            printf("Introducir las filas(4-36):");
            scanf("%d%*c",&tablero->filas);
				if (tablero->filas < 4 || tablero->filas > 36)
					printf("El valor introducido es incorrecto, por favor introduzca de nuevo \n");
			
            }while(tablero->filas < 4 || tablero->filas > 36);
	
 			do         
            {
            printf("Introducir las columnas(4-36) ");
            scanf("%d%*c",&tablero->columnas);
				if (tablero->columnas < 4 || tablero->columnas > 36)
					printf("El valor introducido es incorrecto, por favor introduzca de nuevo \n");
            } while(tablero->columnas < 4 || tablero->columnas > 36);
	
           tablero->nbombas = (tablero->filas * tablero->columnas) -9;
           do
            {
            printf("Porfavor Introducir las minas(1-%d)",tablero->nbombas );
            scanf("%d%*c",&min);
				if (min < 1 || min > tablero->nbombas)
				printf("El valor introducido es incorrecto \n");
            }while(min < 1 || min > tablero->nbombas);
			tablero->nbombas=min;
            break;
         
       }
 }while(opc<1 || opc>4);
printf ("Has creado un campo de minas con %d filas y %d columnas con %d bombas\n",tablero->filas,tablero->columnas,tablero->nbombas);
}

void poner_cero(ttablero *tablero)
{
  int i,j;

  for (i=0; i< tablero->filas;i++)
   {
     for(j=0; j < tablero->columnas; j++)
       {
         tablero->casilla[i][j].estado_casilla = 0;
         tablero->casilla[i][j].valor_casilla = 0;
       }  
    }
	empieza_tiempo();
	tablero->tiempo=0;
}

void poner_alrededor(ttablero *tablero,int fil,int col)
{
	int i,j;
  for(i = fil-1; i <= fil + 1; i++)
  {
    for(j = col-1; j <= col + 1; j++)
    {
		 if(tablero->casilla[i][j].valor_casilla != -1 && ((i>=0 && i<tablero->filas) && (j>=0 && j<tablero->columnas)))
		 {
		  tablero->casilla[i][j].valor_casilla ++;
		 }
			 
	}
	
  }
}
void poner_bomba(ttablero *tablero)
{
	int x=0;
	inicializar_azar();
	while (x < tablero->nbombas)
	{
		int fil=numero_al_azar(tablero->filas);
		int col=numero_al_azar(tablero->columnas);
		if (tablero->casilla[fil][col].valor_casilla!=-1)
		{
			tablero->casilla[fil][col].valor_casilla=-1;
			poner_alrededor(tablero,fil,col);
			x++;
		}
	}

}
void clearscreen()
{
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
void  coordenadas(int x)
{
	char letra =(x+55);
  if(x<10)
  {
  printf("%d",x);
  }else
  {
	  printf ("%c",letra);
  }

}
void tiempo(ttablero *tablero)
{
	
	tablero->tiempo=tiempo_transcurrido()+tablero->tiempo;
	if(tablero->tiempo < 60)
	{
		printf ("\nEl tiempo transcurrido 00m:%ds\n",tablero->tiempo);
	}else if (tablero->tiempo <3600)
	{
	printf ("\nEl tiempo transcurrido %dm:%ds\n",(tablero->tiempo/60),(tablero->tiempo%60));
	}
}
void mostrar(ttablero tablero)
{
	int i,j;
		tiempo(&tablero);
		printf ("	");
		for(j=0;j<tablero.columnas;j++)
		{
			printf ("|");
			coordenadas(j);
		}
		printf ("|");
		printf("\n");
		printf ("	");
		for (j=0;j<tablero.columnas;j++)
		{
			printf ("--");
		}
		printf ("-");
			printf("\n");
	for (i=0;i<tablero.filas;i++)
	{

		coordenadas(i);
		printf("	");
		for(j=0;j<tablero.columnas;j++)
		{

			printf ("|");
			//Aca imprimiremos deacuerdo al estado
			switch (tablero.casilla[i][j].estado_casilla)
			{
				case TAPADO:
					printf (" ");
					break;
				case DESTAPADO:
					if(tablero.casilla[i][j].valor_casilla==-1)
					{
						printf_color(7);
						printf ("*");
						printf_color(-1);
					}else if (tablero.casilla[i][j].valor_casilla==0)
					{
						printf ("_");
					}else
					{
						switch (tablero.casilla[i][j].valor_casilla)
						{
							case 0:
								printf_color(0);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
							case 1:
								printf_color(1);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
							case 2:
								printf_color(2);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
							case 3:
								printf_color(3);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
							case 4:
								printf_color(4);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
							case 5:
								printf_color(5);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
							case 6:
								printf_color(6);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
							case 7:
								printf_color(7);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
							case 8:
								printf_color(8);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
							case 9:
								printf_color(9);
								printf ("%d",tablero.casilla[i][j].valor_casilla);
								printf_color(-1);
								break;
						}
					
					}
					break;
				case BANDERA:
					printf_color(9);
					printf ("!");
					printf_color(-1);
					break;
				case INTERROGACION:
					printf_color(4);
					printf ("?");
					printf_color(-1);
					break;
			}
			
		}
		printf("|\n");
	}
}
int cambiar_int(char x)
{
	int pos=x;
	if (pos<58)
	{
		pos =x-48;
	}else if (pos <90)
	{
		pos=x-55;
	}else if (pos <122)
	{
	pos=x-87;
	}
}
void  cambiar_blanco(ttablero *tablero,int fil,int col)
{
	int i,j,a,b;
  for(i = fil-1; i <= fil + 1; i++)
  {
    for(j = col-1; j <= col + 1; j++)
    {
		 if(tablero->casilla[i][j].valor_casilla == 0 && ((i>=0 && i<tablero->filas) && (j>=0 && j<tablero->columnas)))
		 {
			 tablero->casilla[i][j].estado_casilla=DESTAPADO;
			  for(a = i-1; a <= i + 1; a++)
 		 		{
    			for(b = j-1; b <= j + 1; b++)
   				{
					if(tablero->casilla[a][b].valor_casilla != 0 || 
					   tablero->casilla[a][b].valor_casilla !=-1&&
					   ((a>=0 && a<tablero->filas) && (b>=0 && b<tablero->columnas)))
					{
						 tablero->casilla[a][b].estado_casilla=DESTAPADO;
					}
				}
				}
		}
	}
  		}
}
void cambiar_estado(ttablero *tablero)
{
	char x,y;
	int posx,posy;
	char jugada;
	do{
	printf ("\n Tipos de jugada: Destapar ' ' , Bandera '!' , Interrogacion '?'");
	printf ("\nPor favor introduzca la fila-columna-jugada del tablero(00?):");
	scanf ("%c%c%c%*c",&x ,&y , &jugada);
	//transformar char a int
	posx=cambiar_int (x);
	posy=cambiar_int (y);
	if (posx>tablero->filas||posy>tablero->columnas)
	{
		printf ("\n Coordenadas incorrectasvuelva a introducir");
	}
	}while (posx>(tablero->filas-1)||posy>(tablero->columnas-1));
	
	switch (jugada)
	{
		case ' ':
			tablero->casilla[posx][posy].estado_casilla=1;
			cambiar_blanco(tablero,posx,posy);
			break;
		case '!':
			tablero->casilla[posx][posy].estado_casilla=2;
			break;
		case '?':
			tablero->casilla[posx][posy].estado_casilla=3;
			break;
	}
}
void comprobacion(ttablero *tablero)
{
int i,j,total =(tablero->filas *tablero->columnas)-tablero->nbombas;
		tablero->levantadas=0;
	for(i=0;i<tablero->filas;i++)
	{
		for (j=0;j< tablero->columnas;j++)
		{
			if (tablero->casilla[i][j].estado_casilla==DESTAPADO)
			{
				tablero->levantadas++;
			}
		}
	}
	printf("\nlas levantadas es %dy el total es %d\n",tablero->levantadas,total);
	if (total==tablero->levantadas)
	{
		tablero->game=WIN;
	}else
	{
    for(i=0;i<tablero->filas && tablero->game==INGAME;i++)
	{
		for (j=0;j< tablero->columnas && tablero->game==INGAME;j++)
		{
			if(tablero->casilla[i][j].estado_casilla==DESTAPADO && tablero->casilla [i][j].valor_casilla==BOMBA)
	{
				tablero->game=LOSE;
			}
		}
	}
	}
	
}
void case_lose (ttablero *tablero)
{
	int i,j;
	for(i=0;i<tablero->filas;i++)
	{
		for (j=0;j< tablero->columnas;j++)
		{
			if (tablero->casilla[i][j].valor_casilla==BOMBA)
			{
				tablero->casilla [i][j].estado_casilla=DESTAPADO;
			}
		}
	}
}
void case_win (ttablero *tablero)
{
	int i,j;
	for(i=0;i<tablero->filas;i++)
	{
		for (j=0;j< tablero->columnas;j++)
		{
			tablero->casilla[i][j].estado_casilla=DESTAPADO;
		}
	}
}

