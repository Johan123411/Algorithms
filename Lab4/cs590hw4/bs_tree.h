#ifndef __BS_TREE_H__
#define __BS_TREE_H__

struct bs_tree_Node
{
	int value;

	bs_tree_Node* left;

	bs_tree_Node* right;

	bs_tree_Node* parent;

};

class bs_tree
{
	protected:
		bs_tree_Node* bs_nil;
		bs_tree_Node* bs_root;

    int totalCount;
		int dupCount;
		int height;

	public:
		bs_tree();  //constructor

		~bs_tree();  //destructor

		bs_tree_Node* Bst_tree_search(int);

		void inserT(int);  //insert a new node into the tre

		void inserT(int*,int);

		//void deleTe(int);

		int* inorder_tree_walk();

    void Tree_Min();

    void Tree_Max();

    int size(){
      return totalCount-dupCount;
    }
    
    void printCounter();

    int getHeight();


	protected:
		bs_tree_Node*  Tree_Min(bs_tree_Node *); // find the minimum of the tree

		bs_tree_Node* Tree_Max(bs_tree_Node *); //find max of the tree

		bs_tree_Node* Succ(bs_tree_Node *); //successor

		bs_tree_Node* Pred(bs_tree_Node *);  //Predecessor

		//bs_tree_Node* NodeCreate(int);    //create a node

		void remove_all(bs_tree_Node*);    //removes all nodes in the tree

		int inorder_tree_walk(bs_tree_Node *, int*,int, int);    //perform inorder tree walk
		
		int getHeight(bs_tree_Node * x, int);

		void inserT(bs_tree_Node*);

		bs_tree_Node* Bst_tree_search(bs_tree_Node *, int);  // perform a search operation

};


#endif
