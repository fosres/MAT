#include <stdio.h>
#include <ncurses.h>
#include <stdint.h>

_Bool num_mode = 0;

int main(int argc, char ** argv)
{
	initscr();

	rsize_t i = 0;

	uint8_t c = 0;
			
	printw("\e[38;5;226m");

	static uint8_t num[3] = 0;


	while ( i < 100 )
	{
		printw("%s\n","Hello, World!\n");

		refresh();

		i++;
	}
	
	move(0,0);

	printw("Press any key to exit\n");
	
	while ( ( c = getch() ) != 0x71 )
	{
		
		refresh();

		if ( c == 'j' )
		{

		}

		if ( c == ':' )
		{
			
		}

	}	
		
	
	endwin();

	

	return 0;
}
