#include<iostream>
using namespace std;
//Creating stack using linked list
struct Node
{
    int data;
    struct Node *next;
};
//Initializing stack
struct Node *top = NULL;
//Traversal of stack
void disp_elements() {
    struct Node *ptr;
    if(top == NULL) {
        cout<<"Stack is Empty"<<endl;
    }
    else {
        ptr = top;
        cout<<"Stack elements:"<<endl;
        while (ptr!=NULL)
        {
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        }
        cout<<endl;
    }
}
//Push operation
void push(int element) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = element;
    ptr->next = top;
    top = ptr;
    cout<<top->data<<" pushed into the stack successfully..."<<endl;
}
//Pop operation
void pop() {
    if(top == NULL) {
        cout<<"Stack Underflow..."<<endl;
    }
    else {
        cout<<top->data<<" popped out of the stack successfully..."<<endl;
        top = top->next;
    }
}
int main() {
    int choice, element;
    do
    {
        cout<<"\nSelect an operation\n1.Push\n2.Pop\n3.Traverse\n4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the element to be pushed:";
            cin>>element;
            push(element);
            break;
        case 2:
            pop();
            break;

        case 3:
            disp_elements();
            break;
        
        case 4:
            cout<<"End of program..."<<endl;

        default:
            cout<<"Invalid choice..."<<endl;
        }
    } while (choice!=4);
    return 0;
}