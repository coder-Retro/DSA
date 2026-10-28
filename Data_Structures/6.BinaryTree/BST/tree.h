#include<vector>
#include<queue>
#include<cstddef>
#include<utility>
#include<algorithm>
#include<stdexcept>

// BST Class
template<typename T>
class BST {
    // Node Struct
    struct Node {
        T val;
        Node* left;
        Node* right;
        Node(T val): val(val), left(nullptr), right(nullptr) {}
    };
    Node* root;
    size_t len;
    bool popHelper(Node*& node,const T& val) {
        if(!node) return false; // Node Not Found
        if(val<node->val) return popHelper(node->left,val);
        if(val>node->val) return popHelper(node->right,val);
        // Node Found
        if(!node->left || !node->right) { // 1 Child cases
            Node* target=node;
            if(node->left) // Left Child Only
                node=node->left;
            else // Right Child Only
                node=node->right;
            delete target; // Delete Target Node
        } else { // 2 Child Case (Searching for InOrder Successor)
            Node* inOrderSucc=node->right;
            while(inOrderSucc->left) inOrderSucc=inOrderSucc->left;
            T succVal=inOrderSucc->val;
            node->val=succVal; // Replacing with inOrderSucc's val
            return popHelper(node->right,succVal);
        }
        len--; // Number of nodes decremented
        return true; // Node successfully deleted
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
    Node* buildBSTHelper(std::vector<T>& vals,int lo,int hi) {
        if(lo>hi) return nullptr;
        int mid=lo+(hi-lo)/2;
        Node* node=new Node(vals[mid]);
        node->left=buildBSTHelper(vals,lo,mid-1);
        node->right=buildBSTHelper(vals,mid+1,hi);
        len++;
        return node;
    }
    void preOrderHelper(const Node* node,std::vector<T>& vals) const {
        if(!node) return; 
        vals.push_back(node->val); // Adding Current Root's val
        preOrderHelper(node->left,vals); // Traversing Left Subtree
        preOrderHelper(node->right,vals); // Traversing Right Subtree
    }
    void inOrderHelper(const Node* node,std::vector<T>& vals) const {
        if(!node) return;
        inOrderHelper(node->left,vals); // Traversing Left Subtree
        vals.push_back(node->val); // Adding Current Root's val
        inOrderHelper(node->right,vals); // Traversing Right Subtree
    }
    void postOrderHelper(const Node* node,std::vector<T>& vals) const {
        if(!node) return;
        postOrderHelper(node->left,vals); // Traversing Left Subtree
        postOrderHelper(node->right,vals); // Traversing Right Subtree
        vals.push_back(node->val); // Adding Current Root's val
    }
public:
    BST(): root(nullptr), len(0) {}
    BST(std::vector<T> vals): root(nullptr), len(0) {
        std::sort(vals.begin(),vals.end());
        int newSize=removeDupsFromSorted(vals);
        root=buildBSTHelper(vals,0,newSize-1);
    }
    BST(const BST& other): root(nullptr), len(0) {
        std::vector<T> vals=other.inOrder();
        root=buildBSTHelper(vals,0,(int)vals.size()-1);
    }
    BST& operator=(const BST& other) {
        if(this!=&other) {
            std::vector<T> vals=other.inOrder();
            deleteBST();
            root=buildBSTHelper(vals,0,(int)vals.size()-1);
        }
        return *this;
    }

    bool push(const T& val) {
        if(!root) root=new Node(val); // Root is nullptr, insert at node
        else {
            Node* fall=root; // Fall from root
            while(fall) {
                if(val==fall->val) return false; // Node already exists
                else if(val<fall->val) { // Node goes to left
                    if(fall->left) fall=fall->left;
                    else { fall->left=new Node(val); break; }
                } else { // Node goes to right
                    if(fall->right) fall=fall->right;
                    else { fall->right=new Node(val); break; }
                }
            }
        }
        len++; // Number of nodes incremented
        return true; // Node succesfully inserted
    }
    bool pop(const T& val) { return popHelper(root,val); }
    bool contains(const T& val) const {
        const Node* fall=root;
        while(fall) {
            if(fall->val==val)     return true;
            else if(val<fall->val) fall=fall->left;
            else                   fall=fall->right;
        }
        return false;
    }
    void deleteBST() {
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
    void buildBST(std::vector<T> vals) {
        std::sort(vals.begin(),vals.end());
        int newSize=removeDupsFromSorted(vals);
        deleteBST();
        root=buildBSTHelper(vals,0,newSize-1);
    }
    void balance() {
        std::vector<T> vals=inOrder();
        deleteBST();
        root=buildBSTHelper(vals,0,(int)vals.size()-1);
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
        if(!root) throw std::underflow_error("Empty BST!");
        return root->val;
    }
    T minVal() const {
        if(!root) throw std::underflow_error("Empty BST!");
        const Node* fall=root;
        while(fall->left) fall=fall->left;
        return fall->val;
    }
    T maxVal() const {
        if(!root) throw std::underflow_error("Empty BST!");
        const Node* fall=root;
        while(fall->right) fall=fall->right;
        return fall->val;
    }
    size_t size() const { return len; }
    bool empty() const { return !len; }

    ~BST() { deleteBST(); }
};