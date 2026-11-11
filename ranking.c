#include <stdio.h>
#include <string.h>
#include "ranking.h"


void carregar_ranking(Jogador ranking[])
{
    FILE *arquivo;

    int i;

    arquivo = fopen("ranking.txt", "r");

    if(arquivo == NULL)
    {
        for(i = 0; i < 5; i++)
        {
            strcpy(ranking[i].nome, "---");
            ranking[i].pontos = 0;
        }

        return;
    }

    for(i = 0; i < 5; i++)
    {
        fscanf(arquivo,
               "%15s %d",
               ranking[i].nome,
               &ranking[i].pontos);
    }

    fclose(arquivo);
}

//////////////////////////////

void salvar_ranking(Jogador ranking[])
{
    FILE *arquivo;

    int i;

    arquivo = fopen("ranking.txt", "w");

    if(arquivo == NULL)
    {
        return;
    }

    for(i = 0; i < 5; i++)
    {
        fprintf(arquivo,
                "%s %d\n",
                ranking[i].nome,
                ranking[i].pontos);
    }

    fclose(arquivo);
}

//////////////////////////////


void atualizar_ranking(Jogador ranking[],
                       char nome[],
                       int pontos)
{
    int i;

    int j;

    if(pontos <= ranking[4].pontos)
    {
        return;
    }

    strcpy(ranking[4].nome,
           nome);

    ranking[4].pontos = pontos;

    for(i = 4; i > 0; i--)
    {
        if(ranking[i].pontos >
           ranking[i - 1].pontos)
        {
            Jogador temp;

            temp = ranking[i];

            ranking[i] = ranking[i - 1];

            ranking[i - 1] = temp;
        }
    }
}

//////////////////////////////

void mostrar_ranking(Jogador ranking[])
{
    int i;

    printf("\n===== RANKING =====\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d. %s - %d\n",
               i + 1,
               ranking[i].nome,
               ranking[i].pontos);
    }

    printf("===================\n");
}

//////////////////////////////

void resetar_ranking(Jogador ranking[])
{
    int i;

    for(i = 0; i < 5; i++)
    {
        strcpy(ranking[i].nome, "---");
        ranking[i].pontos = 0;
    }

    salvar_ranking(ranking);
}