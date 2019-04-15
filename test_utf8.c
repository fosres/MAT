#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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

int isutf8(FILE * in)  
{
		
	
	if ( argc < 2 )
	{
		fprintf(stderr,"\e[38;5;196m");
		
		fprintf(stderr,"%llu: Error: Less than two arguments!\n",__LINE__);

		fprintf(stderr,"\e[38;5;0m");

		return -1;
	}

	FILE * in = NULL;

	if ( ( in = fopen(argv[1],"rb") ) == NULL )
	{
		fprintf(stderr,"\e[38;5;196m");
		
		fprintf(stderr,"%llu: Error: Failed to open file!\n",__LINE__);
	
		fprintf(stderr,"\e[38;5;0m");

		return -1;
		
	}

	fseek(in,0,SEEK_END);

	const rsize_t FILE_SIZE = ftell(in);

	rewind(in);

	static uint8_t * file_arr = (uint8_t *)calloc(FILE_SIZE << 3,sizeof(uint8_t));
	
	static uint8_t * file_arr_p = &file_arr[0];
	
	uint8_t c = 0;

	const uint32_t u32_lftpt = 0xeda08000;

	const uint32_t u32_rgtpt = 0xedbfbf00;

	uint32_t u32_temp = u32_ltfpt;

	static uint8_t code_point_hex[9];

	rsize_t i = 0;
#if 0
Unicode hexadecimal code points between U+d800 and U+dfff are forbidden in UTF-8
#endif

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);

		snprintf_s(code_point_hex,9*sizeof(uint8_t),"%08x",c);

		strncat_s(	
				file_arr,
				FILE_SIZE << 3,
				code_point_hex,
				(FILE_SIZE << 3) - strnlen_s(file_arr,(FILE_SIZE << 3))-1
			);

		i++;
		
		file_arr_p++;	
	}

	i = 0;

	rewind(in);

	while ( u16_temp <= u16_rgt )
	{
		memset_s(buf,4*sizeof(uint8_t),0x0,4*sizeof(uint8_t));

		snprintf_s(buf,4*sizeof(uint8_t),"%08x",u16_temp);	
		
		if ( mystrstr(file_arr,buf) != NULL )
		{
			return 0;			
		}	
		
		u16_temp++;
	}
	
	rewind(in);		
		
	i = 0;

	while (i < FILE_SIZE )
	{
		c = fgetc(in);	
		
		if ( c == 0xc0 || c == 0xc1 || c == 0xf5 || c == 0xff )
		{
			return 0;
		}
		
		i++;
	}
		
		
	return 1;
}


int main(int argc, char ** argv)
{
	return 0;
}
