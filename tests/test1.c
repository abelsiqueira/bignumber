#include <stdio.h>
#include "bignumber.h"

int main () {
  int i, n;
  BigNumber bn1, bn2;
  int x, y;

  CreateBigNumber(&bn1);
  CreateBigNumber(&bn2);
  x = 0;
  y = 0;

  AddIntToNumber(480028,&bn1); x += 480028;
  AddIntToNumber(480028,&bn1); x += 480028;
  AddIntToNumber(480028,&bn1); x += 480028;
  AddIntToNumber(999999,&bn2); y += 999999;
  printf("bn1 = %s\n", GetNumberStr(&bn1));
  printf("x   = %d\n", x);
  printf("bn2 = %s\n", GetNumberStr(&bn2));
  printf("y   = %d\n", y);

  for (n = 0; n < 3; n++) {
    for (i = 0; i < 5; i++) {
      AddToNumber(&bn2, &bn1); y += x;
      AddToNumber(&bn1, &bn2); x += y;
    }
    printf("bn1 = %s\n", GetNumberStr(&bn1));
    printf("x   = %d\n", x);
    printf("bn2 = %s\n", GetNumberStr(&bn2));
    printf("y   = %d\n", y);
  }

  return 0;
}
