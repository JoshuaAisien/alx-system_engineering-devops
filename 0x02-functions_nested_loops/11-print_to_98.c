#include <stdio.h>
#include "main.h"

void print_to_98(int n)
{
  int i;
  if(n>=98)
    {
      for (i = n; i>=98; i--)
      {
        _putchar((i / 10) + '0');
        _putchar((i % 10) + '0');
      }

    }
  else
    {
    for (i = 0; i <= 98; i++ )
      {
        {
        if(i >= 10 ){
          _putchar((i / 10) + '0');
        }
        _putchar((i % 10) + '0');
      }
        }
    }
    if(i < 98)
    {
      _putchar(',');
      _putchar(' ');
    }
}