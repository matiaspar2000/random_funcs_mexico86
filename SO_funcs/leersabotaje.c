void leer_sabotaje(EstructuraDeSabotaje sabotaje){
    int x = atoi(get_coords_sabotaje('x', sabotaje));
    int y = atoi(get_coords_sabotaje('y', sabotaje));
    int id_encargado_resolver = tripulante_mas_cercano(x,y);
    Tripulante* encargado_resolver = get_tripulante(id_encargado_resolver);
    resolver_sabotaje(encargado_resolver,sabotaje);
}

void tripulante_mas_cercano(int x, int y){
    struct estado *temp = estado;

    int menor_distancia(void* t1, void* t2) {
        if(
            distancia((t_tripulante*)t2)->pos_x, (t_tripulante*)t2)->pos_y,t1,t2) <
            distancia((t_tripulante*)t2)->pos_x, (t_tripulante*)t2)->pos_y,t1,t2
        ){
		    return ((t_tripulante*)t1);
        }else{
            return ((t_tripulante*)t2); 
        }
	}
    cambiar_estado((list_get_minimum(lista, menorID))->e_estado, bloqueado_emergencia, list_get_minimum(lista, menorID));
    //puede haber +1 emergecia a la vez?
}

int distancia(int x, int y, int y1, int y2){
    int d = ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
    return sqrt(d);
}

/*FALTA = 
    Recibir sabotaje y desarmar estruct
    get_coords_sabotaje
    resolver_sabotaje
    get_tripulante y ver q devuelva la pos en memoria (considerar q estan todos en BLOQ en este momento)
*/