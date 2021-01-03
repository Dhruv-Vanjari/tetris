#ifndef __COLLAPSE_H
#define __COLLAPSE_H

#include<ncurses.h>

class Collapse
{
private:
    WINDOW* win;
    int wH, wW;

    bool *rowBuffer;

    void _clearRow(int row);
    void _clearBlock(int row);
    void _copyRow(int row);
    void _printRow(int row, bool * rowData);
    void _copyBelow(int row);

public:
    Collapse(WINDOW*);

    void row(int row);
    bool canCollapse(int row);
};
#endif
