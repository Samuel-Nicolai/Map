#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

typedef struct no {
  int chave;
  char valor[50];
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
  if (raiz == NULL){
    perror("Nao foi possivel inserir no Mapa!\n");
    return;
  }
  else{
    NO *novoNO = (NO*) malloc (sizeof(NO));
    if(novoNO == NULL){
      perror("Nao foi possivel alocar memoria para o novo no!\n");
      return;
    }
    else {
      novoNO->chave = chave;
      strcpy(novoNO->valor, valor);
      novoNO->esq = NULL;
      novoNO->dir = NULL;
      if(*raiz == NULL) { // se nao existe um no na raiz
        *raiz = novoNO; // novo no passa a ser a raiz
      }
      else {
        NO *ant;
        NO *aux = *raiz;
        while (aux != NULL) { // sempre insere como folha
          ant = aux;
          if(chave == aux->chave){ // nao ha insercao de chave repetida
            printf("A chave %d ja existe, portanto, nao pode ser inserida novamente!\n", chave);
            free(novoNO);
            return;
          }
          if(chave < aux->chave) // verifica a correta posicao do novo no
            aux = aux->esq;
          else
            aux = aux->dir;
        }
        if(chave < ant->chave) // se for pra inserir a esquerda
          ant->esq = novoNO; // atualiza anterior esquerda
        else
          ant->dir = novoNO; // senao atualiza anterior direita
      }
    }
    return;
  }
}

int retornaElemento(MAP *raiz, int chave, char *resultado) {
  int cont = 0;
  if (raiz == NULL)
    return cont;
  NO *aux = *raiz;
  while (aux != NULL) {
    cont++;
    if (chave == aux->chave) {
      strcpy(resultado, aux->valor);
      return cont;
    }
    if (chave > aux->chave) {
      aux = aux->dir;
    }
    else {
      aux = aux->esq;
    }
  }
  return 0;
}

struct no *removeAtual(struct no *atual) {
  struct no *no1, *no2;
  if(atual->esq == NULL) {
    no2 = atual->dir;
    free(atual);
    return no2;
  }
  no1 = atual;
  no2 = atual->esq;
  while(no2->dir != NULL) {
    no1 = no2;
    no2 = no2->dir;
  }
  if(no1 != atual) {
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }
  no2->dir = atual->dir;
  free(atual);
  return no2;
}

int removeElemento(MAP *raiz, int chave) {
  if(raiz == NULL) {
    return 0;
  }
  NO *ant = NULL;
  NO *atual = *raiz;
  while(atual != NULL) {
    if (atual->chave == chave) {
      if (atual == *raiz) {
        *raiz = removeAtual(atual);
      }
      else {
        if (ant->dir == atual)
          ant->dir = removeAtual(atual);
        else
          ant->esq = removeAtual(atual);
      }
      return 1;
    }
    ant = atual;
    if (atual->chave > chave)
      atual = atual->esq;
    else
      atual = atual->dir;
  }
}

void emOrdem(MAP *raiz){
	if(raiz == NULL)
		return;
	if(*raiz != NULL){
		emOrdem(&((*raiz)->esq));
		printf("%d\t%s\n", (*raiz)->chave, (*raiz)->valor);
		emOrdem(&((*raiz)->dir));
	}
}
