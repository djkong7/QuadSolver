#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){

	float a = 0,b = 0,c = 0;
	double duba,dubb,dubc,negb,disc,sqr,root1,root2;
	char *buffer = calloc(4096,sizeof(char));
	char *temp=buffer;

	fprintf(stdout, "Enter a value for a:\n");
	fgets(buffer,sizeof(buffer),stdin);
	temp = buffer;
	a = strtof(temp,NULL);
	if(errno){
		fprintf(stderr, "ERROR: %s\nEXITING...\n", strerror(errno));
		exit(errno);
	}else if(a == 0){
		fprintf(stderr, "ERROR! a cannot equal becuase of divided by 0 error.\n");
		exit(0);
	}

	fprintf(stdout, "Enter a value for b:\n");
	fgets(buffer,sizeof(buffer),stdin);
	temp = buffer;
	b = strtof(temp,NULL);
	if(errno){
		fprintf(stderr, "ERROR: %s\nEXITING...\n", strerror(errno));
		exit(errno);
	}

	fprintf(stdout, "Enter a value for c:\n");
	fgets(buffer,sizeof(buffer),stdin);
	temp = buffer;
	c = strtof(temp,NULL);
	if(errno){
		fprintf(stderr, "ERROR: %s\nEXITING...\n", strerror(errno));
		exit(errno);
	}

	duba = (double)a;
	dubb = (double)b;
	dubc = (double)c;
	
	negb=0-b;

	disc = dubb*dubb-4*duba*dubc;
	if(disc < 0){
		fprintf(stdout, "Solution: 2 complex roots.\n");
		exit(0);
	}

	sqr = sqrt(disc);

	root1 = (negb+sqr)/(duba*2);
	root2 = (negb-sqr)/(duba*2);

	fprintf(stdout, "Root 1: %.40f\nRoot 2: %.40f\n", root1,root2);



	//fprintf(stderr, "a: %.40f\nb: %.40f\nc: %.40f\n",a,b,c);

	return 0;
}