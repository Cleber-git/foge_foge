#include "l.c"
#include <time.h>


    MAPA m;

int main(){

    srand( time( NULL ) );

    int rl;
    int rc;


    
    le_mapa( &m, "map2.txt" );
    
    do
    { 



        rl = rand() % m.linhas;
        rc = rand() % m.colunas;

        
        
        // debug para ver o funcionamento da aleatoriedade da movimentação
        printf( "%d %d\n", rl, rc );
        show_map( &m, m.linhas);

        char comando;
        scanf( " %c", &comando );

        move( comando, &m );
        fantasma( &m, rl, rc );

        
        

    } while (!acabou());
    

 

    
    
    fclose(f);
    

    return 0;
}