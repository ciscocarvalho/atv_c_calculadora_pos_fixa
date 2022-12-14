#define MAX 50

typedef struct pilha Pilha;

Pilha *cria();
void push(Pilha *p, float valor);
float pop(Pilha *p);
int vazia(Pilha *p);
void liberar(Pilha *p);
