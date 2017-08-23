/*
 * find the diameter of a given binary tree.
 * */
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

int diameter_of_bt(node* root, int *height)
{
    int leftTreeHeight = 0, rightTreeHeight = 0, leftTreeDiameter = 0, rightTreeDiameter = 0;
    if (!root)
    {
        *height = 0;
        return 0;
    }
    leftTreeDiameter = diameter_of_bt(root->left, &leftTreeHeight);
    rightTreeDiameter = diameter_of_bt(root->right, &rightTreeHeight);
    *height = std::max(leftTreeHeight, rightTreeHeight)+1;
    return std::max(leftTreeHeight+rightTreeHeight+1, std::max(leftTreeDiameter, rightTreeDiameter));
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
    int height = 0;

    /*
    root = insert(root, 100);
    root = insert(root, 70);
    root = insert(root, 110);
    root = insert(root, 50);
    root = insert(root, 75);
    root = insert(root, 78);
    root = insert(root, 80);
    root = insert(root, 82);
    root = insert(root, 45);
    root = insert(root, 40);
    root = insert(root, 57);
    */

    /*
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 16);
    root = insert(root, 4);
    */

    /*
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    */

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 4);
    root = insert(root, 6);

    //inorder(root);
    std::cout<<std::endl;

    std::cout<<diameter_of_bt(root, &height);

    std::cout<<std::endl;
    return 0;
}
