void leer_sabotaje(EstructuraDeSabotaje sabotaje){
    int x = atoi(get_coords_sabotaje('x', sabotaje));
    int y = atoi(get_coords_sabotaje('y', sabotaje));
    int id_encargado_resolver = tripulante_mas_cercano(BLOQ,x,y);
    Tripulante* encargado_resolver = get_tripulante(id_encargado_resolver);
    resolver_sabotaje(encargado_resolver,sabotaje);
}

void tripulante_mas_cercano(estado estado, int x, int y){
    struct estado *temp = estado;
    int id_encargado;
    int menor_distancia = distancia(temp->tripulante.pos.x,temp->tripulante.pos_y,x,y);
    while(temp->siguiente !=NULL){
        if(menor_distancia < distancia(temp->tripulante.pos.x,temp->tripulante.pos_y,x,y)){
            id_encargado = temp2->tripulante.t_id;
            menor_distancia = distancia(temp->tripulante.pos.x,temp->tripulante.pos_y,x,y);
        }
        temp2 = temp2->siguiente;
    }
    return id_encargado;
}

int distancia(char x, char x, int y1, int y2){
    int x1 = atoi(x);
    int x2 = atoi(y);
    int d = ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
    return sqrt(d);
}

/*FALTA = 
    Recibir sabotaje y desarmar estruct
    get_coords_sabotaje
    resolver_sabotaje
    get_tripulante y ver q devuelva la pos en memoria (considerar q estan todos en BLOQ en este momento)
*/