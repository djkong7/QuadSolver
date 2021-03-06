#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "wline.h"

int main() {
  FILE *f = fopen("wlineTest.txt", "r");
  char* lineRead = calloc(3, sizeof(char));
  size_t len = 0;
  ssize_t read;
  int wlineTest = 0;
  int count = 0;

  while ((read = getline(&lineRead, &len, f)) != -1) {
        wlineTest = wline(lineRead);

        if (wlineTest == -1) {
          printf("ERROR: Test %d, input %s failed!", count, lineRead);
        }
    }

  return 0;
}
