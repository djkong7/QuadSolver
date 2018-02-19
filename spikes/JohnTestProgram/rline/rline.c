#include <stdio.h>

int rline(int n, char* line){
	if(fgets(line, n, stdin)){
		return 1;
	} else {
		return -1;
	}
}
