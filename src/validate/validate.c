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
	for (int i = 0; line[i] != '\0'; i++) {
		if ((line[i] < 48 && line[i] != 32) || (line[i] > 57 && (line[i] != 69 || line[i] != 101))) {
			return -4;
		}
	}
	return 0;
}
