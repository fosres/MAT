#if 0

This program was inspired by Kenneth Lane Thompsons solution

to designing a simple quine program:

http://www.azillionmonkeys.com/qed/self3_c.txt

To convert any non-quine program into a quine program, simply write something

like (leave the empty lines as is when adding them to ken_quine_generator.c:

FILE * target = NULL;

static char name[1024];  

snprintf(name,"%s\b\b_quine.c\0",argv[1]);


if ( ( target = fopen(name,"wb+") ) == NULL )
{
	
	fprintf(stdout,"%d: Error! Can't open %s for rewriting!\n",name);

	return 1;
}



static char * q_p = q;

while ( *q_p != 0x0 )
{
	fputc(target_file.c,*q_p);

	q_p++;
}


fprintf("%s\n",q,target_file.c);

if ( fclose(target)  == EOF )
{
	fprintf(stdout,"Error! Failed to close %s!\n",name);

	return 1;

}

RIGHT BEFORE:

return 0;

which is at the end of the int main function.

Finally, run:

./ken_quine_generator.o file.c

Expect the quine file to be stored in:

file_quine.c

in your current directory

#endif


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char ** argv)
{
	
	
	FILE * in = NULL;

	if ( argc != 2 )
	{ 
		fprintf(stderr,"Error! Less than two arguments.\n");	
		return 1;
	}

	if ( ( in = fopen(argv[1],"rb") ) == NULL )
	{
		fprintf(stderr,"Error! Failed to open file!\n");

		return 1;
	}

	
	fseek(in,0L,SEEK_END);

	const rsize_t SIZE = ftell(in);

	rewind(in);
//#if 0	
	static char * str; 

	static char * s_p;

	static char * tf_p;
	
	str = (char *)calloc(sizeof(char),SIZE+1);
	
	s_p = &str[0];
	
	fread(str,SIZE+1,sizeof(char),in);

	str[SIZE] = 0x0;
//#endif
	char c = 0;

	rewind(in);
#if 0
// printing the contents of the source code in hexadecmial directly from file
// Kenneth Lane Thompson thought of this simple, brilliant idea
	printf("printing the contents of the source code in hexadecmial directly from file:\n\n");

	printf("char q[] = \n{\n");
	while ( ( c = fgetc(in) ) != EOF )
	{
		printf("0x%x, ",c);	
	}
	
	printf("0x0\n",);
	printf("};\n\n");

	s_p = &str[0];

//actually printing the contents of the source code in hexadecimal from array

	printf("printing the contents of the source code in hexadecimal from array\n\n");

	
	printf("char q[] = \n{\n");
	
	while ( ( c = *s_p ) != 0x0 )
	{ 	fprintf(stdout,"0x%x, ",c); s_p++;  }
	printf("};\n\n");

// prints the contents of the source code in ASCII text:

	rewind(in);

	printf("Printing contents of source in ASCII text from file:\n\n");

	while ( ( c = fgetc(in) ) != EOF )
	{
		fputc(c,stdout);
	}
	
	printf("\n\n");

	s_p = &str[0];
#endif

//actually printing the contents of the source code in hexadecimal from array

//	printf("printing the contents of the source code in hexadecimal from array\n\n");

	
	printf("static char q[] = \n{\n");
	
	while ( ( c = *s_p ) != 0x0 )
	{ 	fprintf(stdout,"0x%x, ",c); s_p++;  }
	
	fprintf(stdout,"0x0\n");
	
	fprintf(stdout,"};\n\n");


//	printf("Printing contents of source in ASCII text from array:\n\n");
	
	s_p = str;

	while ( ( c = *s_p ) != 0x0 )
	{
		fputc(c,stdout); s_p++;
	}



	if ( fclose(in) == EOF )
	{
		fprintf(stderr,"Error! Failed to open file!\n");

		return 1;
	}
	
	free(str);	

	return 0;
}
