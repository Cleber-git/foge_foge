#include "l.h"

// definindo constantes para o código ficar mais intuitivo

#define HEROI '@'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define ALIMENTO '.'
#define VAZIO ' '
#define SAIR 'q'
#define FANTASMA 'f'


FILE* f;

void fantasma(MAPA *m){

    for ( int i = 0; i < m->linhas; i++ )
    {
        for ( int j = 0; j < m->colunas; j++ )
        {
            if ( m->matriz[ i ][ j ] == FANTASMA)
            {
                if (m->matriz[ i ][ j + 1 ] == HEROI)
                {
                    exit(1);
                }
                if (m->matriz[ i ][ j + 1 ] != PAREDE_HORIZONTAL &
                m->matriz[ i ][ j+1 ] != PAREDE_VERTICAL )
                {
                    m->matriz[ i ][ j ] = ALIMENTO;
                    m->matriz[ i ][ j+1 ] = FANTASMA;
                    break;
                }
                
                
            }
            
        }
        
    }
    


}
void le_mapa(MAPA* m){


    f = fopen( "mapa.txt", "r" );

    fscanf( f, " %d %d\n", &m->linhas, &m->colunas );


    for ( int i = 0; i < 5; i++ )
    {
        

        fscanf( f, " %s", m->matriz[ i ] );

    }
        if ( !f )
    {
        printf( "Erro, não foi possível abrir seu arquivo!\n" );
    }
}


void show_map( MAPA* m ){

    for ( int i = 0; i < 5; i++ )
    {
        printf("%s\n", m->matriz[ i ]);
    }

}


int acabou(){
    return 0;
}


int find_point( MAPA* m ){

    int calculator = 0;

    for ( int i = 0; i < m->linhas; i++ )
    {
        for ( int j = 0; j < m->colunas; j++ )
        {
            if ( m->matriz[i][j] == ALIMENTO )
            {
                calculator++;
            }
            
        }
        
    }
    if ( calculator < 1 ) exit( 1 );

    return 1;
    

}
 void validar_passo( int x, int y, MAPA *m , char direção ){
    
    switch ( direção )
    {

        case CIMA:

        if (  m->matriz[ x - 1 ][ y ] == ALIMENTO || m->matriz[ x - 1 ][ y ] == VAZIO )
        {

                m->matriz[ x-1 ][ y ] = HEROI;
                m->matriz[ x ][ y ] = VAZIO;
        }
            
            break;
            
        case BAIXO:

        if ( m->matriz[ x + 1 ][ y ] == ALIMENTO || m->matriz[ x + 1 ][ y ] == VAZIO )
        {   

                m->matriz[ x + 1 ][ y ] = HEROI;
                m->matriz[ x ][ y ] = VAZIO;
        }
            break;
            
        case DIREITA:

        if ( m->matriz[ x ][ y + 1 ] == ALIMENTO ||  m->matriz[ x ][ y + 1 ] == VAZIO )
        {
                m->matriz[ x ][ y + 1 ] = HEROI;
                m->matriz[ x ][ y ] = VAZIO;
        }

            break;

        case ESQUERDA:

            if ( m->matriz[ x ][ y - 1 ] == ALIMENTO || m->matriz[ x ][ y - 1 ] == VAZIO)
            {
                    m->matriz[ x ][ y - 1 ] = HEROI;
                    m->matriz[ x ][ y ] = VAZIO;

            }

            break;

        case SAIR:
        
            exit( 1 );
            break;

    }
}

void move( int direção, MAPA* m ){

    int x;
    int y;

    
        
    for ( int i = 0; i < 5; i++ )
    {
        for ( int j = 0; j < m->colunas; j++ )
        {
            if ( m->matriz[ i ][ j ] == HEROI )
            {
                x = i;
                y = j;
                break;
            }
        }
        
    }
    validar_passo( x, y, m, direção );


}

// comentei por não está usando alocação dinâmica


// void libera_mapa(){
    
//     free(m->matriz);

//     for (int i = 0; i < 5; i++)
//     {
//         free(m->matriz[i]);
//     }

// }


// void aloca_mapa(){

//     m->matriz = malloc(sizeof(char*) * 5 );
//     for (int i = 0; i < 5; i++)
//     {
//         m->matriz[i] = malloc(sizeof(char) * (m->colunas +1));
//     }

// }



