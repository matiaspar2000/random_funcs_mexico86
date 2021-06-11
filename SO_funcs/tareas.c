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

            while(t_restante >= 0){
                  if(t_restante >= 0 && quantum_restante >= 0){
                        t_restante--;
                        quantum_restante--;
                  }else if (t_restante >= 0 && quantum_restante == 0){
                        return;
                  }
            }

            ejecutar_tarea();

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
                  destruir_basura(0)
                  
            } else {
                  t_buffer* buffer = serilizar_hacer_tarea(duracion, nombre_tarea[0]);
	            t_paquete* paquete_hacer_tarea = crear_mensaje(buffer, HACER_TAREA);
	            enviar_paquete(paquete_hacer_tarea, conexion_hq);
            }
      }
      actualizar_bitacora(tripulante);
      return 0;
}

void mover_a(tripulante tripulante, bool es_x, char valor_nuevo){
      if(es_x){
            tripulante.pos_x++;
            actualizar_bitacora(tripulante, log);
      }else{
            tripulante.pos_y++;
            actualizar_bitacora(tripulante, log);
      }
      registrar_movimiento(tripulante);
}


movimiento()


log = logs_bitacora(INICIO_TAREA, id, nombre_tarea[0], " ");
reportar_bitacora(log);
log = logs_bitacora(FIN_TAREA, id, nombre_tarea[0], " ");
reportar_bitacora(log);

generar_oxigeno(int duracion){
	t_buffer* buffer = serilizar_hacer_tarea(duracion, GENERAR_OXIGENO);
	t_paquete* paquete_hacer_tarea = crear_mensaje(buffer, HACER_TAREA);
	enviar_paquete(paquete_hacer_tarea, conexion_hq);
}

descartar_oxigeno(int duracion){
	t_buffer* buffer = serilizar_hacer_tarea(duracion, CONSUMIR_OXIGENO);
	t_paquete* paquete_hacer_tarea = crear_mensaje(buffer, HACER_TAREA);
	enviar_paquete(paquete_hacer_tarea, conexion_hq);
}

generar_comida(int duracion){
	t_buffer* buffer = serilizar_hacer_tarea(duracion, GENERAR_COMIDA);
	t_paquete* paquete_hacer_tarea = crear_mensaje(buffer, HACER_TAREA);
	enviar_paquete(paquete_hacer_tarea, conexion_hq);
}

consumir_comida(int duracion){
	t_buffer* buffer = serilizar_hacer_tarea(duracion, CONSUMIR_COMIDA);
	t_paquete* paquete_hacer_tarea = crear_mensaje(buffer, HACER_TAREA);
	enviar_paquete(paquete_hacer_tarea, conexion_hq);
}

generar_basura(int duracion){
	t_buffer* buffer = serilizar_hacer_tarea(duracion, GENERAR_BASURA);
	t_paquete* paquete_hacer_tarea = crear_mensaje(buffer, HACER_TAREA);
	enviar_paquete(paquete_hacer_tarea, conexion_hq);
}

descartar_basura(int duracion){
	t_buffer* buffer = serilizar_hacer_tarea(duracion, DESCARTAR_BASURA);
	t_paquete* paquete_hacer_tarea = crear_mensaje(buffer, HACER_TAREA);
	enviar_paquete(paquete_hacer_tarea, conexion_hq);
}

generar_basura(int duracion);
consumir_basura(int duracion);
generar_basura(int duracion);
consumir_basura(int duracion);
generar_basura(int duracion);
descartar_basura(int duracion);

reportar_bitacora(char* log, int id){
      t_buffer* buffer = serializar_reporte_bitacora(id, log);
	t_paquete* paquete_bitacora = crear_mensaje(buffer, REPORTE_BITACORA);
	enviar_paquete(paquete_bitacora, conexion_hq);
}