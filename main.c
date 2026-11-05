// -------- INCLUDES --------

#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h> 
#include <mmsystem.h>
#include "cobra.h"
#include "entrada.h"
#include <string.h>

// -------- DEFINES --------

#define LINHAS 20
#define COLUNAS 20
#define DIREITA 0
#define ESQUERDA 1
#define CIMA 2
#define BAIXO 3

// -------- ESTADO DO JOGO --------

Cobra cobra;
int direcao = DIREITA;
int pontuacao = 0;
int game_over = 0;
int pausado = 0;
int velocidade = 160;
int comida_x;
int comida_y;
char nome_jogador[16];
int dificuldade = 2;

// -------- COMIDA --------

void gera_comida(void)
{
    comida_x = rand() % COLUNAS;
    comida_y = rand() % LINHAS;
}


void desenha_comida(void)
{
    float tamanho;
    float x;
    float y;

    tamanho = 2.0f / COLUNAS;
    x = -1.0f + comida_x * tamanho;
    y = -1.0f + comida_y * tamanho;

    glColor3f(0.0f, 0.4f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + tamanho, y);
        glVertex2f(x + tamanho, y + tamanho);
        glVertex2f(x, y + tamanho);
    glEnd();
}


// -------- DESENHO DA COBRA --------

void desenha_cobra(void)
{
    int i;
    float x;
    float y;
    float tamanho;

    tamanho = 2.0f / COLUNAS;
    glColor3f(1.0f, 0.5f, 0.0f);

    for(i = 0; i < cobra.tamanho; i++)
    {
        x = -1.0f + cobra.corpo[i].x * tamanho;
        y = -1.0f + cobra.corpo[i].y * tamanho;

        glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + tamanho, y);
            glVertex2f(x + tamanho, y + tamanho);
            glVertex2f(x, y + tamanho);
        glEnd();
    }
}


// -------- REINICIO --------

void reinicia_jogo(void)
{
    inicializa_cobra(&cobra); 
    direcao = DIREITA;  
    pontuacao = 0;  
    pausado = 0;    
    gera_comida();
    game_over = 0;
}


// -------- MOVIMENTO E COLISOES --------

void move_cobra(void)
{
    int i;

    if (pausado || game_over) return;

    for(i = cobra.tamanho - 1; i > 0; i--)
    {
        cobra.corpo[i] = cobra.corpo[i - 1];
    }

    if(direcao == DIREITA) cobra.corpo[0].x++;
    else if(direcao == ESQUERDA) cobra.corpo[0].x--;
    else if(direcao == CIMA) cobra.corpo[0].y++;
    else if(direcao == BAIXO) cobra.corpo[0].y--;
    
    
    if(verifica_colisao(&cobra))
    {
        PlaySound(TEXT("sons/colisao.wav"), NULL, SND_ASYNC | SND_FILENAME);
        game_over = 1;
        return; 
    }

    
    if(cobra.corpo[0].x >= COLUNAS || cobra.corpo[0].x < 0 ||
       cobra.corpo[0].y >= LINHAS || cobra.corpo[0].y < 0)
    {
        PlaySound(TEXT("sons/colisao.wav"), NULL, SND_ASYNC | SND_FILENAME);
        game_over = 1;
        return;
    }


    if(cobra.corpo[0].x == comida_x && cobra.corpo[0].y == comida_y)
    {
        
        PlaySound(TEXT("sons/comida.wav"), NULL, SND_ASYNC | SND_FILENAME);
        
        cobra.corpo[cobra.tamanho] = cobra.corpo[cobra.tamanho - 1];
        cobra.tamanho++;
        pontuacao += 20;
        gera_comida();
    }

    char titulo[50];
    sprintf(titulo, "Jogo da Cobrinha - Pontuacao: %d", pontuacao);
    glutSetWindowTitle(titulo);
}


