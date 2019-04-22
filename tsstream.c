#if 0

Copyright (C) Tanveer Salim. 2018-INFINITY

This program is distributed under a GNU GPL v2.0

License and thus is free and open source software.

All software and works that are inspired or are

derivatives of this work must, in turn, be distributed

with the exact same LICENSE and copyright permissions.

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

_Bool decryption_mode = 0;

#ifndef __uint8_t_defined
typedef unsigned char uint8_t;
#define __uint8_t_defined 1
#endif

#ifndef __uint32_t_defined
typedef unsigned int uint32_t;
#define __uint32_t_defined 1
#endif

#ifndef __rsize_t_defined
typedef size_t rsize_t;
#define __rsize_t_defined 1
#endif

#ifdef __RSIZE_MAX__
#define RSIZE_MAX (__RSIZE_MAX__)
#else

#define RSIZE_MAX ( (SIZE_MAX ) >> ( 1 ) )
#endif

void reverse(uint8_t arr[])
{
	uint8_t temp = 0;
	
	for ( rsize_t i = 0, j = strnlen_s(arr,RSIZE_MAX) - 1; i < j ; i++, j-- )
	{
		temp = arr[i];

		arr[i] = arr[j];

		arr[j] = temp;

	}
}

#if 0
which_endian returns 0 for

little-endian and

return 1 for big-endian

#endif

_Bool which_endian(void)
{
	const uint32_t test = 0xd04bdd22;

	uint32_t result = 0;

	static uint8_t test_str[5];

	memcpy(test_str,&test,sizeof(uint32_t));	

	rsize_t i = 0;

	while ( i < sizeof(test_str) )
	{
		result += test_str[i];

		result <<= 8;

		result &= 0xffffff00;

		i++;
	}

	if ( result != test )
	{
		return 0;
	}

	else
	{
		return 1;
	}

}

uint8_t * symmcipher(FILE * in, const rsize_t FILE_SIZE, FILE * out)
{
	srand(time(NULL));

	static uint8_t nonce[64];

	static uint8_t key = 0x00;
	
	rsize_t i = 0;

	while ( i < sizeof(nonce) )
	{
		nonce[i] = (uint8_t)( rand() % 256 );

		i++;
	}
	
	rewind(in);

	i = 0;

	while ( i < FILE_SIZE )
	{
		key = fgetc(in) ^ nonce[i%64];
		
		fputc(key,out);
		
		i++;
	}

	return nonce;

}

void decrypt(FILE * msg, const rsize_t FILE_SIZE,  FILE * out, uint8_t * key)
{	
	
	rewind(msg);

	rsize_t i = 0;

	uint8_t c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(msg) ^ key[i%64];
		
		fputc(c,out);
		
		i++;
	}


}



_Bool main(rsize_t argc, uint8_t ** argv)
{
	if ( argc < 2 )
	{
		fprintf(stderr,"\e[38;5;9m");

		fprintf(stderr,"Error: Less than two arguments!\n");

		fprintf(stderr,"\e[0m");

		return 1;
	}

	FILE * input = NULL;

	rsize_t INPUT_FILE_SIZE = 0;

	rsize_t OUTPUT_FILE_SIZE = 0;

	FILE * output = stdout;

	static uint8_t * key;

	key = NULL;



	if ( argv[2] != NULL && ( ( output = fopen(argv[2],"wb+") ) == NULL ) )
	{
		fprintf(stderr,"\e[38;5;9m");

		fprintf(stderr,"Error: Cannot open output file for writing!\n");

		fprintf(stderr,"\e[0m");
		
	}

	if ( ( input = fopen(argv[1],"rb") ) == NULL )
	{
		fprintf(stderr,"\e[38;5;9m");

		fprintf(stderr,"Error: Cannot open input file for reading!\n");

		fprintf(stderr,"\e[0m");

		return 1;
		
	}

	fseek(input,0,SEEK_END);

	INPUT_FILE_SIZE = ftell(input);

	rewind(input);

	key = symmcipher(input,INPUT_FILE_SIZE,output);

	fseek(output,0,SEEK_END);

	OUTPUT_FILE_SIZE = ftell(output);

	rewind(output);

	decrypt(output,OUTPUT_FILE_SIZE,stdout,key);

	printf("---------------------------------------");

	printf("%c%cKey is:%c",0xa,0xa,0xa);

	rsize_t i = 0;

	while ( i < 64 )
	{
		printf("%.02x",key[i]);
		
		i++;
	}

	putchar(0xa);

	return 0;

}	
