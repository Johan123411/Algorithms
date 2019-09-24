#ifndef __RB_TREE_H__
#define __RB_TREE_H__

enum rb_tree_color
{
  RB_RED,
  RB_BLACK
};

struct rb_tree_node
{
  int key;
  int color;
  rb_tree_node*	left;
  rb_tree_node*	right;
  rb_tree_node*	p;
};

class rb_tree
{
  protected:
    rb_tree_node*	T_nil;
    rb_tree_node*	T_root;
    
    //counters
    int total_number;
    int height;
    int dup_counter;  //counter for duplicates
    int case1_counter; //insertion case 1
    int case2_counter; //insertion case 2
    int case3_counter; //insertion case 3
    int lr_counter; // left rotate counter
    int rr_counter; // right rotate counter

  public:
    rb_tree();
    ~rb_tree();

    void insert(int*, int);
    void insert(int);
    
    int* inorder_tree_walk();
    
    int size()
    { return total_number-dup_counter;}
    
    void printCounter();
    
    int getHeight();
    
    void inorder_output()
      { inorder_output(T_root, 1); }
    void output()
      { output(T_root, 1); }
    void black_node_number()
      { black_node_number(T_root,0);}
  protected:
    void insert(rb_tree_node*);
    void insert_fixup(rb_tree_node*&);

    void remove_all(rb_tree_node*);

    void left_rotate(rb_tree_node*);
    void right_rotate(rb_tree_node*);
    
    void black_node_number(rb_tree_node*,int);
    int getHeight(rb_tree_node*,int);

    int inorder_tree_walk(rb_tree_node*,int*, int);
    void inorder_output(rb_tree_node*, int);
    void output(rb_tree_node*, int);
};


#endif
