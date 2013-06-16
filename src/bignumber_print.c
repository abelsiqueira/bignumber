#include "bignumber.h"
#include "string.h"

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

char * GetNumberStr (BigNumber *bn) {
  char * str;
  str = (char *) malloc (sizeof(char)*bn->length*BN_DIGITS);
  GetNodeStr(bn->head, str);
  return str;
}

void GetNodeStr (BigNumberNode *node, char *str) {
  if (node->prox != 0) {
    GetNodeStr(node->prox, str);
    sprintf(str + strlen(str), "%06d", node->value);
  } else {
    sprintf(str + strlen(str), "%d", node->value);
  }
}
