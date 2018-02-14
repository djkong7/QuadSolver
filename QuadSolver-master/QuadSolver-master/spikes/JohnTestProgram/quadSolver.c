#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int rline(int n, char* line);
int qsolve(float a, float b, float c, float* x1,  float* x2);
int validate(char* line, int n, float* a, float* b, float* c);
int wline(char* line);
int foutput(char* line);

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

		if(i<3){
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

int rline(int n, char* line){
	if(fgets(line, n, stdin)){
		return 1;
	} else {
		return -1;
	}
}

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

int validate(char* line, int n, float* a, float* b, float* c){
	while(*line!='\0'){
		if((*line<48&&*line!=32)||(*line>57&&(*line!=69||*line!=101))){
			printf("Invalid input. Exiting.\n");
			return -1;
		}
		line++;
	}
	return 0;
}

int wline(char* line){
	printf("%s",line);
	return 0;
}

int foutput(char* line){
	printf("%s",line);
	return 0;
}
