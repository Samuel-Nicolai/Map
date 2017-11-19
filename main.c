#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

#define t 50

void preencheMap(char nomeArquivo[], MAP *raiz) {
  FILE *arquivo;
  int key;
  char value[t];

  arquivo = fopen(nomeArquivo, "r");
  if(!arquivo){
    perror("Nao foi possivel ler o arquivo!\n");
    return;
  }
  else {
    while (fscanf(arquivo, "%d  %s", &key, value) != EOF) {
      insereElemento(raiz, key, value);
    }
  }
  fclose(arquivo);
  return;
}

int main(int argc, char const *argv[]) {
  MAP *raiz;
  char nomeArquivo[t], retorno[t];
  int continuar = 1, ch, comp;

  raiz = criaMapa();
  if(!raiz) // Se matriz não foi alocada corretamente encerra o programa
    return 1;

  printf("Digite o nome do arquivo de dados: ");
  scanf("%s", nomeArquivo);
  preencheMap(nomeArquivo, raiz);
  printf("Preenchendo mapa ...\n");

  do {
    printf("Escolha uma opcao:\n");
    printf("1. Buscar elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Imprimir mapa\n");
    printf("0. Sair\n");

    scanf("%d", &continuar);
    system("cls || clear");

    switch(continuar) {
      case 1:
        printf("Digite a chave para a busca: ");
        scanf("%d", &ch);
        system("cls || clear");
        comp = retornaElemento(raiz, ch, retorno);
        if(comp) {
          printf("Foram realizadas %d comparacoes na busca.\nChave: %d, Valor: %s\n", comp, ch, retorno);
        }
        break;
      case 2:
        printf("Digite a chave do elemento a excluir: ");
        scanf("%d", &ch);
        removeElemento(raiz, ch);
        break;
      case 3:
        printf("Imprimindo mapa em ordem:\n");
        emOrdem(raiz);
        break;
      case 0:
        continue;
      default:
        printf("Digite uma opcao valida!\n");
    }
  } while(continuar);

  return 0;
}
