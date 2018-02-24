#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int validate(char* line, int n, double* a, double* b, double* c){
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
		if(i==0){
			*a = strtod(splitInput, NULL);
		} else if (i==1){
			*b = strtod(splitInput, NULL);
		} else if (i==2){
			*c = strtod(splitInput, NULL);
		}
		splitInput = strtok(NULL, " ");
		i++;
	}

	//only 3 numbers inputted...
	if(i==3){
		//all good
		return 1;
	} else {
		//too many/too few numbers
		return -3;
	}
}
