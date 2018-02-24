#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "wline.h"

int wline(char* line){
	if (printf("%s",line) < 0) {
	    return -2;
	} else {
	    return 0;
        }
}
