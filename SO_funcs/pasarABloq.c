#define num_threads 50
pthread_t hilos[num_threads];

typedef struct {
    int TID;
    int PID;
    int pos_x;
    int pos_y;
    char estado;
}t_tripulante;

typedef struct {
    t_tripulante* tripulante;
    pthread_t hilo;
}t_tripulante_hilo;

typedef struct {
    tripulante* tripulante;
    char* estado;
}auxiliar;

void cambiar_estado(e_estado, nuevo_estado){
    pasar_menor_id(trabajando,nuevo_estado);
    pasar_menor_id(listo,nuevo_estado);
    while(list_size(bloqueado_IO) != 0){
        pasar_menor_id(listo, nuevo_estado);
    }
}

void pasar_menor_id(estado lista, e_estado estado_nuevo){
    while(list_size(estado) != 0){
        pasar_menor(estado, estado_nuevo);
    }
}

void pasar_menor(estado lista, e_estado estado_nuevo){
    int menorID(void* t1, void* t2) {
        if(((t_tripulante*)t1)->TID < ((t_tripulante*)t2)->TID){
		    return ((t_tripulante*)t2);
        }else{
            return ((t_tripulante*)t2); 
        }
	}

    cambiar_estado((list_get_minimum(lista, menorID))->e_estado, estado_nuevo, list_get_minimum(lista, menorID))
}