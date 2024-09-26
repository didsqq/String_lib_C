#include "s21_string.h"

int s21_strcspn(const char *str1, const char *str2) {
  int no_matches_length = 0;
  int dlina = s21_strlen(str1);
  for (int i = 0; i < dlina && (s21_strchr(str2, str1[i]) == s21_NULL); i++) {
    ++no_matches_length;
  }
  return no_matches_length;
}
