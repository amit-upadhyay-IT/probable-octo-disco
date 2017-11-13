#include<iostream>
#include<stdlib.h>

class Node
{
    private:
        int data;
        Node* next;

    public:

        Node* getNewNode()
        {
            return (Node*)malloc(sizeof(Node));
        }

        Node* insert_at_beginning(Node* head, int data)
        {
            Node* temp = getNewNode();
            temp->data = data;
            temp->next = head;
            head = temp;
            return head;
        }

        /*
        Node* insert_in_between(Node* head, int value, int data)
        {

        }
        */

        void printLL(Node* head)
        {
            while (head)
            {
                std::cout<<head->data<<" ";
                head = head->next;
            }

        }

};


int main()
{

    std::cout<<"\nEnter elements :";
    int ch;
    Node obj;
    std::cin>>ch;
    Node* head = NULL;
    while (ch != -1)
    {
        head = obj.insert_at_beginning(head, ch);
        std::cin>>ch;
    }

    obj.printLL(head);
    return 0;
}
