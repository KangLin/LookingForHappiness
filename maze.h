#ifndef MAZE_H
#define MAZE_H

#include <memory>
#include <vector>
#include "cellborder.h"
#include "minimumspanningtreealgorithm.h"
#include <QPainter>
#include <QRect>
#include "Draw.h"

class Maze {
public:
    Maze(int = 0, int = 0, int = 1);
    void GenerateMaze(MinimumSpanningtreeAlgorithm*);
    void PrintMazeGnuplot(const std::string&) const;
    void PrintMazeSVG(const std::string&) const;
    int onDraw(CDraw* pDraw, int nWidth, int nHeight) const;
    void RemoveBorders(const std::vector<std::pair<int, int>>&);
    virtual void InitialiseGraph() = 0;
    
protected:
    // Solving a maze is equivalent to finding a path in a graph
    int vertices_;
    enum MAZE_TYPE{
        OUT_WALL,
        WALL,
        ROAD
    };
    std::vector<MAZE_TYPE> maze_;
    std::vector<std::vector<std::pair<int, std::shared_ptr<CellBorder>>>> adjacencylist_;    
    int startvertex_, endvertex_;
    
    virtual std::tuple<double, double, double, double> GetCoordinateBounds() const = 0;
};

#endif /* end of include guard: MAZE_H */
