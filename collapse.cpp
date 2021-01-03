#include"collapse.h"
#include"pixel.h"

Collapse::Collapse(WINDOW *w)
{
    this->win = w;
    getmaxyx(this->win, this->wH, this->wW);

    this->rowBuffer = new bool[wW];
}

void Collapse::_clearRow(int row)
{
    for(int i = 1; i < this->wW - 2; i++)
        drawPixel(row, i, this->win);

    endPixel(this->win);
}

bool Collapse::canCollapse(int row)
{
    for(int i = 1; i < this->wW - 1; i += Pixel::pixel)
        if((mvwinch(this->win, row, i) & A_REVERSE) == false) //  != A_REVERSE)
            return false;

    return true;
}

void Collapse::_copyBelow(int row)
{
    this->_copyRow(row);
    this->_clearRow(row);
    this->_printRow(row + 1, this->rowBuffer);
}

void Collapse::row(int row)
{
    this->_clearRow(row);
    this->_copyBelow(row - 1);

    if(row != 2)
        this->row(row - 1);
}

void Collapse::_copyRow(int row)
{
    for(int i = 1; i < wW - 1; i++)
        this->rowBuffer[i] = (bool) (mvwinch(this->win, row, i) & A_REVERSE);
}

void Collapse::_printRow(int row, bool *rowData)
{
    initPixel(this->win);
    for(int i = 1; i < wW - 1; i++)
        if(rowData[i] == true)
            mvwprintw(this->win, row, i, " ");
    endPixel(this->win);
}
