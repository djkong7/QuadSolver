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
	double a, b, c, x1, x2;

	foutput(wline("Welcome to Quadratic Formula Solver.\nPlease enter A B C:\n"));
	foutput(rline(256, &input[0]));
	foutput(validate(&input[0], 256, &a, &b, &c));
	foutput(qsolve(a, b, c, &x1, &x2));

	return 0;							
}
