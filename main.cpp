#include"pixel.h"
#include"block.h"
#include<math.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctime>
#include"collapse.h"
#include<chrono>
#include<thread>
#include<iostream>

#define PLAYFIELD_HEIGHT 20
#define PLAYFIELD_WIDTH 30

WINDOW* playGround;
Block *bp;
Collapse* collapse;

static bool quitGame = false;
static bool pauseLowerBlock = false;
static bool pauseKeyEvent = false;

void keyEvent(void)
{
    while(true) {
        char c = wgetch(playGround);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if(pauseKeyEvent)
            continue;
        if(quitGame)
            break;

        if(c == 'q')
            quitGame = true;
        else if(c == 'h') {
        pauseLowerBlock = true;
            bp->moveHorizontal(DIR_LEFT);
            bp->show();
        pauseLowerBlock = false;
        } else if(c == 'l') {
        pauseLowerBlock = true;
            bp->moveHorizontal(DIR_RIGHT);
            bp->show();
        pauseLowerBlock = false;
        } else if(c == 'i') {
        pauseLowerBlock = true;
            bp->rotate(DIR_LEFT);
            bp->show();
        pauseLowerBlock = false;
        } else if(c == 'o') {
        pauseLowerBlock = true;
            bp->rotate(DIR_RIGHT);
            bp->show();
        pauseLowerBlock = false;
        }

    }
}

void _lowerBlock(void)
{
    if(bp->moveVertical(DIR_DOWN)) {
        for(int i = bp->getPos().y; i < bp->getPos().y + BLOCK_HEIGHT; i++) {
            if(i < PLAYFIELD_HEIGHT - 1 && collapse->canCollapse(i))
                    collapse->row(i);
        }
        delete bp;
        bp = new Block(playGround, block[rand() % 7], 0, 0);
    }
}

void lowerBlock(void)
{
    while(true) {
        if(pauseLowerBlock) {
            // std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }

        if(quitGame)
            break;

        pauseKeyEvent = true;
        _lowerBlock();
        bp->show();
        pauseKeyEvent = false;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}

int main(int argc, char** argv)
{
    initscr();
    noecho();
    cbreak();
    curs_set(false);

    playGround = newwin(PLAYFIELD_HEIGHT, PLAYFIELD_WIDTH, 0, 0);
    bp = new Block(playGround, block[rand() % 7], 0, 0);
    collapse = new Collapse(playGround);

    box(playGround, 0, 0);
    wrefresh(playGround);

    std::thread blockThread(lowerBlock);
    std::thread keyThread(keyEvent);
    blockThread.join();
    keyThread.join();


    endwin();
    return 0;
}
