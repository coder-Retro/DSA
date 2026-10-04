#include<vector>
#include<queue>
#include<stdexcept>

// Tree Class
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
    bool popHelper(Node*& currRoot,T val) {
        if(!currRoot) return false; // Node Not Found
        if(val<currRoot->val) return popHelper(currRoot->left,val);
        if(val>currRoot->val) return popHelper(currRoot->right,val);
        // Node Found
        if(!currRoot->left || !currRoot->right) { // 1 Child cases
            Node* target=currRoot;
            if(!currRoot->left) // Right Child Only
                currRoot=currRoot->right;
            else // Left Child Only
                currRoot=currRoot->left;
            delete target; // Delete Target Node
        } else { // 2 Child Case (Searching for InOrder Successor)
            Node* inOrderSucc=currRoot->right;
            while(inOrderSucc->left) inOrderSucc=inOrderSucc->left;
            currRoot->val=inOrderSucc->val; // Replacing with inOrderSucc's val
            return popHelper(currRoot->right,inOrderSucc->val);
        }
        len--; // Number of nodes decremented
        return true; // Node successfully deleted
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
    BST(): root(nullptr), len(0) {}
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    bool push(T val) {
        if(!root) root=new Node(val); // Root is nullptr, insert at currRoot
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
    bool pop(T val) { return popHelper(root,val); }
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