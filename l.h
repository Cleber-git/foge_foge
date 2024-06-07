#pragma once

#include "type.h"

#include <stdlib.h>
#include <time.h>

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









int ehvalida( MAPA* m,int x, int y);

void mostrarMaior( char desenho[4][7] ,int part  );
void move( char direção, MAPA* m, char personagem );


// void aloca_mapa(MAPA* m );

void le_mapa( MAPA *m, char *Nmap, FILE* f );
POS find_person( MAPA* m, char person );


// void libera_mapa(MAPA* m);

void show_map( MAPA *m );

int acabou(MAPA* m, char avatar);

int validar_passo( int x, int y, MAPA *m );

void fantasma( MAPA *m, int rlinhas, int rcolunas );
void explode_fantasma(POS *person);
void explode_fantasma2( int x, int y, int somax, int somay, int qtd );
void verify_find(POS* p, char command);
int ehpilula( MAPA* m, POS* per, char commandl, int *tp, int * qtd );
int validar_comando(char command);


// char desenhoparede[4][7];

// char desenhoheroi[4][7];

// char desenhofantasma[4][7];

// char desenhopilula[4][7];

// char desenhovazio[4][7];

