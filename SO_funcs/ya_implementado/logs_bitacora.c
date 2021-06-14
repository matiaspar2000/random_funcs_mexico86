typedef enum
{
    DESPLAZAMIENTO,
    INICIO_TAREA, 
    FIN_TAREA, 
    SABOTAJE, 
    SABOTAJE_RESUELTO
}regs_bitacora;


char* logs_bitacora(regs_bitacora asunto, t_tripulante tripulante, char* dato1, char* dato2){
switch(asunto){
    case DESPLAZAMIENTO:  //dato 1 posicion inicial en formato x|y, dato 2 posicion final en igual formato
        int size = strlen(dato1) + strlen(dato2) + strlen("Se mueve de ") + strlen(" a ") + 1;
        char *reporte = malloc(size);
        strcpy (reporte, "Se mueve de ");
        strcat (reporte, dato1);
        strcat (reporte, " a ");
        strcat (reporte, dato2);
        return reporte;
        break;

    case INICIO_TAREA: //dato 1 nombre de tarea como string, dato 2 nada
        int size = strlen(dato1) + strlen("Comienza ejecucion de la tarea ") + 1;
        char *reporte = malloc(size);
        strcpy (reporte, "Comienza ejecucion de la tarea ");
        strcat (reporte, dato1);
        return reporte;
        break;

    case FIN_TAREA: //dato 1 nombre de tarea, dato 2 nada
        int size = strlen(dato1) + strlen("Se finaliza la tarea ") + 1;
        char *reporte = malloc(size);
        strcpy (reporte, "Se finaliza la tarea ");
        strcat (reporte, dato1);
        return reporte;
        break;

    case SABOTAJE:
        return "Se corre en pánico a la ubicación del sabotaje";
        break;

    case SABOTAJE_RESUELTO:
        return "Se resuelve el sabotaje";
        break;

   default: 
        return "Situación desconocida";
}

int size = sizeof(int)*2 + sizeof('|');
char *str_start = malloc(size);
char *str_end = malloc(size);

char *x = malloc(sizeof(pos_x));
char *y = malloc(sizeof(pos_x));
char *xn= malloc(sizeof(x_nuevo));
char *yn = malloc(sizeof(y_nuevo));

itoa(pos_x, x, 10);
itoa(pos_y, y, 10);
itoa(pos_x_nuevo, x_nuevo, 10);
itoa(pos_y_nuevo, y_nuevo, 10);

strcpy (str_start, x);
strcat (str_star, "|");
strcat (str_start, y);

strcpy (str_end, x_nuevo);
strcat (str_end, "|");
strcat (str_end, y_nuevo);





/*  int size = strlen(a) + strlen(b) + strlen(c) + 1;
  char *str = malloc(size);
  strcpy (str, a);
  strcat (str, b);
  strcat (str, c);*/