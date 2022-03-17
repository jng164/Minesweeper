// Este fichero se le da al alumno
#include <time.h>	// time()
#include <stdio.h>
#include "tiempo.h"

time_t start,end; 

void empieza_tiempo() {
	time (&start);
}

int tiempo_transcurrido() {
	time (&end); 

	return (int) difftime (end,start); 
}

