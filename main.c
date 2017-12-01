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
  char nomeArquivo[t], retorno[t], novoV[t];
  int continuar = 1, ch, comp, novoCh;

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
    printf("4. Inserir no mapa\n");
    printf("0. Sair\n");

    scanf("%d", &continuar);
    system("cls || clear");
    setbuf(stdin, NULL);

    switch(continuar) {
      case 1:
        printf("Digite a chave para a busca: ");
        scanf("%d", &ch);
        comp = retornaElemento(raiz, ch, retorno);
        if(comp) {
          printf("Foram realizadas %d comparacoes na busca.\nChave: %d, Valor: %s\n", comp, ch, retorno);
        }
        else {
          printf("Nao encontrado!\n");
        }
        break;
      case 2:
        printf("Digite a chave do elemento a excluir: ");
        scanf("%d", &ch);
        if (removeElemento(raiz, ch)) {
          printf("Removido com sucesso!\n");
        }
        else{
          printf("Nao foi possivel remover!\n");
        }
        break;
      case 3:
        printf("Imprimindo mapa em ordem:\n");
        emOrdem(raiz);
        break;
      case 4:
        printf("Digite a chave do novo no: ");
        scanf("%d", &novoCh);
        printf("Digite o valor do novo no: ");
        scanf("%s", novoV);
        insereElemento(raiz, novoCh, novoV);
        break;
      case 0:
        continue;
      default:
        printf("Digite uma opcao valida!\n");
    }
  } while(continuar);

  return 0;
}
