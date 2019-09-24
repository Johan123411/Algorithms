#include<iostream>
#include <stack>
#include<climits>
using namespace std;

class Queue{
private:
    stack<int> stack1, stack2;
public:
    // step1:1st insert data in to stack2 -> 1,2,3,4,5
    // step2:then pop each data and push into stack1 -> 5,4,3,2,1
    // Dequeue just need to pop out stack1. 
    // Enqueue need to :
    // step1:pop out current data(stack1) into stack2 and 
    // step2:push new data into stack2, then do Enqueue step2 again.

    void EnQueue(int data){
        //make sure stack2 is empty
        while(!stack2.empty()){
            stack2.pop();
        }

        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.push(data);

        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int DeQueue(){
        // safe check
        if (stack1.size()==0) {
            cout << "ERR:Empty Queue detected!"<< endl;
            return 0;
        }
        int offer = stack1.top();
        stack1.pop();
        return offer;
    }

};

int main(){
    Queue q;
    for(int i=0; i<10; i++)
        q.EnQueue(i);
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';

    for(int i=10; i<20; i++){
        q.EnQueue(i);
    }
    cout<< "**********" << endl;
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';

    return 0;
}