#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#if 0

Bug: Number of columns == Number of bytes per row!

NUM_HEX_ROWS == (desired number of columns)/2

default number of columns: 16 to make 16 bytes displayed in total per row

So:

NUM_HEX_ROWS == Number of desired columns

Simple! :D
#endif
//#define NUM_HEX_ROWS_ORIGINAL 16

rsize_t NUM_HEX_ROWS = 16;

rsize_t NUM_BIN_ROWS = 5;

_Bool bintable_request = 0;

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

void print_bintable(FILE * in, unsigned char ASCII[],const rsize_t FILE_SIZE)
{
	rsize_t i = 0;

	unsigned char c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);

		if ( (i%NUM_BIN_ROWS != 0) ) 
			
		{ 
			isprint(c) ? (ASCII[i%NUM_BIN_ROWS] = c) : (ASCII[i%NUM_BIN_ROWS] = 0x2e);
		}

		else
		{
			 printf("%s\n%08x:%c",ASCII,i,0x20); 

			 memset_s(ASCII,NUM_BIN_ROWS,0x0,NUM_BIN_ROWS);
		}
#if 0
When printing the actual hexadecimal table, 

do not replace the actual hexadecimal with

0x2e!
#endif
		printf("%08s%c",print_binary(c),0x9);
		

		i++;	
	}

}
void print_hextable(FILE * in,unsigned char ASCII[], const rsize_t FILE_SIZE)
{
	rsize_t i = 0;

	unsigned char c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);

		if ( (i%NUM_HEX_ROWS != 0) ) 
			
		{ 
			( isprint(c) != 0) ? (ASCII[i%NUM_HEX_ROWS] = c) : (ASCII[i%NUM_HEX_ROWS] = 0x2e);
		}

		else
		{
			 printf("%s\n%08x:%c",ASCII,i,0x20); 

			 memset_s(ASCII,NUM_HEX_ROWS,0x0,NUM_HEX_ROWS);
		}
#if 0
When printing the actual hexadecimal table, 

do not replace the actual hexadecimal with

0x2e!
#endif
			(i%2 == 0) ? ( printf("%02x",c) ) : printf("%02x%c",c,0x9);
		

		i++;	
	}

}

#if 0
Last argument, argument index

argc-1, must have filename
#endif

int main(int argc, char ** argv)
{

	FILE * in = NULL;

	if ( argc < 2 )
	{
		fprintf(in,"%llu: Less than two arguments!\n",__LINE__);

		return 1;
	}

	
	if ( ( in = fopen(argv[argc-1],"rb") ) == NULL )
	{
		fprintf(stderr,"\033[1;31m\n\0");	
		
		fprintf(stdout,"%llu: Failed to open file!\n",__LINE__);

		fprintf(stderr,"\033[0m\n\0");

		return 1;
	}
	
	fseek(in,0L,SEEK_END);

	const rsize_t SIZE = ftell(in);

	static unsigned char * ascii_line; 
	
	ascii_line = (unsigned char *)calloc(NUM_HEX_ROWS+1,sizeof(char));

	rewind(in);

	while ( *++argv != NULL && **argv == 0x2d )
	{
		switch ( *++(*argv)  )
		{
			case 0x63:
				{
					// get column number

					char const * column_num = *++argv; 

					while ( isdigit( *(*argv) ) != 0 )
					{	(*argv)++;	}

					if ( **argv != 0x0 )
					{
						
						fprintf(stderr,"\033[1;31m\n\0");	

						fprintf(stderr,"%llu: Error! Column"
								" argument is not a" 
								" type of unsigned"
								" integer!\n",
						        __LINE__
						       );

						fprintf(stderr,"\033[0m\n\0");

						return 1;
					}



					NUM_HEX_ROWS = (rsize_t)strtol(column_num,NULL,10);

					free(ascii_line);

					ascii_line = (unsigned char *)calloc(NUM_HEX_ROWS,sizeof(char));

					NUM_BIN_ROWS = (rsize_t)strtol(column_num,NULL,10);

					break;
				}

			case 0x62:
				{
					bintable_request = 1;	

					free(ascii_line);

					ascii_line = (unsigned char *)calloc(NUM_BIN_ROWS+1,sizeof(char));
					
					break;
				}



			default:
				{
					break;
				}
		}	

	}

	if ( bintable_request == 1 )
	{ 
		print_bintable(in,ascii_line,SIZE);
	}

	else
	{
		print_hextable(in,ascii_line,SIZE);
	}

	if ( fclose(in) == EOF )
	{
		fprintf(stderr,"\033[1;31m\n\0");	
		
		fprintf(stderr,"%llu: Error! Failed to %s\n",__LINE__,argv[argc-1]);

		fprintf(stderr,"\033[0m\n\0");
		
		return 1;
	}
	

	return 0;
}
