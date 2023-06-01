#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int main(int argc, char* argv[])
{
	int	num;
	FILE*	fptr;

	fptr = fopen("data/2.in", "w");
	if (fptr == NULL) {
		printf("Error!");
		exit(1);
	}

	printf("Enter num: ");
	scanf("%d", &num);

	fprintf(fptr, "%d",num);
	fclose(fptr);
	return 0;
}

