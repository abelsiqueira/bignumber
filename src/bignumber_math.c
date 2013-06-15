#include "bignumber.h"

void AddIntToNumber (int x, BigNumber *bn) {
  if (bn->head == 0)
    ERROR("head unnalocated",__LINE__);
  if (x >= BN_BASE)
    ERROR("x greater than BN_BASE",__LINE__);
  AddIntToNode(x, bn->head, bn);
}

void AddIntToNode (int x, BigNumberNode *node, BigNumber *father) {
  int q;

  if (x >= BN_BASE)
    ERROR("x greater than BN_BASE",__LINE__);
  x = x + node->value;
  q = x/BN_BASE;
  node->value = x - q*BN_BASE;
  if (q > 0) {
    if (node->prox == 0) {
      node->prox = AllocBigNumberNode();
      father->length++;
    }
    AddIntToNode(q, node->prox, father);
  }
}

// y = y + x;
void AddToNumber (BigNumber *x, BigNumber *y) {
  BigNumberNode *node_x, *node_y;

  if (x == y)
    ERROR("x = y not implemented yet",__LINE__);
  if (x->length < y->length) {
    node_x = x->head;
    while (node_x->prox != 0) node_x = node_x->prox;
    while (x->length < y->length) {
      node_x->prox = AllocBigNumberNode();
      x->length++;
      node_x = node_x->prox;
    }
  }

  node_x = x->head;
  node_y = y->head;
  while (node_y != 0) {
    AddIntToNode(node_y->value, node_x, x);
    node_x = node_x->prox;
    node_y = node_y->prox;
  }
}

void MultiplyByInt (BigNumber *bn, int x) {
  BigNumber aux;

  if (x < 0)
    ERROR("Can't multiply by negative numbers",__LINE__);

  CreateBigNumber(&aux);
  CopyBigNumber(bn, &aux);

  while (x > 1) {
    AddToNumber(bn, &aux);
    x--;
  }
}
