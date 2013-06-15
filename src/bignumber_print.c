#include "bignumber.h"

void PrintNumber (BigNumber *bn) {
  PrintNumberNode(bn->head);
}

void PrintNumberNode (BigNumberNode *node) {
  if (node->prox != 0) {
    PrintNumberNode(node->prox);
    printf("%06d", node->value);
  } else {
    printf("%d", node->value);
  }
}

