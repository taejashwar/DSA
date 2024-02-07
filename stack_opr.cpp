#include<iostream>
#include<stdlib.h>
using namespace std;

//Stack
struct stack
{
    int size;
    int top;
    int *arr;
};

//Pushing element to stack
void push(struct stack *ptr, int element) {
    if(ptr->top==ptr->size-1) {
        cout<<"Stack Overflow...Cannot push "<<element<<" to the stack"<<endl;
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top]  = element;
        cout<<"Element "<<element<<" pushed to stack successfully..."<<endl;
    }
}

//Deleting top element from stack
struct stack *pop(struct stack *ptr) {
    if(ptr->top==-1) {
        cout<<"Stack Underflow...Cannot pop element"<<endl;
    }
    else {
        int element = ptr->arr[ptr->top];
        ptr->top--;
        cout<<"Element "<<element<<" poped out of the stack successfully..."<<endl;
        return ptr;
    }
}

int main() {
    int size,element,choice;
    struct stack *sp = new struct stack;
    cout<<"Enter the size of the stack:";
    cin>>size;
    sp->size = size;
    sp->top = -1;
    sp->arr = new int;
    do
    {
        cout<<"Select a stack operation:\n1.Push\n2.Pop\n3.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the element to be pushed:";
            cin>>element;
            push(sp,element);
            break;

        case 2:
            pop(sp);
            break;
        }
        } while (choice!=3);
    return 0;
}
