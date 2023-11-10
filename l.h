#ifndef _L_H_
#define _L_H_

#include "l.c"

#include <stdlib.h>
#include <time.h>













int ehvalida( MAPA* m,int x, int y);

void mostrarMaior( char desenho[4][7] ,int part  );
void move( char direção, MAPA* m, char personagem );


// void aloca_mapa(MAPA* m );

void le_mapa( MAPA *m, char *Nmap );
POS find_person( MAPA* m, char person );

// void libera_mapa(MAPA* m);

void show_map( MAPA *m );

int acabou(MAPA* m, char avatar);

int validar_passo( int x, int y, MAPA *m );

void fantasma( MAPA *m, int rlinhas, int rcolunas );
void explode_fantasma(POS *person);
void explode_fantasma2( int x, int y, int somax, int somay, int qtd );
void verify_find(POS* p, char command);
int ehpilula( MAPA* m, POS* per, char command );
int validar_comando(char command);


char desenhoparede[4][7];

char desenhoheroi[4][7];

char desenhofantasma[4][7];

char desenhopilula[4][7];

char desenhovazio[4][7];

#endif