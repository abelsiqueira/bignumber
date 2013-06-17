/*
 * Class for Big Integer.
 * Basically, stores a sequence of number below
 * BN_BASE, signifying a base.
 *
 * Does not accept negative numbers
 */

#ifndef bignumber_h
#define bignumber_h

#include <stdio.h>
#include <stdlib.h>

#define BN_BASE 1000000
#define BN_DIGITS 6

#define ERROR(str) \
  do { \
    fprintf(stderr,"ERROR(%s,%d): "#str"\n",__FILE__,__LINE__); \
    exit(1); \
  } while(0);

#define WARNING(str) \
  do { \
    fprintf(stderr,"WARNING(%s,%d): "#str"\n",__FILE__,__LINE__); \
  } while(0);

#define DBGPRINT(x) \
  do { printf("DBG(%s,%d): %s\n", __FILE__, __LINE__, GetNumberStr(x)); } while(0);

#define ASSERT(c) do { if (!(c)) { ERROR(c); } } while (0);

typedef struct _bignumber_node {
  int value;
  struct _bignumber_node *prox;
} BigNumberNode;

typedef struct _bignumber {
  int length; // How many 'digits' are in the number 
  int check_sanity;
  BigNumberNode *head;
} BigNumber;

// Big Number Memory
BigNumber * AllocBigNumber ();
BigNumberNode * AllocBigNumberNode ();
void CreateBigNumber (BigNumber *);
void DestroyBigNumber (BigNumber *);
void DestroyNode (BigNumberNode *);
void CopyBigNumber (BigNumber *, BigNumber *);
BigNumberNode * CopyNode (BigNumberNode *);
void CheckSanityNode (BigNumberNode *, BigNumber *);

// Print
void PrintNumber (BigNumber *);
void PrintNumberNode (BigNumberNode *);
char * GetNumberStr (BigNumber *);
void GetNodeStr (BigNumberNode *, char *);

// Math
void AddIntToNumber (int, BigNumber *);
void AddIntToNode (int, BigNumberNode *, BigNumber *);
void AddToNumber (BigNumber *, BigNumber *);
void MultiplyByInt (BigNumber *, int);
void SubtractIntFromNumber (int, BigNumber *);
void SubtractIntFromNode (int, BigNumberNode *, BigNumber *);
void SubtractFromNumber (BigNumber *, BigNumber *);

#endif
