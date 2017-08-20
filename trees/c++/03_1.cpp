/*
 * from inorder and postorder construct a tree
 * */

#include<iostream>

struct node
{
    int data;
    node* left, *right;
};

int get_element(int *inorder_exp, int *postorder_exp, int start, int end, int n)
{
    for (int i = n-1; i >= 0; --i)
    {
        int val = postorder_exp[i];
        for (int j = start; j <= end; ++j)
            if (inorder_exp[j] == val)
                return val;
    }
    return -1;
}

int get_position(int *inorder_exp, int val, int start, int end)
{
    for (int i = start; i < end; ++i)
        if (val == inorder_exp[i])
            return i;
    return -1;
}

node* construct_tree(int inorder_exp[], int postorder_exp[], int first_pos, int last_pos, int n)
{
    int root_ele = get_element(inorder_exp, postorder_exp, first_pos, last_pos, n);

    int root_pos = get_position(inorder_exp, root_ele, first_pos, last_pos);

    node* temp = NULL;

    if (root_ele != -1)
    {
        temp = new node();
        temp->data = root_ele;
        temp->left = temp->right = NULL;

        if (first_pos >= last_pos)
            return temp;

        temp->left = construct_tree(inorder_exp, postorder_exp, first_pos, root_pos-1, n);
        temp->right = construct_tree(inorder_exp, postorder_exp, root_pos+1, last_pos, n);

    }

    return temp;
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

void preorder(node* root)
{
    if (root)
    {
        std::cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int inorder_exp[100], postorder_exp[100];
    int n;

    std::cout<<"\nEnter number of elements in tree\n";
    std::cin>>n;
    std::cout<<"\nEnter inorder traversal : \n";
    for (int i = 0; i < n; ++i)
        std::cin>>inorder_exp[i];
    std::cout<<"\nEnter postorder traversal:\n";
    for (int i = 0; i < n; ++i)
        std::cin>>postorder_exp[i];

    node* root = construct_tree(inorder_exp, postorder_exp, 0, n-1, n);
    std::cout<<std::endl;
    //inorder(root);
    std::cout<<std::endl;
    preorder(root);
    std::cout<<std::endl;
    return 0;
}

// T.C = O(n^2) because of searching I am using, this can be done in order n also
// S.C = O(n) in worst case
