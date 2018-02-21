#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

	char input[256];

	if (wline("Welcome to Quadratic Formula Solver.\nPlease enter A B C:\n") ==  -2) {
		foutput(-2);
	} else {
		int ret = rline(256, &input[0]);

		if (ret == 0) {

			char* splitInput = strtok(input," ");
			int i = 0;
			float a, b, c;
			while(splitInput != NULL && i < 3){
				if(i==0){
					a = strtof(splitInput, NULL);
				} else if (i==1){
					b = strtof(splitInput, NULL);
				} else if (i==2){
					c = strtof(splitInput, NULL);
				}
				splitInput = strtok(NULL, " ");
				i++;
			}

			if(i == 3){
				float x1, x2;

				ret = validate(&input[0], 256, &a, &b, &c);
				if(ret == 0){
					ret = qsolve(a, b, c, &x1, &x2);
				} else {
				  	foutput(ret);
				}
			} else {
				foutput(-3);
			}

		
		
		} else {
			foutput(ret);
		}
	}
	return 0;							
}
