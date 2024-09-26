#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t n = 0;
  s21_size_t m = 0;
  int flag = 1;
  if (src != s21_NULL && str != s21_NULL) {
    n = s21_strlen(src);
    m = s21_strlen(str);
    flag = 0;
  }
  char *new_string = s21_NULL;
  if (start_index <= m && !flag) {
    if ((new_string = malloc(sizeof(char) * ((n + m) + 1))) == s21_NULL) {
      flag = 1;
    } else {
      for (s21_size_t i = 0; i < (n + m) + 1; i++) new_string[i] = '\0';
      s21_strncpy(new_string, src, start_index);
      s21_memcpy(new_string + start_index, str, m);
      s21_strncpy(new_string + start_index + m, src + start_index,
                  n - start_index);
    }
  }
  return !flag ? new_string : s21_NULL;
}