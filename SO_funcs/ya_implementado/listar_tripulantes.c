#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void listar_tripulantes(){
    void listar(void* t) {
        printf("Tripulante: %3d    Patota: %3d    Estado: %3d \n", t->TID, t->PID, t->estado);
	}

    int hours, minutes, seconds, day, month, year;
    time_t now;
    time(&now);

    struct tm *local = localtime(&now);
 
    hours = local->tm_hour;         
    minutes = local->tm_min;        
    seconds = local->tm_sec;        
    day = local->tm_mday;            
    month = local->tm_mon + 1;     
    year = local->tm_year + 1900;
    
	printf("---------------------------------------------------------------------------- \n");
    printf("Estado de la nave al día %02d de %02d del anio %d a la hora %02d:%02d:%02d \n", day, month, year, hours, minutes, seconds);
    list_iterate(llegada,listar);
    list_iterate(listo,listar);
    list_iterate(trabajando,listar);
    list_iterate(bloqueado_emergencia,listar);
    list_iterate(bloqueado_IO,listar);
    list_iterate(fin,listar);
    printf("---------------------------------------------------------------------------- \n");
}


/*
--------------------------------------------------------------------
Estado de la Nave: 09/07/21 10:15:01
Tripulante: 1	Patota: 1	Status: EXEC
Tripulante: 2	Patota: 2	Status: EXEC
Tripulante: 3	Patota: 2	Status: BLOCK I/O
Tripulante: 4	Patota: 3	Status: READY

*/