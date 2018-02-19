#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int rline(int n, char* line){
	if(fgets(line, n, stdin)){
		return 1;
	} else {
		return 0;
	}
}
