#ifndef _L_C_
#define _L_C_

#include <stdio.h>
#include <stdlib.h>
#include "l.h"



#define HEROI '@'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define VAZIO '.'
#define SAIR 'q'
#define FANTASMA 'f'
#define BOMBA 'b'
#define PILULA 'p'
#define PERDEU "========== O fantasma te encontrou ==========\n"
#define GANHOU "********** !! VOCÊ VENCEU !! **********\n"

int temPilula = 0;
int qtd_p = 0;

char desenhoparede[ 4 ][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char desenhofantasma[ 4 ][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char desenhoheroi[ 4 ][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char desenhopilula[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char desenhovazio[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};









struct mapa{
    int linhas;
    int colunas;
    char matriz[6][10+1];
};

struct posição
{

    int x;
    int y;

};
typedef struct mapa MAPA;

typedef struct posição POS;


FILE* f;

POS pos;

void mostrarMaior( char desenho[4][7] ,int part  ){

    
    printf("%s", desenho[part]);
        

}

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





void show_map( MAPA* m )
{

    for ( int i = 0; i < m->linhas; i++ )
    {

        for ( int parte = 0; parte < 4; parte++ )
        {
            for ( int j = 0; j < m->colunas + 1; j++ )
            {
                switch ( m->matriz[i][j] )
                {

                case FANTASMA:
                    mostrarMaior( desenhofantasma, parte );
                    break;

                case HEROI:
                    mostrarMaior( desenhoheroi, parte );
                    break;

                case PILULA:
                    mostrarMaior( desenhopilula, parte );
                    break;

                case PAREDE_HORIZONTAL:
                    mostrarMaior( desenhoparede, parte );
                    break;
                    
                case PAREDE_VERTICAL:
                    mostrarMaior( desenhoparede, parte );
                    break;

                case VAZIO:
                    mostrarMaior( desenhovazio, parte );
                    break;
                
                default:
                    break;
                    
                }
            }
            
            printf( "\n" );
        }
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

int ehpilula( MAPA* m, POS* per, char command ){

    POS hero = find_person(m, HEROI);
    // printf("%d %d\n", hero.x, hero.y);

    verify_find(&hero, command);

    if(m->matriz[ hero.x ][ hero.y ] == PILULA ){
        
        temPilula += 1;
        qtd_p += 1;

        return 1;
    }

    return 0;

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
                m->matriz[ pos.x ][ pos.y ] =  VAZIO;

            }else if ( m->matriz[ posx ][ posy ] == FANTASMA  )
            {

                show_map( m );
                m->matriz[ pos.x ][ pos.y ] =  VAZIO;
                printf( "%s", PERDEU );
                
            }
        }
    }

    
        


}

int ehvalida( MAPA* m, int x, int y){
    if ( x >= m->linhas || y >= m->colunas) return 0;

    return 1;

    
}


void fantasma( MAPA *m, int rlinhas, int rcolunas )
{

    for ( int i = 0; i < m->linhas; i++ )
    {

        for ( int j = 0; j < m->colunas + 1; j++ )
        {

            if ( m->matriz[ i ][ j ] == FANTASMA )
            {

                if ( validar_passo( rlinhas, rcolunas, m )  )
                {

                    if ( m->matriz[ rlinhas ][ rcolunas ] != HEROI && ehvalida( m,rlinhas, rcolunas) )
                    {

                        m->matriz[ i ][ j ] =  VAZIO;
                        m->matriz[ rlinhas ][ rcolunas ] = FANTASMA;
                        
                    }else if(m->matriz[ rlinhas ][ rcolunas ] == HEROI)
                    {

                        m->matriz[ i ][ j ] =  VAZIO;
                        m->matriz[ rlinhas ][ rcolunas ] = FANTASMA;  
                        show_map( m );
                        printf("%s\n", PERDEU);

                    }

                }  
                
            }
            
        }
        
    }

}



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




// char desenhoParede[4][7] = {
//     {"......"},
//     {"......"},
//     {"......"},
//     {"......"}
// };


// char desenhoHeroi[4][7] = {
// 	{" .--. "  },
// 	{"/ _.-'"  },
// 	{"\\  '-." },
// 	{" '--' "  }
// };

// char desenhoFantasma[4][7] = {
// 	{" .-.  " },
// 	{"| OO| " },
// 	{"|   | " },
// 	{"'^^^' " }
// };


// char desenhoPilula[4][7] = {
// 	{"      "},
// 	{" .-.  "},
// 	{" '-'  "},
// 	{"      "}
// };


// char desenhoVazio[4][7] = {
//     {"      "},
//     {"      "},
//     {"      "},
//     {"      "}

// };




#endif
