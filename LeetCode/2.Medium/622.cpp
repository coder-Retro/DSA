#include<iostream>
#include<vector>
using namespace std;

/*
Constructor:
Approach: Dynamic Array Initialization
TC: O(1)
SC: O(1)

enQueue:
Approach: Wraparound vector push_back
TC: O(1)
SC: O(1)

deQueue:
Approach: Wrapaound vector pop_front
TC: O(1)
SC: O(1)

Front:
Approach: Front index retrieval
TC: O(1)
SC: O(1)

Rear:
Approach: Rear index retrieval
TC: O(1)
SC: O(1)

isFull:
Approach: Max size check
TC: O(1)
SC: O(1)

isEmpty:
Approach: Zero size check
TC: O(1)
SC: O(1)
*/

class MyCircularQueue {
    vector<int> arr;
    int front;
    int rear;
    int limit;
public:
    MyCircularQueue(int k) {
        front=rear=0;
        limit=k+1;
        arr=vector<int>(limit);
    }
    bool enQueue(int value) {
        if(isFull()) return false;
        arr[rear]=value;
        rear=(rear+1)%limit;
        return true;
    }
    bool deQueue() {
        if(isEmpty()) return false;
        front=(front+1)%limit;
        return true;
    }
    int Front() { return isEmpty()?-1:arr[front]; }
    int Rear() {
        if(isEmpty()) return -1;
        return !rear?arr[limit-1]:arr[rear-1];
    }
    bool isEmpty() { return front==rear; }
    bool isFull() { return (rear+1)%limit==front; }
};

int main() {
    int k=3;
    MyCircularQueue* obj=new MyCircularQueue(k);
    cout<<(obj->enQueue(1)?"true":"false")<<'\n';
    cout<<(obj->enQueue(2)?"true":"false")<<'\n';
    cout<<(obj->enQueue(3)?"true":"false")<<'\n';
    cout<<(obj->enQueue(4)?"true":"false")<<'\n';
    cout<<obj->Rear()<<'\n';    
    cout<<(obj->isFull()?"true":"false")<<'\n';  
    cout<<(obj->deQueue()?"true":"false")<<'\n'; 
    cout<<(obj->enQueue(4)?"true":"false")<<'\n';
    cout<<obj->Rear()<<'\n';
    delete obj;
    return 0;
}