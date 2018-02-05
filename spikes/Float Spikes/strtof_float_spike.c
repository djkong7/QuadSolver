#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char** argv){

	if(argc==2){
		errno = 0;
		char* input = argv[1];
		float test = strtof(input, NULL);
		if(errno!=0){
			printf("Conversion failed");
		} else {
			printf("%f",test);
		}
	}

	return 0;
}
