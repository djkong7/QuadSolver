#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "foutput.h"

int main() {
  for (int i = -1; i > -7; i--) {
	int fd = fork();
	if (fd == 0) {
		foutput(i);
	}
  }

  return 0;
}
