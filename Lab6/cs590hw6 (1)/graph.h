#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <set>

using namespace std;


class Graph
{
    private:
        int nodes;
        int **matrix;
        int *vTime;
        int *fTime;
        
        //void dfs(int, set<int>*);
        void dfs(int, int**);
        //void bfs(int, set<int>*);
        void bfs(int, int**);
        
        void clearTime();
        int order;
    public:
        Graph(int);
        Graph(int**, int);
        ~Graph();

        bool set_edge(int, int, int);
        void dfs(int);
        void bfs(int);
        void setOrder(int);
        void printTime();
};

#endif
