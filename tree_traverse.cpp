#include<iostream>
using namespace std;

//Binary Tree
struct Node {
    int data;
    Node *left, *right;
};

//Insert new node
Node *insert_node(int element) {
    Node *ptr = new Node();
    ptr->data = element;
    ptr->left = ptr->right = NULL;
    return ptr;
}

//Preorder traversal
void preorderTraverse(struct Node *root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<"->";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

//Inorder traversal
void inorderTraverse(struct Node *root) {
    if(root == NULL) {
        return;
    }
    inorderTraverse(root->left);
    cout<<root->data<<"->";
    inorderTraverse(root->right);
}

//Postorder traversal
void postorderTraverse(struct Node *root) {
    if(root == NULL) {
        return;
    }
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    cout<<root->data<<"->";
}

int main() {
    Node *root = insert_node(15);
    root->left = insert_node(11);
    root->right = insert_node(20);
    root->left->left = insert_node(7);
    root->left->right = insert_node(13);
    root->right->left = insert_node(18);
    root->right->right = insert_node(25);

    cout<<"\nPreorder Traversal:"<<endl;
    preorderTraverse(root);

    cout<<"\nInorder Traversal:"<<endl;
    inorderTraverse(root);

    cout<<"\nPostorder Traversal:"<<endl;
    postorderTraverse(root);

    return 0;
}