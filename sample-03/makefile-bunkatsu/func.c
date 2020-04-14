#include "header.h"

_Val value = {100, 1000};

void func1(void)
{
  
  printf("func1!\n");
  _Val v = func2();
  printf("(a,b) = (%d, %d)\n", v.a, v.b);
  printf("(a,b) = (%d, %d)\n", value.a, value.b);
  
}

_Val func2(void)
{
  _Val v;
  v.a = 10;
  v.b = 1;
  return v;
}
