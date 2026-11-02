#include <GL/glut.h>

#define LINHAS 20
#define COLUNAS 20

//----------------GRADE----------------

void desenha_grade(void)
{
    int i;
    float x;
    float y;

    // COR CINZA CLARO
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

//----------------TELA----------------

void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    desenha_grade();

    glutSwapBuffers();
}

//----------------FUNCAO PRINCIPAL---------------- 

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutCreateWindow("Jogo da Cobrinha");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(desenha);

    glutMainLoop();

    return 0;
}
