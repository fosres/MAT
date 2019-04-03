#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


uint32_t shr_n(uint64_t n, uint32_t x)
{
	if ( n >= ( sizeof(uint32_t) << 3 ) )
	{
		fprintf(stderr,"\033[1;31m");	
		fprintf(stderr,"%d: n is larger than size of x\n",__LINE__);	
		fprintf(stderr,"\033[0m");
		exit(1);
	}

	return x >> n;
}

uint32_t rotr_n(uint64_t n, uint32_t x)
{
	if ( n >= ( sizeof(uint32_t) << 3 ) )
	{
		fprintf(stderr,"\033[1;31m");	
		fprintf(stderr,"%d: n is larger than size of x\n",__LINE__);	
		fprintf(stderr,"\033[0m");
		exit(1);
	}

	return (x >> n ) | ( x << ( ( sizeof(uint32_t) << 3) - n) );
}

uint32_t rotl_n(uint64_t n, uint32_t x)
{
	if ( n >= ( sizeof(uint32_t) << 3 ) )
	{
		fprintf(stderr,"\033[1;31m");	
		fprintf(stderr,"%llu: Error!: n is larger than size of x\n",__LINE__);	
		fprintf(stderr,"\033[0m");
		exit(1);
	}

	return ( x << n ) | ( x >> ( sizeof(uint32_t) << 3 ) - n );

}

#if 0

The message should be a string of the binary form of the file

You should use "rb" when opening a file

To convert the contents of a file to bit string

#endif

void reverse(unsigned char s[])
{
  for (int i = 0, j = strlen(s)-1; i < j; i++, j--)
  {
    char temp = s[i];

    s[i] = s[j];

    s[j] = temp;
  }
}

unsigned char * print_binary(unsigned char input)
{


  static char s[10];

  char * s_p = &s[0];

  while (input > 0)
  {
    *s_p++ = (char)((input&1)+'0');

    input >>= 1;
  }

  *s_p = '\0';
  
  reverse(s);

  return s;

}

#if 0

The unsigned char * msg should actually be a bit string so it

contains nothing but pure 1s and 0s ONLY.

To convert any unsigned char array into this bit string, you must 

use strncat_s. Each char is translated

to an 8-bit string of 1s and 0s. Concatenate each 8-bit string to

dest until 0xff (EOF).

Thus, msg_maxsize is the original size of the char array message

multiplied by 8 (there are 8 bits in a byte) + 1 ( 0x0 NUL byte).

#endif

const unsigned char * padded_msg(const unsigned char * msg, uint64_t msg_maxsize)
{
	const uint64_t L = msg_maxsize;	
	
	if ( msg_maxsize == 0 )
	{
		fprintf(stderr,"\033[1;31m");
		fprintf(stderr,"%llu: Error: msg_maxsize == 0\n");
		fprintf(stderr,"\033[0m");
		exit(1);
	}

	if ( msg_maxsize == UINTMAX_MAX )
	{
		
		fprintf(stderr,"\033[1;31m");
		fprintf(stderr,"%llu: Error: msg_maxsize == UINTMAX_MAX\n");
		fprintf(stderr,"\033[0m");
		exit(1);
	
	}	
	
	
	if ( 
			
		( strnlen_s(msg,msg_maxsize) == msg_maxsize )
			
	   )
		
	{
		if 
		(
		  
			( ( msg_maxsize*2) < msg_maxsize ) 

			|| 
		
			( ( msg = realloc(msg,msg_maxsize*2) ) == NULL )
		
		)

		{
		
		
		
			fprintf(stderr,"\033[1;31m");

			fprintf(stderr,"%llu: Error: Failed to resize msg\n",__LINE__);	

			fprintf(stderr,"\033[0m");

			exit(1);

		}
	
	}
#if 0

First calculate L+1+K that makes

the following formula true:

(L + 1 +K ) % 512 == 448

#endif

		uint64_t K = UINTMAX_MAX;

// when ++K happens the first time, UINTMAX_MAX will be overclocked to 0

		while ( ( L + 1 + ++K ) % 512 == 448 )
			;

		static unsigned char L_string[65];

		static unsigned char L_bitstring[65];

		snprintf_s(L_string,65*sizeof(unsigned char),"%llu",L);

		rsize_t i = 0;

		while ( i < 65 && L_string[i] != 0x0 )
		{
			strncat_s(
					L_bitstring,
					65*sizeof(unsigned char),
					print_binary(L_string[i]),
					( 65*sizeof(unsigned char) ) 
					
					- 
					
					strnlen_s(L_bitstring,65*sizeof(unsigned char)) - 1
				 );
						
			i++;		
		}
		
		msg_size = L + 1 + K + 64; //64 is for the 64 bitstring representation of L

#if 0
The new msg will be a multiple

of 512 bits.
#endif

		free(msg);

		msg = (unsigned char *)calloc( msg_size,sizeof(unsigned char) );
		
}



int main(void)
{

	return 0;
}
