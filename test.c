#include <stdio.h>
int main(void)
{
	uint64_t a = ~0;

	printf("0x%-16.16x\n",a);

	printf("%-10d\n",3);

	(3 % 3) != 0 ? ( printf("Yes") ): ( putchar(0x0) );

	putchar(0x30);

	return 0;
}
