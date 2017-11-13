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

        // inserting after the node which contains the data part as value
        Node* insert_in_between(Node* head, int value, int data)
        {
            Node* temp = head;

            while (temp->data != value)
            {
                temp = temp->next;
            }
            // now temp is pointing to the node which contains `value` as data part
            Node *t = getNewNode();
            t->data = data;
            t->next = temp->next;
            temp->next = t;

            return head;
        }

        Node* insert_at_end(Node* head, int data)
        {
            Node* t = getNewNode();

            t->data = data;
            t->next = NULL;

            Node* temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }

            temp->next = t;

            return head;
        }

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

    int choice;
    Node *head = NULL;
    Node obj;

    do
    {
        std::cout<<"1. insert at beginning\n2.insert after val\n3.insert at end\n4.print LL\n9.exit";
        std::cin>>choice;

        switch (choice)
        {
            case 1:
                {
                    std::cout<<"\nEnter element\n";
                    int ch;
                    std::cin>>ch;
                    head = obj.insert_at_beginning(head, ch);
                }
                break;
            case 2:
                {
                    int val, d;
                    std::cout<<"\nEnter data:\n";
                    std::cin>>d;
                    std::cout<<"\nEnter value to insert after\n";
                    std::cin>>val;

                    head = obj.insert_in_between(head, val, d);
                }
                break;
            case 3:
                {
                    int ele;
                    std::cout<<"\nEnter element:\n";
                    std::cin>>ele;
                    head = obj.insert_at_end(head, ele);
                }
                break;
            case 4:
                {
                    obj.printLL(head);
                }
                break;
            case 9:
                exit(0);
        }

    }while (choice != 9);

    return 0;
}
