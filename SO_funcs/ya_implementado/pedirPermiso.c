bool planificacion = false; 

void circular(tripulante){
    if(puede_ejecutar(tripulante) || planificacion){
        ejecutar(tripulante,tarea);
    }else if(planificacion){
        pedir_permiso(tripulante);
    }else{
        while(!planificacion){
            wait(1);
        }
    }
}

bool puede_ejecutar(tripulante tripulante){
    if(primeroEnLista(listo, tripulante) || espacioLibre()){
        return true;
    }else{
        return false;
    }
}

bool espacioLibre(){
    return (list_size(trabajando) < 2);
}

bool primeroEnLista(tripulante tripulante){
    t_tripulante aux = list_get(listo,1);

    if(aux->PID == tripulante->PID){
        return 1;
    }
    return 0;
}

void pedir_permiso(tripulante){
    if (espacioLibre() && primeroEnLista(tripulante)){
        //mutex de la lista
        cambiar_estado(e_listo,e_trabajando,tripulante);
        //
    }else{
        return;
    }
}