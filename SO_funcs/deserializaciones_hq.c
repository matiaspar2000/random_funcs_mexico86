typedef struct{
	uint32_t tid;
	uint32_t x;
    uint32_t y;
}t_movimiento;

typedef struct{
	uint32_t tid;
	char estado;
}t_cambio_estado;

t_movimiento* recibir_movimiento(int socket_cliente){
	int size;
	int desplazamiento = 0;
	void* buffer;
	t_movimiento* mov = malloc(sizeof(t_movimiento));

	buffer = recibir_buffer(&size, socket_cliente);

	memcpy(&(mov->tid), (buffer+desplazamiento), sizeof(uint32_t));
	desplazamiento+=sizeof(uint32_t);

	memcpy(&(mov->x), buffer+desplazamiento, sizeof(uint32_t));
	desplazamiento+=sizeof(uint32_t);

	memcpy(&(mov->y), buffer+desplazamiento, sizeof(uint32_t));

	free(buffer);
	return mov;
}

t_cambio_estado* recibir_cambio_estado(int socket_cliente){
	int size;
	int desplazamiento = 0;
	void* buffer;
	t_movimiento* ce = malloc(sizeof(t_cambio_estado));

	buffer = recibir_buffer(&size, socket_cliente);

	memcpy(&(ce->tid), (buffer+desplazamiento), sizeof(uint32_t));
	desplazamiento+=sizeof(uint32_t);

	memcpy(&(ce->estado), buffer+desplazamiento, sizeof(char));

	free(buffer);
	return ce;
}

uint32_t* recibir_solicitud_tarea(int socket_cliente){
	int size;
	int desplazamiento = 0;
	void* buffer;
	uint32_t* trip = malloc(sizeof(uint32_t));

	buffer = recibir_buffer(&size, socket_cliente);

	memcpy(&(trip), (buffer+desplazamiento), sizeof(uint32_t));

	free(buffer);
	return trip;
}

t_movimiento* recibir_movimiento(int socket_cliente);
t_cambio_estado* recibir_cambio_estado(int socket_cliente);
uint32_t* recibir_solicitud_tarea(int socket_cliente);