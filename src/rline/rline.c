#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "rline.h"

int rline(int n, char* line){
	if(fgets(line, n, stdin)){
		return 0;
	} else {
		return -1;
	}
}
