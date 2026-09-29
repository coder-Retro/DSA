#include<iostream>
#include<vector>
using namespace std;

/*
Constructor:
Approach: Vector initialization
TC: O(1)
SC: O(1)

enQueue:
Approach: Wraparound Modulo Insertion
TC: O(1)
SC: O(1)

deQueue:
Approach: Wrapaound Modulo Deletion
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
    int size;
    int cap;
public:
    MyCircularQueue(int k) {
        front=0;
        rear=-1;
        size=0;
        cap=k;
        arr=vector<int>(cap);
    }
    bool enQueue(int value) {
        if(isFull()) return false;
        rear=(rear+1)%cap;
        arr[rear]=value;
        size++;
        return true;
    }
    bool deQueue() {
        if(isEmpty()) return false;
        front=(front+1)%cap;
        size--;
        return true;
    }
    int Front() { return isEmpty()?-1:arr[front]; }
    int Rear() { return isEmpty()?-1;arr[rear]; }
    bool isEmpty() { return !size; }
    bool isFull() { return size==cap; }
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