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
  DestroyNode(bn->head);
}

void DestroyNode (BigNumberNode *node) {
  if (node == 0)
    return;
  DestroyNode(node->prox);
}

void CopyBigNumber (BigNumber *from, BigNumber *to) {
  to->length = from->length;
  to->head = CopyNode(from->head);
}

BigNumberNode * CopyNode (BigNumberNode *node) {
  BigNumberNode *copy;

  if (node == 0)
    return 0;
  copy = AllocBigNumberNode();
  copy->value = node->value;
  copy->prox = CopyNode(node->prox);

  return copy;
}

