#include <iostream>
#include <climits>
#include "maxHeap.h"

using namespace std; 



maxHeap::maxHeap(int cap)  //constructor of the class maxHeap
{ 
	heapSize = 0;
	capacity = cap;
	heapArray = new int[capacity];
} 

// in case size meet capacity
void maxHeap::grow()
{
	if(heapSize>=capacity)   //cheaks if heapSize is greater than or equal to the capacity of the heap
	{
		capacity*=2;
		int* newArray = new int[capacity]; // creating a new Array newArray
		for(int i=0;i<heapSize;i++)
		{
			newArray[i]=heapArray[i];
		}
		delete[] heapArray;

		heapArray = newArray;
	}
}

void maxHeap::swap(int i, int j)
{
	int foobar = heapArray[i];  //
	heapArray[i] = heapArray[j];// SWAP FUNCTIONALITY
	heapArray[j] = foobar;     //
}

void maxHeap::insertKey(int k)   //insert the value k into the heap
{ 
	grow();    // calls grow function 	 	
	heapArray[heapSize]=k;  //inputting the value k at position "heapSize" in array heapArray
	heapSize++;  //increamenting the heap size because when you insert a new value the size of the heap should increase
	for(int i=parent(heapSize-1);i>=0;i--)
		maxHeapify(i); // calls maxHeapify function for all values of i 
} 

void maxHeap::increaseKey(int i, int new_val) 
{ 
	if(new_val <= heapArray[i])
	{
		cout << "New key should be greater than old key!"<<endl;
		return;
	}	
	heapArray[i]=new_val; // the new val is assigned to heapArray at position i 
	maxHeapify(parent(i));// calls maxHeapify on the value of i  so it is positioned in the right location in the heap

} 

int maxHeap::extractMax() 
{ 
	int offer = heapArray[0];
	deleteKey(0);
	return offer;
} 
 
void maxHeap::deleteKey(int i) 
{ 
	swap(heapSize-1,i); //calls swap function with index heapSize-1 and  i 
	heapSize--;      //decrement the heap size after deletion
	maxHeapify(i);   // call max heapify to makke the heap follow the maxheap properties
} 

void maxHeap::maxHeapify(int i) 
{ 
	int l=left(i);   // l contains the left child of i
	int r=right(i);  // r contains the right child of i
	if(r<heapSize && heapArray[l]>heapArray[r])
	{
		if(heapArray[l]>heapArray[i])
		{
			swap(l,i);  // call swap function
			maxHeapify(l); //Calling maxHeapify at position l which is the left child of i
		}
	}
	else if(r<heapSize && heapArray[r]>heapArray[l])
	{
		if(heapArray[r]>heapArray[i])
		{
			swap(r,i);  // call swap function
			maxHeapify(r);  // calling maxHeapify at position r whic is the right child of i
		}
	}
	else if(l<heapSize)
	{
		if(heapArray[l]>heapArray[i])
		{
			swap(l,i); // call swap function
			maxHeapify(l);  // calls maxHeapify at position l where l is the left child of i
		}
	}
} 