char* instruccion[5];

inicializar_tripulante(char** instruccion, int cantidad_ya_iniciada){
    new Tripulante = malloc(sizeof(tripulante));
    tripulante.id = instruccion[1];
    if(instruccion[3] == NULL){
        tripulante.coords = 0|0;
    }else{
        tripulante.coords = instruccion[3+cantidad_ya_iniciada];
    }
}