/*
 * Class for Big Integer.
 * Basically, stores a sequence of number below
 * BN_BASE, signifying a base.
 */

#ifndef bignumber_h
#define bignumber_h

#include <stdio.h>
#include <stdlib.h>

#define BN_BASE 1000000

#define ERROR(str,line) \
  do { \
    fprintf(stderr,"ERROR: " #str " at %d\n",line); \
    exit(1); \
  } while(0);

typedef struct _bignumber_node {
  int value;
  struct _bignumber_node *prox;
} BigNumberNode;

typedef struct _bignumber {
  int length; // How many 'digits' are in the number 
  BigNumberNode *head;
} BigNumber;

BigNumber * AllocBigNumber ();
BigNumberNode * AllocBigNumberNode ();
void CreateBigNumber (BigNumber *);
void DestroyBigNumber (BigNumber *);

void PrintNumber (BigNumber *);
void PrintNumberNode (BigNumberNode *);

void AddIntToNumber (int, BigNumber *);
void AddIntToNode (int, BigNumberNode *, BigNumber *);

void AddToNumber (BigNumber *, BigNumber *);
void AddToNode (int, BigNumberNode *, BigNumberNode *);

#endif
