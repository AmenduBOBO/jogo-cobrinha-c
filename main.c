#include <GL/glut.h>
#include "cobra.h"
#include <stdio.h>

#define LINHAS 20
#define COLUNAS 20

#define DIREITA 0
#define ESQUERDA 1
#define CIMA 2
#define BAIXO 3

// -------- COBRA --------

Cobra cobra;

int direcao = DIREITA;

void inicializa_cobra(void)
{
    cobra.tamanho = 3;

    cobra.corpo[0].x = 10;
    cobra.corpo[0].y = 10;

    cobra.corpo[1].x = 9;
    cobra.corpo[1].y = 10;

    cobra.corpo[2].x = 8;
    cobra.corpo[2].y = 10;
}

void desenha_cobra(void)
{
    int i;
    float x;
    float y;
    float tamanho;

    tamanho = 2.0f / COLUNAS;

    glColor3f(0.0f, 0.7f, 0.0f);

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


// -------- MOVIMENTO --------

void move_cobra(void)
{
    int i;

    for(i = cobra.tamanho - 1; i > 0; i--)
    {
        cobra.corpo[i] = cobra.corpo[i - 1];
    }

    if(direcao == DIREITA)
    {
        cobra.corpo[0].x++;
    }
    else if(direcao == ESQUERDA)
    {
        cobra.corpo[0].x--;
    }
    else if(direcao == CIMA)
    {
        cobra.corpo[0].y++;
    }
    else if(direcao == BAIXO)
    {
        cobra.corpo[0].y--;
    }

    if(cobra.corpo[0].x >= COLUNAS)
        cobra.corpo[0].x = 0;

    if(cobra.corpo[0].x < 0)
        cobra.corpo[0].x = COLUNAS - 1;

    if(cobra.corpo[0].y >= LINHAS)
        cobra.corpo[0].y = 0;

    if(cobra.corpo[0].y < 0)
        cobra.corpo[0].y = LINHAS - 1;
}

void timer(int valor)
{
    move_cobra();

    glutPostRedisplay();

    glutTimerFunc(200, timer, 0);
}

void teclado_especial(int tecla, int x, int y)
{


    if(tecla == GLUT_KEY_RIGHT && direcao != ESQUERDA)
    {
        direcao = DIREITA;
    }

    else if(tecla == GLUT_KEY_LEFT && direcao != DIREITA)
    {
        direcao = ESQUERDA;
    }

    else if(tecla == GLUT_KEY_UP && direcao != BAIXO)
    {
        direcao = CIMA;
    }

    else if(tecla == GLUT_KEY_DOWN && direcao != CIMA)
    {
        direcao = BAIXO;
    }
}


// -------- GRADE --------

void desenha_grade(void)
{
    int i;
    float x;
    float y;

    // COR CINZA CLARA
    glColor3f(0.8f, 0.8f, 0.8f);

    glBegin(GL_LINES);

    // LINHAS VERTICAIS
    for(i = 0; i <= COLUNAS; i++)
    {
        x = -1.0f + (2.0f * i / COLUNAS);

        glVertex2f(x, -1.0f);
        glVertex2f(x, 1.0f);
    }
    // LINHAS HORIZONTAIS
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

    desenha_cobra();

    glutSwapBuffers();
}

// -------- FUNCAO PRINCIPAL --------

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutCreateWindow("Jogo da Cobrinha");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    inicializa_cobra();

    glutDisplayFunc(desenha);

    glutSpecialFunc(teclado_especial);

    glutTimerFunc(200, timer, 0);

    glutMainLoop();

    return 0;
}