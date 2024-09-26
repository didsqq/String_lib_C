#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *delenie = s21_NULL;
  if (str != s21_NULL) {
    delenie = str;
    while (*delenie && s21_strchr(delim, *delenie)) {
      *delenie++ = '\0';
    }
  }
  int n = s21_strlen(delenie);
  int m = s21_strlen(delim);
  int i = 0;
  int flag = 1;
  for (; i < n && flag; ++i) {
    for (int j = 0; j < m && flag; ++j) {
      if (delenie[i] == delim[j]) {
        delenie[i] = '\0';
        while (delenie[i + 1] == delim[j]) {
          ++i;
          delenie[i] = '\0';
        }
        --flag;
      }
    }
  }
  int k = 0;
  for (; k < n && delenie[k] == '\0'; k++)
    ;
  if (k == n) {
    n = 0;
  }
  delenie += i;
  return !n ? s21_NULL : delenie - i;
}