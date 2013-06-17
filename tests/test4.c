#include <stdio.h>
#include "bignumber.h"

int main () {
  BigNumber bn1, bn2;

  CreateBigNumber(&bn1);
  CreateBigNumber(&bn2);

  AddIntToNumber(999999,&bn1); 
  AddIntToNumber(999999,&bn2); 
  MultiplyByInt(&bn1, 9999999);
  MultiplyByInt(&bn2, 9999999);
  AddIntToNumber(1,&bn1);
  printf("bn1 = %s\n", GetNumberStr(&bn1));
  printf("bn2 = %s\n", GetNumberStr(&bn2));
  SubtractFromNumber(&bn1, &bn2);
  printf("bn1-bn2 = %s\n", GetNumberStr(&bn1));

  DestroyBigNumber(&bn1);
  DestroyBigNumber(&bn2);

  return 0;
}
