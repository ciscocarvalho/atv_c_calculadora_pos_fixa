#include "calculadora.h"
#include "pilha.c"
#include <stdio.h>

struct calc {
  Pilha *operandos;
};

Calc *cria_calc() {
  Calc *c = (Calc *)malloc(sizeof(Calc));
  c->operandos = (Pilha *)malloc(sizeof(Pilha));
  return c;
};

void operando(Calc *c, float valor) { push(c->operandos, valor); };

void operador(Calc *c, char op) {
  // ordem de insercao é inversa da ordem de operacao
  int v2 = pop(c->operandos);
  int v1 = pop(c->operandos);
  int resultado;

  if (op == '-') {
    resultado = v1 - v2;
  } else if (op == '+') {
    resultado = v1 + v2;
  } else if (op == '*') {
    resultado = v1 * v2;
  } else if (op == '/') {
    resultado = v1 / v2;
  } else {
    printf("Operador invalido!");
    exit(1);
  }

  push(c->operandos, resultado);
};

void libera_calc(Calc *c) { free(c); };

int main() {
  Calc *c = cria_calc();
  operando(c, 1);   // 1
  operando(c, 2);   // 2
  operador(c, '-'); // (1 - 2)
  operando(c, 4);   // (1 - 2) 4
  operando(c, 5);   // (1 - 2) 4 5
  operador(c, '+'); // (1 - 2) (4 + 5)
  operador(c, '*'); // (1 - 2) * (4 + 5)
  printf("Resultado: %f", pop(c->operandos));
}
