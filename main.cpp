#include"pixel.h"
#include"blocks.h"
#include<math.h>
#include<unistd.h>

void drawBlock(int index, int y, int x, bool invertColor = true);

int main(int argc, char** argv)
{
    initscr();
    noecho();
    cbreak();
    curs_set(false);

    int scrH, scrW;
    getmaxyx(stdscr, scrH, scrW);

    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    attron(A_REVERSE | COLOR_PAIR(1));
    mvprintw(15, 18, "      ");
    attroff(A_REVERSE | COLOR_PAIR(1));

    box(stdscr, 0, 0);
    refresh();

    int y1 = 10;
    int y2 = 10;
    while(true) {
        int x = 10;
        drawBlock(1, y1 -1, x, false);
        drawBlock(1, y1, x);

        drawBlock(0, y2 -1, 19, false);
        drawBlock(0, y2, 19);

        sleep(1);

        endPixel();

        if((mvinch(y1+2, 1) & 0xff) != ' ')
            break;

        if((mvinch(y2 + 2, 19) & 0xFFFFFFFFFFFF00FF) != (' ' | A_REVERSE))
            y2++;

        y1++;
    }


    getch();
    endwin();

    return 0;
}

void drawBlock(int index, int y, int x, bool invertColor)
{
    for(int j = 0; j < 3; j++)
        for(int i = 0; i < 3; i++) {
            if(block[index][(3*j) + i]) {
                if(invertColor)
                    initPixel();
                drawPixel(y+j,x+(2*i));
                endPixel();
            }
        }
}
