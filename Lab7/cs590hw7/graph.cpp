
#include "graph.h"
#include <list>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
 * constructor/destructor
 */
graph::graph(int n)
{ /*<<<*/
  no_vert = (n > 0) ? n : 1;
/*
 * allocate adjacency matrix
 */
  m_edge = new int*[no_vert];
  for (int i = 0; i < no_vert; i++)
    m_edge[i] = new int[no_vert];

  initialize();
} /*>>>*/

graph::~graph()
{ /*<<<*/
/*
 * delete nil element and all other allocated nodes
 */
  for (int i = 0; i < no_vert; i++)
    delete[] m_edge[i];
  delete[] m_edge;
} /*>>>*/


void graph::initialize()
{ /*<<<*/
/*
 * initialize adjacency matrix
 * -> use infinity to allow 0 weight edges
 */
  for (int i = 0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
      m_edge[i][j] = INT_MAX;
      
} /*>>>*/

void graph::permutation(int* perm, int n)
{ /*<<<*/
  random_generator rg;
  int p_tmp, p_pos;

  for (int i = 0; i < n; i++)
    perm[i] = i;
  
  for (int i = 0; i < n; i++)
    {
      rg >> p_pos;
      p_pos = (p_pos % (n - i)) + i;
      p_tmp = perm[i];
      perm[i] = perm[p_pos];
      perm[p_pos] = p_tmp;
    }
} /*>>>*/

void graph::output()
{ /*<<<*/
  cout << "[";
  for (int i = 0; i < no_vert; i++)
    {
      cout << "[\t";
      for (int j = 0; j < no_vert; j++)
	if (m_edge[i][j] == INT_MAX)
	  cout << "Inf\t";
	else
	  cout << m_edge[i][j] << "\t";
      cout << "]" << endl;
    }
  cout << "]" << endl;
} /*>>>*/

void graph::random_graph(int m, int w){
  max_val = (w > 0) ? w : 1;
  no_edge = (m > 0) ? m : 1;
  
  // you can't have more than no_vert*(no_vert-1) edges
  if(no_edge > no_vert*(no_vert-1)){
    no_edge = no_vert*(no_vert-1);
  }
  
  int curr_edge = 0;
  while (curr_edge < no_edge){
    int * path = new int[no_vert];
    permutation(path, no_vert);
    for(int i=0; i<no_vert-1; i++){
      int j=path[i];
      int k=path[i+1];
      // node j to node k has a edge
      // eg: path -> {4,1,3,0,2} no_vert=5
      // then 4->1->3->0->2
      // m_edge[j][k]==INF means already exist an edge
      // so shared edges are only counted once
      if(m_edge[j][k]==INT_MAX){
        random_generator rg;
        int random_val;
        // random weight
        rg >> random_val;
        // here we allow no zero weight
        while(random_val%max_val==0){
          rg >> random_val;
        }
        int neg = 1;
        // random negetive vals
        if(random_val%13==0){
          neg = -1;
        }
        m_edge[j][k]= random_val%max_val*neg;
        curr_edge++;
        if(curr_edge>no_edge) break;
      }
    }
    // free memory
    delete[] path;
  }
  for(int i=0; i<no_vert; i++){
    m_edge[i][i] = 0;
  }

  return;
}

// s-> 1 to no_vert
bool graph::BF(int s){
  int * distance = new int[no_vert];
  int * pred = new int[no_vert];
  for(int i=0; i<no_vert;i++){
    distance[i] = INT_MAX;
    pred[i] = -1;
  }
  if(s>no_vert){
    s=no_vert;
  }
  distance[s-1]=0;
  // |V|-1 times relax
  for(int i=1; i<=no_vert-1;i++){
    for(int j=0; j<no_vert; j++){
      for(int k=0; k<no_vert; k++){
        if(m_edge[j][k]!=INT_MAX){
          if(distance[k]>distance[j]+m_edge[j][k]){
            //cout <<j << " " <<k << " "<< distance[j] <<"  " << m_edge[j][k] << endl;
            if(distance[j] != INT_MAX ){
              distance[k]=distance[j]+m_edge[j][k];
            }else{
              // in case of integer overflow
              distance[k]=distance[j];
            }
            pred[k]=j;
          }
        }
      }
    }
  }
  for(int i=0; i<no_vert;i++){
    for(int j=0; j<no_vert; j++){
      if(m_edge[i][j]!=INT_MAX){
          if(distance[j]>distance[i]+m_edge[i][j]){
          return false;
        }
      }
    }
  }
  cout << "Bellman-Ford:" << endl;
  cout << "Vertex" << "\t\t" << "Distance from " << s+1<<"\t" <<"Pre"<<endl;
  for(int i=0; i<no_vert;i++){
    if(pred[i]==-1){
      cout << i+1 << "\t\t" <<distance[i] << "\t\t" << "NIL"<<endl;
    }else{
      cout << i+1 << "\t\t" <<distance[i] << "\t\t" << pred[i]+1<<endl;
    }
  }
  
  // free memory
  delete[] distance;
  delete[] pred;
  return true;
}

void graph::FW(){
  int** floyd = new int*[no_vert];
  int** pred = new int*[no_vert];
  for(int i=0; i<no_vert;i++){
    floyd[i] = new int[no_vert];
    pred[i] = new int[no_vert];
    for(int j=0; j<no_vert; j++){
      floyd[i][j] = m_edge[i][j];
      pred[i][j] = -1;
    }
  }
  for(int i=0; i<no_vert;i++){
    floyd[i][i] = 0;
    for(int j=0; j<no_vert; j++){
      if(m_edge[i][j]!=INT_MAX&&m_edge[i][j]!=0){
        pred[i][j] = i;
      }
    }
  }
  
  for(int k=0; k<no_vert;k++){
    for(int i=0; i<no_vert; i++){
      for(int j=0; j<no_vert; j++){
        if(floyd[i][k]!=INT_MAX && floyd[k][j]!=INT_MAX){
          if((floyd[i][k]+floyd[k][j])<floyd[i][j]){
            pred[i][j] = pred[k][j];
          }
          floyd[i][j] = (floyd[i][k]+floyd[k][j])<floyd[i][j]?(floyd[i][k]+floyd[k][j]):floyd[i][j];
        }
      }
    }
  }
  
  cout<<endl << "Floyd-Warshell: weight matrix" << endl;
  for(int i=0; i<no_vert;i++){
    for(int j=0; j<no_vert; j++){
      if(floyd[i][j] == INT_MAX){
        cout <<"Inf" <<"\t";
      }else{
        cout << floyd[i][j] <<"\t";
      }
      
    }
    cout << endl;
  }
  
  cout<<endl << "Floyd-Warshell: predcessor matrix" << endl;
  for(int i=0; i<no_vert;i++){
    for(int j=0; j<no_vert; j++){
      if(pred[i][j] == -1){
        cout <<"NIL" <<"\t";
      }else{
        cout << pred[i][j]+1 <<"\t";
      }
      
    }
    cout << endl;
  }
  // free memory
  for(int i=0; i<no_vert;i++){
   delete[] floyd[i];
   delete[] pred[i];
  }
  delete[] floyd;
  delete[] pred;
  return;
}

// for testing
void graph::set_edge(int ** e){
  int curr_edge = 0;
  for(int i=0; i<no_vert; i++){
    for(int j=0; j<no_vert; j++){
      m_edge[i][j] = e[i][j];
      if(m_edge[i][j]!=0 && m_edge[i][j]!=INT_MAX){
        curr_edge++;
      }
    }
    
  }
  no_edge = curr_edge;
}