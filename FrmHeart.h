#ifndef FRMHEART_H
#define FRMHEART_H

#include <QWidget>

namespace Ui {
class CFrmHeart;
}

class CFrmHeart : public QWidget
{
    Q_OBJECT

public:
    explicit CFrmHeart(QWidget *parent = 0);
    ~CFrmHeart();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

private:
    int initHeart();
    int drawHeart();

    typedef enum { ROAD, WALL, OUTWALL } BlockType;
    typedef enum { EAST, SOUTH, WEST, NORTH } Direction;
#define X 47
#define Y 37
    BlockType m_Maze[Y][X];

    int m_nHeartX, m_nHeartY;
    int m_nWallWidth, m_nWallHeight;

private:
    Ui::CFrmHeart *ui;
};

#endif // FRMHEART_H
