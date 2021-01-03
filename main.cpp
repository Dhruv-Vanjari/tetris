#include"pixel.h"
#include"block.h"
#include<math.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctime>
#include"collapse.h"

#define PLAYFIELD_HEIGHT 20
#define PLAYFIELD_WIDTH 30

int main(int argc, char **argv)
{
    initscr();
    noecho();
    cbreak();
    curs_set(false);
    timeout(25);

    int scrH, scrW;
    getmaxyx(stdscr, scrH, scrW);

    int fieldStartX, fieldStartY;
    fieldStartY = (scrH / 2) - (PLAYFIELD_HEIGHT / 2);
    fieldStartX = (scrW / 2) - (PLAYFIELD_WIDTH / 2);

    WINDOW *win = newwin(PLAYFIELD_HEIGHT, PLAYFIELD_WIDTH, fieldStartY, fieldStartX);
    nodelay(win, true);
    box(win, 0, 0);
    wrefresh(win);

    Block *bp = new Block(win, block[rand() % 7], 0, 0);

    Collapse collapse = Collapse(win);
    while(true) {
        char c = wgetch(win);

        if(c == 'q') {
            endwin();
            return 0;
        }

        if(c == 'h')
            bp->moveHorizontal(DIR_LEFT);
        else if (c == 'l')
            bp->moveHorizontal(DIR_RIGHT);
        else if (c == 'j') {
            if(bp->moveVertical(DIR_DOWN)) {
                delete bp;
                bp = new Block(win, block[rand() % 7], 0, 0);
                if(collapse.canCollapse(PLAYFIELD_HEIGHT - 2))
                    collapse.row(PLAYFIELD_HEIGHT - 2);
            }
        } else if (c == 'k')
            bp->moveVertical(DIR_UP);
        else if (c == ' ') {
            while(!bp->moveVertical(DIR_DOWN));
            bp->show();
            delete bp;
            bp = new Block(win, block[rand() % 7], 0, 0);
            if(collapse.canCollapse(PLAYFIELD_HEIGHT - 2))
                collapse.row(PLAYFIELD_HEIGHT - 2);

        } else if (c == 'i') {
            bp->rotate(BLOCK_RIGHT);
        } else if (c == 'o') {
            bp->rotate(BLOCK_LEFT);
        }

        bp->show();
        usleep(50000);
    }
    wrefresh(win);
    refresh();

    getch();
    endwin();
    return 0;
}
