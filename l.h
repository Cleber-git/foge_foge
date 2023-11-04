#include <stdio.h>
#include <stdlib.h>


struct mapa
{
    char matriz[ 5 ][ 10 + 1 ];
    int linhas;
    int colunas;
};

struct posição
{

    int x;
    int y;
};

typedef struct mapa MAPA;

typedef struct posição POS;





void move( char direção, MAPA* m, char personagem );

POS find_person( MAPA *m, char person );

// void aloca_mapa(MAPA* m );

void le_mapa( MAPA *m, char *Nmap );

// void libera_mapa(MAPA* m);

void show_map( MAPA *m, int r );

int acabou(MAPA* m, char avatar);

int validar_passo( int x, int y, MAPA *m );

void fantasma( MAPA *m, int rlinhas, int rcolunas );

void explode_fantasma(MAPA *m, int x, int y);
void verify_find(POS* p, char command);
int ehpilula( MAPA* m, POS* per, char command );
int validar_comando(char command);