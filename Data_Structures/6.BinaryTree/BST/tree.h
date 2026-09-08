#include<vector>
#include<queue>

// Tree Class
template<typename T>
class Tree {
    // Node Struct
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T data): data(data), left(nullptr),right(nullptr) {}
    };
    Node* root;
    size_t len;
    void deleteTree(Node*& root) {
        if(!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root=nullptr;
        len--;
    }
    Node* deleteHelper(Node* curr, T val) {
        if (!curr) return nullptr;
        if (val < curr->data) {
            curr->left = deleteHelper(curr->left, val);
        } else if (val > curr->data) {
            curr->right = deleteHelper(curr->right, val);
        } else {
            // Case 1 & 2: 0 or 1 child
            if (!curr->left) {
                Node* temp = curr->right;
                delete curr;
                return temp;
            } else if (!curr->right) {
                Node* temp = curr->left;
                delete curr;
                return temp;
            }
            // Case 3: 2 children
            // Find in-order successor (smallest node in the right subtree)
            Node* succ = curr->right;
            while (succ->left) succ = succ->left;
            // Copy in-order successor data to current node
            curr->data = succ->data;
            // Recursively delete the in-order successor
            curr->right = deleteHelper(curr->right, succ->data);
        }
        return curr;
    }
    void preOrderHelper(Node* root, std::vector<T>& v) {
        if(root==nullptr) return;
        v.push_back(root->data);
        preOrderHelper(root->left, v);
        preOrderHelper(root->right, v);
    }
    void inOrderHelper(Node* root, std::vector<T>& v) {
        if(root==nullptr) return;
        inOrderHelper(root->left, v);
        v.push_back(root->data);
        inOrderHelper(root->right, v);
    }
    void postOrderHelper(Node* root, std::vector<T>& v) {
        if(root==nullptr) return;
        postOrderHelper(root->left, v);
        postOrderHelper(root->right, v);
        v.push_back(root->data);
    }
    void levelOrderHelper(Node* root, std::vector<std::vector<T>>& ans) {
        if(!root) return;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            std::vector<T> v;
            size_t s=q.size();
            for(size_t i=0;i<s;i++) {
                Node* node=q.front();
                q.pop();
                v.push_back(node->data);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(v);
        }
    }
    Node* findHelper(Node* root, T data) const {
        while(root)
            if(data<root->data)      root=root->left;
            else if(data>root->data) root=root->right;
            else                     break;
        return root;
    }
public:
    Tree(): root(nullptr), len(0) {}
    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

    void insert(T data) {
        Node* newNode=new Node(data);
        if(!root) root=newNode;
        else {
            Node* temp=root;
            while(true) {
                if(data<temp->data) {
                    if(temp->left) temp=temp->left;
                    else { temp->left=newNode; break; }
                } else if(data>temp->data) {
                    if(temp->right) temp=temp->right;
                    else { temp->right=newNode; break; }
                }
                else { delete newNode; return; }
            }
        }
        len++;
    }
    void remove(T data) {
        if(findHelper(root, data)) {
            root=deleteHelper(root, data);
            len--;
        }
    }
    bool contains(T data) const {
        return findHelper(root, data);
    }
    std::vector<T> preOrder() {
        std::vector<T> ans;
        preOrderHelper(root, ans);
        return ans;
    }
    std::vector<T> inOrder() {
        std::vector<T> ans;
        inOrderHelper(root, ans);
        return ans;
    }
    std::vector<T> postOrder() {
        std::vector<T> ans;
        postOrderHelper(root, ans);
        return ans;
    }
    std::vector<std::vector<T>> levelOrder() {
        std::vector<std::vector<T>> ans;
        levelOrderHelper(root, ans);
        return ans;
    }

    ~Tree() { deleteTree(root); }
};