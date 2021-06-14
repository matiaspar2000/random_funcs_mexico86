void cambiar_estado(int estado_anterior, int estado_nuevo, t_tripulante tripulante){
    
   bool es_el_tripulante(void* tripulante_en_lista) {
		return ((t_tripulante*)tripulante_en_lista)->TID == argumentos->tripulante->TID;
	}

   switch(estado_anterior){
    case e_llegada:
        list_remove_by_condition(llegada, es_el_tripulante);
        break;
    case e_listo:
        list_remove_by_condition(listo, es_el_tripulante);
        break;
    case e_fin:
        list_remove_by_condition(fin, es_el_tripulante);
        break;
    case e_trabajando:
        list_remove_by_condition(trabajando, es_el_tripulante);
        break;
    case e_bloqueado_IO:
        list_remove_by_condition(bloqueado_IO, es_el_tripulante);
        break;
    case e_bloqueado_emergencia:
        list_remove_by_condition(bloqueado_emergencia, es_el_tripulante);
        break;
   }

   switch(estado_actual){
    case e_llegada:
        list_add(llegada, tripulante);
        return;
    case e_listo:
        list_add(listo, tripulante);
        return;
    case e_fin:
        list_add(fin, tripulante);
        return;
    case e_trabajando:
        list_add(trabajando, tripulante);
        return;
    case e_bloqueado_IO:
        list_add(bloqueado_IO, tripulante);
        return;
    case e_bloqueado_emergencia:
        list_add(bloqueado_emergencia, tripulante);
        return;
    }
}

typedef enum
{
	e_llegada,
	e_listo,
	e_fin,
	e_trabajando,
	e_bloqueado_IO,
	e_bloqueado_emergencia,
}estado;

typedef struct {
int TID;
int PID;
int pos_x;
int pos_y;
estado estado;
}t_tripulante;