#include <stdio.h>

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


void mostrar_historico(void)
{
    FILE *arquivo;

    char nome[16];

    int pontos;

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
        printf(
            "%s - %d pontos\n",
            nome,
            pontos);
    }

    printf(
        "=====================\n");

    fclose(arquivo);
}