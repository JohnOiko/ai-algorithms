//
// Created by John on 3/24/2021.
//

#include "Board.h"

Board::Board(int table[WIDTH][HEIGHT])
{
    for (int i = 0 ; i < WIDTH ; i++) {
        for (int j = 0 ; j < HEIGHT ; j++) {
            content[i][j] = table[i][j];
            if (content[i][j] == -1) {
                xgap = j;
                ygap = i;
            }
        }
    }
    setHvalue(0);
    setActionName("");
    setPrevious(nullptr);
}

int Board::getContent(int x, int y)
{
    return content[y][x];
}

int Board::getGapX() const
{
    return xgap;
}

int Board::getGapY() const
{
    return ygap;
}

int Board::getDepth()
{
    int counter =0;
    Board *p = this;
    while (p->prev!=nullptr)
    {
        p=p->prev;
        counter++;
    }
    return counter;
}

double Board::getHvalue() const
{
    return Hvalue;
}

unsigned long Board::getKey()
{
    unsigned long k = 0;
    int power= HEIGHT*WIDTH;
    for (int i = 0 ; i < HEIGHT ; i++) {
        for (int j = 0 ; j < WIDTH ; j++) {
            power--;
            if (content[i][j] != -1) {
                k += (int) (pow(10, power) + 0.5) * content[i][j];
            }
        }
    }
    return k;
}

void Board::setContent(int newContent, int x, int y)
{
    content[y][x] = newContent;
}

void Board::setGapX(int x)
{
    xgap = x;
}

void Board::setGapY(int y)
{
    ygap = y;
}

void Board::setHvalue(double h)
{
    Hvalue = h;
}

bool Board::goUp(Board &n)
{
    if (getGapY()>0 && isValid(getGapX(), getGapY()-1)) {
        n=*this;
        n.setContent(n.getContent(n.getGapX(), n.getGapY()-1), n.getGapX(), n.getGapY());
        n.setGapY(n.getGapY()-1);
        n.setContent(-1, n.getGapX(), n.getGapY());
        n.setActionName("up");
        n.setPrevious(this);
        return true;
    }
    return false;
}

bool Board::goDown(Board &n)
{
    if (getGapY()<HEIGHT-1 && isValid(getGapX(), getGapY()+1)) {
        n=*this;
        n.setContent(n.getContent(n.getGapX(), n.getGapY()+1), n.getGapX(), n.getGapY());
        n.setGapY(n.getGapY()+1);
        n.setContent(-1, n.getGapX(), n.getGapY());
        n.setActionName("down");
        n.setPrevious(this);
        return true;
    }
    return false;
}

bool Board::goLeft(Board &n)
{
    if (getGapX()>0 && isValid(getGapX()-1, getGapY())) {
        n=*this;
        n.setContent(n.getContent(n.getGapX()-1, n.getGapY()), n.getGapX(), n.getGapY());
        n.setGapX(n.getGapX()-1);
        n.setContent(-1, n.getGapX(), n.getGapY());
        n.setActionName("left");
        n.setPrevious(this);
        return true;
    }
    return false;
}

bool Board::goRight(Board &n)
{
    if (getGapX()<WIDTH-1 && isValid(getGapX()+1, getGapY())) {
        n=*this;
        n.setContent(n.getContent(n.getGapX()+1, n.getGapY()), n.getGapX(), n.getGapY());
        n.setGapX(n.getGapX()+1);
        n.setContent(-1, n.getGapX(), n.getGapY());
        n.setActionName("right");
        n.setPrevious(this);
        return true;
    }
    return false;
}

void Board::findContent(int key, int &x, int &y)
{
    x = 0;
    y = 0;
    for (int i = 0 ; i < WIDTH ; i++) {
        for (int j = 0 ; j < HEIGHT ; j++) {
            if (key == content[i][j]) {
                x = j;
                y = i;
                return;
            }
        }
    }
}

int Board::heuristic(Board *goal)
{
    int dist = 0;
    int x;
    int y;
    for (int i = 0 ; i < WIDTH ; i++) {
        for (int j = 0 ; j < WIDTH ; j++) {
            findContent(goal->getContent(i, j), x, y);
            dist += abs(x-i) + abs(y-j);
        }
    }
    return dist;
}

bool Board::isValid(int x, int y)
{
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

vector <Board *> Board::expand()
{
    vector <Board *> children;
    Board *child;
    child = new Board(*this);
    if (goUp(*child))
        children.push_back(child);
    else
        delete child;
    child = new Board(*this);
    if (goDown(*child))
        children.push_back(child);
    else
        delete child;
    child = new Board(*this);
    if (goLeft(*child))
        children.push_back(child);
    else
        delete child;
    child = new Board(*this);
    if (goRight(*child))
        children.push_back(child);
    else
        delete child;
    return children;
}

string Board::toString () const
{
    stringstream ot;
    for (int i = 0 ; i < HEIGHT ; i++) {
        ot<<"[";
        for (int j = 0 ; j < WIDTH ; j++) {
            if (content[i][j] == -1) {
                ot<<" ";
            }
            else {
                ot<<content[i][j];
            }
            if (j < WIDTH - 1) {
                ot<<" ";
            }
        }
        ot<<"]\n";
    }
    return ot.str();
}

void Board::printPath()
{
    vector <Board *> path;
    vector <string> actions;
    Board *p = this;
    path.push_back(p);
    actions.push_back(p->getActionName());
    while (p->prev!=nullptr)
    {
        p=p->prev;
        path.push_back(p);
        actions.push_back(p->getActionName());
    }
    for (int i = path.size()-1 ; i >= 0 ; i--) {
        if (!actions.at(i).empty()) {
            cout<<"Moved gap "<<actions.at(i)<<":"<<endl;
        }
        else {
            cout<<"Initial state:"<<endl;
        }
        cout<<path.at(i)->toString()<<endl;
    }
}

bool Board::operator==(const Board& o) const
{
    for (int i = 0 ; i < WIDTH ; i++) {
        for (int j = 0 ; j < HEIGHT ; j++) {
            if (content[i][j] != o.content[i][j]) {
                return false;
            }
        }
    }
    return true;
}