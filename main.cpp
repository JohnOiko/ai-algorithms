#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include "Board.h"

#define EXAM_LIMIT 1000000

using namespace std;

Board *DFS(Board *initial, Board *goal, long long &examined, long long &mem)
{
    stack<Board *> agenda;
    unordered_map <long long,Board *> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0 && examined < EXAM_LIMIT)
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
            pair<long long,Board *> k (s->getKey(),s);
            closed.insert(k);
            vector<Board *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
                if (closed.count(children[i]->getKey())==0)
                    agenda.push(children[i]);
                else
                    delete children[i];
        }
    }
    return nullptr;
}

Board *BFS(Board *initial, Board *goal, long long &examined, long long &mem)
{
    queue<Board *> agenda;
    unordered_map <long long,Board *> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size() > 0 && examined < EXAM_LIMIT)
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
            pair<long long,Board *> k (s->getKey(),s);
            closed.insert(k);
            vector<Board *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
                if (closed.count(children[i]->getKey())==0)
                    agenda.push(children[i]);
                else
                    delete children[i];
        }
    }
    return nullptr;
}

Board *BestFS(Board *initial, Board *goal, long long &examined, long long &mem)
{
    priority_queue <Board*, vector<Board *>, myComparator > agenda;
    unordered_map <long long,Board*> closed;
    agenda.push(initial);
    examined = 0;
    mem=1;
    while (agenda.size()>0 && examined < EXAM_LIMIT)
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
            pair<long long,Board*> k (s->getKey(),s);
            closed.insert(k);
            vector<Board *> children = s->expand();
            for (unsigned int i=0;i<children.size();i++)
            {
                if (closed.count(children[i]->getKey())==0)
                {
                    children.at(i)->setHvalue(children.at(i)->heuristic(goal));
                    agenda.push(children.at(i));
                }
                else
                    delete children[i];
            }
        }
    }
    return nullptr;
}

Board *Astar(Board *initial, Board *goal, long long &examined, long long &mem)
{
    double heuristicWeight = 1;
    if (HEIGHT > 3 || WIDTH > 3)
        heuristicWeight = 2;
    priority_queue <Board*, vector<Board *>, myComparator > agenda;
    unordered_map <long long,Board*> closed;
    agenda.push(initial);
    examined = 0;
    mem=1;
    while (agenda.size()>0 && examined < EXAM_LIMIT)
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
            pair<long long,Board*> k (s->getKey(),s);
            closed.insert(k);
            vector<Board *> children = s->expand();
            for (unsigned int i=0;i<children.size();i++)
            {
                if (closed.count(children[i]->getKey())==0)
                {
                    children.at(i)->setHvalue(heuristicWeight * children.at(i)->heuristic(goal) + children.at(i)->getDepth());
                    agenda.push(children.at(i));
                }
                else
                    delete children[i];
            }
        }
    }
    return nullptr;
}

void printResults(Board *solution, long long examined, long long mem) {
    if (solution != nullptr)
        cout<<"depth = "<<solution->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl;
    else if (examined == EXAM_LIMIT)
        cout<<"Hit examined states limit"<<endl;
    else
        cout<<"Problem unsolvable"<<endl;
}

void randomize(int array[HEIGHT][WIDTH]) {
    for (int i = 0 ; i < HEIGHT ; i++) {
        for (int j = 0 ; j < WIDTH ; j++) {
            array[i][j] = 0;
        }
    }
    int size = HEIGHT * WIDTH;
    int randIndex = rand() % size;
    array[randIndex / WIDTH][randIndex % WIDTH] = -1;
    for (int i = 1 ; i < size ; i++) {
        randIndex = rand() % size;
        while (array[randIndex / WIDTH][randIndex % WIDTH] != 0) {
            randIndex = rand() % size;
        }
        array[randIndex / WIDTH][randIndex % WIDTH] = i;
    }
}

int main()
{
    srand(time(nullptr));
    long long mem,examined;
    int start[HEIGHT][WIDTH];
    int ending[HEIGHT][WIDTH];
    int defaultStart[3][3] = {3, 6, -1, 1, 4, 2, 7, 5, 8};

    cout<<"Do you want to have a random initial and goal state?\n"
          "Pick by entering the corresponding number:\n"
          "(Warning: some random states may lead to unsolvable problems)"
          "\n1 -> No random states\n2 -> Only random initial state"
          "\n3 -> Only random goal state\n4 -> Both random states\n"<<endl;
    string useRand;
    cin>>useRand;
    cout<<endl;
    while (useRand != "1" && useRand != "2" && useRand != "3" && useRand != "4") {
        cout<<"Please give a valid answer:\n";
        cin>>useRand;
        cout<<endl;
    }

    if (useRand == "2" || useRand == "4" || sizeof(defaultStart)/(sizeof(int)*WIDTH) != HEIGHT || sizeof(defaultStart[0])/sizeof(int) != WIDTH) {
        randomize(start);
        if (useRand != "2" && useRand != "4")
            cout<<"Using random initial state because default initial state is of incorrect dimensions.\n"<<endl;
    }
    else {
        for (int i = 0 ; i < HEIGHT ; i++) {
            for (int j = 0 ; j < WIDTH ; j++) {
                start[i][j] = defaultStart[i][j];
            }
        }
    }

    if (useRand == "3" || useRand == "4") {
        randomize(ending);
    }
    else {
        int counter = 0;
        for (int i = 0 ; i < HEIGHT ; i++) {
            for (int j = 0 ; j < WIDTH ; j++) {
                counter++;
                ending[i][j] = counter;
            }
        }
        ending[HEIGHT - 1][WIDTH - 1] = -1;
    }

    Board m(start);
    Board g(ending);
    Board *initial = &m;
    Board *goal = &g;

    cout<<"Initial:"<<endl<<initial->toString()<<endl;
    cout<<"Goal:"<<endl<<goal->toString()<<endl;

    cout<<"DFS: ";
    Board *DFSsol = DFS(initial,goal,examined,mem);
    printResults(DFSsol, examined, mem);

    cout<<endl<<"BFS: ";
    Board *BFSsol = BFS(initial,goal,examined,mem);
    printResults(BFSsol, examined, mem);

    cout<<endl<<"BestFS: ";
    Board *BestFSsol = BestFS(initial,goal,examined,mem);
    printResults(BestFSsol, examined, mem);

    cout<<endl<<"A*: ";
    Board *Astarsol = Astar(initial,goal,examined,mem);
    printResults(Astarsol, examined, mem);

    if (DFSsol != nullptr || BFSsol != nullptr || BestFSsol != nullptr || Astarsol != nullptr) {
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
            else if (choice == "1" || choice == "2" || choice == "3" || choice == "4")
                cout<<"No path available as solution wasn't found\n"<<endl;
            else {
                flag = false;
                cout<<"Exiting program."<<endl;
            }
        }
    }
    return 0;
}