void timer(int valor)
{
    move_cobra();
    glutPostRedisplay();
    glutTimerFunc(velocidade, timer, 0);
}


// -------- CONTROLES TECLADO E MOUSE --------

void teclado_especial(int tecla, int x, int y)
{
    if(tecla == GLUT_KEY_RIGHT && direcao != ESQUERDA) direcao = DIREITA;
    else if(tecla == GLUT_KEY_LEFT && direcao != DIREITA) direcao = ESQUERDA;
    else if(tecla == GLUT_KEY_UP && direcao != BAIXO) direcao = CIMA;
    else if(tecla == GLUT_KEY_DOWN && direcao != CIMA) direcao = BAIXO;
}


void teclado_normal(unsigned char tecla, int x, int y)
{
    if(tecla == 27)
    {
        exit(0);
    }

    if(game_over)
    {
        return;
    }

    if(tecla == 'p' || tecla == 'P')
    {
        pausado = !pausado;

        PlaySound(TEXT("sons/pause.wav"), NULL, SND_ASYNC | SND_FILENAME);
    }
}



void clique_mouse(int botao, int estado, int x, int y)
{
    if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && game_over)
    {
        reinicia_jogo();
    }
}


// -------- GRADE --------

void desenha_grade(void)
{
    int i;
    float x;
    float y;

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_LINES);

    for(i = 0; i <= COLUNAS; i++)
    {
        x = -1.0f + (2.0f * i / COLUNAS);
        glVertex2f(x, -1.0f);
        glVertex2f(x, 1.0f);
    }
    for(i = 0; i <= LINHAS; i++)
    {
        y = -1.0f + (2.0f * i / LINHAS);
        glVertex2f(-1.0f, y);
        glVertex2f(1.0f, y);
    }
    glEnd();
}


// -------- TELA --------

void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    desenha_grade();
    desenha_comida();
    desenha_cobra();
    glutSwapBuffers();
}

// -------- FUNÇÃO PRINCIPAL --------

int main(int argc, char *argv[])
{

    //  MENU INICIAL 
    const char *rotulo[4] =
{
    "",
    "facil",
    "normal",
    "dificil"
};

int velocidade_dificuldade[4] =
{
    0,
    250,
    160, // Velocidade da personalização de matricula
    120
};

printf("========================\n");
printf("   COBRINHA - MENU\n");
printf("========================\n");

if(!ler_linha(
      "Nome do Jogador: ",
      nome_jogador,
      sizeof(nome_jogador)))
{
    fprintf(stderr,
            "Entrada encerrada.\n");

    return 1;
}

if(nome_jogador[0] == '\0')
{
    strcpy(nome_jogador,
           "anonimo");
}

printf("\n");

if(!ler_inteiro(
      "Dificuldade (1=Facil, 2=Normal, 3=Dificil): ",
      1,
      3,
      &dificuldade))
{
    fprintf(stderr,
            "Entrada encerrada.\n");

    return 1;
}

printf("\n----- RESUMO -----\n");

printf("%-12s %s\n",
       "Jogador:",
       nome_jogador);

printf("%-12s %d (%s)\n",
       "Nivel:",
       dificuldade,
       rotulo[dificuldade]);

printf("%-12s %d ms por passo\n",
       "Velocidade:",
       velocidade_dificuldade[dificuldade]);
    
velocidade = velocidade_dificuldade[dificuldade];

printf("\nAbrindo o jogo...\n\n");


//  INICIALIZAÇÃO DO GLUT 

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Jogo da Cobrinha - Pontuacao: 0");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    inicializa_cobra(&cobra);
    srand(time(NULL));
    gera_comida();

    glutDisplayFunc(desenha);
    glutSpecialFunc(teclado_especial);
    glutKeyboardFunc(teclado_normal);
    glutMouseFunc(clique_mouse);
    glutTimerFunc(velocidade, timer, 0);

    glutMainLoop();
    return 0;
}