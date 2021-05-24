bool pedir_permiso(tripulante tripulante){
    if(primeroEnLista(listo, tripulante) || espacioLibre()){
        return true;
    }else{
        return false;
    }
}

bool espacioLibre(){
    return (list_size(trabajando) < 2);
}

bool primeroEnLista(t_list lista, tripulante tripulante){
    t_tripulante aux = list_get(lista,1);

    if(aux->PID == tripulante->PID){
        return 1;
    }
    return 0;
}