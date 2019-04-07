#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("\e[1;33m");	
	printf("Testing         ");
	printf("\e[0m");

	printf("\e[38;5;214m");
	printf("Testing\n");
	return 0;
}
