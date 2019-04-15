#include <stdio.h>
#include <locale.h>

int main(void)
{
	const uint8_t * locale = setlocale(LC_ALL,"");

	printf("The current locale is %s\n",locale);

	printf(u8"%lc\n",0x10fffe);

}
