#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "../rline/rline.h"
#include "../validate/validate.h"
#include "../qsolve/qsolve.h"
#include "../wline/wline.h"
#include "../foutput/foutput.h"
#include "../validate/validate.h"

int main(int argc, char** argv){

	char input[256];

	if (wline("Welcome to Quadratic Formula Solver.\nPlease enter A B C:\n") ==  -2) {
		foutput(-2);
	} else {
		int ret = rline(256, &input[0]);

		if (ret == 0) {
			double a,b,c;
			ret = validate(&input[0], 256, &a, &b, &c);
			if(ret == 1){
				double x1, x2;
				ret = qsolve(a, b, c, &x1, &x2);
			} else {
				//validate failed
				foutput(ret);
			}
		} else {
			//rline failed
			foutput(ret);
		}
	}
	return 0;							
}
