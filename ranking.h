#ifndef RANKING_H
#define RANKING_H


typedef struct
{
    char nome[16];
    int pontos;
} Jogador;


void carregar_ranking(Jogador ranking[]);
void salvar_ranking(Jogador ranking[]);
void atualizar_ranking(Jogador ranking[],
                       char nome[],
                       int pontos);

void mostrar_ranking(Jogador ranking[]);

#endif