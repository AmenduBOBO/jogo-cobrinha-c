[ JOGO DA COBRINHA EM C ]
Projeto desenvolvido para a disciplina Programação de Software Básico em C (ARA3327).


[ ALUNO ]
Nome: JOAO JOSE FURTADO BONARRIGO
Matrícula: 202308970674


[ TECNOLOGIAS UTILIZADAS ]

- Linguagem C (C89)
- OpenGL
- FreeGLUT
- GCC
- MSYS2 UCRT64
- Git
- GitHub


[ PERSONALIZAÇÃO DA MATRÍCULA ]

Últimos dígitos da matrícula:

A = 6 B = 7 C = 4


[ CONFIGURAÇÃO GERADA PELAS REGRAS DO TRABALHO ]

Grade: 20 x 20
Velocidade inicial: 160 ms
Cor da cobra: Laranja
Pontos por comida: 20


[ COMO COMPILAR/EXECUTAR ]

NOTEBOOK:
C:\Users\JOSE BONARRIGO\Desktop\jogo-cobrinha-c

PC:
cd /c/Users/jose2/OneDrive/Desktop/jogo-cobrinha-c

1- Add icone
windres icone.rc -O coff -o icone.o

2- Compilar
gcc main.c cobra.c entrada.c config.c ranking.c historico.c icone.o -o snake.exe -lfreeglut -lopengl32 -lglu32 -lm -lwinmm

3- iniciar
./snake.exe


[ CONTROLES ]

Setas = Mover a cobra
P = Pausar
ESC = Sair
Clique esquerdo mouse = Reinicia jogo, após o game over