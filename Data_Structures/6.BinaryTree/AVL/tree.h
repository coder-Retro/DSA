#include <vector>
#include <queue>
#include <cstddef>
#include <utility>
#include <algorithm>
#include <stdexcept>

template<typename T>
// AVL Class
class AVL {
private:
    struct Node {
        T val;
        int height;
        Node* left;
        Node* right;
        Node(T val): val(val), height(1), left(nullptr), right(nullptr) {}
    };
    Node* root;
    size_t len;
    int nodeH(Node* node) const { return node?node->height:0; }
    int balanceFactor(const Node* node) const {
        return node?nodeH(node->left)-nodeH(node->right):0;
    }
    void updateHeight(Node* node) {
        node->height=1+std::max(nodeH(node->left),nodeH(node->right));
    }
    Node* rotateL(Node* x) {
        Node* y=x->right;
        Node* b=y->left;
        y->left=x;
        x->right=b;
        updateHeight(x);
        updateHeight(y);
        return y;
    }
    Node* rotateR(Node* y) {
        Node* x=y->left;
        Node* b=x->right;
        x->right=y;
        y->left=b;
        updateHeight(y);
        updateHeight(x);
        return x;
    }
    void rebalance(Node*& node) {
        if(!node) return;
        updateHeight(node);
        int bFactor=balanceFactor(node);
        if(bFactor>1) {
            if(balanceFactor(node->left)<0)
                node->left=rotateL(node->left);
            node=rotateR(node);
        } else if(bFactor<-1) {
            if(balanceFactor(node->right)>0)
                node->right=rotateR(node->right);
            node=rotateL(node);
        }
    }
    bool pushHelper(Node*& currRoot,const T& val) {
        if(!currRoot) {
            currRoot=new Node(val);
            len++;
            return true;
        }
        bool pushed=false;
        if(val<currRoot->val)      pushed=pushHelper(currRoot->left,val);
        else if(val>currRoot->val) pushed=pushHelper(currRoot->right,val);
        else                       return false;
        if(pushed) rebalance(currRoot);
        return pushed;
    }
    bool popHelper(Node*& currRoot,const T& val) {
        if(!currRoot) return false;
        bool popped=false;
        if(val<currRoot->val)      popped=popHelper(currRoot->left,val);
        else if(val>currRoot->val) popped=popHelper(currRoot->right,val);
        else {
            if(!currRoot->left || !currRoot->right) {
                Node* target=currRoot;
                currRoot=currRoot->left?currRoot->left:currRoot->right;
                delete target;
                len--;
                return true;
            }
            Node* succ=currRoot->right;
            while(succ->left) succ=succ->left;
            T succVal=succ->val;
            currRoot->val=succVal;
            popped=popHelper(currRoot->right,succVal);
        }
        if(popped) rebalance(currRoot);
        return popped;
    }
    static int removeDupsFromSorted(std::vector<T>& vals) {
        if(vals.empty()) return 0;
        int k=1;
        for(size_t i=1;i<vals.size();i++) {
            if(vals[i]!=vals[k-1]) {
                std::swap(vals[i],vals[k]);
                k++;
            }
        }
        return k;
    }
    Node* buildAVLHelper(std::vector<T>& vals,int lo,int hi) {
        if(lo>hi) return nullptr;
        int mid=lo+(hi-lo)/2;
        Node* currRoot=new Node(vals[mid]);
        currRoot->left=buildAVLHelper(vals,lo,mid-1);
        currRoot->right=buildAVLHelper(vals,mid+1,hi);
        updateHeight(currRoot);
        len++;
        return currRoot;
    }
    void preOrderHelper(const Node* currRoot,std::vector<T>& vals) const {
        if(!currRoot) return; 
        vals.push_back(currRoot->val); // Adding Current Root's val
        preOrderHelper(currRoot->left,vals); // Traversing Left Subtree
        preOrderHelper(currRoot->right,vals); // Traversing Right Subtree
    }
    void inOrderHelper(const Node* currRoot,std::vector<T>& vals) const {
        if(!currRoot) return;
        inOrderHelper(currRoot->left,vals); // Traversing Left Subtree
        vals.push_back(currRoot->val); // Adding Current Root's val
        inOrderHelper(currRoot->right,vals); // Traversing Right Subtree
    }
    void postOrderHelper(const Node* currRoot,std::vector<T>& vals) const {
        if(!currRoot) return;
        postOrderHelper(currRoot->left,vals); // Traversing Left Subtree
        postOrderHelper(currRoot->right,vals); // Traversing Right Subtree
        vals.push_back(currRoot->val); // Adding Current Root's val
    }
public:
    AVL(): root(nullptr), len(0) {}
    AVL(std::vector<T> vals): root(nullptr), len(0) {
        std::sort(vals.begin(),vals.end());
        int newSize=removeDupsFromSorted(vals);
        root=buildAVLHelper(vals,0,newSize-1);
    }
    AVL(const AVL& other): root(nullptr), len(0) {
        std::vector<T> vals=other.inOrder();
        root=buildAVLHelper(vals,0,(int)vals.size()-1);
    }
    AVL& operator=(const AVL& other) {
        if(this!=&other) {
            std::vector<T> vals=other.inOrder();
            deleteAVL();
            root=buildAVLHelper(vals,0,(int)vals.size()-1);
        }
        return *this;
    }

    bool push(const T& val) { return pushHelper(root,val); }
    bool pop(const T& val) { return popHelper(root,val); }
    bool contains(const T& val) const {
        Node* fall=root;
        while(fall) {
            if(val==fall->val)     return true;
            else if(val<fall->val) fall=fall->left;
            else                   fall=fall->right;
        }
        return false;
    }
    void buildAVL(std::vector<T> vals) {
        std::sort(vals.begin(),vals.end());
        int newSize=removeDupsFromSorted(vals);
        deleteAVL();
        root=buildAVLHelper(vals,0,newSize-1);
    }
    std::vector<T> preOrder() const {
        std::vector<T> vals;
        preOrderHelper(root,vals);
        return vals;
    }
    std::vector<T> inOrder() const {
        std::vector<T> vals;
        inOrderHelper(root,vals);
        return vals;
    }
    std::vector<T> postOrder() const {
        std::vector<T> vals;
        postOrderHelper(root,vals);
        return vals;
    }
    std::vector<std::vector<T>> levelOrder() const {
        if(!root) return {};
        std::vector<std::vector<T>> levels;
        std::queue<const Node*> q;
        q.push(root);
        while(!q.empty()) {
            std::vector<T> level;
            size_t currLevelSize=q.size();
            for(size_t i=0;i<currLevelSize;i++) {
                const Node* curr=q.front(); q.pop();
                level.push_back(curr->val);
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            levels.push_back(level);
        }
        return levels;
    }
    T rootVal() const {
        if(!root) throw std::underflow_error("Empty AVL!");
        return root->val;
    }
    T minVal() const {
        if(!root) throw std::underflow_error("Empty AVL!");
        const Node* fall=root;
        while(fall->left) fall=fall->left;
        return fall->val;
    }
    T maxVal() const {
        if(!root) throw std::underflow_error("Empty AVL!");
        const Node* fall=root;
        while(fall->right) fall=fall->right;
        return fall->val;
    }
    void deleteAVL() {
        if(!root) return;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* curr=q.front(); q.pop();
            if(curr->left)  q.push(curr->left);
            if(curr->right) q.push(curr->right);
            delete curr;
            len--;
        }
        root=nullptr;
    }
    int height() const { return nodeH(root); }
    size_t size() const { return len; }
    bool empty() const { return !len; }

    ~AVL() { deleteAVL(); }
};