/*
 * create a mirror tree of a binary tree
 *
 * */
#include<iostream>

struct node
{
    int data;
    node *left, *right;
};

node* get_new_node(int data)
{
    node* new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int data)
{
    // case 1 when root is null
    if (!root)
        root = get_new_node(data);
    // case 2 when data is less than root
    else if (data < root->data)
        root->left = insert(root->left, data);
    // case 3 when data is greater than root
    else
        root->right = insert(root->right, data);
    return root;
}

void swap(node** a, node** b)
{
    node *temp = *a;
    *a = *b;
    *b = temp;
}

node* get_mirror_tree(node* root)
{
    if (!root)
        return root;
    else
    {
        get_mirror_tree(root->left);
        get_mirror_tree(root->right);
        swap(&root->left, &root->right);
    }
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
    node *root1 = NULL, *root2 = NULL;

    root1 = insert(root1, 50);
    root1 = insert(root1, 40);
    root1 = insert(root1, 60);
    root1 = insert(root1 ,30);
    root1 = insert(root1, 35);
    root1 = insert(root1, 70);
    root1 = insert(root1, 20);
    root1 = insert(root1, 10);

    std::cout<<std::endl<<std::endl;

    inorder(root1);

    get_mirror_tree(root1);


    std::cout<<std::endl;
    inorder(root1);
    return 0;
}

//T.C = O(n)
//S.C = O(n)
