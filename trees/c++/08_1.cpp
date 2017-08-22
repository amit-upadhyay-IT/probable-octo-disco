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

node* merge_two_node(node* first, node* second)
{
    /*
    if (!first && !second)
        return first;
    if (!first)
        return second;
    if (!second)
        return first;
    */

    while (first->right)
        first = first->right;
    while (second->left)
        second = second->left;

    first->right = second;
    second->left = first;

    return first;
    /*
    // to return the pointer to first node of first dll
    while (first->left->left)
        first = first->left;
    return first;
    */
}

node* make_dll(node* root)
{
    if (root)
    {
        node* l_node, *r_node;
        l_node = make_dll(root->left);
        r_node = make_dll(root->right);
        root = merge_two_node(merge_two_node(l_node, root), r_node);
        return root;
    }
}

void iterate_ll(node* head)
{
    node* temp = head;

    while (temp)
    {
        std::cout<<temp->data<<" ";
        temp = temp->right;
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

    root = make_dll(root);

    iterate_ll(root);
    std::cout<<std::endl;
    return 0;
}
