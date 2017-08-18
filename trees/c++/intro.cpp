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

BSTnode* find_min(BSTnode* root)
{
    if (!root) return root;
    BSTnode* temp = root;// we can even use the root variable itself, because root here is local copy of root pointer.
    while (temp->left)// finding the leaf
        temp = temp->left;
    return temp;
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

BSTnode* remove(BSTnode* root, int data)
{
    if (!root)
        return NULL;
    if (data < root->data)
        root->left = remove(root->left, data);
    else if (data > root->data)
        root->right = remove(root->right, data);

    else
    {
        // the element is found now
        // case 1: leaf element
        if (!root->left && !root->right)
        {
            delete root; // root is now dangling pointer
            root = NULL;
        }
        // case 2: with one child
        else if (!root->left)
        {
            BSTnode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right)
        {
            BSTnode* temp = root;
            root = root->left; // or root = temp->left;
            delete temp;
        }
        // case 3: with two children
        // else
        {
            BSTnode* inorder_successor = find_min(root->right);
            root->data = inorder_successor->data;
            root->right = remove(root->right, inorder_successor->data);
        }
    }
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
