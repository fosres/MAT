#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
	const uint8_t * locale = setlocale(LC_ALL,"ar_EG.UTF-8");

	uint8_t s[5] = {0x00,0x00,0xfd,0xf0,0x00};

	//printf("\U000000ae");

	rsize_t i = 0;

	while ( i < 10 )
	{
		printf("%c",0x82);

		i++;
	}
	
	return 0;
}
