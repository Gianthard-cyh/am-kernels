
#include <stdint.h>
#include <trap.h>
#define N 512
char data[N] = {
    2,   17,  52,  9,   121, 42,  110, 12,  62,  36,  69,  94,  51,  39,  24,
    81,  9,   45,  118, 126, 74,  18,  83,  15,  110, 11,  26,  109, 49,  110,
    3,   43,  1,   47,  44,  114, 89,  28,  118, 24,  56,  60,  110, 107, 91,
    0,   54,  100, 37,  45,  92,  111, 56,  48,  0,   39,  51,  18,  21,  92,
    1,   24,  9,   2,   64,  45,  108, 26,  65,  99,  43,  114, 24,  0,   94,
    116, 18,  13,  81,  56,  51,  38,  40,  107, 86,  32,  11,  11,  50,  32,
    103, 52,  48,  104, 46,  112, 15,  28,  4,   80,  119, 39,  67,  17,  57,
    27,  125, 76,  0,   71,  5,   75,  110, 37,  47,  61,  70,  58,  64,  120,
    82,  33,  0,   4,   10,  84,  108, 17,  104, 104, 90,  88,  16,  22,  97,
    74,  41,  95,  15,  74,  32,  20,  14,  15,  0,   62,  76,  119, 120, 0,
    105, 76,  39,  0,   72,  41,  83,  45,  59,  60,  23,  22,  14,  31,  44,
    111, 0,   78,  80,  112, 0,   104, 0,   39,  0,   47,  93,  60,  39,  87,
    0,   9,   28,  105, 17,  92,  0,   100, 10,  79,  26,  33,  93,  40,  57,
    2,   24,  35,  80,  96,  21,  97,  0,   18,  2,   0,   57,  95,  118, 89,
    47,  49,  98,  67,  28,  107, 32,  40,  73,  43,  111, 99,  68,  77,  4,
    125, 71,  20,  26,  17,  117, 39,  106, 55,  49,  100, 105, 107, 69,  88,
    69,  108, 10,  32,  49,  30,  13,  73,  70,  86,  116, 54,  50,  50,  123,
    54,  48,  60,  74,  66,  77,  56,  105, 48,  104, 20,  22,  82,  0,   83,
    35,  61,  64,  45,  93,  105, 76,  98,  0,   11,  57,  33,  66,  99,  83,
    54,  26,  5,   114, 93,  63,  56,  14,  42,  105, 118, 62,  119, 65,  54,
    75,  100, 115, 12,  11,  73,  110, 79,  45,  35,  90,  94,  68,  21,  59,
    25,  76,  77,  22,  55,  43,  85,  104, 50,  119, 74,  33,  46,  66,  99,
    100, 14,  64,  80,  18,  67,  19,  1,   19,  56,  28,  102, 15,  97,  123,
    74,  114, 64,  25,  9,   120, 60,  86,  97,  110, 71,  44,  17,  117, 102,
    0,   83,  116, 37,  28,  126, 105, 47,  1,   116, 103, 21,  91,  111, 118,
    88,  58,  97,  25,  83,  98,  10,  17,  58,  99,  119, 0,   8,   1,   111,
    110, 109, 67,  91,  12,  88,  91,  117, 8,   84,  98,  104, 105, 63,  88,
    89,  16,  19,  59,  33,  95,  31,  44,  104, 81,  16,  88,  75,  25,  90,
    59,  0,   72,  119, 0,   84,  80,  56,  66,  80,  5,   38,  57,  110, 93,
    10,  64,  109, 22,  124, 15,  117, 20,  51,  86,  101, 60,  47,  49,  77,
    10,  100, 77,  75,  92,  42,  24,  45,  0,   91,  126, 95,  121, 48,  71,
    79,  59,  8,   61,  81,  124, 68,  63,  17,  120, 22,  110, 45,  61,  32,
    122, 72,  6,   72,  12,  90,  107, 36,  9,   70,  119, 0,   31,  113, 48,
    94,  65,  99,  0,   118, 53,  92,  60,  108, 101, 45,  3,   85,  90,  65,
    109, 85,
};
uint32_t ans[N] = {
    45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27,
    26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,
    7,  6,  5,  4,  3,  2,  1,  0,  8,  7,  6,  5,  4,  3,  2,  1,  0,  18, 17,
    16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  34, 33,
    32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14,
    13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  13, 12, 11, 10, 9,
    8,  7,  6,  5,  4,  3,  2,  1,  0,  21, 20, 19, 18, 17, 16, 15, 14, 13, 12,
    11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  4,  3,  2,  1,  0,  3,  2,
    1,  0,  12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  3,  2,  1,  0,
    1,  0,  1,  0,  5,  4,  3,  2,  1,  0,  5,  4,  3,  2,  1,  0,  15, 14, 13,
    12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  2,  1,  0,  62, 61, 60,
    59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
    40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22,
    21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,
    2,  1,  0,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  81, 80, 79, 78, 77, 76,
    75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57,
    56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38,
    37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19,
    18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,
    25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,
    6,  5,  4,  3,  2,  1,  0,  34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23,
    22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,
    3,  2,  1,  0,  2,  1,  0,  33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22,
    21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,
    2,  1,  0,  32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17,
    16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  6,  5,
    4,  3,  2,  1,  0,  13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,
};

void test_strlen() {
  for (int i = 0; i < N; i++) {
    check(ans[i] == strlen(data + i));
  }
}
int main(int argc, char *argv[]) { test_strlen(); }
