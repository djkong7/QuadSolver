#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "rline.h"

int main() {
  char* line;
  int lengths[10] = {5, 10, 20, 32, 50, 64, 100, 128, 200, 256};
  for (int i = 0; i < 10; i++) {
    line = calloc(lengths[i], sizeof(char));
    if (rline(lengths[i], line) == -1) {
      printf("ERROR: Length %d failed!", lengths[i]);
    }
    
    free(line);
  }
  return 0;
}
