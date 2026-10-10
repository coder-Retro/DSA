#include<vector>
#include<utility>
#include<stdexcept>
#include<functional>

template <typename T,typename Compare=std::less<T>>
// Heap Class
class Heap {
private:
    std::vector<T> heap;
    Compare compare;
    void heapifyUp(size_t idx) {
        while(idx) {
            size_t parent=(idx-1)/2;
            if(!compare(heap[idx],heap[parent])) break;
            std::swap(heap[idx],heap[parent]);
            idx=parent;
        }
    }
    void heapifyDown(size_t idx) {
        while(true) {
            size_t target=idx;
            size_t left=idx*2+1;
            size_t right=idx*2+2;
            if(left<heap.size() && compare(heap[left],heap[target]))   target=left;
            if(right<heap.size() && compare(heap[right],heap[target])) target=right;
            if(target==idx) break;
            std::swap(heap[idx],heap[target]);
            idx=target;
        }
    }
public:
    Heap() {}
    Heap(const std::vector<T>& vals): heap(vals) {
        for(int idx=(int)heap.size()/2;idx>=0;idx--) heapifyDown(idx);
    }
    void push(const T& val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }
    T pop() {
        if(heap.empty()) throw std::underflow_error("Heap is empty");
        T poppedVal=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        if(!heap.empty()) heapifyDown(0);
        return poppedVal;
    }
    T top() const {
        if(heap.empty()) throw std::underflow_error("Heap is empty");
        return heap[0];
    }
    size_t size() const { return heap.size(); }
    bool empty() const { return heap.empty(); }
};