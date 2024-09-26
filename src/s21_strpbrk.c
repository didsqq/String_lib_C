#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int n1 = s21_strlen(str1);
  int n2 = s21_strlen(str2);
  const char *symbol = s21_NULL;
  for (int i = 0; i < n1 && symbol == s21_NULL; ++i)
    for (int j = 0; j < n2; ++j)
      if (str1[i] == str2[j]) {
        symbol = str1 + i;
      }
  return (char *)symbol;
}