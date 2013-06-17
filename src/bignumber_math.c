#include "bignumber.h"

void AddIntToNumber (int x, BigNumber *bn) {
  if (x < 0) {
    WARNING("Negative number: calling SubtractIntFromNumber");
    SubtractIntFromNumber(-x, bn);
    return;
  } else if (x == 0)
    return;
  if (bn->head == 0)
    ERROR("head unnalocated");
  if (x >= BN_BASE)
    ERROR("x greater than BN_BASE");
  AddIntToNode(x, bn->head, bn);
}

void AddIntToNode (int x, BigNumberNode *node, BigNumber *father) {
  int q;

  if (x >= BN_BASE)
    ERROR("x greater than BN_BASE");
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
    ERROR("x = y not implemented yet");
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
    ERROR("Can't multiply by negative numbers");

  CreateBigNumber(&aux);
  CopyBigNumber(bn, &aux);

  while (x > 1) {
    AddToNumber(bn, &aux);
    x--;
  }
}

void SubtractIntFromNumber (int x, BigNumber *bn) {
  if (x < 0) {
    WARNING("Negative number: calling AddIntToNumber");
    AddIntToNumber(-x,bn);
    return;
  }
  SubtractIntFromNode(x, bn->head, bn);
  if (bn->check_sanity)
    CheckSanityNode(bn->head, bn);
}

void SubtractIntFromNode (int x, BigNumberNode *node, BigNumber *father) {
  int q, r;
  if (node->value >= x) {
    node->value -= x;
    if (node->value == 0 && node->prox == 0)
      father->check_sanity = 1;
    return;
  }
  if (node->prox == 0)
    ERROR("Negative Big Number");

  q = x/BN_BASE;
  r = x - q*BN_BASE;
  if (r > node->value) {
    r -= BN_BASE;
    q++;
  }

  node->value -= r;
  ASSERT(q > 0);
  SubtractIntFromNode(q, node->prox, father);
  if (node->value == 0 && node->prox == 0)
    father->check_sanity = 1;

}

void SubtractFromNumber (BigNumber *x, BigNumber *y) {
  BigNumberNode *node_x, *node_y;
  if (x->length < y->length)
    ERROR("Negative number");

  node_x = x->head;
  node_y = y->head;

  while (node_y != 0) {
    SubtractIntFromNode(node_y->value, node_x, x);
    node_x = node_x->prox;
    node_y = node_y->prox;
  }

  if (x->check_sanity) 
    CheckSanityNode(x->head, x);
}


