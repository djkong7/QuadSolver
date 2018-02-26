#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "validate.h"

int validate(char *line, int n, double *a, double *b, double *c){
	for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
		char cur = line[i];
		if ((cur < 48 && cur != 32 && cur != 46 && cur != 45) || (cur > 57 && cur != 69 && cur != 101)) {
			//invalid char inputted
			return -4;
		}

		if(i>=n){
			break;
		}
	}

	char* splitInput = strtok(line," ");
	int i = 0;
	while(splitInput != NULL){
		char* endptr = NULL;
		if(i==0){
			*a = strtod(splitInput, &endptr);
		} else if (i==1){
			*b = strtod(splitInput, &endptr);
		} else if (i==2){
			*c = strtod(splitInput, &endptr);
		}

		if(splitInput == endptr || errno){
			//invalid double input
			return -7;
		}

		splitInput = strtok(NULL, " ");
		i++;
	}

	//Check for lost accuracy
	float aFloat = (float)*a;
	float bFloat = (float)*b;
	float cFloat = (float)*c;

	int accLost = 0;
	//The floats are not equal to their double equivalents
	if((*a != (double)aFloat) || (*b != (double)bFloat) || (*c != (double)cFloat)){
		accLost = 1;
	}

	if(fpclassify(*a)==FP_SUBNORMAL||fpclassify(*b)==FP_SUBNORMAL||fpclassify(*c)==FP_SUBNORMAL){
		accLost = 1;
	}

	//only 3 numbers inputted...
	if(i==3 && accLost == 0){
		//all good
		return 0;
	} else if(i==3 && accLost == 1){
		//Accuracy was lost
		return -10;
	} else {
		//too many/too few numbers
		return -3;
	}
}
