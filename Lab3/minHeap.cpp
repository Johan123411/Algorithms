#include <iostream>
#include <climits>
#include "minHeap.h"

using namespace std; 



minHeap::minHeap(int cap) //Constructor to initialize the heap  
{ 
	heapSize = 0;
	capacity = cap;
	heapArray = new int[capacity];
} 

// in case size meet capacity
void minHeap::grow()
{
	if(heapSize>=capacity) //checks if the size of the heap has reached the capacity of the heap or not
	{  
		capacity*=2;
		int* newArray = new int[capacity]; // creating a new array newArray
		
		for(int i=0;i<heapSize;i++)
		{
			newArray[i]=heapArray[i];
		}
		delete[] heapArray;
		heapArray = newArray;
	}
}

void minHeap::swap(int i, int j)
{
	int foobar = heapArray[i];		//
	heapArray[i] = heapArray[j];    //SWAP FUNCTIONALITY
	heapArray[j] = foobar;			//
}


void minHeap::insertKey(int k)  // inserts the key k
{ 
	grow(); //calls the grow function
	heapArray[heapSize]=k; //inputting the value k at position "heapSize" in array heapArray
	heapSize++;  //increamenting the heap size because when you insert a new value the size of the heap should increase
	for(int i=parent(heapSize-1);i>=0;i--)
		minHeapify(i); // calls minHeapify function for all values of i 
} 

void minHeap::decreaseKey(int i, int new_val) 
{ 
	if(new_val>=heapArray[i])
	{
		cout << "New key should be smaller than old key!"<<endl;
		return;
	}	
	heapArray[i]=new_val;  // the new val is assigned to heapArray at position i 
	minHeapify(parent(i)); //calls minHeapify on the value of i  so it is positioned in the right location in the heap
} 

int minHeap::extractMin() 
{ 
	// just want return offer XD
	int offer=heapArray[0];
	deleteKey(0);
	return offer;
} 

void minHeap::deleteKey(int i) 
{ 
	swap(heapSize-1,i);
	heapSize--;   //after key is deleted , it's heapSize is reduced.
	minHeapify(i);   //calls minHeapify at position i 
} 

void minHeap::minHeapify(int i) 
{ 
	int l=left(i); //the value of left child of i is assiged to varable l
	int r=right(i);  // the value of the right child of i is assigned to variable r
	if(r<heapSize && heapArray[l]<heapArray[r])
	{ 											//if the heapsize is greater than right child of i and if the heapArray at position l is lesser than heapArray at position r; where l = left child of i and r = right child of i
		if(heapArray[l]<heapArray[i])  //if heapArray at position i is greater than heapArray at position l swap them
		{
			swap(l,i);
			minHeapify(l); //calls minHeapify
		}
	}
	else if(r<heapSize && heapArray[r]<heapArray[l])  //if the Heapsize is greater than r and heaparray at position l is greater than heapArray at position r; where l = left child of i and r = right child of i
	{ 
		if(heapArray[r]<heapArray[i])   //if heapArray at position r is lesser then heapArray at position i  thenn swap them .
		{
			swap(r,i);
			minHeapify(r);  //calls min heapify.
		}
	}else if(l<heapSize)   // if heapSize is greater then l
	{
		if(heapArray[l]<heapArray[i]) //if heapArray at position i is greater then heapArray  at position l then swap them.  // calls min heapify   
		{
			swap(l,i);
			minHeapify(l);  // calls min heapify   
		}
	}
} 