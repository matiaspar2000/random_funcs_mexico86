//if(tripulante_desbloqueado)
char* prox_tarea = pedir_tarea(); 
while (prox_tarea != EOF) {  //todos los tripulantes tienen q hacer todas las tareas, esto no hace q circule x el archivo y saltee?
//controlar EOF antes de la func

void* leer_tareas(void* tripulante, char* tarea){
            char** parametros_tarea = string_split(prox_tarea, ";");
            char** parametros_tarea = string_split(prox_tarea, ";");
            char** nombre_tarea = string_split(parametros_tarea[0], " ");
            char* pos_x = prox_tarea[1];
            char* pos_y = prox_tarea[2];
            char* duracion = prox_tarea[3];

            mover_a(tripulante,'x',pos_x);
            mover_a(tripulante,'y',pos_y);
            //como controlar quantum en caso de RR 
            sleep(atoi(duracion));

            if(strcmp(nombre_tarea[0], "GENERAR_OXIGENO") == 0) {
                  generar_oxigeno(nombre_tarea[1]);

            } else if (strcmp(nombre_tarea[0], "CONSUMIR_OXIGENO") == 0) {
                  consumir_oxigeno(nombre_tarea[1]);

            } else if (strcmp(nombre_tarea[0], "GENERAR_COMIDA") == 0) {
                  generar_comida(nombre_tarea[1]);

            } else if (strcmp(nombre_tarea[0], "CONSUMIR_COMIDA") == 0) {
                  consumir_comida(nombre_tarea[1]);

            } else if (strcmp(nombre_tarea[0], "GENERAR_BASURA") == 0) {
                  generar_basura(nombre_tarea[1]);

            } else if (strcmp(nombre_tarea[0], "DESCARTAR_BASURA") == 0) {
                  destruir_basura()
            } else {
                  log_info(logger, "no se reconocio la tarea");
            }
      }
      actualizar_bitacora(tripulante);
      return 0;
}

void mover_a(tripulante tripulante, char xOy, char valor_nuevo){
      if(xOy == 'x'){
            tripulante.pos_x = atoi(valor_nuevo);
            actualizar_bitacora(tripulante, log);
      }else{
            tripulante.pos_y = atoi(valor_nuevo);
            actualizar_bitacora(tripulante, log);
      }
      registrar_movimiento(tripulante);
}

/*TO DO: 
pedir_tarea()
func de cada tarea (sockets con FS)
registrar en bitacora y memoria

*/