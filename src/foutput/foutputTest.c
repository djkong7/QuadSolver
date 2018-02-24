#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "foutput.h"

int main() {
  for (int i = -1; i > -8; i--) {
	foutput(i);
  }

  return 0;
}
