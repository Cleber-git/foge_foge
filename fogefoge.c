#include "l.c"
#include <time.h>

MAPA m;



void explode_fantasma(POS *person){

    explode_fantasma2(person->x, person->y, 0, 1, 3);
    explode_fantasma2(person->x, person->y, 0, -1, 3);
    explode_fantasma2(person->x, person->y, 1, 0, 3);
    explode_fantasma2(person->x, person->y, -1, 0, 3);
}

void explode_fantasma2( int x, int y, int somax, int somay, int qtd ){

    int novox = x +somax;
    int novoy = y +somay;


    if(qtd == 0) return;
    if (!validar_passo(novox, novoy , &m)) return;

    m.matriz[ novox ][ novoy ] = VAZIO;
    qtd--;
    explode_fantasma2( novox, novoy, somax, somay, qtd );

    
            
            

        
}
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

            explode_fantasma( &person );
            temPilula=0;
        }

        
        fantasma( &m, rl, rc );

    } while (acabou( &m, HEROI ));
    

 

    
    
    fclose(f);
    

    return 0;
}