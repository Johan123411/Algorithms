#ifndef __AM_GRAPH_H__
#define __AM_GRAPH_H__

#include <limits.h>
#include "random_generator.h"
    
class graph
{
  protected:
    int**	m_edge;
    int		no_vert;
    int   no_edge;
    int   max_val;


  public:
    graph(int);
    ~graph();

    int get_no_of_vertices()
      { return no_vert; }

    void set_edge(int **);

    void output();
    void random_graph(int,int);
    // Bellman-Ford
    bool BF(int);
    // Floyd-Warshall
    void FW();
  protected:
    void initialize();
    void permutation(int*, int);
    
};

// Notes:
// 1. determine the number of maximal allowed edges for a non-cyclic random path v0 v1...vk.
// it should be n! ?

#endif
