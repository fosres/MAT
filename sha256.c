#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint32_t shr_n(uint64_t n, uint32_t x)
{
	if ( n >= sizeof(uint32_t) )
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
	if ( n >= sizeof(uint32_t) )
	{
		fprintf(stderr,"\033[1;31m");	
		fprintf(stderr,"%d: n is larger than size of x\n",__LINE__);	
		fprintf(stderr,"\033[0m");
		exit(1);
	}

	return (x >>n ) | ( x >> ( sizeof(uint32_t - n) ) );
}

uint32_t rotl_n(uint64_t n, uint32_t x)
{
	if ( n >= sizeof(uint32_t) )
	{
		fprintf(stderr,"\033[1;31m");	
		fprintf(stderr,"%llu: Error!: n is larger than size of x\n",__LINE__);	
		fprintf(stderr,"\033[0m");
		exit(1);
	}

	return ( x << n ) | ( x >> sizeof(uint32_t) - n );

}

const unsigned char * padded_msg(const unsigned char * msg,uint64_t msg_maxsize)
{
	if ( msg_maxsize == 0 )
	{
		fprintf(stderr,"\033[1;31m");
		fprintf(stderr,"%llu: Error: msg_maxsize == 0\n");
		fprintf(stderr,"\033[0m");
		exit(1);
	}

	if ( ( msg_maxsize << 3 ) >= UINTMAX_MAX )
	{
		
		fprintf(stderr,"\033[1;31m");
		fprintf(stderr,"%llu: Error: ( msg_maxsize << 3 ) >= UINTMAX_MAX\n");
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

		strncat_s(msg,msg
	
	}
	
}



int main(void)
{

	return 0;
}
