#include <string>
#include <iostream>
using namespace std;
// Binary Search Tree
template <typename T>
class TreeNode {
public:
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T v): val(v), left(nullptr), right(nullptr) {};
    ~TreeNode() {}
};

template <typename T>
TreeNode<T>* search(TreeNode<T>* root, T target) {
    // search for target in the BST
    // return a pointer to it
    if (root == nullptr) {
        return nullptr;
    } 
    cout << root->val << endl;
    if (root->val == target) {
        return root;
    } else if (root->val > target) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

template <typename T>
TreeNode<T>* findMin(TreeNode<T>* root) {
    // find the minimum element in the BST
    // which is the leftmost descendant
    if (root == nullptr) return nullptr;
    if (root->left) {
        return findMin(root->left);
    } else {
        return root;
    }
}

template <typename T>
void insert(TreeNode<T>* &root, T val) {
    // insert node into the BST
    if (root == nullptr) {
        root = new TreeNode<T>(val);
        return;
    }
    if (root->val > val) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

template <typename T>
TreeNode<T>* deleteItem(TreeNode<T>* root, T key) {
    // delete item with key, return new root
    if (root == nullptr) return root;
    if (root->val < key) {
        // item to delete is in right subtree
        root->right = deleteItem(root->right, key);
    } else if (root->val > key) {
        // item to delete is in left subtree
        root->left = deleteItem(root->left, key);
    } else {
        // root is the item to delete
        // node with no or one child
        if (root->left == nullptr) {
            TreeNode<T>* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            TreeNode<T>* temp = root->left;
            delete root;
            return temp;
        }
        // node with two children
        // replace with inorder successor (immediate successor in sorted order)
        TreeNode<T>* succ = ::findMin(root->right);
        root->val = succ->val;
        // delete the inorder sucessor
        root->right = deleteItem(root->right, succ->val);
    }
    return root;
}


// Tree Traversal
template<typename T>
void preorder(TreeNode<T>* root, void (*visit)(TreeNode<T>*)) {
    if (root == nullptr) return;
    visit(root);
    preorder(root->left, visit);
    preorder(root->right, visit);
}
  
template<typename T>
void inorder(TreeNode<T>* root, void (*visit)(TreeNode<T>*)) {
    if (root == nullptr) return;
    inorder(root->left, visit);
    visit(root);
    inorder(root->right, visit);
}

template<typename T>
void postorder(TreeNode<T>* root, void (*visit)(TreeNode<T>*)) {
    if (root == nullptr) return;
    postorder(root->left, visit);
    postorder(root->right, visit);
    visit(root);
}

template<typename T>
void printNode(TreeNode<T>* node) {
    if (node) cout << node->val << endl;
}

template<typename T>
class BST {
public:
    TreeNode<T>* root;
    BST(): root(nullptr) {}
    BST(TreeNode<T>* t): root(t) {}
    ~BST() {
        clear(root);
    }
    TreeNode<T>* search(T val) {
        return ::search(root, val);
    }
    void insert(T val) {
        return ::insert(root, val);
    }
    void traverse() {
        ::inorder(root, printNode);
    }
    void deleteItem(T key) {
        TreeNode<T>* newRoot = ::deleteItem(root, key);
        root = newRoot;
    }
private:
    void clear(TreeNode<T>* root) {
        if (root) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }
};


int main() {
    /*
     *             8 
     *           3     10
     *         1   6       14
     *           4  7    13
     *
     *
     */
    BST<int> bst;
    bst.insert(8);
    bst.insert(1);
    bst.insert(7);
    bst.insert(6);
    bst.insert(4);
    bst.insert(10);
    bst.insert(14);
    bst.insert(3);
    bst.insert(13);
    TreeNode<int>* n = bst.search(8);
    if (n) cout << n->val << endl;

    bst.traverse();
    bst.deleteItem(8);
    bst.traverse();


    BST<string> bst2;
    bst2.insert("apple");
    bst2.insert("banana");
    bst2.insert("orange");
    bst2.insert("avocado");
    bst2.insert("blueberry");
    bst2.insert("cranberry");
    bst2.insert("lemon");
    bst2.insert("kiwi");

    bst2.traverse();
    return 0;
}
