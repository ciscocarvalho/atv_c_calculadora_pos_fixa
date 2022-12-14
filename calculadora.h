typedef struct calc Calc;

Calc *cria_calc();
void operando(Calc *c, float valor);
void operador(Calc *c, char op);
void libera_calc(Calc *c);
