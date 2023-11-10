#include <stdio.h>

#include "l.h"


MAPA m;




void explode_fantasma(POS *person){

    if(!temPilula) return;

    explode_fantasma2(person->x, person->y, 0, 1, 3);
    explode_fantasma2(person->x, person->y, 0, -1, 3);
    explode_fantasma2(person->x, person->y, 1, 0, 3);
    explode_fantasma2(person->x, person->y, -1, 0, 3);
    temPilula--;
    qtd_p--;
    
}

void explode_fantasma2( int x, int y, int somax, int somay, int qtd ){

    int novox = x +somax;
    int novoy = y +somay;


    if(qtd == 0) return;
    if (!validar_passo(novox, novoy , &m)) return;

    m.matriz[ novox ][ novoy ] =  VAZIO;
    qtd--;
    explode_fantasma2( novox, novoy, somax, somay, qtd );

}

int main(){


    srand( time( NULL ) );
    int rl;
    int rc;


    le_mapa( &m, "mapa.txt" );
    
    do
    { 
        for(int i = 0; i < qtd_p; i++)
        {
            if(qtd_p > 0){
                printf("%s", temPilula?"°":"*");
                
            }
        }
        printf("\n");

        


        rl = rand() % m.linhas;
        rc = rand() % m.colunas;



        // rl2 = rand() % (m.linhas +1);
        // rc2 = rand() % (m.colunas + 1);

        show_map( &m );

        char comando;
        scanf( " %c", &comando );

        POS person;

        person = find_person( &m, HEROI );
        
        verify_find(&person, comando);
        ehpilula(&m, &person, comando);



        
        
        move( comando, &m, HEROI );
        if (comando == BOMBA && temPilula)
        {

            explode_fantasma( &person );
            
        }

        fantasma( &m, rl, rc );

    } while (acabou( &m, HEROI ));
    

 

    
    
    fclose(f);
    

    return 0;
}