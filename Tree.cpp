#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* leftChildPtr;
        TreeNode* rightChildPtr;

    TreeNode(int val) {  
        data = val;  
        leftChildPtr = NULL;  
        rightChildPtr = NULL;  
    }  
};

void inOrderTraversalRecursive(TreeNode* node){
    if (node == NULL) return;

    inorderTraversal(node->left);
    cout << node->data << "->";
    inorderTraversal(node->right);
}

void inOrderTraversalIterative(TreeNode* node){
    stack<TreeNode*> s;
    TreeNode* curr = node;

    while(node->leftChildPtr != NULL){
        s.push(node);
        node = node->leftChildPtr;
    }
    cout << node->data;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->leftChildPtr = new TreeNode(2);
    root->rightChildPtr = new TreeNode(3);
    root->leftChildPtr->leftChildPtr = new TreeNode(4);
    root->leftChildPtr->rightChildPtr = new TreeNode(5);

    inOrderTraversalIterative(root);
    return 0;
}