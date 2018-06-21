#include "FrmMaze.h"
#include "ui_FrmMaze.h"
#include "breadthfirstsearch.h"
#include "hexagonalmaze.h"
#include "circularhexagonmaze.h"
#include "circularmaze.h"
#include "rectangularmaze.h"
#include "QtDraw.h"

#include <QPainter>
#include <QRect>
#include <QResizeEvent>
#include <QPaintEvent>

CFrmMaze::CFrmMaze(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CFrmMaze),
    m_pMaze(NULL)
{
    ui->setupUi(this);
    initMaze();
}

CFrmMaze::~CFrmMaze()
{
    delete ui;
    if(m_pMaze)
        delete m_pMaze;
}

void CFrmMaze::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    
    QImage image(":/png/Backgroup");
    painter.drawImage(this->geometry(), image);
    
    std::auto_ptr<CDraw> pDraw(new CQtDraw(&painter));
    if(m_pMaze)
        m_pMaze->onDraw(pDraw.get(), this->geometry().width(), this->geometry().height());
}

void CFrmMaze::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
}

int CFrmMaze::initMaze()
{
    int nRet = 0;
    //TODO:
    //m_pMaze = new HexagonalMaze(100);
    m_pMaze = new RectangularMaze(100, 100);
    if(NULL == m_pMaze)
        return -1;
    m_pMaze->InitialiseGraph();
    std::auto_ptr<MinimumSpanningtreeAlgorithm> pAlgorithm(new BreadthFirstSearch());
    m_pMaze->GenerateMaze(pAlgorithm.get());
    
    //m_pMaze->PrintMazeSVG("Maze");

    return nRet;
}
