

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define N 32
char data_a[N] = "Hello, world!Holallo";
char data_b[N] = "Hello, world!Holallo";

void init() {}

void test_strcmp() {
  int l1, l2, s, cnt = 0;
  printf("{");
  for (l1 = 0; l1 < N; l1++) {
    printf("{");
    for (l2 = 0; l2 < N; l2++) {
      printf("%d,", strcmp(data_a + l1, data_b + l2));
      cnt++;
    }
    printf("},");
  }
  printf("}");
}
int main(int argc, char *argv[]) { test_strcmp(); }
