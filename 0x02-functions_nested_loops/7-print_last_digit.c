#include <stdio.h>
#include"main.h"

int print_last_digit(int a)
{
  int last_digit = 0;
  

  if(last_digit < 0 ){
    last_digit = a % 10;
    _putchar(last_digit + '0');
    return last_digit;
  }
  else{
      last_digit = a % 10;
      _putchar(last_digit + '0');
      return last_digit;
  }
  
}
