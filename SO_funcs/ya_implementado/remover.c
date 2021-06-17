void expulsar_tripulante(int id) {
   bool es_el_tripulante(void* tripulante_en_lista) {
		return ((t_tripulante*)tripulante_en_lista)->TID == id;
	}

    if(list_find(llegada, es_el_tripulante)){
        list_remove_and_destroy_by_condition(llegada, es_el_tripulante, free);
        return;
    }
    else if(list_find(listo, es_el_tripulante)){
        list_remove_and_destroy_by_condition(listo, es_el_tripulante, free);
        return;
    }
    else if(list_find(fin, es_el_tripulante)){
        list_remove_and_destroy_by_condition(fin, es_el_tripulante, free);
        return;
    }
    else if(list_find(bloqueado_IO, es_el_tripulante)){
        list_remove_and_destroy_by_condition(bloqueado_IO, es_el_tripulante, free);
        return;
    }
    else if(list_find(bloqueado_emergencia, es_el_tripulante)){
        list_remove_and_destroy_by_condition(bloqueado_emergencia, es_el_tripulante, free);
        return;
    }
    else{
        list_remove_and_destroy_by_condition(trabajando, es_el_tripulante, free);
        return;
    }
   //enviar__remover_a_hq(id);
   return;
}