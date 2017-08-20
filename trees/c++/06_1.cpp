/*
 * find lca
 * tree used is BST
 * approach used:
 * find val1 in tree and store elements in array while finding val1
 * find val2 in tree and store elements in array while finding val2
 * compare the array and return appropriate value
 * */
#include<iostream>
#include<queue>

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

void preorder(node* root)
{
    if (root)
    {
        std::cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void level_order(node* root)
{
    // traverse only if root is not null
    if (root)
    {
        std::queue<node*> q;

        q.push(root);

        while (!q.empty())
        {
            node* temp = q.front();
            q.pop();
            std::cout<<temp->data<<" ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void print_array(node* arr[], int k)
{
    for (int i = 0; i < k; ++i)
    {
        std::cout<<arr[i]->data<<" ";
    }
    std::cout<<std::endl;
}

int get_array(node* root, int val1, node* arr1[])
{
    int k = 0;

    while (root != NULL)
    {
        if (val1 < root->data)
        {
            arr1[k++] = root;
            root = root->left;
        }
        if (val1 > root->data)
        {
            arr1[k++] = root;
            root = root->right;
        }
        if (val1 == root->data)
        {
            arr1[k++] = root;
            break;
        }
    }
    return k;
}

node* compare_arrays(node* arr1[], node* arr2[])
{
    int k = 0;

    while (arr1[k] == arr2[k])
    {
        k++;
    }
    return arr1[k-1];
}

node* get_lca(node* root, int val1, int val2)
{
    node* arr1[100], *arr2[100];
    int size1 = get_array(root, val1, arr1);
    int size2 = get_array(root, val2, arr2);
    return compare_arrays(arr1, arr2);
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

    node* lca_node = get_lca(root, 65, 150);
    std::cout<<lca_node->data;

    std::cout<<std::endl;
    return 0;
}

