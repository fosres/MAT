#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <locale.h>
//#include <wchar.h>
#include <iconv.h>

void reverse(unsigned char s[])
{
  for (int i = 0, j = strlen(s)-1; i < j; i++, j--)
  {
    unsigned char temp = s[i];

    s[i] = s[j];

    s[j] = temp;
  }
}

int main(void)
{
	const uint8_t * locale = setlocale(LC_ALL,"");

	//printf("The locale is %s\n",locale);

	uint32_t utf8_hex = 0xe1bea8;	
	
	uint32_t utf8_space = 0x20;

	
	static uint8_t s[5];
	
	memcpy(s,&utf8_hex,sizeof(uint32_t));

	reverse(s);

#if 0	
	rsize_t i = 0;

	while ( i < 5 )
	{
		printf("%.02x",s[i]);

		i++;
	}

	putchar(0xa);
#endif
	printf("%s",s);

//	memset_s(s,5*sizeof(uint8_t),0x0,5*sizeof(uint8_t));

	memcpy(s,&utf8_space,sizeof(uint32_t));	

	reverse(s);

//	printf("%s",s);

//	memset_s(s,5*sizeof(uint8_t),0x0,5*sizeof(uint8_t));

	memcpy(s,&utf8_hex,sizeof(uint32_t));

	reverse(s);

	printf("%s",s);

	printf("%s",s);

	printf("%s",s);

	printf("%s",s);

	printf("%s",s);

	return 0;
}
