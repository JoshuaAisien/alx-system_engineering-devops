#include <stdio.h>
#include "main.h"

void times_table(void)
{
  int i,result,j;
  i = 0; 
  while(i<10)
  {
    for (j = 0; j<10; j++)
    {
      result = i * j;
      if (result < 0){
        _putchar(' ');
      }
      else{
        _putchar((result/10) + '0');
    }
    _putchar((result % 10) + '0');
      if( j<9 )
      {
        _putchar(',');
        _putchar(' ');
      }
    }
    _putchar('\n');
    i++;
  
}
}