#include<iostream>
#include<stack>

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

void recursive_preorder(node* root)
{
    if (root)
    {
        std::cout<<root->data<<" ";
        recursive_preorder(root->left);
        recursive_preorder(root->right);
    }
}

void iterative_preorder(node* root)
{
    if (!root)
        return ;
    std::stack<node*> s;
    s.push(root);

    while (!s.empty())
    {
        node* temp = s.top(); s.pop();
        std::cout<<temp->data<<" ";

        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
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

    recursive_preorder(root);
    std::cout<<std::endl;
    iterative_preorder(root);

    std::cout<<std::endl;
    return 0;
}

