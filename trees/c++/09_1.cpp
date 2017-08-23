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

int find_height(node* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)// for leaf
        return 0;
    return (1+std::max(find_height(root->left), find_height(root->right)));
}

int max_diameter = 0;

void set_diameter(node* root)
{
    if (!root)
        return ;
    set_diameter(root->left);
    int l = find_height(root->left);
    int r = find_height(root->right);
    if (l+r+1 > max_diameter)
        max_diameter = l+r+1+1;// 1 is added to count the parent node in that path, and another 1 is added because when we are calculating height of LST and RST then both of them are starting from 0, but while counting the diameter we need to count the number of nodes, so we add one.
    set_diameter(root->right);
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

    set_diameter(root);
    std::cout<<"Diameter = "<<max_diameter;
    std::cout<<std::endl;
    return 0;
}
