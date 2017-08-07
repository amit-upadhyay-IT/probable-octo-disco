/*
 * first convert to postfix,
 * scan the postfix expression
 * push each operand onto the stack
 * if an operator is found then pop the elements from stack (according to the unary or binary operand) and perform operation and again push it back to stack
 * at the end of iteration of expression pop up the element of the stack and that would be the answer
 * */
#include<iostream>
#include<stdlib.h>
#include<cstring>

struct node{
    char data;
    struct node*  next;
};

class Stack
{
    private:
        struct node* top;
    public:
        Stack()
        {
            top = NULL;
        }

        void push(char data)
        {
            //node* new_node = (node*)malloc(sizeof(node));
            node* new_node = new node;
            new_node->next = top;
            new_node->data = data;
            top = new_node;
        }

        void pop()
        {
            if (!top)
                return ;
            struct node* temp = top;
            top = top->next;
            free(temp);
        }

        int is_empty()
        {
            return top == NULL;
        }

        char Top()
        {
            if (!top)
                return 0;
            return top->data;
        }

        void print_stack()
        {
            struct node* temp = top;
            while (temp)
            {
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
            std::cout<<std::endl;
        }
};

// till this point we don't need to check associativity because all these op used are left associative.
int get_precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 3;
    }
}

void infix_to_postfix(char *arr, Stack s1, char *exp)
{
    int k = 0;
    for (int i = 0; i < strlen(arr); ++i)
    {
        if (isalpha(arr[i]))
            exp[k++] = arr[i]; //std::cout<<arr[i];
        else if (arr[i] == ')')
        {
            while (s1.Top() != '(')
            {
                exp[k++] = s1.Top();
                //std::cout<<s1.Top();
                s1.pop();
            }
            s1.pop(); // for removing '('
        }
        else // the char is operator
        {
            if (s1.is_empty()==0)
                while (get_precedence(s1.Top()) > get_precedence(arr[i]) && s1.Top() != '(')
                {
                    exp[k++] = s1.Top(); s1.pop();
                }
            s1.push(arr[i]);
        }
    }
    while (!s1.is_empty())
    {
        exp[k++] = s1.Top();
        s1.pop();
    }
}

bool is_binary_operator(char c)
{
    bool val;
    switch (c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            val = true;
            break;
        default:
            val = false;
    }
    return val;
}

int perform_operation(int op1, int op2, char operand)
{
    if (operand == '+')
        return op2 + op1;
    else if (operand == '-')
        return op2 - op1;
    else if (operand == '*')
        return op2 * op1;
    else if (operand == '/')
        return op2 / op1;
    else
        return 0;
}

int char_to_int(char x)
{
    return x - '0';
}

char int_to_char(int val)
{
    return val + '0';
}

// the operator would not consists of (, ) because in postfix we don't have (, )
char postfix_eval(char *exp, Stack s)
{
    for (int i = 0; i < strlen(exp); ++i)
    {
        if (isdigit(exp[i]))
        {
            s.push(exp[i]);
        }
        else
        {
            if (is_binary_operator(exp[i]))
            {
                if (!s.is_empty())
                {
                    int op2 = char_to_int(s.Top()); s.pop();
                    int op1 = char_to_int(s.Top()); s.pop();

                    int val = perform_operation(op1, op2, exp[i]);
                    s.push(int_to_char(val));
                }
            }
        }
    }
    return s.Top();
}

int main()
{
    Stack s1, s2;
    char arr[100] = "(1+3)*4";
    char exp[100];
    infix_to_postfix(arr, s1, exp);
    std::cout<<exp;
    std::cout<<std::endl;

    char val_ret = postfix_eval(exp, s2);
    std::cout<<char_to_int(val_ret);
    std::cout<<std::endl;
    return 0;
}
