
char estado_a_char(int estado){
   switch(estado){
    case e_llegada:
        return 'N';
        break;
    case e_listo:
        return 'R';
        break;
    case e_fin:
        return 'E';
        break;
    case e_trabajando:
        return 'W';
        break;
    case e_bloqueado_IO:
        return 'B';
        break;
    case e_bloqueado_emergencia:
        return 'B';
        break;
   }
}