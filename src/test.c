#include <stdio.h>
#include "includes/s21_string.h"

int main(void)
{
  char str[] = "hello world!\n";
  s21_strstr("adadsdadadg", "adg");
  char a[10];
  s21_strcpy(a, "asdf");
  s21_strlen(a);

  printf("%s", s21_strpbrk(str, "11123ow"));

  return 0;
}