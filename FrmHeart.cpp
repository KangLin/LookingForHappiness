#include "FrmHeart.h"
#include "ui_FrmHeart.h"
#include <QDebug>
#include <QPainter>
#include <QRect>
#include <QResizeEvent>
#include <QPaintEvent>

CFrmHeart::CFrmHeart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CFrmHeart)
{
    ui->setupUi(this);
    initHeart();
    m_nWallWidth = m_nWallHeight = 5;
}

CFrmHeart::~CFrmHeart()
{
    delete ui;
}

void CFrmHeart::paintEvent(QPaintEvent *event)
{
    drawHeart();
}

void CFrmHeart::resizeEvent(QResizeEvent *event)
{
    int w = event->size().width();
    int h = event->size().height();
    if(w < h)
        m_nWallHeight = m_nWallWidth = w / X;
    else
        m_nWallHeight = m_nWallWidth = h / Y;

    m_nHeartX = (w - m_nWallWidth * X) >> 1;
    m_nHeartY = (h - m_nWallHeight * Y) >> 1;
}

int CFrmHeart::initHeart()
{
    int i = 0, j = 0;
    for (float y = 1.2f; y > -1.0f; y -= 0.06f)
    {
        for (float x = -1.1f; x < 1.2f; x += 0.05f)
        {
            float a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y <= 0.0f)
                m_Maze[i][j] = WALL;
            else
                m_Maze[i][j] = OUTWALL;
            j++;
        }
        i++;
        j = 0;
    }
    return 0;
}

int CFrmHeart::drawHeart()
{
    int nRet = 0;

    QPainter painter(this);

    for(int i = 0; i < X; i++)
        for(int j = 0; j < Y; j++)
        {
            if(WALL == m_Maze[j][i])
            {
                QRect rect(m_nHeartX + i * m_nWallWidth,
                           m_nHeartY + j * m_nWallHeight,
                           m_nWallWidth,
                           m_nWallHeight);
                painter.drawRect(rect);
            }
        }

    return nRet;
}
