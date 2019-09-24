#include <iostream>
#include <limits.h>

#include "graph.h"
#include "random_generator.h"

using namespace std;

int main(int argc, char* argv[])
{
  int n,m,w,s;
  if (argc == 5)
    {
      n = atoi(argv[1]);
      n = (n>0) ? n : 1;
      m = atoi(argv[2]);
      m = (m>0) ? m : 1;
      w = atoi(argv[3]);
      w = (w>0) ? w : 1;
      s = atoi(argv[4]);
      s = (s>0) ? s : 1;
      
      if(n>INT_MAX||m>INT_MAX||w>INT_MAX||s>INT_MAX){
        cout << "Input out of bounds.";
        return 0;
      }
    }
    else
    {
      cout << "hw7: [n] [m] [w]" << endl;
      cout << "[n]    number of vertices generated" << endl;
      cout << "[m]    number of edges generated" << endl;
      cout << "[w]    interval of weights [-w, w]" << endl;
      cout << "[s]    source node fo Bellman-Ford" << endl;
      cout << endl;
      return 0;
    }
  // int -> number of vertecs n,
  graph g(n);
  // int0-> number of edges m,
  // int1-> interval of possible weights w, [-w, w]
  g.random_graph(m, w);
  g.output();
  
  // //manully testing
  //   int testMatrix[5][5] ={
  // // A B C D E
  // // 1 2 3 4 5
  //   {0,3,8,INT_MAX,-4},//A 1
  //   {INT_MAX,0,INT_MAX,1,7},//B 2
  //   {INT_MAX,4,0,INT_MAX,INT_MAX},//C 3
  //   {2,INT_MAX,-5,0,INT_MAX},//D 4
  //   {INT_MAX,INT_MAX,INT_MAX,6,0},//E 5
  // };
  
  // int ** edge = new int*[5];
  // for(int i=0; i<5; i++){
  //   edge[i] = testMatrix[i];
  // }
  // g.set_edge(edge);
  // g.output();
  
  //  int testMatrix[5][5] ={
  // // A B C D E
  // // 1 2 3 4 5
  //   {0,6,INT_MAX,7,INT_MAX},//A 1
  //   {INT_MAX,0,5,8,-4},//B 2
  //   {INT_MAX,-2,0,INT_MAX,INT_MAX},//C 3
  //   {INT_MAX,INT_MAX,-3,0,9},//D 4
  //   {2,INT_MAX,7,INT_MAX,0},//E 5
  // };
  
  if(!g.BF(s)){
    cout << "exist negetive-weight cycle!" << endl;
  }
  g.FW();
  return 0;
}
  
