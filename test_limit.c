#include <stdio.h>
#include <stdint.h>

int main(void)
{
	printf("%llu\n",UINTMAX_MAX);

	fprintf(stderr,"\033[1;31m");
	fprintf(stderr,"Testing\n");
	fprintf(stderr,"%llu\n",RSIZE_MAX);
	fprintf(stderr,"%llu\n",sizeof(uint32_t) >> 3);
	uint64_t K = UINTMAX_MAX;
	fprintf(stderr,"%llu\n",K++);
	fprintf(stderr,"%llu\n",K);
	fprintf(stderr,"\033[0m");
}
