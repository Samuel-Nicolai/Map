#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

int main(int argc, char const *argv[]) {
  MAP *raiz;
  int i, chave;
  char nome[20], retorno[20];

  raiz = criaMapa();
  if(!raiz) // Se matriz não foi alocada corretamente encerra o programa
    return 1;

  for (i = 0; i < 3; i++) {
    printf("Digite a chave e nome:\n");
    scanf("%d", &chave);
    scanf("%s", nome);
    insereElemento(raiz, chave, nome);
  }

  if(retornaElemento(raiz, 5, retorno))
    printf("retorno = %s\n", retorno);
  else
    printf("Nao encontrado!\n");

  emOrdem(raiz);
  removeElemento(raiz, 5);
  emOrdem(raiz);

  return 0;
}
