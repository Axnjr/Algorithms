#include <iostream>
#include <stack>
#include <vector>
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

void inOrderTraversalRecursive(TreeNode* node){ // left most node -> root node -> right node
    if (node == NULL) return;

    inOrderTraversalRecursive(node->leftChildPtr);
    cout << node->data << "->";
    inOrderTraversalRecursive(node->rightChildPtr);
}

void preOrderTraversalRecusrive(TreeNode* node){ // root node -> left node -> right node
    if(node == NULL) return;
    cout << node->data << "->";
    preOrderTraversalRecusrive(node->leftChildPtr);
    preOrderTraversalRecusrive(node->rightChildPtr);
}

void inOrderTraversalIterative(TreeNode* node){
    stack<TreeNode*> s;
    vector<int> v;
    TreeNode* curr = node;
    
    while(curr != NULL || s.empty() == false){
        while(curr != NULL){
            s.push(curr);
            curr = curr->leftChildPtr;
        }
        curr = s.top();              // assign the top most element as current pointer in the tree.
        s.pop();                     // once assigned pop it out
        v.push_back(curr->data);     // push the value at the traversed node in the vector
        curr = curr->rightChildPtr;  // now traverse right side if it exists
    }
}

void preOrderTraversalIterative(TreeNode* node){
    stack<TreeNode*> s;
    vector<int> v;
    TreeNode* curr = node;

    while(curr != NULL || s.empty() == false){
        v.push_back(curr->data);
        s.push(curr);
        curr = curr->leftChildPtr;
        if(curr == NULL){
            curr = s.top();
            s.pop();
            curr = curr->rightChildPtr;
        }
    }

    cout << "TRAVERSED TREE IN PRE-ORDER STYLE: ";
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << endl;
    // }
}

// Inorder: 4 2 5 1 3
// Preorder: 1 2 4 5 3
// Postorder: 4 5 2 3 1

int main(){
    TreeNode* root = new TreeNode(1);
    root->leftChildPtr = new TreeNode(2);
    root->rightChildPtr = new TreeNode(3);
    root->leftChildPtr->leftChildPtr = new TreeNode(4);
    root->leftChildPtr->rightChildPtr = new TreeNode(5);

    // inOrderTraversalIterative(root);
    preOrderTraversalIterative(root);
    return 0;
}