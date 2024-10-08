#include <stdint.h>
#include <string.h>
#include <trap.h>
#define N 16
uint8_t data_a[N] = {
    103, 198, 105, 115, 81, 255, 74, 236, 41, 205, 186, 171, 242, 251, 227, 70,
};
uint8_t data_b[N] = {
    103, 198, 105, 115, 81, 255, 74, 236, 41, 205, 186, 171, 242, 251, 227, 70,
};
int16_t ans[N * N * N] = {
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    -95,  -95,  -95,  -95,  -95,  -95,  -95,
    -95,  -95,  -95,  -95,  -95,  -95,  -95,  0,    -2,   -2,   -2,   -2,
    -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   -2,   0,    -12,  -12,
    -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  0,    22,
    22,   22,   22,   22,   22,   22,   22,   22,   22,   22,   0,    -152,
    -152, -152, -152, -152, -152, -152, -152, -152, -152, 0,    29,   29,
    29,   29,   29,   29,   29,   29,   29,   0,    -133, -133, -133, -133,
    -133, -133, -133, -133, 0,    62,   62,   62,   62,   62,   62,   62,
    0,    -102, -102, -102, -102, -102, -102, 0,    -83,  -83,  -83,  -83,
    -83,  0,    -68,  -68,  -68,  -68,  0,    -139, -139, -139, 0,    -148,
    -148, 0,    -124, 0,    0,    95,   95,   95,   95,   95,   95,   95,
    95,   95,   95,   95,   95,   95,   95,   0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    93,
    93,   93,   93,   93,   93,   93,   93,   93,   93,   93,   93,   93,
    0,    83,   83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
    83,   0,    117,  117,  117,  117,  117,  117,  117,  117,  117,  117,
    117,  0,    -57,  -57,  -57,  -57,  -57,  -57,  -57,  -57,  -57,  -57,
    0,    124,  124,  124,  124,  124,  124,  124,  124,  124,  0,    -38,
    -38,  -38,  -38,  -38,  -38,  -38,  -38,  0,    157,  157,  157,  157,
    157,  157,  157,  0,    -7,   -7,   -7,   -7,   -7,   -7,   0,    12,
    12,   12,   12,   12,   0,    27,   27,   27,   27,   0,    -44,  -44,
    -44,  0,    -53,  -53,  0,    -29,  0,    0,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    0,    -93,  -93,
    -93,  -93,  -93,  -93,  -93,  -93,  -93,  -93,  -93,  -93,  -93,  0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
    -10,  -10,  0,    24,   24,   24,   24,   24,   24,   24,   24,   24,
    24,   24,   0,    -150, -150, -150, -150, -150, -150, -150, -150, -150,
    -150, 0,    31,   31,   31,   31,   31,   31,   31,   31,   31,   0,
    -131, -131, -131, -131, -131, -131, -131, -131, 0,    64,   64,   64,
    64,   64,   64,   64,   0,    -100, -100, -100, -100, -100, -100, 0,
    -81,  -81,  -81,  -81,  -81,  0,    -66,  -66,  -66,  -66,  0,    -137,
    -137, -137, 0,    -146, -146, 0,    -122, 0,    0,    12,   12,   12,
    12,   12,   12,   12,   12,   12,   12,   12,   12,   0,    -83,  -83,
    -83,  -83,  -83,  -83,  -83,  -83,  -83,  -83,  -83,  -83,  0,    10,
    10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,   0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    34,   34,   34,   34,   34,   34,   34,   34,   34,   34,   34,
    0,    -140, -140, -140, -140, -140, -140, -140, -140, -140, -140, 0,
    41,   41,   41,   41,   41,   41,   41,   41,   41,   0,    -121, -121,
    -121, -121, -121, -121, -121, -121, 0,    74,   74,   74,   74,   74,
    74,   74,   0,    -90,  -90,  -90,  -90,  -90,  -90,  0,    -71,  -71,
    -71,  -71,  -71,  0,    -56,  -56,  -56,  -56,  0,    -127, -127, -127,
    0,    -136, -136, 0,    -112, 0,    0,    -22,  -22,  -22,  -22,  -22,
    -22,  -22,  -22,  -22,  -22,  -22,  0,    -117, -117, -117, -117, -117,
    -117, -117, -117, -117, -117, -117, 0,    -24,  -24,  -24,  -24,  -24,
    -24,  -24,  -24,  -24,  -24,  -24,  0,    -34,  -34,  -34,  -34,  -34,
    -34,  -34,  -34,  -34,  -34,  -34,  0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    -174, -174, -174, -174, -174,
    -174, -174, -174, -174, -174, 0,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    0,    -155, -155, -155, -155, -155, -155, -155, -155,
    0,    40,   40,   40,   40,   40,   40,   40,   0,    -124, -124, -124,
    -124, -124, -124, 0,    -105, -105, -105, -105, -105, 0,    -90,  -90,
    -90,  -90,  0,    -161, -161, -161, 0,    -170, -170, 0,    -146, 0,
    0,    152,  152,  152,  152,  152,  152,  152,  152,  152,  152,  0,
    57,   57,   57,   57,   57,   57,   57,   57,   57,   57,   0,    150,
    150,  150,  150,  150,  150,  150,  150,  150,  150,  0,    140,  140,
    140,  140,  140,  140,  140,  140,  140,  140,  0,    174,  174,  174,
    174,  174,  174,  174,  174,  174,  174,  0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    181,  181,  181,  181,  181,
    181,  181,  181,  181,  0,    19,   19,   19,   19,   19,   19,   19,
    19,   0,    214,  214,  214,  214,  214,  214,  214,  0,    50,   50,
    50,   50,   50,   50,   0,    69,   69,   69,   69,   69,   0,    84,
    84,   84,   84,   0,    13,   13,   13,   0,    4,    4,    0,    28,
    0,    0,    -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  0,
    -124, -124, -124, -124, -124, -124, -124, -124, -124, 0,    -31,  -31,
    -31,  -31,  -31,  -31,  -31,  -31,  -31,  0,    -41,  -41,  -41,  -41,
    -41,  -41,  -41,  -41,  -41,  0,    -7,   -7,   -7,   -7,   -7,   -7,
    -7,   -7,   -7,   0,    -181, -181, -181, -181, -181, -181, -181, -181,
    -181, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    -162, -162, -162, -162, -162, -162, -162, -162, 0,    33,   33,   33,
    33,   33,   33,   33,   0,    -131, -131, -131, -131, -131, -131, 0,
    -112, -112, -112, -112, -112, 0,    -97,  -97,  -97,  -97,  0,    -168,
    -168, -168, 0,    -177, -177, 0,    -153, 0,    0,    133,  133,  133,
    133,  133,  133,  133,  133,  0,    38,   38,   38,   38,   38,   38,
    38,   38,   0,    131,  131,  131,  131,  131,  131,  131,  131,  0,
    121,  121,  121,  121,  121,  121,  121,  121,  0,    155,  155,  155,
    155,  155,  155,  155,  155,  0,    -19,  -19,  -19,  -19,  -19,  -19,
    -19,  -19,  0,    162,  162,  162,  162,  162,  162,  162,  162,  0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    195,  195,  195,
    195,  195,  195,  195,  0,    31,   31,   31,   31,   31,   31,   0,
    50,   50,   50,   50,   50,   0,    65,   65,   65,   65,   0,    -6,
    -6,   -6,   0,    -15,  -15,  0,    9,    0,    0,    -62,  -62,  -62,
    -62,  -62,  -62,  -62,  0,    -157, -157, -157, -157, -157, -157, -157,
    0,    -64,  -64,  -64,  -64,  -64,  -64,  -64,  0,    -74,  -74,  -74,
    -74,  -74,  -74,  -74,  0,    -40,  -40,  -40,  -40,  -40,  -40,  -40,
    0,    -214, -214, -214, -214, -214, -214, -214, 0,    -33,  -33,  -33,
    -33,  -33,  -33,  -33,  0,    -195, -195, -195, -195, -195, -195, -195,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    -164, -164, -164,
    -164, -164, -164, 0,    -145, -145, -145, -145, -145, 0,    -130, -130,
    -130, -130, 0,    -201, -201, -201, 0,    -210, -210, 0,    -186, 0,
    0,    102,  102,  102,  102,  102,  102,  0,    7,    7,    7,    7,
    7,    7,    0,    100,  100,  100,  100,  100,  100,  0,    90,   90,
    90,   90,   90,   90,   0,    124,  124,  124,  124,  124,  124,  0,
    -50,  -50,  -50,  -50,  -50,  -50,  0,    131,  131,  131,  131,  131,
    131,  0,    -31,  -31,  -31,  -31,  -31,  -31,  0,    164,  164,  164,
    164,  164,  164,  0,    0,    0,    0,    0,    0,    0,    0,    19,
    19,   19,   19,   19,   0,    34,   34,   34,   34,   0,    -37,  -37,
    -37,  0,    -46,  -46,  0,    -22,  0,    0,    83,   83,   83,   83,
    83,   0,    -12,  -12,  -12,  -12,  -12,  0,    81,   81,   81,   81,
    81,   0,    71,   71,   71,   71,   71,   0,    105,  105,  105,  105,
    105,  0,    -69,  -69,  -69,  -69,  -69,  0,    112,  112,  112,  112,
    112,  0,    -50,  -50,  -50,  -50,  -50,  0,    145,  145,  145,  145,
    145,  0,    -19,  -19,  -19,  -19,  -19,  0,    0,    0,    0,    0,
    0,    0,    15,   15,   15,   15,   0,    -56,  -56,  -56,  0,    -65,
    -65,  0,    -41,  0,    0,    68,   68,   68,   68,   0,    -27,  -27,
    -27,  -27,  0,    66,   66,   66,   66,   0,    56,   56,   56,   56,
    0,    90,   90,   90,   90,   0,    -84,  -84,  -84,  -84,  0,    97,
    97,   97,   97,   0,    -65,  -65,  -65,  -65,  0,    130,  130,  130,
    130,  0,    -34,  -34,  -34,  -34,  0,    -15,  -15,  -15,  -15,  0,
    0,    0,    0,    0,    0,    -71,  -71,  -71,  0,    -80,  -80,  0,
    -56,  0,    0,    139,  139,  139,  0,    44,   44,   44,   0,    137,
    137,  137,  0,    127,  127,  127,  0,    161,  161,  161,  0,    -13,
    -13,  -13,  0,    168,  168,  168,  0,    6,    6,    6,    0,    201,
    201,  201,  0,    37,   37,   37,   0,    56,   56,   56,   0,    71,
    71,   71,   0,    0,    0,    0,    0,    -9,   -9,   0,    15,   0,
    0,    148,  148,  0,    53,   53,   0,    146,  146,  0,    136,  136,
    0,    170,  170,  0,    -4,   -4,   0,    177,  177,  0,    15,   15,
    0,    210,  210,  0,    46,   46,   0,    65,   65,   0,    80,   80,
    0,    9,    9,    0,    0,    0,    0,    24,   0,    0,    124,  0,
    29,   0,    122,  0,    112,  0,    146,  0,    -28,  0,    153,  0,
    -9,   0,    186,  0,    22,   0,    41,   0,    56,   0,    -15,  0,
    -24,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0};

void init() {}

void test_memcmp() {
  int l1, l2, s, cnt = 0;
  for (l1 = 0; l1 < N; l1++) {
    for (l2 = 0; l2 < N; l2++) {
      for (s = 0; l1 + s < N && l2 + s < N; s++) {
        check(memcmp(data_a + l1, data_b + l2, s) == ans[cnt]);
        cnt++;
      }
    }
  }
}
int main(int argc, char *argv[]) { test_memcmp(); }
