// test validate
#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "validate.h"

int main() {
  FILE *f = fopen("validateTest.txt", "r");
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
      printf("ERROR: Test %d failed!\n", count);
    }
    else if(validateError == -7){
      printf("Test lost accuracy\n");
    }

    count++;

  }

  return 0;
}
