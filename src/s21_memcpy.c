#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *chardest = (char *)dest;
  const char *charsrc = (char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    *(chardest + i) = *(charsrc + i);
  }
  return dest;
}
