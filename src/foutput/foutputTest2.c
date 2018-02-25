#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "foutput.h"

int main() {
  char* errorMessages[7] = {"rline() Failed.\n",
			    "wline() Failed.\n",
			    "3 input values required.\n",
			    "Invalid characters entered.\n",
			    "First value cannot be 0.\n",
			    "Two complex roots. No result.\n",
				"Input cannot cannot fit into double. Calculation failed.\n"};

  for (int i = -1; i > -8; i--) {
	char* error = calloc(1000, sizeof(char));
	fgets(error, 1000, stdin);
	if ((strncmp(error, errorMessages[-i - 1], strlen(errorMessages[-i - 1]))) != 0) {
		printf("foutputTest Failed.");
	}

	free(error);
  }
  
  return 0;
}
