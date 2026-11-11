#ifndef CONFIG_H
#define CONFIG_H


typedef struct
{
    int velocidade;
} Config;


void carregar_config(Config *config);

#endif