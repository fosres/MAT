#include <stdio.h>

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

#if 0
A smarter algorithm would have checked the

SHA256 hashes!
#endif

int main(int argc, char ** argv)
{
	FILE * in = NULL;

	if ( argc < 2 )
	{
		fprintf("\e[30;48;5;9m");
		
		fprintf(stderr,"Error: Less than two arguments!\n");

		fprintf("\e[0m");	

		return 1;
	}

	if ( 

	
}
