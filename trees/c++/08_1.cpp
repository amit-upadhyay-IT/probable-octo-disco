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

node* merge_three_node(node* l_node, node* root, node* r_node)
{
    node* last_l_node = l_node, *first_r_node = r_node;
    while (last_l_node->right)
    {
        last_l_node = last_l_node->right;
    }
    while (first_r_node->left)
    {
        first_r_node = first_r_node->left;
    }

    last_l_node->right = root;
    root ->left = last_l_node;

    first_r_node->left = root;
    root->right = first_r_node;

    return root;
}

node* make_dll(node* root)
{
    if (root)
    {
        node *l_node = make_dll(root->left);
        node *r_node = make_dll(root->right);
        root = merge_three_node(l_node, root, r_node);
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

    iterate_ll(root);
    return 0;
}
