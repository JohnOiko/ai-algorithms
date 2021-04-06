//
// Created by John on 3/24/2021.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

#define HEIGHT 3
#define WIDTH 3

using namespace std;

class Board
{
public:
    Board(int table[HEIGHT][WIDTH]);
    int getContent(int row, int col) const {return content[row][col];}
    int getGapRow() const {return gapRow;}
    int getGapCol() const {return gapCol;}
    int getDepth();
    double getHvalue() const {return Hvalue;}
    long long getKey() const;
    string getActionName() const {return actionName;}
    Board *getPrevious() const {return prev;}
    void setContent(int newContent, int row, int col) {content[row][col] = newContent;}
    void setGapRow(int row) {gapRow = row;}
    void setGapCol(int col) {gapCol = col;}
    void setHvalue(double h) {Hvalue = h;}
    void setActionName(string s) {actionName = move(s);}
    void setPrevious (Board *p) {prev = p;}
    bool goUp(Board &n);
    bool goDown(Board &n);
    bool goLeft(Board &n);
    bool goRight(Board &n);
    bool findContent(int key, int &row, int &col) const;
    int heuristic (Board *goal) const;
    static bool isValid(int row, int col) {return row >= 0 && row < HEIGHT && col >= 0 && col < WIDTH;}
    vector <Board*> expand();
    string toString() const;
    void printPath();
    bool operator==(const Board& o) const;

protected:

private:
    int content[HEIGHT][WIDTH];
    int gapRow;
    int gapCol;
    double Hvalue;
    string actionName;
    Board *prev;
};

class myComparator
{
public:
    int operator() (Board *p1 , Board *p2) const
    {
        return p1->getHvalue()>p2->getHvalue();
    }
};

#endif // BOARD_H