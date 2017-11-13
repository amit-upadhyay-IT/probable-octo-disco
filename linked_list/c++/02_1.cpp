#include<iostream>
#include<stdlib.h>

class Node
{
    /*
    private:
        int data;
        Node* next;
    */

    public:

        int data;
        Node* next;

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

            // inserting the first node
            if (!head)
                return insert_at_beginning(head, data);

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

        Node* reverse_iterative(Node* head)
        {
            if (!head)
                return head;
            // ll has one node only
            if (!head->next)
                return head;

            Node* prev, *nextNode;
            prev = nextNode = NULL;

            while (head)
            {
                nextNode = head->next;
                head->next = prev;
                prev = head;
                head = nextNode;
            }
            return prev;
        }

        Node* reverse_recursive(Node* first)
        {
            if (!first)
                return NULL;
            if (!first->next)
                return first;

            Node* rest = reverse_recursive(first->next);

            first->next->next = first;
            first->next = NULL;
            return rest;
        }

};


class Operation: public Node
{
    public:

    Node* getMiddleNode(Node* head)
    {
        Node* fastPtr, *slowPtr;
        fastPtr = slowPtr = head;

        while (fastPtr && fastPtr->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return slowPtr;
    }
};

int main()
{

    Node *head = NULL;
    Operation obj;

    head = obj.insert_at_end(head, 1);
    head = obj.insert_at_end(head, 2);
    head = obj.insert_at_end(head, 3);
    head = obj.insert_at_end(head, 4);
    head = obj.insert_at_end(head, 5);
    head = obj.insert_at_end(head, 6);
    head = obj.insert_at_end(head, 7);

    std::cout<<"The linked list:\n";
    obj.printLL(head);

    //Operation o;
    Node* midNode = obj.getMiddleNode(head);

    std::cout<<"\nThe mid node value is : ";
    std::cout << midNode->data << "\n";


    return 0;
}
