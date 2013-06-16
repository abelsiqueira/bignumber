#include <stdio.h>
#include "bignumber.h"

int main () {
  int x;
  BigNumber bn1;

  CreateBigNumber(&bn1);
  x = 0;

  AddIntToNumber(123456,&bn1); 
  x = 48359;
  printf("bn1 = %s\n", GetNumberStr(&bn1));
  printf("x   = %d\n", x);

  MultiplyByInt(&bn1, x);
  printf("x*bn1 = %s\n", GetNumberStr(&bn1));

  return 0;
}
