#pragma once
#include<iostream>
#include<stdexcept>
#include<utility>
#include<string>

template<typename T>
class LinkedList {
    struct Node {
        int key;
        T data;
        Node* next;
        Node(int _key,T _data,Node* _next): key(_key), data(_data), next(_next) {}
    };
    Node* head; // Points to Front Node of list
    size_t len;
    void copy(const LinkedList& other) {
        Node* tail=nullptr; // Local tail keeps the original order
        Node* copier=other.head;
        while(copier) {
            Node* newNode=new Node(copier->key,copier->data,nullptr);
            if(!tail) head=newNode;
            else tail->next=newNode;
            tail=newNode;
            len++;
            copier=copier->next;
        }
    }
public:
    LinkedList(): head(nullptr), len(0) {}
    LinkedList(const LinkedList& other): head(nullptr), len(0) {
        copy(other);
    }
    LinkedList& operator=(const LinkedList& other) {
        if(this!=&other) {
            clear();
            copy(other);
        }
        return *this;
    }

    bool push(int _key,T _data) {
        if(contains(_key)) return false;
        head=new Node(_key,_data,head);
        len++;
        return true;
    }
    bool pop(int _key) {
        if(empty()) return false;
        Node dummy(-1,T(),head);
        Node* prev=&dummy;
        while(prev->next && prev->next->key != _key) prev=prev->next;
        if(prev->next) {
            Node* target=prev->next;
            prev->next=target->next;
            if(target==head) head=head->next;
            delete target;
            len--;
            return true;
        }
        return false;
    }
    T& updateValue(int _key) {
        Node* curr=head;
        while(curr && curr->key!=_key) curr=curr->next;
        return curr->data;
    }
    bool contains(int _key) const {
        Node* curr=head;
        while(curr) {
            if(curr->key==_key) return true;
            curr=curr->next;
        }
        return false;
    }
    std::pair<int,T> headInfo() const {
        if(empty()) throw std::underflow_error("List is empty!\n");
        return {head->key,head->data};
    }
    void clear() { while(head) pop(head->key); }
    size_t size() const { return len; }
    bool empty() const { return !len; }
    void printList() const {
        std::cout<<"[";
        Node* curr=head;
        while(curr) {
            std::cout<<"("<<curr->key<<":"<<curr->data<<")";
            if(curr->next) std::cout<<",";
            curr=curr->next;
        }
        std::cout<<"]\n";
    }

    ~LinkedList() { clear(); }
};

template<typename T>
class HashMap {
private:
    size_t cap;
    size_t len;
    LinkedList<T>* table;
    size_t hash(int _key) const { return _key%cap; }
    void rehash() {
        size_t old_cap=cap;
        cap*=2;
        LinkedList<T>* newTable=new LinkedList<T>[cap];
        for(int i=0;i<(int)old_cap;i++) {
            LinkedList<T>& curr=table[i];
            while(!curr.empty()) {
                auto [key,data]=curr.headInfo();
                size_t bucket=hash(key);
                newTable[bucket].push(key,data);
                curr.pop(key);
            }
        }
        delete[] table;
        table=newTable;
    }
    void copy(const HashMap& other) {
        cap=other.cap;
        len=other.len;
        table=new LinkedList<T>[cap];
        for(size_t i=0;i<cap;i++) table[i]=other.table[i];
    }
public:
    HashMap(size_t _cap=11): cap(_cap?_cap:11), len(0), table(new LinkedList<T>[cap]) {}
    HashMap(const HashMap& other): cap(0), len(0), table(nullptr) {
        copy(other);
    }
    HashMap& operator=(const HashMap& other) {
        if(this!=&other) {
            delete[] table;
            copy(other);
        }
        return *this;
    }
    T& operator[](int _key) {
        size_t bucket=hash(_key);
        if(!table[bucket].contains(_key)) {
            if(len+1>cap*0.75) { rehash(); bucket=hash(_key); }
            table[bucket].push(_key,T());
            len++;
        }
        return table[bucket].updateValue(_key);
    }

    bool insert(int _key,T _data) {
        if(len+1>cap*0.75) rehash();
        size_t bucket=hash(_key);
        bool inserted=table[bucket].push(_key,_data);
        if(inserted) len++;
        return inserted;
    }
    bool erase(int _key) {
        size_t bucket=hash(_key);
        bool erased=table[bucket].pop(_key);
        if(erased) len--;
        return erased;
    }
    bool contains(int _key) const {
        size_t bucket=hash(_key);
        return table[bucket].contains(_key);
    }

    void clear() {
        for(int i=0;i<(int)cap;i++) table[i].clear();
        len=0;
    }
    size_t buckets() const { return cap; }
    size_t size() const { return len; }
    bool empty() const { return !len; }
    void printMap() const {
        std::cout<<"HashMap: [\n";
        for(int i=0;i<(int)cap;i++) {
            std::cout<<"    "<<i<<": ";
            table[i].printList();
        }
        std::cout<<"]\n";
    }

    ~HashMap() { delete[] table; }
};