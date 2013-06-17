#include "bignumber.h"
#include <stdlib.h>

BigNumber * AllocBigNumber () {
  BigNumber * bn = (BigNumber *) malloc (sizeof(BigNumber));
  bn->length = 0;
  bn->head = 0;
  bn->check_sanity = 0;

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
    ERROR("Can only be called with allocated big numbers");
  bn->length = 0;
  bn->head = (BigNumberNode*) malloc (sizeof(BigNumberNode));
  bn->head->prox = 0;
  bn->head->value = 0;
  bn->check_sanity = 0;
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
  to->check_sanity = from->check_sanity;
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

void CheckSanityNode (BigNumberNode *node, BigNumber *father) {
  if (node->prox == 0)
    return;

  CheckSanityNode(node->prox, father);
  if (node->prox->value == 0) {
    free(node->prox);
    node->prox = 0;
    father->length--;
  }
  father->check_sanity  = 0;
}
