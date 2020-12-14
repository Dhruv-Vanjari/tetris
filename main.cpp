#include"pixel.h"
#include"block.h"
#include<math.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    initscr();
    noecho();
    cbreak();
    curs_set(false);

    int scrH, scrW;
    getmaxyx(stdscr, scrH, scrW);


    WINDOW *win = newwin(scrH, scrW - (scrW % 2), 0, 0);
    box(win, 0, 0);
    wrefresh(win);

    Block o = Block(win, block[0], 3, 0);
    Block b = Block(win, block[1], 4, scrW / 4);
    Block d = Block(win, block[2], 5, 0);
    Block h = Block(win, block[3], 5, 6);

    Block o1 = Block(win, block[0], 3, 0);
    Block b1 = Block(win, block[1], 4, scrW / 4);
    Block d1 = Block(win, block[3], 5, 2);
    Block h1 = Block(win, block[0], 5, 6);
    Block *bp[] =
    {
        &o, &b, &d, &h, &o1, &b1, &d1, &h1
    };

    int i = 0;
    int maxBlocks = 7;
    while(true) {
        bp[i]->show();
        if(bp[i]->moveVertical(DIR_DOWN)) {
            i++;
            if(i > maxBlocks)
                break;
        }

        sleep(1);
    }
    wrefresh(win);
    refresh();

    getch();
    endwin();
    return 0;
}
