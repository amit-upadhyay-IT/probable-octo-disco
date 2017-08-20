/*
 * find lca
 * tree used is normal binary tree
 * approach used:
 * find the path to reach to node 1 and find the path to reach to node 2
 * store the part into arrays
 * compare two arrays and see the last common node in the path
 * */
#include<iostream>
#include<stack>
#include<stdlib.h>

struct node
{
    int data;
    node* left, *right;
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
    // case 1, when root is empty
    if (!root)
        root = get_new_node(data);

    // case 2, when data is less
    else if (root->data > data)
        root->left = insert(root->left, data);

    // case 3, when data is greater than parent
    else if (root->data < data)
        root->right = insert(root->right, data);

    return root;
}

int get_array(node* root, node* arr[], int val)
{
    int k = 0;

    if (root)
    {
        std::stack<node*> s;
        s.push(root);

        while (!s.empty())
        {
            node* temp = s.top(); s.pop();
            arr[k++] = temp;
            if (temp->data == val)
                break;
            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);

        }
    }
    return k;
}

void print_array(node** arr, int k)
{
    for  (int i = 0; i < k; ++i)
    {
        std::cout<<arr[i]->data<<" ";
    }
    std::cout<<std::endl;
}

node* get_lca(node* root, int val1, int val2)
{
    node** arr1 = (node**)malloc(sizeof(node*)*100);
    node** arr2 = (node**)malloc(sizeof(node*)*100);
    int size1 = get_array(root, arr1, val1);
    int size2 = get_array(root, arr2, val2);

    print_array(arr1, size1);
    print_array(arr2, size2);
}


int main ()
{
    node* root = NULL;
    root = insert(root, 100);
    root = insert(root, 70);
    root = insert(root, 75);
    root = insert(root, 130);
    root = insert(root, 115);
    root = insert(root, 150);
    root = insert(root, 60);
    root = insert(root, 65);

    std::cout<<std::endl;

    get_lca(root, 65, 75);
    std::cout<<std::endl;
    return 0;
}

