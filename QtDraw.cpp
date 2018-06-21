#include "QtDraw.h"

CQtDraw::CQtDraw(QPainter *painter)
{
    m_pPainter = painter;
}

int CQtDraw::drawLine(int x1, int y1, int x2, int y2) const
{
    int nRet = 0;
    m_pPainter->drawLine(x1, y1, x2, y2);
    return nRet;
}

int CQtDraw::drawCricular(int centX, int centY, int r) const
{
    int nRet = 0;
    
    return nRet;
}

int CQtDraw::drawRectangular(int x, int y, int width, int height) const
{
    int nRet = 0;
    m_pPainter->drawRect(x, y, width, height);
    return nRet;
}
