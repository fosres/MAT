#if 0

Official documentation for SHA-256 is found in

RFC (Request For Comments) 6234.

#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


static uint32_t hex_table[64] =
{

0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,      

0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,      

0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,      

0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,      

0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,      

0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,      

0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,      

0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,      

0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,      

0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,      

0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,      

0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,      

0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,      

0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,      

0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,      

0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2

};

uint32_t shr_n(uint64_t n, uint32_t x)
{
	if ( n >= ( sizeof(uint32_t) << 3 ) )
	{
		fprintf(stderr,"\033[1;31m");	
		fprintf(stderr,"%d: n is larger than size of x\n",__LINE__);	
		fprintf(stderr,"\033[0m");
		exit(1);
	}

	return ( x >> n );
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
		
		msg_size = L + 1 + K + 65 * sizeof(unsigned char); 
		
// The first 64 is for the 64 bitstring representation of L.

// The 65th unsigned char byte appended is for the NUL byte.

#if 0
The new msg will be a multiple

of 512 bits.
#endif

		free(msg);

		msg = (unsigned char *)calloc( msg_size,sizeof(unsigned char) );

		strncat_s(
				msg,
				msg_size,
				"1\0",
				msg_size

				-

				strnlen_s(msg,msg_size) - 1
			 );

		unsigned char * K_ap = msg + strnlen_s(msg,msg_size);
		
		i = 0;

		while ( i < K )
		{
			*K_ap++ = 0x30;
			
			i++;
		}	
		
		return msg;		
}

uint32_t  CH( uint32_t x, uint32_t y, uint32_t z)
{
	return ( ( x & y ) ^ ( (~x) & z ) );

}

uint32_t MAJ( uint32_t x, uint32_t y, uint32_t z )
{
	return ( ( x & y ) ^ ( x & z ) ^ ( y & z ) );

}

uint32_t BSIG0(uint32_t x)
{
	return ( rotr_n(2,x) ^ rotr_n(13,x) ^ rotr_n(22,x) );

}

uint32_t BSIG1(uint32_t x)
{
	return ( rotr_n(6,x) ^ rotr_n(11,x) ^ rotr_n(25,x) );

}

uint32_t SSIG0(uint32_t x)
{
	return ( rotr_n(7,x) ^ rotr_n(18,x) ^ shr_n(3,x) );
}

uint32_t SSIG1(uint32_t x)
{
	return ( rotr_n(17,x) ^ rotr_n(19,x) ^ shr_n(10,x) );	

}

int main(void)
{
	
#if 0
These are the initial output values

of the SHA-256 hash algorithm if the

input is absolutely empty.
#endif	
	static uint32_t H[8] =
	{
		0x6a09e667,      
		
		0xbb67ae85,      
		
		0x3c6ef372,      
		
		0xa54ff53a,      
		
		0x510e527f,      
		
		0x9b05688c,      
		
		0x1f83d9ab,      
		
		0x5be0cd19	
	};

	return 0;
}
