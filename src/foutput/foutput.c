#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "../wline/wline.h"

void foutput(int errorNumber){
	switch (errorNumber) {
		case -1:
			if (wline("rline() Failed.\n") != 0) {
			    // What do we do in this case?
			}
			break;
		case -3:
			if (wline("3 input values required.\n") != 0) {
			    // What do we do in this case?
			}
			break;
		case -4:
			if (wline("Invalid characters entered.\n") != 0) {
			    // What do we do in this case?
			}
			break;
		case -5:
			if (wline("First value cannot be 0.\n") != 0) {

			}
		case -6:
		  if (wline("Two complex roots. No result.\n") != 0) {
				
			}
		default:
			if (wline("Invalid error number.") != 0) {
			    // What do we do in this case?
			}
			break;
	}
}
