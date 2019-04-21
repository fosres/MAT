#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
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
	uint32_t utf8_hex = 0xd8a8;

	static uint8_t str[5];

	memcpy(str,&utf8_hex,sizeof(uint32_t));
	
	reverse(str);

	printf("%s%s%s%s",str,str,str,str);

	return 0;
}
