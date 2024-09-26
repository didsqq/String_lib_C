#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *pointer = s21_NULL;
  int dlina = s21_strlen(str);
  for (int i = 0; i <= dlina && pointer == s21_NULL; ++i) {
    if (str[i] == c) {
      pointer = str + i;
    }
  }
  return (char *)pointer;
}