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

node* find_min(node* root)
{
    if (!root) return root;
    node* temp = root;// we can even use the root variable itself, because root here is local copy of root pointer.
    while (temp->left)// finding the leaf
        temp = temp->left;
    return temp;
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

bool search(node* root, int data)
{
    if (!root) return false;
    else if (root->data == data) return true;
    else if (root->data > data) return search(root->left, data);
    else return search(root->right, data);
}

int get_size(node* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    else
        return (1 + get_size(root->left) + get_size(root->right));
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
    node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root ,30);
    root = insert(root, 35);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 10);

    inorder(root);// should print all elements in sorted order
    std::cout<<std::endl;
    std::cout<<std::endl<<std::endl;

    std::cout<<"Size of tree is "<<get_size(root);

    std::cout<<std::endl;
    return 0;
}
