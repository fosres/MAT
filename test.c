#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	uint8_t s[4];

	uint8_t temp[33];

	s[0] = 0x31;

	s[1] = 0x30;

	s[2] = 0x31;

	s[3] = 0x0;

	snprintf_s(temp,33,"%032s",s);	
	
	uint32_t w = (uint32_t)strtol(temp,NULL,2);

	printf("%032s\n",temp);	

	printf("%llu\n",w);

	return 0;
}
