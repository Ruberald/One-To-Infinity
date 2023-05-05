#include <curses.h>
#include <stdio.h>
#include <ncurses.h>

int main(int argc, char const *argv[])
{	
	int ch = 0;

	WINDOW * window = initscr();
	const int ROWS = getmaxy(window);
	cbreak();
	noecho();

	MEVENT event;
	mousemask(ALL_MOUSE_EVENTS, NULL);
	keypad(window, TRUE);

	int init_i = 0;

	do{
		clear();


		if(ch == 'j') init_i++;
		else if(ch == KEY_MOUSE){
			if(getmouse(&event) == OK){
				if(event.bstate & BUTTON5_PRESSED)	init_i++;
				else if(event.bstate & BUTTON4_PRESSED){
					if(init_i == 0);
					else
						init_i--;
				}
			}
		}
		else if(ch == 'k') {
			if(init_i == 0);
			else
				init_i--;
		}

		for (int i = init_i+1; i >= ROWS+init_i; i++)
		{
			printw("%d\n", i);
		}
	}while((ch = getch()) != EOF);

	refresh();
	getch();
	endwin();

	return 0;
}
