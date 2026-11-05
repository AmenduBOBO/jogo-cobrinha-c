#include <stdio.h>
#include <string.h>
#include "entrada.h"

int ler_linha(const char *pergunta,
              char *destino,
              int tamanho)
{
    int c;

    printf("%s", pergunta);

    fflush(stdout);

    if(fgets(destino, tamanho, stdin) == NULL)
    {
        return 0;
    }

    if(strchr(destino, '\n') == NULL)
    {
        while((c = getchar()) != '\n' &&
              c != EOF)
        {
        }
    }
    else
    {
        destino[strcspn(destino, "\n")] = '\0';
    }

    return 1;
}

int ler_inteiro(const char *pergunta,
                int minimo,
                int maximo,
                int *valor)
{
    char linha[32];

    int numero;

    char sobra;

    while(1)
    {
        if(!ler_linha(pergunta,
                      linha,
                      sizeof(linha)))
        {
            return 0;
        }

        if(sscanf(linha,
                  "%d %c",
                  &numero,
                  &sobra) != 1)
        {
            fprintf(stderr,
                    "Digite apenas um numero inteiro.\n");

            continue;
        }

        if(numero < minimo ||
           numero > maximo)
        {
            fprintf(stderr,
                    "O valor deve estar entre %d e %d.\n",
                    minimo,
                    maximo);

            continue;
        }

        *valor = numero;

        return 1;
    }
}