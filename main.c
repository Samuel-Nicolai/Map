#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main(int argc, char const *argv[]) {
  MAP *raiz;

  raiz = criaMapa();
  if(!raiz) // Se matriz não foi alocada corretamente encerra o programa
    return 1;

  return 0;
}
