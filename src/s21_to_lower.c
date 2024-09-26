#include "s21_string.h"

void *s21_to_lower(const char *str) {
  int n = s21_strlen(str);
  int flag = 0;
  char *buff;
  if ((buff = malloc(sizeof(char) * (n + 1))) == s21_NULL) {
    flag = 1;
  }
  for (int i = 0; i < (n + 1); i++) buff[i] = '\0';
  s21_strncpy(buff, str, n);
  if (buff[0] != '\0') {
    for (int i = 0; i < n; i++) {
      if (buff[i] >= 'A' && buff[i] <= 'Z') {
        buff[i] -= ('A' - 'a');
      }
    }
  } else {
    s21_strncpy(buff, str, n);
  }
  return !flag ? buff : s21_NULL;
}