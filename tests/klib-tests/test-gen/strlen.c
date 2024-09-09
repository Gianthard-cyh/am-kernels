#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 512
char data[N];

void test_strlen() {
  for (int i = 0; i < N; i++) {
    data[i] = rand() % CHAR_MAX;
  }
  for (int i = 0; i < 20; i++) {
    data[rand() % N] = 0;
  }

  printf("{");
  for (int i = 0; i < N; i++) {
    printf("%d,", data[i]);
  }
  printf("}\n");

  printf("{");
  for (int i = 0; i < N; i++) {
    printf("%ld,", strlen(data + i));
  }
  printf("}\n");
}
int main(int argc, char *argv[]) { test_strlen(); }
