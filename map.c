#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

typedef struct no {
  int chave;
  char valor[20];
  struct no *esq;
  struct no *dir;
}NO;

MAP* criaMapa() {
  MAP *raiz = (MAP*) malloc ( sizeof(MAP));
  if (!raiz)
    perror("Mapa nao foi alocado com sucesso!\n");
  else
    *raiz = NULL;
  return raiz;
}

void insereElemento(MAP *raiz, int chave, char valor[]) {
  if (!raiz){
    perror("Nao foi possivel inserir no Mapa!\n");
    return;
  }
  else{
    NO *novoNO = (NO*) malloc (sizeof(NO));
    if(!novoNO){
      perror("Nao foi possivel alocar memoria para o novo no!\n");
      return;
    }
    else {
      novoNO->chave = chave;
      strcpy(novoNO->valor, valor);
      novoNO->esq = NULL;
      novoNO->dir = NULL;
      if(*raiz = NULL){
        *raiz = novoNO;
      }
      else {
        NO *ant;
        NO *aux = *raiz;
        while (aux) {
          ant = aux;
          if(chave == aux->chave){
            perror("A chave %d ja existe, portanto, nao pode ser inserida novamente!\n", chave);
            return;
          }
          if(chave < aux->chave)
            aux = aux->esq;
          else
            aux = aux->dir;
        }
        if(chave < ant->chave)
          ant->esq = novoNO;
        else
          ant->dir = novoNO;
      }
    }
    return;
  }
}
