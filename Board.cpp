//
// Created by John on 3/24/2021.
//

#include "Board.h"

Board::Board(int table[HEIGHT][WIDTH])
{
    for (int i = 0 ; i < HEIGHT ; i++) {
        for (int j = 0 ; j < WIDTH ; j++) {
            content[i][j] = table[i][j];
            if (getContent(i, j) == -1) {
                gapRow = i;
                gapCol = j;
            }
        }
    }
    Hvalue = 0;
    actionName = "";
    prev = nullptr;
}

int Board::getDepth()
{
    int counter =0;
    Board *p = this;
    while (p->getPrevious() != nullptr)
    {
        p = p->getPrevious();
        counter++;
    }
    return counter;
}

long long Board::getKey() const
{
    long long k = 0;
    int gapIndex = 0;
    for (int i = 0 ; i < HEIGHT ; i++) {
        for (int j = 0 ; j < WIDTH ; j++) {
            if (getContent(i, j) != -1)
                k += getContent(i, j) * pow(7, i * WIDTH + j);
            else
                gapIndex = i * WIDTH + j;
        }
    }
    return k * 100 + gapIndex;
}

bool Board::goUp(Board &n)
{
    if (isValid(getGapRow()-1, getGapCol())) {
        n = *this;
        n.setContent(n.getContent(n.getGapRow()-1, n.getGapCol()), n.getGapRow(), n.getGapCol());
        n.setGapRow(n.getGapRow()-1);
        n.setContent(-1, n.getGapRow(), n.getGapCol());
        n.setActionName("up");
        n.setPrevious(this);
        return true;
    }
    return false;
}

bool Board::goDown(Board &n)
{
    if (isValid(getGapRow()+1, getGapCol())) {
        n = *this;
        n.setContent(n.getContent(n.getGapRow()+1, n.getGapCol()), n.getGapRow(), n.getGapCol());
        n.setGapRow(n.getGapRow()+1);
        n.setContent(-1, n.getGapRow(), n.getGapCol());
        n.setActionName("down");
        n.setPrevious(this);
        return true;
    }
    return false;
}

bool Board::goLeft(Board &n)
{
    if (isValid(getGapRow(), getGapCol()-1)) {
        n = *this;
        n.setContent(n.getContent(n.getGapRow(), n.getGapCol()-1), n.getGapRow(), n.getGapCol());
        n.setGapCol(n.getGapCol()-1);
        n.setContent(-1, n.getGapRow(), n.getGapCol());
        n.setActionName("left");
        n.setPrevious(this);
        return true;
    }
    return false;
}

bool Board::goRight(Board &n)
{
    if (isValid(getGapRow(), getGapCol()+1)) {
        n = *this;
        n.setContent(n.getContent(n.getGapRow(), n.getGapCol()+1), n.getGapRow(), n.getGapCol());
        n.setGapCol(n.getGapCol()+1);
        n.setContent(-1, n.getGapRow(), n.getGapCol());
        n.setActionName("right");
        n.setPrevious(this);
        return true;
    }
    return false;
}

bool Board::findContent(int key, int &row, int &col) const
{
    row = 0;
    col = 0;
    for (int i = 0 ; i < HEIGHT ; i++) {
        for (int j = 0 ; j < WIDTH ; j++) {
            if (key == getContent(i, j)) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

int Board::heuristic(Board *goal) const
{
    int dist = 0;
    int row;
    int col;
    for (int i = 0 ; i < HEIGHT ; i++) {
        for (int j = 0 ; j < WIDTH ; j++) {
            if (!findContent(goal->getContent(i, j), row, col)) {
                row = 0;
                col = 0;
            }
            dist += abs(row - i) + abs(col - j);
        }
    }
    return dist;
}

vector <Board *> Board::expand()
{
    vector <Board*> children;
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
    int size = to_string(HEIGHT * WIDTH).size();
    stringstream ot;
    for (int i = 0 ; i < HEIGHT ; i++) {
        ot<<"[";
        for (int j = 0 ; j < WIDTH ; j++) {
            for (int k = 0 ; k < size - (getContent(i, j) == -1 ? 0 : to_string(getContent(i, j)).size()) ; k++)
                ot<<" ";
            if (getContent(i, j) != -1)
                ot<<getContent(i, j);
            if (j < WIDTH - 1)
                ot<<" ";
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
    while (p->getPrevious() != nullptr)
    {
        p=p->getPrevious();
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
            if (getContent(i, j) != o.getContent(i, j)) {
                return false;
            }
        }
    }
    return true;
}