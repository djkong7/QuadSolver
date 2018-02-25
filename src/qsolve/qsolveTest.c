#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "qsolve.h"

int main() {
  FILE *f = fopen("qsolveTest.txt", "r");
  char lineRead[128];
  int size = 128;
  int qsolveError = 0;
  int count = 0;

  //Values for validate
  double a, b, c, x1, x2, x1Expected, x2Expected;

  while (fgets(lineRead, size, f) != NULL) {
  	char* splitInput = strtok(lineRead,",");
  	a = strtod(splitInput, NULL);
  	splitInput = strtok(NULL, ",");
  	b = strtod(splitInput, NULL);
  	splitInput = strtok(NULL, ",");
  	c = strtod(splitInput, NULL);
  	splitInput = strtok(NULL, ",");
  	x1Expected = strtod(splitInput, NULL);
  	splitInput = strtok(NULL, ",");
  	x2Expected = strtod(splitInput, NULL);

    qsolveError = qsolve(a, b, c, &x1, &x2);

    //if abs error is greater than 7 decimal places
    if(fabs(x1-x1Expected) > .0000001 || fabs(x2-x2Expected) > .0000001){
    	fprintf(stderr,"qsolve Error: Test #%d failed. Output does not match.\n",count);
    } else if (qsolveError != 0) {
    	fprintf(stderr,"qsolve Error: Test #%d failed. Error in input.\n",count);
    }
    count++;

  }

  return 0;
}
