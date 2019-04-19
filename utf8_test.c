#include <stdio.h>
#include <stdint.h>
#include <string.h>

#if 0
Lesson Learned: It is easier to reverse the actual number

than the string representation of the Unicode number
#endif

uint32_t reverse_uint32_t(uint32_t x)
{
	uint32_t ans = 0x00;

	while ( x != 0 )
	{
		ans += (x & 0xff);

		ans <<= 8;

		x >>= 8;

		x &= 0x00ffffff;
		
	}

	return ans;

}

int main(void)
{

#if 0
Lesson Learned: It is easier to reverse the actual number

than the string representation of the Unicode number
#endif
	
	uint32_t utf8_hex = 0xe0a194;

	printf("%.8x\n",utf8_hex);

	uint32_t utf8_hex_rev = reverse_uint32_t(utf8_hex);

	printf("%.8x\n",utf8_hex_rev);

	return 0;
}
