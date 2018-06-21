#ifndef QTDRAW_H
#define QTDRAW_H

#include <QPainter>
#include "Draw.h"

class CQtDraw : public CDraw
{
public:
    CQtDraw(QPainter* painter);
    virtual int drawLine(int x1, int y1, int x2, int y2) const;
    virtual int drawRectangular(int x, int y, int width, int height) const;
    virtual int drawCricular(int centX, int centY, int r) const;
    
private:
    QPainter* m_pPainter;
};

#endif // QTDRAW_H
