/*
 * intro to bst: INCLUDE FUNCTIONS FOR INSERTION DELETION SEARCHING TRAVERSING
 * */
#include<iostream>

struct BSTnode
{
    int data;
    BSTnode *left, *right;
};

BSTnode* get_new_node(int data)
{
    BSTnode* new_node = new BSTnode();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

BSTnode* insert(BSTnode* root, int data)
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

bool search(BSTnode* root, int data)
{
    if (!root) return false;
    else if (root->data == data) return true;
    else if (root->data > data) return search(root->left, data);
    else return search(root->right, data);
}

void preorder(BSTnode* root)
{
    if (root)
    {
        std::cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BSTnode* root)
{
    if (root)
    {
        inorder(root->left);
        std::cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(BSTnode* root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        std::cout<<root->data<<" ";
    }
}

int main()
{
    BSTnode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root ,30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 10);

    inorder(root);// should print all elements in sorted order
    std::cout<<std::endl;
    preorder(root);
    std::cout<<std::endl;
    postorder(root);
    std::cout<<std::endl<<std::endl;

    if (search(root, 40))
        std::cout<<"40 is found\n";
    if (search(root, 100))
        std::cout<<"100 is found\n";

    return 0;
}
