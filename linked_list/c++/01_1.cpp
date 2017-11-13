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

        Node* remove_from_beginning(Node* head)
        {
            Node* temp = head;
            head = head->next;
            free(temp);
            return head;
        }

        Node* remove_from_middle(Node* head, int val)
        {
            Node* temp = head;
            while (temp->next->data != val)
                temp = temp->next;
            //now temp is pointing to one node before the node containing val
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            return head;
        }

        Node* remove_from_end(Node* head)
        {
            Node *temp = head;
            while (temp->next->next)
            {
                temp = temp->next;
            }

            // temp is now pointing to 2nd last node
            Node *temp2 = temp->next;
            temp->next = NULL;
            free(temp2);
            return head;
        }

        void printLL(Node* head)
        {
            while (head)
            {
                std::cout<<head->data<<" ";
                head = head->next;
            }
            std::cout<<std::endl;
        }

};


int main()
{

    int choice;
    Node *head = NULL;
    Node obj;

    do
    {
        std::cout<<"\n1. insert at beginning\n2.insert after val\n3.insert at end\n4.print LL\n5.delete from beginning\n6.delete from middle\n7.delete from end\n9.exit\n";
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
            case 5:
                {
                    head = obj.remove_from_beginning(head);
                }
                break;
            case 6:
                {
                    int val;
                    std::cout<<"\nEnter the value of node:\n";
                    std::cin>>val;
                    head = obj.remove_from_middle(head, val);
                }
                break;
            case 7:
                {
                    head = obj.remove_from_end(head);
                }
                break;
            case 9:
                exit(0);
        }

    }while (choice != 9);

    return 0;
}
