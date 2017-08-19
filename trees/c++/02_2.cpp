/*
 * check whether two trees are identical or not
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

void inorder(node* root)
{
    if (root)
    {
        inorder(root->left);
        std::cout<<root->data<<" ";
        inorder(root->right);
    }
}

bool check_recursively(node* root1, node* root2)
{
    if (!root1 && !root2)
        return 1;
    if (root1 && root2)
    {
        if (root1->data == root2->data)
        {
            return (root1->data == root2->data) &&
                check_recursively(root1->left, root2->left) &&
                check_recursively(root1->right, root2->right);
        }
    }
    return false;
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

    root2 = insert(root2, 50);
    root2 = insert(root2, 40);
    root2 = insert(root2, 60);
    root2 = insert(root2 ,30);
    root2 = insert(root2, 35);
    root2 = insert(root2, 70);
    root2 = insert(root2, 20);
    root2 = insert(root2, 10);


    std::cout<<std::endl;
    std::cout<<std::endl<<std::endl;

    bool ret_val = check_recursively(root1, root2);

    ret_val?std::cout<<"Trees are identical":std::cout<<"Not identiacl";

    std::cout<<std::endl;
    return 0;
}

// T.C = O(n)
// S.C = O(height of tree)
