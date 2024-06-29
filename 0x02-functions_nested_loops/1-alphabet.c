#include <stdio.h>

/**
 * print only lower case alphabets
 */
void print_alphabet(void)
{
  char i;
  for(i ='a'; i <= 'z'; i++ )
  {
    putchar(i);
    putchar('\n');
  }
}