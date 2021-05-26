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

void cambiar_estado(estado estado_nuevo){
    pasar_a_estado(trabajando,nuevo_estado);
    pasar_a_estado(listo,nuevo_estado);
    pasar_bloqueados_io(nuevo_estado);
}

void pasar_a_estado(estado estado, estado estado_nuevo){
    struct estado *temp = estado;
    while(temp != NULL){
        pasar_uno_por_id(estado, estado_nuevo);
        }
    }
}

void pasar_uno_por_id(estado estado, estado estado_nuevo){
    struct estado *temp2 = estado;
    uint32_t mayor_id = 0;
    while(estado->siguiente !=NULL){
        if(mayor_id < temp2->tripulante.t_id){
            mayor_id = temp2->tripulante.t_id;
        }
        temp2 = temp2->siguiente;
    }
    temp2->t_tripulante_hilo.tripulante.estado = nuevo_estado; 
    list_add(bloqueado, temp2->t_tripulante_hilo);
    list_remove(estado, int index); //q es el index?
}

void pasar_bloqueados_io(estado estado_nuevo){
    struct estado *temp3 = bloqueado_IO;
    for (int i = 0; i < num_threads || temp3 != NULL; ++i){
        auxiliar *vargs = malloc(sizeof *vargs);
        vargs->tripulante = &temp3->t_tripulante_hilo.tripulante;
        vargs->nuevo_estado = &nuevo_estado;
        int hilo = pthread_create(&hilos[i], NULL, esperar_io_y_pasar, vargs);
        pthread_detatch(hilos[i]);
        temp3=temp3->siguiente; //esto es asi? 
    }
}

void* esperar_io_y_pasar(void* vargs){
    //auxiliar *actual_vargs = vargs;
    //((struct args*)input) = actual_vargs
    while(((struct vargs*)input)->tripulante.estado == 'I'){}
    ((struct vargs*)input)->estado = ((struct vargs*)input)->nuevo_estado;
    free(input));
}