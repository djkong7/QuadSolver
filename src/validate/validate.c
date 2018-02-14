//double a,b,c;
//ret = validate(char *line, int n, double &a, double &b, double &c);
//check a!=0
//check all are numeric and doubles

#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

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