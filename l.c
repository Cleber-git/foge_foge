#include "l.h"
#include <time.h>


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
#define BOMBA 'b'
#define PILULA 'p'
#define PERDEU "========== O fantasma te encontrou ==========\n"
#define GANHOU "********** !! VOCÊ VENCEU !! **********\n"

int temPilula = 0;




FILE* f;

POS pos;
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
        printf( "%s\n", m->matriz[ i ] );
    }

}


int acabou(MAPA* m, char avatar)
{
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas + 1; j++)
        {
            if ( m->matriz[ i ][ j ] == avatar )
            {
                
                return 1;

            }
            
        }
        
    

    }

    return 0;
    

    
}

void verify_find(POS* p, char command){

    switch (command)
    {
        case CIMA:
            p->x += -1;
            break;
        case BAIXO:
            p->x += 1;
            break;
        case ESQUERDA:
            p->y += -1;
            break;
        case DIREITA:
            p->y += 1;
            break;
        default:
            break;
    }

}

int ehpilula( MAPA* m, POS* per, char command ){

    POS hero = find_person(m, HEROI);
    // printf("%d %d\n", hero.x, hero.y);

    verify_find(&hero, command);

    if(m->matriz[ hero.x ][ hero.y ] == PILULA ){
        
        temPilula=1;

        return 1;
    }

    return 0;

}


POS find_person( MAPA* m, char person )
{

    POS per;
    
    for ( int i = 0; i < m->linhas; i++ )
    {

        for ( int j = 0; j < m->colunas + 1 ; j++ )
        {

            if ( m->matriz[ i ][ j ] == person )
            {

                per.x = i;
                per.y = j;
                break;

            }
        }
        
    }

    return per;
    

}

// int find_bomba(MAPA* m){
//     int x
//     int y
//     if( m->matriz[x][y] == BOMBA ){




//     }


// }

int validar_passo( int x, int y, MAPA *m  )
{


    if ( m->matriz[ x ][ y ] != PAREDE_HORIZONTAL 
      && m->matriz[ x ][ y ] != PAREDE_VERTICAL )
    {

        return 1;
        
    }
    return 0;


}

int validar_comando(char command){

    if (command != CIMA && command != BAIXO && command != ESQUERDA && command != DIREITA && command != BOMBA)
    {
        return 0;
    }
    return 1;
}


void move( char direção, MAPA* m, char personagem )
{


    int posx;
    int posy;
    

    for ( int i = 0; i < m->linhas; i++ )
    {

        for ( int j = 0; j < m->colunas; j++ )
        {

            if ( m->matriz[ i ][ j ] == personagem )
            {

                pos.x = i;
                pos.y = j;
                break;
                
            }

        }
        
    }




    posx = pos.x;
    posy = pos.y;

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
        default:
            break;


    
    }

    if( validar_passo( posx, posy, m ) )
    {

        
        if ( personagem == HEROI )
        {

            if ( m->matriz[ posx ][ posy ] != FANTASMA && direção != BOMBA && validar_comando(direção) )//&& validar_comando(direção)
            {
                
                m->matriz[ posx ][ posy ] = personagem;
                m->matriz[ pos.x ][ pos.y ] = VAZIO;

            }else if ( m->matriz[ posx ][ posy ] == FANTASMA  )
            {
                show_map( m, m->linhas );
                m->matriz[ pos.x ][ pos.y ] = VAZIO;
                printf( "%s", PERDEU );

                
            }
        }
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

                if ( validar_passo( rlinhas, rcolunas, m ) )
                {

                    if ( m->matriz[ rlinhas ][ rcolunas ] != HEROI )
                    {
                        m->matriz[ i ][ j ] = ALIMENTO;
                        m->matriz[ rlinhas ][ rcolunas ] = FANTASMA;
                        

                    }else
                    {

                        m->matriz[ i ][ j ] = ALIMENTO;
                        m->matriz[ rlinhas ][ rcolunas ] = FANTASMA;  
                        show_map(m, m->linhas);
                        printf("%s\n", PERDEU);

                    }
                }
                    

                   
                
            }
            
        }
        
    }
    


}

    // show_map(m, m->linhas);

    







// comentei por não está usando alocação dinâmica


// void libera_mapa(){
    
//     free(m->matriz);

//     for ( int i = 0; i < 5; i++ )
//     {
//         free( m->matriz[ i ] );
//     }

// }


// void aloca_mapa(){

//     m->matriz = malloc( sizeof( char* ) * 5 );
//     for ( int i = 0; i < 5; i++ )
//     {
//         m->matriz[ i ] = malloc( sizeof( char ) * ( m->colunas +1 ) );
//     }

// }



