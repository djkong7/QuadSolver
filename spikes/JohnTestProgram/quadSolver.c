#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv){

	char aInput[256];
	char bInput[256];
	char cInput[256];

	printf("Welcome to Quadratic Formula Solver.\nPlease Enter a floating point value for a:\n");

	if(fgets(aInput, 256, stdin)){

		printf("Please enter a value for b:\n");
		if(fgets(bInput, 256, stdin)){

			printf("Please enter a value for c:\n");

			if(fgets(cInput, 256, stdin)){

				errno = 0;
				float a = strtof(aInput, NULL);
				float b = strtof(bInput, NULL);
				float c = strtof(cInput, NULL);

				if(errno == 0){

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
					}

				} else {
					printf("Input error. Exiting.\n");
				}									
			}
		}
	}
}
