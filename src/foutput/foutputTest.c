#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "foutput.h"

int main() {
  for (int i = -1; i > -7; i--) {
	int pid = fork();
	if (pid == 0) {
		foutput(i);
	}
	waitpid(pid, NULL, 0);
  }

  return 0;
}
