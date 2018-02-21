#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void foutput(int errorNumber){
	switch (errorNumber) {
		case -1:
			if (wline("rline() Failed.") != 0) {
			    // What do we do in this case?
			}
			break;
		case -3:
			if (wline("3 input values required.") != 0) {
			    // What do we do in this case?
			}
			break;
		case -4:
			if (wline("Invalid characters entered.") != 0) {
			    // What do we do in this case?
			}
			break;
		default:
			if (wline("Invalid error number.") != 0) {
			    // What do we do in this case?
			}
			break;
	}
}
