#include "l.h"

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
#define PERDEU "========== O fantasma te encontrou ==========\n"
#define GANHOU "********** !! VOCÊ VENCEU !! **********\n"



FILE* f;


void le_mapa(MAPA* m, char * Nmap)
{
    
    f = fopen( Nmap, "r" );

    fscanf( f, " %d %d\n", &m->linhas, &m->colunas );


    for ( int i = 0; i < m->linhas; i++ )
    {
        
        fscanf( f, " %s", m->matriz[ i ] );

    }
        if ( !f )
    {
        printf( "Erro, não foi possível abrir seu arquivo!\n" );
    }
}


void show_map( MAPA* m , int r )
{

    for ( int i = 0; i < r; i++ )
    {
        printf("%s\n", m->matriz[ i ]);
    }

}


int acabou()
{
    return 0;
}


int find_point( MAPA* m )
{

    int calculator = 0;

    for ( int i = 0; i < m->linhas; i++ )
    {
        for ( int j = 0; j < m->colunas; j++ )
        {
            if ( m->matriz[ i ][ j ] == ALIMENTO )
            {
                calculator++;
            }
            
        }
        
    }
    if ( !calculator ) {
        
        printf( "%s", GANHOU );
        exit( 1 );
    };

    return 1;
    

}

int validar_passo( int x, int y, MAPA *m  )
{


    if ( m->matriz[ x ][ y ] != PAREDE_HORIZONTAL 
      && m->matriz[ x ][ y ] != PAREDE_VERTICAL )
    {

        return 1;
        
    }
    return 0;


}

void move( char direção, MAPA* m )
{

    int x;
    int y;
    int posx;
    int posy;
    
    if ( !isRun )
    {
        exit( 1 );
    }


    for ( int i = 0; i < m->linhas; i++ )
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




    posx = x;
    posy = y;

    switch ( direção )
    {

        case CIMA:
            posx--;
            break;
            
        case BAIXO:
            posx++;
            break;
            
        case DIREITA:
            posy++;
            break;

        case ESQUERDA:
            posy--;
            break;

        case SAIR:
            exit( 1 );
            break;
    
    }

    if( validar_passo( posx, posy, m ) )
    {

        if ( m->matriz[ x ][ y ] == FANTASMA )
        {
            m->matriz[ posx ][ posy ] = FANTASMA;   
            show_map( m , m->linhas);
            printf( "%s", PERDEU );
            exit( 1 );
        }
        
        m->matriz[ posx ][ posy ] = HEROI;
        m->matriz[ x ][ y ] = VAZIO;

    }

}


void fantasma( MAPA *m, int rlinhas, int rcolunas )
{

    for ( int i = 0; i < m->linhas; i++ )
    {

        for ( int j = 0; j < m->colunas; j++ )
        {

            if ( m->matriz[ i ][ j ] == FANTASMA )
            {

                if ( m->matriz[ i ][ j + 1 ] == HEROI )
                {
                    printf("%s", PERDEU );
                    exit( 1 );
                }

                if ( m->matriz[ rlinhas ][ rcolunas ] != PAREDE_HORIZONTAL &
                     m->matriz[ rlinhas ][ rcolunas ] != PAREDE_VERTICAL )
                {

                    m->matriz[ i ][ j ] = ALIMENTO;
                    m->matriz[ rlinhas ][ rcolunas ] = FANTASMA;
                    break;

                }
                
            }
            
        }
        
    }
    


}

int isRun( MAPA *m )
{

   if ( find_heroi( m ) &&
        find_point( m ))
   {
        return 1;
   }
   return 0;
   
}

int find_heroi( MAPA *m )
{
    
    
    int find = 0;

    for (int i = 0; i < m->linhas; i++)
    {

        for (int j = 0; j < m->colunas; j++)
        {
            
            if ( m->matriz[ i ][ j ] == HEROI )
            {

                find++;
            
            }
            
        }
        
    }
    if( !find ){
        printf( "%c ", PERDEU );
        exit( 1 );
    }
    return 1;

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



