#ifndef COBRA_H
#define COBRA_H

typedef struct
{
    int x;
    int y;
} Segmento;

typedef struct
{
    Segmento corpo[100];
    int tamanho;
} Cobra;

void inicializa_cobra(Cobra *c);
int verifica_colisao(Cobra *c);

#endif