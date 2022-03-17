#include <stdio.h>
#include "tiempo.h"
#define VACIA -1
#define FM1 5
#define CM1 4
#define N 10
typedef struct 
{
int numerador;
char div;
int denominador ;
}tmat_frac;

main ()
{
 int m1 [FM1][CM1],fm1,cm1,sf1,sc1,fmat,cmat,tiempo;
 int sudoku [9][9]={{5,3,VACIA,VACIA,7,VACIA,VACIA,VACIA,VACIA},
 {6,VACIA,VACIA,1,9,5,VACIA,VACIA,VACIA},
 {VACIA,9,8,VACIA,VACIA,VACIA,VACIA,6,VACIA},
 {8,VACIA,VACIA,VACIA,6,VACIA,VACIA,VACIA,3},
 {4,VACIA,VACIA,8,VACIA,3,VACIA,VACIA,1},
 {7,VACIA,VACIA,VACIA,2,VACIA,VACIA,VACIA,6},
 {VACIA,6,VACIA,VACIA,VACIA,VACIA,2,8,VACIA},
 {VACIA,VACIA,VACIA,4,1,9,VACIA,VACIA,5},
 {VACIA,VACIA,VACIA,VACIA,8,VACIA,VACIA,7,9}};
 tmat_frac mat_frac [N][N];
	empieza_tiempo();
//Iniciar m1
 for (fm1=0;fm1<FM1;fm1++){
  for(cm1=0;cm1<CM1;cm1++){
  m1[fm1][cm1]=1;}
 }
//mostrar en pantalla m1
 printf ("Valor de m1\n");
 printf ("\n");
 for (fm1=0;fm1<FM1;fm1++){
  for(cm1=0;cm1<CM1;cm1++){
   printf ("%d ",m1[fm1][cm1]);
  }
 printf ("\n");
 }

//mostrar en pantalla sudoku
 printf ("Valor de sudoku\n");
 printf ("\n");
 for (sf1=0;sf1<9;sf1++){
  for(sc1=0;sc1<9;sc1++) {
   if (sudoku [sf1][sc1]!=-1)
   {
    printf ("|%d ",sudoku[sf1][sc1]); 
   }else{printf ("|  ");}
  }
  printf ("\n");
 }
//Iniciar mat_frac
 for (fmat=0;fmat<N;fmat++){
  for(cmat=0;cmat<N;cmat++){
   mat_frac[fmat][cmat].numerador=fmat+1;
   mat_frac[fmat][cmat].div='/';
   mat_frac[fmat][cmat].denominador=cmat+1;
  }
 }
//mostrar en pantalla mat_frac
printf ("Valor de mat_frac\n");
printf ("\n");
 for (fmat=0;fmat<N;fmat++){
  for(cmat=0;cmat<N;cmat++){
  printf ("%d",mat_frac[fmat][cmat].numerador);
  printf ("%c",mat_frac[fmat][cmat].div);
  printf ("%d ",mat_frac[fmat][cmat].denominador);
  }
 printf ("\n");
 }
	tiempo=tiempo_transcurrido();
	while(tiempo <10)
	{
		tiempo=tiempo_transcurrido();
	printf ("el tiempo transcurrido es %d\n",tiempo);
	}

}