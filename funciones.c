    //Funcion para limpiar '\n'
    void limpiarN (char variable[]){
        for(int i = 0; variable[i] != '\0'; i++){
            if(variable[i] == '\n'){
                variable[i] = '\0';
                break;
            }
        }
    }

    //Funcion para calcular la longitud
    int longitud (char variable[]){
        int i;
        for(i = 0; variable[i] != '\0'; i++);
        return i;
    }








