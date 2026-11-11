#include "cobra.h"


void inicializa_cobra(Cobra *c)
{
    c->tamanho = 3;

    c->corpo[0].x = 10;
    c->corpo[0].y = 10;

    c->corpo[1].x = 9;
    c->corpo[1].y = 10;

    c->corpo[2].x = 8;
    c->corpo[2].y = 10;
}


int verifica_colisao(Cobra *c)
{
    int i;
    for(i = 1; i < c->tamanho; i++)
    {
        if(c->corpo[0].x == c->corpo[i].x && c->corpo[0].y == c->corpo[i].y)
        {
            return 1; 
        }
    }
    return 0;
}