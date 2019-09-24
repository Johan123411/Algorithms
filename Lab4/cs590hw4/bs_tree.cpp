
#include "bs_tree.h"
#include <iostream>

using namespace std;

bs_tree::bs_tree() //this is the constructor method
{
	bs_nil = new bs_tree_Node;

	bs_nil->parent = bs_nil;

	bs_nil->left = bs_nil;

	bs_nil->right = bs_nil;

	bs_root = bs_nil;

  totalCount = 0;
  dupCount = 0;
  height = 0;
}

bs_tree::~bs_tree() //this is the destructor method
{
	remove_all(bs_root);
	delete bs_nil;
}

void bs_tree::remove_all(bs_tree_Node* x)
{
/*
 * recursively remove all tree elements
 */
  if (x !=bs_nil)
    {
      remove_all(x->left);
      remove_all(x->right);

      delete x;
    }


}

void bs_tree::inserT(int* ArrayOfKeys, int size)
{
	for(int i=0; i<size ; i++)
	{
		inserT(ArrayOfKeys[i]);
	}

}

void bs_tree::inserT(int key)
{
	bs_tree_Node* z;

	z = new bs_tree_Node;

	z->value = key;

	z->right = bs_nil;

	z->left = bs_nil;

	z->parent = bs_nil;

	inserT(z);
}

void bs_tree::inserT(bs_tree_Node* z)
{
  totalCount++;
    // if(Bst_tree_search(bs_root,z->value)!= bs_nil)
    // {
    //     dupCount++;
    //     return;
    // }
	bs_tree_Node* x;
	bs_tree_Node* y;

	y = bs_nil;
	x = bs_root;

	while(x != bs_nil)
	{
		y = x;

		if(z->value < x->value)
			x = x->left;
		else if(z->value > x->value)
			x = x->right;
		else {
		  dupCount ++;
		  return;
		}
	}

	z->parent = y;

	if(y == bs_nil)
	{
		bs_root = z;
	}
	else
	{
		if(z->value < y->value)
		{
			y->left = z;
		}
		else
		{
			y->right = z;
		}
	}
}

int* bs_tree::inorder_tree_walk(){
  if(totalCount - dupCount == 0) return nullptr;
  int* result = new int[totalCount - dupCount];
  inorder_tree_walk(bs_root,result, 1,0);
  return result;
}

int bs_tree::inorder_tree_walk(bs_tree_Node * x,int* r, int level, int index)
{
	  if (x != bs_nil)
    {

      index = inorder_tree_walk(x->left,r, level+1,index);

      cout << "(" << x->value << "," << level << ")" << endl;
      r[index]=x->value;
      index++;

      index = inorder_tree_walk(x->right,r , level+1,index);

    }
    return index;
}


bs_tree_Node * bs_tree::Bst_tree_search(int x)
{
	return Bst_tree_search(bs_root,x);
}

bs_tree_Node * bs_tree::Bst_tree_search(bs_tree_Node * x, int k)
{
	if( x == bs_nil || k == x->value)
	{
		return x;
	}
	if(k < x->value)
	{
		return Bst_tree_search(x->left,k);
	}
	else
	{
		return Bst_tree_search(x->right,k);
	}

}
void bs_tree::Tree_Min()
{
	cout<<"The minimum value in the tree is = "<< Tree_Min(bs_root) << endl ;
}

void bs_tree::Tree_Max()
{
	cout<<"The maximum value in the tree is = "<< Tree_Max(bs_root) << endl ;
}

bs_tree_Node* bs_tree::Tree_Min(bs_tree_Node *x)
{
	while(x->left != bs_nil)
	{
		x = x->left;
	}
	return x;
}

bs_tree_Node* bs_tree::Tree_Max(bs_tree_Node *x)
{
	while(x->right != bs_nil)
	{
		x = x->right;
	}
	return x;
}

bs_tree_Node* bs_tree::Succ(bs_tree_Node * x)
{
	if(x->right != bs_nil)
	{
		return Tree_Min(x->right);
	}

		bs_tree_Node* y;


		y = x->parent;

	while(y != bs_nil && x==y->right)
	{
		x=y;
		y=y->parent;
	}
	return y;
}


bs_tree_Node* bs_tree::Pred(bs_tree_Node* x)
{
	if(x->left != bs_nil)
	{
		return Tree_Max(x->left);
	}

		bs_tree_Node* y;


		y = x->parent;

	while(y != bs_nil && x==y->left)
	{
		x=y;
		y=y->parent;
	}
	return y;
}

void bs_tree::printCounter(){
  cout << "input_size:" << totalCount << '\t';
  cout << "dup:" << dupCount << '\t';
  cout << "height:" << getHeight() <<endl;
}

int bs_tree::getHeight(bs_tree_Node * x, int level){
  if (x == bs_nil)
  {
    return level-1; // return the level of parent
  }
  int leftlevel = 0;
  int rightlevel = 0;
  if(x->left!=bs_nil) leftlevel = getHeight(x->left,level+1);
  if(x->right!=bs_nil) rightlevel = getHeight(x->right,level+1);
  if(leftlevel>rightlevel){
    if(leftlevel >level) level=leftlevel;
  }else{
    if(rightlevel > level) level = rightlevel;
  }
  return level;
}

int bs_tree::getHeight(){
  height = getHeight(bs_root,0);
  return height;
}


//code template taken from the given red_black_tree lecture codes and the logic is taken from the lecture slides.





























