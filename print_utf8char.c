#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <locale.h>

void reverse(uint8_t arr[])
{
	uint8_t temp = 0;	
	
	for ( rsize_t i = 0, j = strlen(arr) - 1; i < j; i++, j-- )
	{
		temp = arr[i];

		arr[i] = arr[j];

		arr[j] = temp;

	}	

}

int main(void)
{
	uint8_t * locale = setlocale(LC_ALL,"");

	uint32_t x = 0xc381;
	
	printf("%.08x\n",x);

#if 0

Lesson Learned: It is much easier to print UTF-8 hexadecimals

using an uint32_t than a string of bytes

#endif

	rsize_t i = 0;

	return 0;

	uint8_t utf8_hex[3] = { 0xc3, 0x81, 0x0 };

	uint32_t store = 0;

	while ( i < 3 )
	{
		store += utf8_hex[i];

		store <<= 8;

		i++;
	}

	printf("%.08x\n",store);

			
}
