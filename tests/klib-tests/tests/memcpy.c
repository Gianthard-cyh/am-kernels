#include <string.h>
#include <trap.h>
#define N 32
uint8_t data_src[N];
uint8_t data_dest[N];

void reset() {
  int i;
  for (i = 0; i < N; i++) {
    data_dest[i] = i + 1;
  }
  for (i = 0; i < N; i++) {
    data_src[i] = rand();
  }
}

void check_seq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i++) {
    check(data_dest[i] == val + i - l);
  }
}

void check_eq(int l, int r) {
  int i;
  for (i = l; i < r; i++) {
    check(data_dest[i] == data_src[i]);
  }
}

void test_memcpy() {
  int l, r;
  for (l = 0; l < N; l++) {
    for (r = l + 1; r <= N; r++) {
      reset();
      memcpy(data_dest + l, data_src + l, r - l);
      check_seq(0, l, 1);
      check_eq(l, r);
      check_seq(r, N, r + 1);
    }
  }
}
int main(int argc, char *argv[]) { test_memcpy(); }
