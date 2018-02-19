#include <stdio.h>

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
