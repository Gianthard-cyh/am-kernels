#include <limits.h>
#include <trap.h>
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
int data[] = {0,           INT_MAX / 17,  INT_MAX,      INT_MIN,
              INT_MIN + 1, UINT_MAX / 17, INT_MAX / 17, UINT_MAX};

char *pat[] = {"%d", "%d Hello", "%08X"};

char *ans[ARRLEN(data)][ARRLEN(pat)] = {
    {"0", "0 Hello", "00000000"},
    {"126322567", "126322567 Hello", "07878787"},
    {"2147483647", "2147483647 Hello", "7FFFFFFF"},
    {"-2147483648", "-2147483648 Hello", "80000000"},
    {"-2147483647", "-2147483647 Hello", "80000001"},
    {"252645135", "252645135 Hello", "0F0F0F0F"},
    {"126322567", "126322567 Hello", "07878787"},
    {"-1", "-1 Hello", "FFFFFFFF"},
};
char buf[128];

void test_sprintf() {
  for (int i = 0; i < ARRLEN(data); i++) {
    for (int j = 0; j < ARRLEN(pat); j++) {
      sprintf(buf, pat[j], data[i]);
      check(strcmp(buf, ans[i][j]) == 0);
    }
  }
}
int main(int argc, char *argv[]) { test_sprintf(); }
