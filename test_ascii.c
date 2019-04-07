#include <stdio.h>
#include <wchar.h>

int main(void)
{
	printf("\u00b7");
	
	wputchar(0x00b7);

	return 0;
}
