//
// Created by John on 3/24/2021.
//

#ifndef BOARD_H
#define BOARD_H
#define WIDTH 3
#define HEIGHT 3
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

#include <iostream>

using namespace std;

class Board
{
public:
    Board(int table[WIDTH][HEIGHT]);
    int getContent(int x, int y);
    int getGapX();
    int getGapY();
    int getDepth();
    double getHvalue();
    unsigned long getKey();
    string getActionName()const {return actionName;}
    Board *getPrevious()const {return prev;}
    void setContent(int newContent, int x, int y);
    int setGapX(int x);
    int setGapY(int y);
    void setHvalue(double h);
    void setActionName(string s) {actionName=s;}
    void setPrevious (Board *p) {prev=p;}
    bool goUp(Board &n);
    bool goDown(Board &n);
    bool goLeft(Board &n);
    bool goRight(Board &n);
    void findContent(int key, int &x, int &y);
    int heuristic (Board *);
    bool isValid(int x, int y);
    vector <Board *> expand();
    string toString() const;
    void printPath();
    bool operator==(const Board& o) const;

protected:

private:
    int content[WIDTH][HEIGHT];
    int xgap;
    int ygap;
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

