#ifndef FRMMAZE_H
#define FRMMAZE_H

#include <QWidget>
#include "maze.h"

namespace Ui {
class CFrmMaze;
}

class CFrmMaze : public QWidget
{
    Q_OBJECT
    
public:
    explicit CFrmMaze(QWidget *parent = 0);
    ~CFrmMaze();
    
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    
private:
    int initMaze();
    
private:
    Ui::CFrmMaze *ui;
    
    Maze* m_pMaze;
};

#endif // FRMMAZE_H
