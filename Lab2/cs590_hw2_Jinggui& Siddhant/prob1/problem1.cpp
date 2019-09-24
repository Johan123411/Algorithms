#include <iostream>
#include "LinkedList.h"
#include <set>
#include <stdlib.h> // for testing
#include <time.h> // for testing 

using namespace std;

// First implementation; uses additional data structure
void removeDupl_1(Node* head)
{
    // no Node or only one Node in the LinkedList, do nothing
    if(head == 0 || head->next == 0){
        return;
    }
    // set: no duplicate data
    set <int, greater<int>> tempSet; 
    tempSet.insert(head->data);

    Node* currentNode = head->next;
    Node* lastNode = head;
    while(currentNode !=0){
        if(tempSet.count(currentNode->data) == 0){
            tempSet.insert(currentNode->data);
            lastNode = currentNode;
            currentNode = currentNode->next;
        }else{
            Node* tempNode = currentNode;
            lastNode->next = currentNode->next;
            currentNode = currentNode->next;
            delete tempNode;
        }
    }
}


// This implementation uses no additional data structure 
// time complxity O(N^2)
void removeDupl_2(Node* head)
{
    // take the ith node and compare with each one, remove the one who has same data.
    Node* currentNode = head;
    Node* lastNode;
    Node* compareNode;
    
    // no Node or only one Node in the LinkedList, do nothing
    if(head == 0 || head->next == 0){
        return;
    }

    // loop compare and remove until the last one (nullptr)
    while(currentNode!=0){
        //compareNode start from the next one of currentNode
        compareNode = currentNode->next;
        lastNode = currentNode;
        // compare with each Node after current Node
        while(compareNode!=0){
            // find the same one
            if(compareNode->data == currentNode->data){
                Node* temp = compareNode;
                lastNode->next = compareNode->next;
                compareNode = compareNode->next;
                delete temp;
            }else{
                lastNode = compareNode;
                compareNode = compareNode->next;
            }
        }
        // move currentNode to next one and start next loop
        currentNode = currentNode->next;
    }

}


int main()
{
    time_t start,stop;
    start=time(0);

    srand(time(0));
    LinkedList* myList = new LinkedList();
    for(int i=0; i<300000000; i++){
        myList->insert(rand()%10);
    }

    //cout << "The original list is: ";
    //myList->display();

    //Use removeDupl_2 to run that implementation
    removeDupl_2(myList->head);

    //cout << "The list with duplicated removed is: ";
    //myList->display();
    delete myList;
    stop = time(0);
    cout <<"Origin Time used :" <<(stop-start)<<endl;
    return 0;
}