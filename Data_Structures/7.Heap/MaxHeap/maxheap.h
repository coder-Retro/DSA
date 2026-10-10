#include<vector>
#include<utility>
#include<stdexcept>

template <typename T>
// MaxHeap Class
class MaxHeap {
private:
    std::vector<T> heap;
    void heapifyUp(size_t idx) {
        if(!idx) return;
        size_t p=(idx-1)/2;
        if(heap[idx]>heap[p]) {
            std::swap(heap[idx],heap[p]);
            heapifyUp(p);
        }
    }
    void heapifyDown(size_t idx) {
        size_t left=idx*2+1;
        size_t right=idx*2+2;
        size_t target=idx;
        if(left<heap.size() && heap[left]>heap[target])   target=left;
        if(right<heap.size() && heap[right]>heap[target]) target=right;
        if(target!=idx) {
            std::swap(heap[idx],heap[target]);
            heapifyDown(target);
        }
    }
public:
    void push(const T& val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }
    T pop() {
        if(heap.empty()) throw std::underflow_error("MaxHeap is empty");
        T poppedVal=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        if(!heap.empty()) heapifyDown(0);
        return poppedVal;
    }
    T top() const {
        if(heap.empty()) throw std::underflow_error("MaxHeap is empty");
        return heap[0];
    }
    size_t size() const { return heap.size(); }
    bool empty() const { return heap.empty(); }
};