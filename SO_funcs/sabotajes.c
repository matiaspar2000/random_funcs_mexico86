typedef struct{
    uint32_t x;
    uint32_t y;
}t_sabotaje;

void sabotaje(t_sabotaje datos){} 
    //Hilo de esperar sabotaje (o algo q no haga espera activa) que cada vez que le llega la señal deserializa y llama a esta func
   mover_trips(e_bloqueado); //hecho como q todos pasan a bloqueado y el que resuelve pasa a bloqueado_emergencia, podrian pasar todos a em directo y agarrar el mas cerca de esos
   tripulante* asignado = tripulante_mas_cercano(datos->x, datos->y);
   resolver_sabotaje(asignado, datos);
   desbloquear_trips_inverso();
   cambiar_estado(asignado->e_estado, e_listo, asignado);
   return;
}

void mover_trips(e_estado nuevo_estado){
    //mutex de cada lista
    pasar_menor_id(trabajando,nuevo_estado);
    pasar_menor_id(listo,nuevo_estado);
    while(list_size(bloqueado_IO) != 0){
        pasar_menor_id(bloqueado_IO, nuevo_estado);
        pasar_menor_id(listo, nuevo_estado);
    }
}

void desbloquear_trips_inverso(estado listo){
    while(list_size(lista) != 0){
        pasar_ultimo(lista, e_listo);
    }
    return;
}

void pasar_menor_id(estado lista, e_estado estado_nuevo){
    while(list_size(estado) != 0){
        t_tripulante cambio = list_get_minimum(lista, (void*)menorID);
        cambiar_estado(cambio->e_estado, estado_nuevo, cambio);
    }
    return;
}

void pasar_ultimo(estado lista, e_estado nuevo){
    int x = list_size(lista);
    t_tripulante* ultimo = list_get(lista,x-1);
    cambiar_estado(ultimo->estado, nuevo, ultimo);
    return;
}

tripulante* tripulante_mas_cercano(int x, int y){
    static void* distancia(t_tripulante* t1, t_tripulante* t2){
        return distancia(t1, x, y) < distancia(t1, x, y) ? t1 : t2;
    }
    t_tripulante asignado = list_get_minimum(lista, (void*)distancia);
    return asignado;  
}

static void* menorID(t_tripulante* t1, t_tripulante* t2) {
    return t1->TID < t2->TID ? t1 : t2;
}

float distancia(t_tripulante trip, int x, int y){
    return sqrt((x - trip->pos_x)*(x - trip->pos_x) + (y - trip->pos_y)*(y - trip->pos_y));
}

void resolver_sabotaje(t_tripulante asignado, t_sabotaje datos){
    cambiar_estado(asignado->e_estado, e_bloqueado_emergencia, asignado);
    reportar_bitacora(logs_bitacora(SABOTAJE, " ", " "), asignado->TID);
    int tiempo = atoi(config_get_string_value(config, "DURACION_SABOTAJE"));
    mover_a(asignado, true, datos->x, retardo_ciclo_cpu);
	mover_a(asignado, false, datos->y, retardo_ciclo_cpu);
    //invocar_FSCK_de_hq(); //ESTO ES UNA SERIALIZACION Y ESPERAR RTA
    sleep(tiempo); //SUPONGO Q ACÁ NO HAY FIFO NI RR
    reportar_bitacora(logs_bitacora(SABOTAJE_RESUELTO, " ", " "), asignado->TID);
    return;
}

void resolver_sabotaje(t_tripulante asignado, t_sabotaje datos);
float distancia(t_tripulante trip, int x, int y);
static void* menorID(t_tripulante* t1, t_tripulante* t2);
tripulante* tripulante_mas_cercano(int x, int y);
void pasar_ultimo(estado lista, e_estado nuevo);
void pasar_menor_id(estado lista, e_estado estado_nuevo);
void desbloquear_trips_inverso(estado listo);
void mover_trips(e_estado nuevo_estado);


/*FALTA = 
    Recibir sabotaje y desarmar estruct
    Invocar fsck
    ver de agarrar solo los de listo y trabajando
*/