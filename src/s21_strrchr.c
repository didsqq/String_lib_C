#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *pointer = s21_NULL;
  int dlina = s21_strlen(str);
  for (int i = dlina; i >= 0 && pointer == s21_NULL; --i) {
    if (str[i] == c) {
      pointer = str + i;
    }
  }
  return (char *)pointer;
}