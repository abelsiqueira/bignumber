#include <stdio.h>
#include "bignumber.h"

int main () {
  BigNumber bn1;

  CreateBigNumber(&bn1);

  AddIntToNumber(999999,&bn1); 
  MultiplyByInt(&bn1, 99);
  printf("bn1 = %s\n", GetNumberStr(&bn1));
  SubtractIntFromNumber(999999,&bn1);
  printf("bn1 = %s\n", GetNumberStr(&bn1));
  SubtractIntFromNumber(98*999999-100,&bn1);
  printf("bn1 = %s\n", GetNumberStr(&bn1));

  DestroyBigNumber(&bn1);

  return 0;
}
