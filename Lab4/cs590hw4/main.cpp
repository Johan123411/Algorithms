#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "bs_tree.h"
#include "rb_tree.h"
#include "timer.h"
#include "random_generator.h"

//code template taken from the lecture code and algorithm from lecture slides

int main(int argc, char* argv[])
{
    int m, n;

    if (argc == 3)
    {
      m = atoi(argv[1]);
      m = (m < 1) ? 1 : m;
      n = atoi(argv[2]);
      n = (n<0 || n>2)? 0:n;
    }
    else
    {
      cout << "hw4: [m] [n]" << endl;
      cout << "[m]              number of the random numbers generated" << endl;
      cout << "[n]              0:random input; 1:sorted input; 2:inverse sorted input" << endl;
      cout << endl;
      return 0;
    }
  int* nums;
  if(n==0){
    nums = create_random(m);
  }else if(n==1){
    nums = create_sorted(m);
  }else if(n==2){
    nums = create_reverse_sorted(m);
  }
  
  timer t;
  rb_tree* rbt = new rb_tree();
  
  t.start();
  rbt->insert(nums, m);
  t.stop();
  cout << "RED_BLACK_TREE:" << endl;
  rbt->printCounter();
  //rbt->black_node_number();
  cout<<"time :" << endl << t<<endl;
  
  
  bs_tree* bst = new bs_tree();
  
  t.start();
  bst->inserT(nums, m);
  t.stop();
  // int * c = bst->inorder_tree_walk();
  // for(int i=0; i<bst->size(); i++){
  //   cout <<"->" << c[i];
  // }
  // cout << endl;
  // if(check_sorted(c,0,bst->size()))
  //   cout << "sorted!" <<endl;
  // else
  //   cout << "not sorted!";
  cout << "BINARY_SEARCH_TREE:"<<endl;
  bst->printCounter();
  cout<<"time:" << endl << t<<endl;
  
  
  // timer t;
  // t.start();
  // //int a[] = {1,2,3,4,5,6,7,1,2,3};
  // int* randonNums = create_random(m);
  // rb_tree *r = new rb_tree();
  // r->insert(randonNums,m);
  // r->inorder_output();
  // r->output();
  
  // int * b = r-> inorder_tree_walk();
  // cout << endl;
  // for(int i=0; i<r->size(); i++){
  //   cout <<"->" << b[i];
  // }
  // cout <<endl;
  // if(check_sorted(b,0,r->size()))
  //   cout << "sorted!" <<endl;
  // else
  //   cout << "not sorted!";
    
  // r->black_node_number();
  
  // t.stop();
  // cout << t <<endl;
  
  // bs_tree* bt = new bs_tree();
  // int *randonNums1 = create_random(m);
  // bt->inserT(randonNums1,m);
  // int * c = bt->inorder_tree_walk();
  // for(int i=0; i<bt->size(); i++){
  //   cout <<"->" << c[i];
  // }
  // cout << endl;
  // if(check_sorted(b,0,r->size()))
  //   cout << "sorted!" <<endl;
  // else
  //   cout << "not sorted!";
  cout << endl;
  return 0;
}
  
