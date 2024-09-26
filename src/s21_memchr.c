#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *symbol_pointer = s21_NULL;
  for (s21_size_t i = 0; i < n && symbol_pointer == s21_NULL; ++i) {
    if (*((char *)str + i) == c) {  //*(char*) дает первый символ строки str
                                    //после приведения str к типу char*
      symbol_pointer = (char *)str + i;
    }
  }
  return (char *)symbol_pointer;
}