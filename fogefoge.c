#include "l.c"


    MAPA m;

int main(){
    
    
    le_mapa(&m);
    
    do
    { 
          
        show_map(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando, &m);
        find_point(&m);
        fantasma(&m);

    } while (!acabou());
    

 

    
    
    fclose(f);
    

    return 0;
}