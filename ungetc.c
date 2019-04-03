#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	putchar('T'); putchar('h'); putchar('e');
	ungetc(0x30,stdout);
	ungetc(0x30,stdout);
	ungetc(0x30,stdout);
	putchar(' ');	
	return 0;
}
