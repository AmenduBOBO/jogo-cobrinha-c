#ifndef ENTRADA_H
#define ENTRADA_H

int ler_linha(const char *pergunta,
              char *destino,
              int tamanho);

int ler_inteiro(const char *pergunta,
                int minimo,
                int maximo,
                int *valor);

#endif