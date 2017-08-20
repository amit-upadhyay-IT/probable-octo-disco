/*
 * level order traversal
 * tree used is BST
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

    std::cout<<"\nPreorder\n";
    preorder(root);

    std::cout<<std::endl;

    std::cout<<"\nLevel order traversal\n";
    level_order(root);
    std::cout<<std::endl;
    return 0;
}

// T.C = O(n)
// S.C = O(n/2) max size of queue is maximum number of nodes in any level in the tree
