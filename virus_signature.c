#include <stdio.h>

int main(int argc, char ** argv)
{
	if ( argc != 2 )
	{
		fprintf(stderr,"\033[1;31m\n\0");

		fprintf(stderr,"%llu: Error! Less than two arguments!\n",__LINE__);

		fprintf(stderr,"\033[0m\n\0");

		return 1;
	}

	FILE * in = NULL;

	if ( ( in = fopen(argv[1],"rb") ) == NULL )
	{
		fprintf(stderr,"\033[1;31m\n\0");

		fprintf(stderr,"%llu: Error! Failed to open file!\n",__LINE__);

		fprintf(stderr,"\033[0m\n\0");

		return 1;

	}		

	rewind(in);

	fseek(in,-8,SEEK_END);

	rsize_t i = 0;

	unsigned char c = 0;

	while ( i < 8 )
	{
		c = fgetc(in);

		printf("%02x",c);

		i++;
	}

	printf("\n\0");

	rewind(in);

	if ( fclose(in)  == EOF )
	{
		fprintf(stdout,"\033[1;31m\n\0");

		fprintf(stdout,"%llu: Error! Failed to close file\n",__LINE__);

		fprintf(stdout,"\033[0m\n\0");

		return 1;
	}
	
	return 0;
}
