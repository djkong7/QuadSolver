//double x1, x2;
// ret = solve(a, b, c, &x1, &x2)
//x1, x2 are real roots only
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



int qsolve(float a, float b, float c, float* x1,  float* x2){
	if(a==0){
		printf("a is 0. No output.\n");
		return -1;
	}

	float desc = powf(b,2.0)-(4*a*c);
		
	if(desc<0){
		printf("No output: two complex roots.\n");
		return -1;
	} else if (desc==0) {
		printf("One real root with multiplicity two:");
	} else {
		printf("Two real roots:");
	}
	float r1, r2;
	if(b<0){
		r1 = (-b+sqrt(desc))/(2*a);
		r2 = (c/(a*r1));
	} else if (b>0) {
		r1 = (-b-sqrt(desc))/(2*a);
		r2 = (c/(a*r1));
	} else {
		r1 = sqrt(abs(c/a));
		r2 = -sqrt(abs(c/a));
	}

	if(errno == 0){
		printf(" No calculation failures.\n");
		if(desc!=0){
			printf("r1: %.9g\nr2: %.9g\n", r1, r2);
		} else {
			printf("r1: %.9g\n", r1);
		}
	} else {
		printf(" Calculation failures. Cannot guarantee precise answer.\n");
		return -1;
	}
	return 0;
}