#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "Board.h"

using namespace std;

Board *DFS(Board *initial, Board *goal, long long &examined, long long &mem)
{
    stack<Board *> agenda;
    unordered_map <unsigned long,Board *> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        Board *s = agenda.top();
        agenda.pop();
        if (closed.count(s->getKey())==0)
        {
            examined++;
            if (*s==*goal)
                return s;
            pair<unsigned long,Board *> k (s->getKey(),s);
            closed.insert(k);
            vector<Board *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
                if (closed.count(children[i]->getKey())==0)
                    agenda.push(children[i]);
        }
    }
    return nullptr;
}

Board *BFS(Board *initial, Board *goal, long long &examined, long long &mem)
{
    queue<Board *> agenda;
    unordered_map <unsigned long,Board *> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        Board *s = agenda.front();
        agenda.pop();
        if (closed.count(s->getKey())==0)
        {
            examined++;
            if (*s==*goal)
                return s;
            pair<unsigned long,Board *> k (s->getKey(),s);
            closed.insert(k);
            vector<Board *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
                if (closed.count(children[i]->getKey())==0)
                    agenda.push(children[i]);
        }
    }
    return nullptr;
}

Board *BestFS(Board *initial, Board *goal, long long &examined, long long &mem)
{
    priority_queue <Board*, vector<Board *>, myComparator > agenda;
    unordered_map <unsigned long,Board*> closed;
    agenda.push(initial);
    examined = 0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        Board *s = agenda.top();
        agenda.pop();

        if (closed.count(s->getKey())==0)
        {
            examined++;
            if (*s==*goal)
                return s;
            pair<unsigned long,Board*> k (s->getKey(),s);
            closed.insert(k);
            vector<Board *> children = s->expand();
            for (unsigned int i=0;i<children.size();i++)
            {
                if (closed.count(children[i]->getKey())==0)
                {
                    children.at(i)->setHvalue(children.at(i)->heuristic(goal));
                    agenda.push(children.at(i));
                }
            }
        }
    }
    return nullptr;
}

Board *Astar(Board *initial, Board *goal, long long &examined, long long &mem)
{
    priority_queue <Board*, vector<Board *>, myComparator > agenda;
    unordered_map <unsigned long,Board*> closed;
    agenda.push(initial);
    examined = 0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        Board *s = agenda.top();
        agenda.pop();

        if (closed.count(s->getKey())==0)
        {
            examined++;
            if (*s==*goal)
                return s;
            pair<unsigned long,Board*> k (s->getKey(),s);
            closed.insert(k);
            vector<Board *> children = s->expand();
            for (unsigned int i=0;i<children.size();i++)
            {
                if (closed.count(children[i]->getKey())==0)
                {
                    children.at(i)->setHvalue(children.at(i)->heuristic(goal) + children.at(i)->getDepth());
                    agenda.push(children.at(i));
                }
            }
        }
    }
    return nullptr;
}

int main()
{
    long long mem,examined;
    int start[3][3] = {3, 6, -1, 1, 4, 2, 7, 5, 8};
    int ending[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, -1};
    Board m(start);
    Board g(ending);

    Board *initial = &m;
    Board *goal = &g;

    cout<<"Initial:"<<endl<<initial->toString()<<endl;
    cout<<"Goal:"<<endl<<goal->toString()<<endl;

    cout<<"DFS: ";
    Board *DFSsol;
    DFSsol=DFS(initial,goal,examined,mem);
    if (DFSsol!=nullptr)
    {
        cout<<"depth = "<<DFSsol->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl;
    }
    else
        cout<<"Problem unsolvable"<<endl;

    Board *BFSsol;
    cout<<endl<<"BFS: ";
    BFSsol=BFS(initial,goal,examined,mem);
    if (BFSsol!=nullptr)
    {
        cout<<"depth = "<<BFSsol->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl;
    }
    else
        cout<<"Problem unsolvable"<<endl;

    Board *BestFSsol;
    cout<<endl<<"BestFS: ";
    BestFSsol=BestFS(initial,goal,examined,mem);
    if (BestFSsol!=nullptr)
    {
        cout<<"depth = "<<BestFSsol->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl;
    }
    else
        cout<<"Problem unsolvable"<<endl;

    Board *Astarsol;
    cout<<endl<<"A*: ";
    Astarsol=Astar(initial,goal,examined,mem);
    if (Astarsol!=nullptr)
    {
        cout<<"depth = "<<Astarsol->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl;
    }
    else
        cout<<"Problem unsolvable"<<endl;

    bool flag = true;
    while (flag) {
        cout<<"\nPick an algorithm's path to show by entering the corresponding number, or enter any other symbol to close the program:\n1 -> DFS\n2 -> BFS\n3 -> BestFS\n4 -> A*\n"<<endl;
        string choice;
        cin>>choice;
        cout<<endl;
        if (choice == "1" && DFSsol != nullptr)
            DFSsol->printPath();
        else if (choice == "2" && BFSsol != nullptr)
            BFSsol->printPath();
        else if (choice == "3" && BestFSsol != nullptr)
            BestFSsol->printPath();
        else if (choice == "4" && Astarsol != nullptr)
            Astarsol->printPath();
        else if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            cout<<"No path available as solution wasn't found"<<endl;
        }
        else {
            flag = false;
            cout<<"Exiting program."<<endl;
        }
    }

    return 0;
}