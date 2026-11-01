#include <GL/glut.h>

// TELA
void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

//FUNÇÃO PRINCIPAL
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
