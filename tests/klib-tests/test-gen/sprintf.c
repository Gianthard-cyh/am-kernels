#include <limits.h>
#include <stdio.h>
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
int data[] = {0,           INT_MAX / 17,  INT_MAX,      INT_MIN,
              INT_MIN + 1, UINT_MAX / 17, INT_MAX / 17, UINT_MAX};

char *pat[] = {"%d", "%d Hello", "%08X"};

void test_sprintf() {
  printf("{");
  for (int i = 0; i < ARRLEN(data); i++) {
    for (int j = 0; j < ARRLEN(pat); j++) {
      printf("\"");
      printf(pat[j], data[i]);
      printf("\",");
    }
  }

  printf("}");
}
int main(int argc, char *argv[]) { test_sprintf(); }
