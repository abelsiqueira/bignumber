#include "bignumber.h"
#include <stdlib.h>

BigNumber * AllocBigNumber () {
  BigNumber * bn = (BigNumber *) malloc (sizeof(BigNumber));
  bn->length = 0;
  bn->head = 0;

  return bn;
}

BigNumberNode * AllocBigNumberNode () {
  BigNumberNode * node = (BigNumberNode *) malloc (sizeof(BigNumberNode));
  node->value = 0;
  node->prox = 0;

  return node;
}

void CreateBigNumber (BigNumber *bn) {
  if (bn == 0)
    ERROR("Can only be called with allocated big numbers",__LINE__);
  bn->length = 0;
  bn->head = (BigNumberNode*) malloc (sizeof(BigNumberNode));
  bn->head->prox = 0;
  bn->head->value = 0;
}

void DestroyBigNumber (BigNumber *bn) {
  free(bn->head);
}

// Print
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

// Basic Math Operations
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
