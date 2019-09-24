#include "graph.h"
#include<iostream>
using namespace std;
int main()
{
  int testMatrix[12][12] ={
  // A B C D E F G H I J K L
  // 1 2 3 4 5 6 7 8 9 101112
    {0,0,0,1,0,0,0,0,0,0,0,0},//A 1
    {0,0,1,1,0,0,0,0,0,0,0,0},//B 2
    {0,0,0,0,0,0,0,0,0,0,0,0},//C 3
    {1,1,0,0,1,0,0,0,0,0,0,0},//D 4
    {0,0,1,1,0,0,1,0,0,0,0,0},//E 5
    {0,0,0,0,0,0,0,0,1,0,0,0},//F 6
    {0,0,0,0,0,0,0,1,0,0,0,0},//G 7
    {0,0,0,0,0,1,0,0,1,0,1,0},//H 8
    {0,0,0,0,0,1,0,0,0,0,0,0},//I 9
    {0,0,0,0,0,0,0,0,0,0,0,1},//J 10
    {0,0,0,0,0,0,1,0,0,1,0,0},//K 11
    {0,0,0,0,0,0,0,0,0,0,1,0} //L 12
  };
  int ** edge = new int*[12];
  for(int i=0; i<12; i++){
    edge[i] = testMatrix[i];
  }
  
  Graph g(edge, 12);
  g.setOrder(0); // 0 for increasing and 1 for decreasing
  cout << "bfs:" << endl;
  g.bfs(0);
  g.printTime();
  cout << endl<< "dfs:" << endl;
  g.dfs(0);
  cout << endl;
  g.printTime();
  
  g.setOrder(1); // 0 for increasing and 1 for decreasing
  cout << "bfs:" << endl;
  g.bfs(0);
  g.printTime();
  cout << endl<< "dfs:" << endl;
  g.dfs(0);
  g.printTime();
  
  delete[] edge;
  
  return 0;
}
