#ifndef DRAW_H
#define DRAW_H


class CDraw
{
public:
    CDraw();
    virtual int drawLine(int x, int y, int x1, int y1) const = 0;
    virtual int drawRectangular(int x, int y, int width, int height) const = 0;
    virtual int drawCricular(int centX, int centY, int r) const = 0;
};

#endif // DRAW_H
