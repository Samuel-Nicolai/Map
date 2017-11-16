// TAD - implementação de uma estrutura de dados do tipo MAP usando uma arvore binaria

typedef struct no *MAP; // Estrtura do tipo MAP e um ponteiro para um no

// Assinatura das funcoes

MAP* criaMapa (); // Retorna um ponteiro para um mapa
void insereElemento(MAP *raiz, int chave, char valor[]); //