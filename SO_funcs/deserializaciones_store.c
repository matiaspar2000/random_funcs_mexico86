
typedef struct{
	uint32_t cantidad;
	uint32_t tid;
	char* tarea;
}t_tarea_para_hacer;

typedef struct{
	uint32_t tid;
	char* reporte;
}t_reporte;

t_tarea_para_hacer* recibir_tarea(int socket_cliente){
	int size;
	int desplazamiento = 0;
	void* buffer;
	t_tarea_para_hacer* th = malloc(sizeof(t_tarea_para_hacer));

	buffer = recibir_buffer(&size, socket_cliente);

	memcpy(&(th->cantidad), (buffer+desplazamiento), sizeof(uint32_t));
	desplazamiento+=sizeof(uint32_t);

	memcpy(&(th->tid), (buffer+desplazamiento), sizeof(uint32_t));
	desplazamiento+=sizeof(uint32_t);

	void* tarea_len = malloc(sizeof(uint32_t));
	memcpy(&tarea_len, (buffer+desplazamiento), sizeof(uint32_t));
	desplazamiento += sizeof(uint32_t);
	th->tarea = malloc(tarea_len);
	memcpy(th->tareas, buffer+desplazamiento, tarea_len);

	free(buffer);
	return th;
}

t_reporte* recibir_reporte_bitacora(int socket_cliente){
	int size;
	int desplazamiento = 0;
	void* buffer;
	t_reporte* re = malloc(sizeof(t_reporte));

	buffer = recibir_buffer(&size, socket_cliente);

	memcpy(&(re->tid), (buffer+desplazamiento), sizeof(uint32_t));
	desplazamiento+=sizeof(uint32_t);

	void* reporte_len = malloc(sizeof(uint32_t));
	memcpy(&reporte_len, (buffer+desplazamiento), sizeof(uint32_t));
	desplazamiento += sizeof(uint32_t);
	re->reporte = malloc(reporte_len);
	memcpy(re->reporte, buffer+desplazamiento, reporte_len);

	free(buffer);
	return re;
}

t_tarea_para_hacer* recibir_tarea(int socket_cliente);
t_reporte* recibir_reporte_bitacora(int socket_cliente);