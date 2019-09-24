#include "graph.h"
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

Graph::Graph(int num){
  nodes = num;
  order = 0;
}

Graph::Graph(int** edges, int num){
  matrix = new int*[num];
  vTime = new int[num];
  fTime = new int[num];
  for(int i=0; i<num ;i++){
    matrix[i] = new int[num];
    for(int j=0; j<num; j++){
      matrix[i][j] = edges[i][j];
    }
  }
  for(int i=0; i<num ;i++){
    vTime[i] = 0;
    fTime[i] = 0;
  }
  nodes = num;
  order = 0;
}

Graph::~Graph(){
  for(int i=0; i<nodes;i++){
    delete[] matrix[i];
  }
  delete[] matrix;
}

void Graph::setOrder(int x){
  order = x;
  if(order == 0)
    cout << "increasing order." << endl;
  else
    cout << "decreasing order." << endl;
}

void Graph::bfs(int x, int** m){
  clearTime();
  int *result = new int[nodes]; // distance from x to node[i]
  int *visited = new int[nodes];
  int vSeq = 0;
  for(int i=0; i<nodes; i++){
    visited[i] = 0;// not visited
    result[i] = 0;
  }
  queue<int> q;
  q.push(x);
  cout << (char)(x+65) << " ";
  visited[x] = 1; // visited 1st node
  result[x] = 0; // from x to x
  vSeq ++;
  vTime[x] = vSeq;
  while(q.size()!=0){
    int currentNode = q.front();
    q.pop();
    //for(int i=nodes-1; i>=0; i--){ // decreasing
    if(order == 0){
      for(int i=0; i<nodes; i++){
        if(matrix[currentNode][i]>0 && visited[i] == 0){
          //test
          vSeq++;
          vTime[i] = vSeq;
          cout << (char)(i+65) << " ";
          result[i] = result[currentNode] + matrix[currentNode][i];
          visited[i] = 1;
          q.push(i);
        }
      }
    }else{
      for(int i=nodes-1; i>=0; i--){
        if(matrix[currentNode][i]>0 && visited[i] == 0){
          //test
          vSeq++;
          vTime[i] = vSeq;
          cout << (char)(i+65) << " ";
          result[i] = result[currentNode] + matrix[currentNode][i];
          visited[i] = 1;
          q.push(i);
        }
      }
    }
  }
}

void Graph::dfs(int x, int** m){
  clearTime();
  int *result = new int[nodes]; // distance from x to node[i]
  int *visited = new int[nodes];
  int vSeq = 0;
  for(int i=0; i<nodes; i++){
    visited[i] = 0;// not visited
    result[i] = 0;
  }
  stack<int> s;
  cout << (char)(x+65) << " ";
  s.push(x);
  visited[x] = 1; // visited 1st node
  result[x] = 0;// from x to x
  vSeq ++;
  vTime[x] = vSeq;
  while(s.size()!=0){
    int currentNode = s.top();
    bool isMoreVertex = false;
    //for(int i=nodes-1; i>=0; i--){ // decreasing
    if (order == 0){
      for(int i=0; i<nodes; i++){
        if(matrix[currentNode][i]>0 && visited[i] == 0){
        //test
          vSeq ++;
          vTime[i] = vSeq;
          cout << (char)(i+65) << " ";
          result[i] = result[currentNode] + matrix[currentNode][i];
          visited[i] = 1;
          s.push(i);
          isMoreVertex = true;
          break;
        }
      }
    }else{
      for(int i=nodes -1; i>=0; i--){
        if(matrix[currentNode][i]>0 && visited[i] == 0){
        //test
          vSeq++;
          vTime[i] = vSeq;
          cout << (char)(i+65) << " ";
          result[i] = result[currentNode] + matrix[currentNode][i];
          visited[i] = 1;
          s.push(i);
          isMoreVertex = true;
          break;
        }
      }
    }
    
    if(!isMoreVertex){
        //cout << (char)(i+65) << " ";
        //if(s.size()>0)
        vSeq++;
        fTime[s.top()] = vSeq;
        s.pop();
    }
    if(s.size()==0){
      if (order == 0){
        for(int i=0; i<nodes; i++){
          if(visited[i] == 0){
            cout <<  (char)(i+65)<<" ";
            visited[i] = 1;
            s.push(i);
            vSeq ++;
            vTime[i] = vSeq;
            break;
          }
        }
      }else{
        for(int i=nodes -1; i>=0; i--){
          if(visited[i] == 0) {
            cout <<  (char)(i+65)<<" ";
            s.push(i);
            visited[i] = 1;
            vSeq ++;
            vTime[i] = vSeq;
            break;
          }
       }
      }
    }
  }
}

void Graph::printTime(){
  cout <<endl <<"Visit time and finish time:";
  for(int i=0; i<nodes; i++){
    cout << endl << (char)(i+65) << "["
    << vTime[i] << ":"<< fTime[i]<<"]";
  }
  cout <<endl;
}

/*
 * node1, node2, weight
 */
bool Graph::set_edge(int x, int y, int weight){
  matrix[x][y] = weight;
}

/*
 * x-> start node
 */
void Graph::dfs(int x){
  dfs(x, matrix);
}

void Graph::clearTime(){
  for(int i=0; i<nodes ;i++){
    vTime[i] = 0;
    fTime[i] = 0;
  }
}
/*
 *
 */
void Graph::bfs(int x){
  bfs(x, matrix);
}