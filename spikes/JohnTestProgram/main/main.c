#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../rline/rline.h"
#include "../validate/validate.h"
#include "../qsolve/qsolve.h"

int main(int argc, char** argv){

	char input[256];

	printf("Welcome to Quadratic Formula Solver.\nPlease enter A B C:\n");
	int ret = rline(256, &input[0]);

	if(ret){

		char* splitInput = strtok(input," ");
		int i = 0;
		float a, b, c;
		while(splitInput != NULL){
			if(i==0){
				a = strtof(splitInput, NULL);
			} else if (i==1){
				b = strtof(splitInput, NULL);
			} else {
				c = strtof(splitInput, NULL);
			}
			splitInput = strtok(NULL, " ");
			i++;
		}

		if(i!=3){
			printf("Input error. Exiting.\n");
			return -1;
		}
		float x1, x2;

		ret = validate(&input[0], 256, &a, &b, &c);
		if(ret != -1){
			ret = qsolve(a, b, c, &x1, &x2);
		}
		
	}								
}