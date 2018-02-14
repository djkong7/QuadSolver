#include <stdio.h>
#include <float.h>

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
  printf("Largest Float - %.10e (0x%x)\n", test.f, test.i);
  //Smallest float
  test.f = FLT_MIN;
  printf("Smallest Positive Float - %.10e (0x%08x)\n", test.f, test.i);

  //NaN
  test.i = -1;
  printf("32 Bits set to 1 - %f\n", test.f);

  //infinity
  //Set sign bit to 0
  //Set EXP field to all 1
  //Set FRAC field to all 0
  test.i = -1 & 0x7F800000;
  printf("Infinity - %.10e\n", test.f);

  printf("\nView numbers as bits\n");
  test.f = 15;
  printf("15 as a float - 0x%x\n", test.i);
  test.f = 15.123456789;
  printf("15.123456789 as encoded float - 0x%x\n", test.i);
  printf("15.123456789 as a float - %.10f\n", test.f);

  return 0;
}
