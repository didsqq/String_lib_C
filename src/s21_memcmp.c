#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n && result == 0; i++) {
    if (*((char *)str1 + i) != *((char *)str2 + i)) {
      if (*((char *)str1 + i) > *((char *)str2 + i)) {
        result = (*((unsigned char *)str1 + i)) - *((unsigned char *)str2 + i);
      } else if (*((char *)str1 + i) < *((char *)str2 + i)) {
        result = *((unsigned char *)str1 + i) - *((unsigned char *)str2 + i);
      }
    }
  }
  return result;
}