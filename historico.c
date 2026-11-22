#include <stdio.h>
#include <string.h>
#include "historico.h"

void salvar_historico(
    const char nome[],
    int pontos)
{
    FILE *arquivo;

    arquivo = fopen(
        "historico.txt",
        "a");

    if(arquivo == NULL)
    {
        return;
    }

    fprintf(
        arquivo,
        "%s %d\n",
        nome,
        pontos);

    fclose(arquivo);
}

//////////////////////////////

void mostrar_historico(void)
{
    FILE *arquivo;
    char nome[16];
    int pontos;
    int quantidade = 0;
    int soma = 0;
    int maior = 0;
    char recordista[16] = "---";

    arquivo = fopen(
        "historico.txt",
        "r");

    if(arquivo == NULL)
    {
        printf(
            "\nNenhum historico encontrado.\n");

        return;
    }

    printf(
        "\n===== HISTORICO =====\n");

    while(
    fscanf(
        arquivo,
        "%15s %d",
        nome,
        &pontos) == 2)
{
    quantidade++;

    soma += pontos;

    if(pontos > maior)
{
    maior = pontos;

    strcpy(
        recordista,
        nome);
}

    printf(
        "%s - %d pontos\n",
        nome,
        pontos);
}
printf("\n");

printf(
    "Partidas registradas: %d\n",
    quantidade);

printf(
    "Maior pontuacao: %d\n",
    maior);

printf(
    "Recordista: %s\n",
    recordista);
    
if(quantidade > 0)
{
    printf(
        "Media de pontos: %d\n",
        soma / quantidade);
}

    printf(
        "=====================\n");

    fclose(arquivo);
}