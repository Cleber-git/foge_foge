#include "l.c"
#include <time.h>

MAPA m;




int main(){


    
    srand( time( NULL ) );

    int rl;
    int rc;


    POS prox;
    le_mapa( &m, "mapa.txt" );
    
    do
    { 
        printf("%s\n", temPilula?"SIM":"NÃO");


        rl = rand() % m.linhas;
        rc = rand() % m.colunas;


        show_map( &m, m.linhas);

        char comando;
        scanf( " %c", &comando );

        

        POS person = find_person( &m, HEROI );
        // printf("%d %d\n", person.x, person.y);
        
        verify_find(&person, comando);
        ehpilula(&m, &person, comando);



        
        // 
        // printf("%d %d\n", person.x, person.y);
        
        move( comando, &m, HEROI );
        if (comando == BOMBA && temPilula)
        {

            explode_fantasma(&m, person.x, person.y, 3);
            temPilula=0;
        }

        
        fantasma( &m, rl, rc );

    } while (acabou( &m, HEROI ));
    

 

    
    
    fclose(f);
    

    return 0;
}