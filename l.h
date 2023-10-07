#include <stdio.h>
#include <stdlib.h>


struct mapa
{
    char matriz[ 5 ][ 10 + 1 ];
    int linhas;
    int colunas;
};



typedef struct mapa MAPA;





void move( char direção, MAPA* m );

int find_point( MAPA *m );

// void aloca_mapa(MAPA* m );

void le_mapa( MAPA *m, char *Nmap );

// void libera_mapa(MAPA* m);

void show_map( MAPA *m, int r );

int acabou();

int validar_passo( int x, int y, MAPA *m );

void fantasma( MAPA *m, int rlinhas, int rcolunas );

int find_heroi( MAPA *m );

int isRun( MAPA *m );




