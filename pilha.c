#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

// codigo baseado nos slides, nao assumo responsabilidade

struct pilha {
  int n;
  float vet[MAX];
};

Pilha *cria() {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->n = 0;

  return p;
};

void push(Pilha *p, float valor) {
  if (p->n == MAX) {
    printf("A pilha esta cheia!\n");
    exit(1);
  }

  p->vet[p->n] = valor;
  p->n++;
};

float pop(Pilha *p) {
  int valor;

  if (p->n == 0) {
    printf("A pilha esta vazia!\n");
    exit(1);
  } else {
    valor = p->vet[p->n - 1];
    p->n--;

    return valor;
  }
};

int vazia(Pilha *p) { return (p->n == 0); };

void liberar(Pilha *p) { free(p); };
