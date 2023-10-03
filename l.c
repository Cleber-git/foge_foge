

#include "l.h"

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'


void le_mapa(MAPA* m){


    f = fopen("mapa.txt", "r");

    fscanf(f, " %d %d\n", &m->linhas, &m->colunas);


    for (int i = 0; i < 5; i++)
    {
        

        fscanf(f, " %s", m->matriz[i]);

    }
        if (!f)
    {
        printf("Erro, não foi possível abrir seu arquivo!\n");
    }
}


void show_map(MAPA* m){

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", m->matriz[i]);
    }

}


int acabou(){
    return 0;
}


int find_point(MAPA* m){

    int calculator = 0;

    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            if (m->matriz[i][j] == '.')
            {
                calculator++;
            }
            
        }
        
    }
    if ( calculator < 1 ) exit(1);

    return 1;
    

}

void validar_passo(int x, int y, MAPA *m , char direção){
    
    switch (direção)
    {

        case CIMA:

        if (  m->matriz[x-1][y] == '.' || m->matriz[x-1][y] == ' ')
        {

                m->matriz[x-1][y] = '@';
                m->matriz[x][y] = ' ';
        }

        if (m->matriz[x-1][y] == 'u')
                    {
                        printf("O fantasma te encontrouuu, você perdeu!\n");
                        exit(1);
                    }
            
            break;
            
        case BAIXO:

        if (m->matriz[x+1][y] == '.' || m->matriz[x+1][y] == ' ')
        {   

                m->matriz[x+1][y] = '@';
                m->matriz[x][y] = ' ';
        }
            break;
            
        case DIREITA:

        if ( m->matriz[x][y+1] == '.' ||  m->matriz[x][y+1] == ' ')
        {
                m->matriz[x][y+1] = '@';
                m->matriz[x][y] = ' ';
        }
        if (m->matriz[x][y+1] == 'u')
                    {
                        printf("O fantasma te encontrouuu, você perdeu!\n");
                        exit(1);
                    }

            break;

        case ESQUERDA:

            if ( m->matriz[x][y-1] == '.' || m->matriz[x][y-1] == ' ')
            {
                    m->matriz[x][y-1] = '@';
                    m->matriz[x][y] = ' ';

            }
            if (m->matriz[x][y-1] == 'u')
                    {
                        printf("O fantasma te encontrouuu, você perdeu!\n");
                        exit(1);
                    }
            break;

        case 'q':
        
            exit(1);
            break;

    }
}

void move(int direção, MAPA* m){

    int x;
    int y;

    
        
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            if (m->matriz[i][j] == '@')
            {
                x = i;
                y = j;
                break;
            }
        }
        
    }
    validar_passo(x, y, m, direção);


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
}


