struct mapa
{
    char matriz[5][10+1];
    int linhas;
    int colunas;
};

FILE* f;

typedef struct mapa MAPA;

void move(int direção, MAPA* m);

int find_point(MAPA *m);

// void aloca_mapa(MAPA* m );

void le_mapa(MAPA* m);

// void libera_mapa(MAPA* m);

void show_map(MAPA* m);

int acabou();

// move fantasma





