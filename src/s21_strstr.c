#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (needle[0] == '\0') {
    return (char *)haystack;
  }
  int h_size = s21_strlen(haystack);
  int n_size = s21_strlen(needle);
  int fl_stop = 1;
  int cnt = 0;
  for (int i = 0; (i < h_size) && fl_stop; ++i) {
    cnt = 0;
    for (int j = 0; j < n_size && fl_stop; ++j) {
      if (haystack[i + j] == needle[j]) {
        ++cnt;
      }
      if (cnt == n_size) {
        fl_stop = 0;
        cnt = i;
      }
    }
  }
  return !fl_stop ? (char *)(haystack + cnt) : s21_NULL;
}