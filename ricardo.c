#include <stdio.h>

/*
 * Desenvolvido por Ricardo Medeiros <ricardo.junior@agrotis.com>
 * Implementa o desafio da ampulheta. https://github.com/solid-skills/challenges/blob/master/proposicaoAmpulheta.md
 *
 * AINDA NÃO TESTADO
 */

// Realiza a soma do quadrante
int soma(int matriz[3][3]) {
  return (matriz[0][0] + matriz[0][1] + matriz[0][2] +
                         matriz[1][1] + 
          matriz[2][0] + matriz[2][1] + matriz[2][2]);
}

// Apenas preenche a matriz estaticamente, pra não precisar ficar inputando toda vez
// TODO: Verificar se é possível retornar essa matriz dessa forma
int[6][6] preenche_matriz() {
  int matriz[6][6];

  //  1 2 2 0 0 0
  //  0 1 0 0 0 0
  //  2 2 2 0 0 0
  //  0 0 0 2 2 2
  //  0 0 0 0 3 0
  //  0 0 0 2 2 2
  
  matriz[0][0] = 1; matriz[0][1] = 2; matriz[0][2] = 2; matriz[0][3] = 0; matriz[0][4] = 0; matriz[0][5] = 0; 
  matriz[1][0] = 0; matriz[1][1] = 1; matriz[1][2] = 0; matriz[1][3] = 0; matriz[1][4] = 0; matriz[1][5] = 0; 
  matriz[2][0] = 2; matriz[2][1] = 2; matriz[2][2] = 2; matriz[2][3] = 0; matriz[2][4] = 0; matriz[2][5] = 0;
  matriz[3][0] = 0; matriz[3][1] = 0; matriz[3][2] = 0; matriz[3][3] = 2; matriz[3][4] = 2; matriz[3][5] = 2;
  matriz[4][0] = 0; matriz[4][1] = 0; matriz[4][2] = 0; matriz[4][3] = 0; matriz[4][4] = 3; matriz[4][5] = 0;
  matriz[5][0] = 0; matriz[5][1] = 0; matriz[5][2] = 0; matriz[5][3] = 2; matriz[5][4] = 2; matriz[5][5] = 2;
}

int main() {
  int soma, i, j = 0;
  int matriz[6][6] = preenche_matriz();

  while(i < len(matriz[0][0])) { // TODO: Verificar se isso é possível
    while (j < len(matriz[[0]])) { // TODO: O mesmo da linha de cima
      int quadrante[3][3];

      for(int xi=i; i < (i+2); i++) {
        for(int xj=j; j < (j+2); j++) {
          quadrante[i][j] = matriz[i][j];
        }
      }
      if(soma(quadrante) > soma) {
        soma = soma(quadrante);
      }
      j =+ 3;
    }
    i =+ 3;
  }
  
  printf("Soma: %d", soma);

  return 0;
}
