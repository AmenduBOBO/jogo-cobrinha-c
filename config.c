#include <stdio.h>
#include "config.h"


void carregar_config(Config *config)
{
    FILE *arquivo;

    arquivo = fopen("config.txt", "r");

    config->velocidade = 160;

    if(arquivo == NULL)
    {
        return;
    }

    fscanf(arquivo,
           "velocidade=%d",
           &config->velocidade);

    fclose(arquivo);
}