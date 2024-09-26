#include "s21_string.h"
void *s21_trim(const char *src, const char *trim_chars) {
  int n = s21_strlen(src);
  int flag = 0;
  char *buff = s21_NULL;
  if (src != s21_NULL) {
    if (trim_chars && *trim_chars) {
      if ((buff = calloc(sizeof(char), (n + 1))) != s21_NULL) {
        s21_strncpy(buff, src, n);
        int i = left_trim(trim_chars, buff, n);
        int m = s21_strlen(buff);
        for (i = m; s21_strchr(trim_chars, buff[i]) != s21_NULL && i > 0 && n;
             i--) {
          buff[i] = '\0';
        }
      }
    } else {
      buff = s21_trim(src, " \t\n");
    }
  }
  return buff;
}

int left_trim(const char *trim_chars, char *buff, int n) {
  int i = 0;
  for (; s21_strchr(trim_chars, buff[i]) != s21_NULL && n;) {
    int shift = 0;
    for (int j = 0; j < n; ++j) {
      shift = 1;
      buff[j] = buff[j + 1];
    }
    if (!shift) {
      i++;
    } else {
      shift = 0;
    }
  }
  return i;
}