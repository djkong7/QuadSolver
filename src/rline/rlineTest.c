#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "rline.h"

int main() {
  FILE *f = fopen("rlineTest.txt", "r");

  int numTests;
  char* numTestsLine = calloc(3, sizeof(char));
  fgets(numTestsLine, 3, f);
  numTests = atoi(numTestsLine);

  for (int i = 0; i < numTests; i++) {
    char* line;
    int lengths[10] = {5, 10, 20, 32, 50, 64, 100, 128, 200, 256};
    for (int j = 0; j < 10; j++) {
      line = calloc(lengths[j] + 1, sizeof(char));
      if (rline(lengths[j] + 1, line) == -1) {
        printf("ERROR: Test %d, Length %d failed!", i, lengths[j]);
      }

      if (strlen(line) == lengths[j]) {
        while ((getchar()) != '\n');
      }
      free(line);
    }
  }

  return 0;
}
