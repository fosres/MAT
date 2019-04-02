#include <stdio.h>
#include <stdint.h>

int main(void)
{
	printf("%llu\n",UINTMAX_MAX);

	fprintf(stderr,"\033[1;31m");
	fprintf(stderr,"Testing\n");
	fprintf(stderr,"%llu",RSIZE_MAX);
	fprintf(stderr,"\033[0m");
}
