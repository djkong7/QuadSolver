#include <stdio.h>
//For float constants
#include <float.h>
//For test macros
#include <math.h>

union myUnion {
  //Enter the float in decimal
  float f;
  //Interpret as 32 bit
  unsigned i;
};

int main(int argc, char **argv) {
  union myUnion test;

  //Largest float
  test.f = FLT_MAX;
  printf("Largest Float: %.10e (0x%x)\n", test.f, test.i);
  //Smallest float
  test.f = FLT_MIN;
  printf("Smallest Positive Float: %.10e (0x%08x)\n", test.f, test.i);

  //NaN
  test.i = -1;
  printf("\n32 Bits set to 1: %f\n", test.f);
  printf("Comparison to NaN: ");
  printf(isnan(test.f) ? "True\n":"False\n");

  //infinity
  //Set sign bit to 0
  //Set EXP field to all 1
  //Set FRAC field to all 0
  //01111111 10000000 00000000 00000000
  test.i = 0x7F800000;
  printf("\nInfinity: %.10e\n", test.f);
  printf("Comparison to INF: ");
  printf(isinf(test.f) ? "True\n":"False\n");
  printf("Comparison to NaN: ");
  printf(isnan(test.f) ? "True\n":"False\n");
  //-infinity
  //11111111 10000000 00000000 00000000
  test.i = 0xFF800000;
  printf("-Infinity: %.10e\n", test.f);
  printf("Comparison to INF: ");
  printf(isinf(test.f) ? "True\n":"False\n");
  printf("Comparison to NaN: ");
  printf(isnan(test.f) ? "True\n":"False\n");

  printf("\n");
  printf("View numbers as bits\n");
  test.f = 15;
  printf("15 as a float: 0x%x\n", test.i);
  test.f = 15.123456789;
  printf("15.123456789 as encoded float: 0x%x\n", test.i);
  printf("15.123456789 as a float: %.10f\n", test.f);

  test.i = 0x00000001;
  printf("\nDenormalized\nIs 0x00000001 Normal?: ");
  printf(isnormal(test.f) ? "True\n":"False\n");

  return 0;
}
