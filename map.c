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
  if(raiz == NULL){
    perror("O mapa nao existe!\n");
    return 0;
  }
  else {
    if((*raiz) == NULL) {
      perror("O mapa nao contem nenhum elemento!\n");
      return 0;
    }
    else {
      NO *aux = *raiz;
      while(aux->chave != chave && aux) {
        if(chave < aux->chave) {
          aux = aux->esq;
        }
        if(chave > aux->chave) {
          aux = aux->dir;
        }
      }
      if(!aux) {
        printf("O elemento de chave %d nao foi encontrado!\n", chave);
      }
      else {
        strcpy(resultado, aux->valor);
      }
    }
    return 1;
  }
}

struct no *removeAtual(struct no *atual) {
  NO *aux, *subAux;
  if(atual->dir == NULL) { // se o no nao tem sucessor
    aux = atual->esq;
    free(atual);
    return aux;
  }
  aux = atual;
  subAux = atual->dir; // sub arvore a direita
  while(subAux->esq != NULL) { // procura pelo sucessor (no mais a esquerda da sub arvore a direita)
    aux = subAux;
    subAux = subAux->esq;
  }
  if(aux != atual){ // se encontrei sucessor
    aux->esq = subAux->dir;
    subAux->dir = atual->dir;
  }
  subAux->esq = atual->esq;
  free(atual);
  return subAux;
}

void removeElemento(MAP *raiz, int chave) {
  if(raiz == NULL) {
    perror("O mapa nao existe!\n");
    return;
  }
  else {
    if(*raiz == NULL){
      perror("Nao existem elementos a serem removidos!\n");
      return;
    }
    else {
      NO *atual = *raiz;
      NO *anterior = NULL;
      while(atual != NULL) { // procura pelo no a excluir
        if(atual->chave == chave) { // se entrar aqui achou o no
          if(atual == *raiz) { // se o no encontrado for a raiz
            *raiz = removeAtual(atual); // atualiza a raiz
            return;
          }
          else {
            if(anterior->esq == atual){ // se o no foi encontrado a esquerda do anterior
              anterior->esq = removeAtual(atual); // atualiza a esquerda do anterior
              return;
            }
            else { // se o no foi encontrado a direita do anterior
              anterior->dir = removeAtual(atual); // atualiza a direita do anterior
              return;
            }
          }
        }
        anterior = atual; // anda na arvore
        if(chave < atual->chave)
          atual = atual->esq;
        else
          atual = atual->dir;
      }
    }
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
