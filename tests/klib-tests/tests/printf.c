
#include <limits.h>
#include <trap.h>
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
int data[] = {0,           INT_MAX / 17,  INT_MAX,      INT_MIN,
              INT_MIN + 1, UINT_MAX / 17, INT_MAX / 17, UINT_MAX};

char *pat[] = {"%d\n", "%d Hello\n"};
char *ans[ARRLEN(data)][ARRLEN(pat)] = {
    {"0", "0 Hello"},
    {"126322567", "126322567 Hello"},
    {"2147483647", "2147483647 Hello"},
    {"-2147483648", "-2147483648 Hello"},
    {"-2147483647", "-2147483647 Hello"},
    {"252645135", "252645135 Hello"},
    {"126322567", "126322567 Hello"},
    {"-1", "-1 Hello"},
};
char buf[128];

void test_printf() {
  for (int i = 0; i < ARRLEN(data); i++) {
    for (int j = 0; j < ARRLEN(pat); j++) {
      printf(pat[j], data[i]);
    }
  }
}
int main(int argc, char *argv[]) { test_printf(); }
