void cambiarEstado(int nuevoEstado, t_list* estadoNuevo, t_list* estadoViejo, tripulante tripulante){
    int id_buscado = tripulante.p_id;

    bool idABorrar(t_list lista){
        lista->tripulante.p_id = id_buscado;
    }

    tripulante.estado = nuevoEstado;
    list_add(estadoNuevo, tripulante);
    list_remove_by_condition(estadoViejo, idABorrar);
}