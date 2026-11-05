[JOGO DA COBRINHA EM C]
Projeto desenvolvido para a disciplina Programação de Software Básico em C (ARA3327).

[ALUNO]
Nome: JOSE BONARRIGO
Matrícula: 202308970674

[TECNOLOGIAS UTILIZADAS]

- Linguagem C (C89)
- OpenGL
- FreeGLUT
- GCC
- MSYS2 UCRT64
- Git
- GitHub

[PERSONALIZAÇÃO DA MATRÍCULA]
Últimos dígitos da matrícula:

A = 6 B = 7 C = 4

[CONFIGURAÇÃO GERADA PELAS REGRAS DO TRABALHO]

Grade: 20 x 20
Velocidade inicial: 160 ms
Cor da cobra: Laranja
Pontos por comida: 20



[FUNCIONALIDADES IMPLEMENTADAS - ETAPA 1]

Janela OpenGL 600x600
Cobra com 3 segmentos iniciais
Movimento automático
Controle pelas setas do teclado
Crescimento ao comer
Comida aleatória
Sistema de pontuação
Colisão com parede
Colisão com o próprio corpo
Reinício da partida com clique esquerdo do mouse
Pausa com a tecla P
Saída do jogo com ESC
Efeitos sonoros
Modularização com arquivos .h e .c

[COMO COMPILAR/EXECUTAR]

NOTEBOOK:
C:\Users\JOSE BONARRIGO\Desktop\jogo-cobrinha-c

PC:
cd /c/Users/jose2/OneDrive/Desktop/jogo-cobrinha-c

1-
gcc main.c cobra.c entrada.c -o snake.exe -lfreeglut -lopengl32 -lglu32 -lm -lwinmm

2-
./snake.exe

[CONTROLES]

Setas = Mover a cobra
P = Pausar
ESC = Sair
Clique esquerdo mouse = Reinicia jogo, após o game over