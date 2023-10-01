#include "l.c"
#include <stdio.h>
#include <stdlib.h>

    MAPA m;

int main(){
    
    
    le_mapa(&m);
    
    do
    { 
          
        show_map(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando, &m);

    } while (!acabou());
    

 

    
    
    fclose(f);
    

    return 0;
}