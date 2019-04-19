#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t * mystrstr(char * s, char *t)
{
  if ( *s == '\0' && *s == *t )
  { return s; }

  if (*t == '\0')
  { return &s[strlen(s)];}

  char * s_start; char * t_zero = t;

  while (*s != '\0')
  {
    if (*s != *t)
    {
      s++;

      continue;
    }

    s_start = s;

    while (*t != '\0' && *s == *t)
    {
      s++; t++;
    }

    if ( (*t != '\0') && (*(s-1) != t[strlen(t_zero)-1]) )
    {
      s = s_start; s++; t = t_zero;
    }

    else
    {
      return s_start;
    }
  }

  return NULL;

}

uint8_t * utf8hextostr(uint32_t utf8_hex)
{
	static uint8_t hex_str[5];
	
	memcpy(hex_str,5*sizeof(uint8_t),sizeof(uint32_t));

	reverse(hex_str);

	return hex_str;	

}

uint32_t utf8_to_codept(uint8_t * utf8_str,const rsize_t STR_SIZE) 
{
	uint32_t code_point = 0x00;

	reverse(utf8_str);

	memcpy(code_point,utf8_str,sizeof(STR_SIZE));	

	return code_point;	

}

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



