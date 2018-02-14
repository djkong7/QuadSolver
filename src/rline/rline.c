//int n
//char line[100]
//ret = rline(n, &line);
//ret == 0 ok
//ret != 0 bad

#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int rline(int n, char* line){
	if(fgets(line, n, stdin)){
		return 1;
	} else {
		return -1;
	}
}
