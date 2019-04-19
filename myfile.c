#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>


_Bool isiso_8859(FILE * in, const rsize_t FILE_SIZE)
{
	rsize_t i = 0;

	uint8_t c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);


		if ( c > 0xff )
		{ 
			return 0; 
		}	
		
		i++;
	}

	return 1;

}

_Bool isascii(FILE * in, const rsize_t FILE_SIZE)
{
	rsize_t i = 0;

	uint8_t c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);

		if ( c > 0x7f )
		{
			return 0;
		}
		
		i++;
	}

	return 1;	

}

_Bool iswindex(FILE * in,const rsize_t FILE_SIZE)
{
	const uint32_t IMAGE_NT_SIGNATURE = 0x00004550;	//PE(NUL)(NUL)

	const uint32_t IMAGE_OS2_SIGNATURE_LE = 0x454c; // LE

	const uint32_t IMAGE_OS2_SIGNATURE = 0x454e; // NE

	const uint32_t IMAGE_DOS_SIGNATURE = 0x5a4d; // MZ

	static uint32_t hex_sig[10];

	static uint8_t * input = (uint8_t *)calloc(FILE_SIZE,sizeof(uint8_t));
	
	rsize_t i = 0;
		
	if ( isascii(in,FILE_SIZE) == 1 )
	{
			return 0;
	}	

	while ( i < FILE_SIZE )	
	{
		memset_s(hex_sig,10*sizeof(uint8_t),0x0,10*sizeof(uint8_t));
		
		memcpy(hex_sig,IMAGE_NT_SIGNATURE,sizeof(uint32_t));

		reverse(hex_sig);

		if ( 
			mystrstr(input,hex_sig) != NULL

			&&
			
					
		   )
						
		i++;	
	}

	free(input);

}

_Bool isutf8(FILE * in,const rsize_t FILE_SIZE)  
{
		

	fseek(in,0,SEEK_END);

	const rsize_t FILE_SIZE = ftell(in);

	rewind(in);
	
	uint8_t c = 0;

	const uint32_t utf8_lftpt = 0xeda080; //U+d800

	const uint32_t utf8_rgtpt = 0xedbfbf; //U+dfff

	static uint32_t utf8_hex = 0x00;

	rsize_t i = 0;
	
	while (i < FILE_SIZE )
	{
		c = fgetc(in);	
		
		if ( c == 0xc0 || c == 0xc1 || c == 0xf5 || c == 0xff )
		{
			return 0;
		}

		if ( 
			!( ( c >> 4 )  == 0b1111 ) // 4 byte UTF-8 character

			&&

			!( ( c >> 4 ) == 0b1110 ) // 3 byte UTF-8 character

			&&

			!( ( c >> 5 ) == 0b110 ) // 2 byte UTF-8 character

			&&

			!( ( c >> 6 ) == 0b10 ) // 1 byte UTF-8 character

			&&

			!( ( c >> 7 ) == 0b0 ) // ASCII plain-text character

		   )
		{
			return 0;	
		}

		if ( ( c >> 6 ) != 0b10 ) //beginning byte for UTF-8 character
		{

#if 0
invalid UTF-8 code point
#endif
			if ( utf8_hex >= utf8_lftpt && utf8_hex <= utf8_rgtpt )
			{
				return 0;
			}

			else if ( utf8_hex >  0xf0a1bfbf )
			{
				return 0;
			}

			utf8_hex = 0x00;

			utf8_hex += c;

			utf8_hex <<= 8;


		}

		else // continuation byte
		{
			utf8_hex += c;

			utf8_hex <<= 8;
			
		}
		
		i++;
	}

	rewind(in);

		
	return 1;
}

_Bool isutf16(FILE * in, const rsize_t FILE_SIZE)
{

	return 1;
}

_Bool isutf32(FILE * in, const rsize_t FILE_SIZE)
{

	return 1;
}


int main(int argc, char ** argv)
{
	if ( argc < 2 )
	{
		fprintf("\e[1;31m\n\0");

		fprintf(stderr,"%llu: Error: Less than two arguments!\n");

		fprintf("\e[0m\n\0");

		return 1;

	}	

	FILE * input = NULL;

	if ( ( input = fopen(argv[1]) ) == NULL )
	{
		fprintf("\e[1;31m\n\0");

		fprintf(stderr,"%llu: Error: Failed to open file!\n");

		fprintf("\e[0m\n\0");

		return 1;
		
	}

	fseek(input,0,SEEK_END);

	const rsize_t SIZE = ftell(input);

	rewind(input);	
	
	return 0;
}
