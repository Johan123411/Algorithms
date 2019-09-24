#include <iostream>
#include <climits>
#include "medianHeaps.h"
#include "minHeap.h"
#include "maxHeap.h"

using namespace std; 

medianHeaps::medianHeaps(int cap)    //Constructor 
{ //initializing the member variables 
	maxH=new maxHeap(cap);
	minH=new minHeap(cap);
} 

medianHeaps::~medianHeaps()   //Destructor
{
	delete maxH;   //delets maxH
	delete minH;   //delets minH
	minH = nullptr;//minH assigned to a null pointer
	maxH = nullptr;//minH assigned to a null pointer
}

void medianHeaps::addNewNumber(int x) 
{ 
	maxH->insertKey(x);  // insert a key x into the max Heap
	minH->insertKey(x);  // insert a key into the min Heap
} 

 
int medianHeaps::getMedian()   // function to get median values
{
	if(maxH->size()==0)
    {
		cout<<"not enough elements!";  // if the heap size is 0 then there are not enought elements to get the median for
		return -1;
	}
    if(maxH->size()%2!=0)   //if the heapSize is even  i.e when divided by 2 gives us the remainder 0
    {
    	int min, max;
    	for(int i=0; i<maxH->size();i++)
        {
    		min=minH->extractMin();  //you extract the mininmum value from the minHeap by calling the extractMin Function
    		max=maxH->extractMax();  //you extract the maximum value of the maxHeap by calling the extractMax Function
    		if(min==max) 
            {
    			return min;  //in a situation where minimum and maximum values in the two heap are same , we've reached a median
			}
    	}
    }
    else
    {
    	int min1, min2, max1, max2;  //case where the number of elements in the heap is odd
    	min1=minH->extractMin();
    	max1=maxH->extractMax();
    	for(int i=0; i<maxH->size();i++)
        {
    		min2=minH->extractMin();
    		max2=maxH->extractMax();
    		if(min1==max2 && min2==max1)
            {
    			return (min1+min2)/2;   // in this case the average of the two values min 1 and min 2 are taken and returned
    		}  
    		min1=min2;
    		max1=max2;
    	}
    }

} 
