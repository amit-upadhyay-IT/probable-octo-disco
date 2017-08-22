#include<iostream>

struct node
{
    int data;
    node* left, *right;
};

node* get_new_node(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, int data)
{
    if (!root)
        root = get_new_node(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void inorder(node* root)
{
    if (root)
    {
        inorder(root->left);
        std::cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    node* root = NULL;

    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 110);

    //inorder(root);
    std::cout<<std::endl;

    std::cout<<std::endl;
    return 0;
}
