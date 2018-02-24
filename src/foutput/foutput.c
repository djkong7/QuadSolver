#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "../wline/wline.h"

void foutput(int errorNumber){
	switch (errorNumber) {
		case 0:
			if (wline("Success.\n") != 0) {
			    err_sys("Error printing failed!");
			}
			break;
		case -1:
			if (wline("rline() Failed.\n") != 0) {
			    err_sys("Error printing failed!");
			}
			break;
		case -2:
			if (wline("wline() Failed.\n") != 0) {
			    err_sys("Error printing failed!");
			}
			break;
		case -3:
			if (wline("3 input values required.\n") != 0) {
			    err_sys("Error printing failed!");
			}
			break;
		case -4:
			if (wline("Invalid characters entered.\n") != 0) {
			    err_sys("Error printing failed!");
			}
			break;
		case -5:
			if (wline("First value cannot be 0.\n") != 0) {
			    err_sys("Error printing failed!");
			}
			break;
		case -6:
		  	if (wline("Two complex roots. No result.\n") != 0) {
			    err_sys("Error printing failed!");
			}
	}
}
