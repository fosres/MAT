#include <stdio.h>
#include <stdlib.h>

void reverse(uint8_t s[])
{
	uint8_t temp = 0;

	for ( rsize_t i = 0, j = strnlen_s(s,RSIZE_MAX) - 1; i < j; i++, j-- )
	{
		temp = s[i];

		s[i] = s[j];

		s[j] = temp;	
	}

}

int main(void)
{

	printf("%s",);
	return 0;
}
