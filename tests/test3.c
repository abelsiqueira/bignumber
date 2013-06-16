#include <stdio.h>
#include "bignumber.h"

int main () {
  BigNumber bn1;

  CreateBigNumber(&bn1);

  AddIntToNumber(BN_BASE/2,&bn1); 
  AddIntToNumber(BN_BASE/2,&bn1); 
  printf("bn1 = %s\n", GetNumberStr(&bn1));

  return 0;
}
