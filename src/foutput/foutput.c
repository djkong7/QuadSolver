#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "foutput.h"
#include "../wline/wline.h"

void foutput(int errorNumber){
	switch (errorNumber) {
		case -1:
			if (wline("rline() Failed.\n") != 0) {
			    perror("Error printing failed!");
			}
			exit(0);
		case -2:
			if (wline("wline() Failed.\n") != 0) {
			    perror("Error printing failed!");
			}
			exit(0);
		case -3:
			if (wline("3 input values required.\n") != 0) {
			    perror("Error printing failed!");
			}
			exit(0);
		case -4:
			if (wline("Invalid characters entered.\n") != 0) {
			    perror("Error printing failed!");
			}
			exit(0);
		case -5:
			if (wline("First value cannot be 0.\n") != 0) {
			    perror("Error printing failed!");
			}
			exit(0);
		case -6:
		  	if (wline("Two complex roots. No result.\n") != 0) {
			    perror("Error printing failed!");
			}
			exit(0);
		case -7:
			if (wline("Input cannot cannot fit into double. Calculation failed.\n") != 0){
				perror("Error printing failed!");
			}
			exit(0);
		case -10:
			if (wline("Input lost precision. Denormalized or too big for float.\n") != 0){
				perror("Error printing failed!");
			}
	}
}
