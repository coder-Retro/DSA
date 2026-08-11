#include<vector>
#include<queue>

// Node Class
template<typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T data): data(data), left(nullptr),right(nullptr) {}
};

// tree Class
template<typename T>
class tree {
    Node<T>* root;
    void deleteTree(Node<T>*& root) {
        if(!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root=nullptr;
    }
    Node<T>* deleteHelper(Node<T>* curr, T val) {
        if (!curr) return nullptr;
        if (val < curr->data) {
            curr->left = deleteHelper(curr->left, val);
        } else if (val > curr->data) {
            curr->right = deleteHelper(curr->right, val);
        } else {
            // Case 1 & 2: 0 or 1 child
            if (!curr->left) {
                Node<T>* temp = curr->right;
                delete curr;
                return temp;
            } else if (!curr->right) {
                Node<T>* temp = curr->left;
                delete curr;
                return temp;
            }
            // Case 3: 2 children
            // Find in-order successor (smallest node in the right subtree)
            Node<T>* succ = curr->right;
            while (succ->left) succ = succ->left;
            // Copy in-order successor data to current node
            curr->data = succ->data;
            // Recursively delete the in-order successor
            curr->right = deleteHelper(curr->right, succ->data);
        }
        return curr;
    }
public:
    tree():root(nullptr){}

    // Disable copying to prevent double-free bugs
    tree(const tree&) = delete;
    tree& operator=(const tree&) = delete;
    
    Node<T>* getRoot()const { return root; }

    void insertNode(T data) {
        Node<T>* newNode=new Node<T>(data);
        if(!root) { root=newNode; return; }
        Node<T>* temp=root;
        while(true) {
            if(data<temp->data) {
                if(temp->left) temp=temp->left;
                else { temp->left=newNode; return; }
            } else if(data>temp->data) {
                if(temp->right) temp=temp->right;
                else { temp->right=newNode; return; }
            }
            else { delete newNode; return; }
        }
    }
    Node<T>* searchBST(Node<T>* root, T data) {
        while(root)
            if(data<root->data)      root=root->left;
            else if(data>root->data) root=root->right;
            else                     break;
        return root;
    }
    void deleteNode(T data) {
        root=deleteHelper(root, data);
    }
    void preOrder(Node<T>* root, std::vector<T>& v) {
        if(root==nullptr) return;
        v.push_back(root->data);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
    void inOrder(Node<T>* root, std::vector<T>& v) {
        if(root==nullptr) return;
        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }
    void postOrder(Node<T>* root, std::vector<T>& v) {
        if(root==nullptr) return;
        postOrder(root->left, v);
        postOrder(root->right, v);
        v.push_back(root->data);
    }
    void levelOrder(Node<T>* root, std::vector<std::vector<T>>& ans) {
        if(!root) return;
        std::queue<Node<T>*> q;
        q.push(root);
        while(!q.empty()) {
            std::vector<T> v;
            int s=q.size();
            for(int i=0;i<s;i++) {
                Node<T>* node=q.front();
                q.pop();
                v.push_back(node->data);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(v);
        }
    }

    ~tree() {
        deleteTree(root);
    }
};