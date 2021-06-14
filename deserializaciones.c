
t_buffer* serilizar_desplazamiento(uint32_t tid, uint32_t x_nuevo, uint32_t y_nuevo)

typedef struct{
	uint32_t pid;
	uint32_t x;
    uint32_t y;
}t_movimiento;

t_movimiento* recibir_pcb(int socket_cliente){
	int size;
	int desplazamiento = 0;
	void* buffer;
	t_movimiento* mov = malloc(sizeof(t_movimiento));

	buffer = recibir_buffer(&size, socket_cliente);

	memcpy(&(mov->pid), (buffer+desplazamiento), sizeof(uint32_t));
	desplazamiento+=sizeof(uint32_t);

	memcpy(&(mov->x), buffer+desplazamiento, sizeof(uint32_t));
	desplazamiento+=sizeof(uint32_t);

	memcpy(&(mov->y), buffer+desplazamiento, sizeof(uint32_t));
	desplazamiento+=sizeof(uint32_t);

	free(buffer);
	return mov;
}