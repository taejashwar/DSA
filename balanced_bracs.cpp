#include<iostream>
#include<stdlib.h>
using namespace std;

//Stack
struct stack
{
    int size;
    int top;
    char *arr;
};

//Pushing element to stack
void push(struct stack *ptr, char element) {
    if(ptr->top==ptr->size-1) {
        cout<<"Stack Overflow...Cannot push "<<element<<" to the stack"<<endl;
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top]  = element;
    }
}

//Deleting top element from stack
char pop(struct stack *ptr) {
    if(ptr->top==-1) {
        cout<<"Stack Underflow...Cannot pop element"<<endl;
    }
    else {
        char element = ptr->arr[ptr->top];
        ptr->top--;
        return element;
    }
}

//Checking parenthesis match
int check_parenthesis(struct stack *ptr, char *exp) {
    for (int i = 0;exp[i]!='\0'; i++)
    {
        if(exp[i]=='(') {
            push(ptr,'(');
        }
        else if(exp[i]==')') {
            if(ptr->top==-1) {
                return 0;
            }
            pop(ptr);
        }
    }
    if(ptr->top==-1) {
        return 1;
    }
    else {
        return 0;
    }  
}

int main() {
    char *exp;
    struct stack *sp = new struct stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char;
    cout<<"Enter the expression:";
    cin>>exp;
    if(check_parenthesis(sp, exp)) {
        cout<<"The parenthesis is matching..."<<endl;
    }
    else {
        cout<<"The parenthesis is not matching..."<<endl;
    }
    return 0;
}