#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_length = s21_strlen(dest);
  s21_size_t i = 0;
  for (; i < n && src[i] != '\0'; ++i) {
    dest[dest_length + i] = src[i];
  }
  dest[dest_length + i] = '\0';
  return dest;
}