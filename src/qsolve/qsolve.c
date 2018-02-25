#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "qsolve.h"
#include "../wline/wline.h"

int qsolve(double a, double b, double c, double* x1,  double* x2){
	if (a == 0) {
		//cannot divide by 0
		return -5;
	}

	double desc = pow(b, 2.0) - (4 * a * c);

	if(desc < 0){
		//2 imaginary roots
		return -6;
	} else if (desc == 0) {
		wline("One real root with multiplicity two:");
	} else {
		wline("Two real roots:");
	}

	double r1, r2;
	if(b < 0){
		r1 = (-b + sqrt(desc)) / (2 * a);
		r2 = (c / (a * r1));
	} else if (b > 0) {
		r1 = (-b - sqrt(desc)) / (2 * a);
		r2 = (c / (a * r1));
	} else {
		r1 = sqrt(fabs(c / a));
		r2 = -sqrt(fabs(c / a));
	}

	if(desc != 0){
		printf("\nr1: %.7g\nr2: %.7g\n", r1, r2);
	} else {
		printf("\nr1: %.7g\n", r1);
	}
	
	return 0;
}
