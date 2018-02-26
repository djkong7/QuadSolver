// test validate
#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "validate.h"

int main() {
  FILE *f = fopen("validateInput.txt", "r");
  char* lineRead = calloc(3, sizeof(char));
  size_t len = 0;
  ssize_t read;
  int validateError = 0;
  int count = 0;

  //Values for validate
  int n = 0;
  double a;
  double b;
  double c;

  while ((read = getline(&lineRead, &len, f)) != -1) {
    validateError = validate(lineRead, n, &a, &b, &c);

    if (validateError == -3) {
      printf("Validate ERROR: Test %d failed. Wrong amount of numbers.\n", count);
    } else if (validateError == -7){
      printf("Validate ERROR: Test %d failed. Input cannot fit in double.\n", count);
    } else if(validateError == -10){
      printf("Validate ERROR: Test %d lost accuracy\n", count);
    }

    count++;

  }

  return 0;
}
