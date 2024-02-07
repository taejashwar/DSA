#include<iostream>
#include<stdlib.h>
using namespace std;

//Linked List
struct Node
{
    int data;
    struct Node * next;
};

//Traversal
void displayElement(struct Node *ptr) {
    while (ptr!=NULL)
    {
        cout<<"\n"<<ptr->data;
        ptr = ptr->next;
    }
}

// Insertion
struct Node *insertElement(struct Node **head, int data, int index) {
    struct Node *ptr = new struct Node;
    ptr->data = data;
    struct Node *p = *head;
    if(index==1) {
        ptr->next = p;
        *head = ptr;
        return *head;
    }
    else {
        int i = 1;
        while(i!=index-1 && p!=NULL) {
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
        return *head;
    }
}

//Deletion 
struct Node *deleteElement(struct Node **head, int index) {
    struct Node *ptr1 = *head;
    if(index==1) {
        *head = (*head)->next;
        free(ptr1);
        return *head;
    }
    else {
        struct Node *ptr2 = (*head)->next;
        for (int i = 1; i < index; i++)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(ptr2->next!=NULL) {
            ptr1->next = ptr2->next;
        }
        else {
            ptr1->next = NULL;
        }
        free(ptr2);
        return *head;
    }
}

int main() {
    int num,element,index;
    cout<<"Enter the number of elements to be inserted:";
    cin>>num;
    struct Node *head = NULL;
    for(int i=0;i<num;i++) {
        cout<<"Enter element:";
        cin>>element;
        cout<<"Enter index of element:";
        cin>>index;
        insertElement(&head,element,index);
    }
    displayElement(head);
    cout<<"\nEnter the number of elements to be deleted:";
    cin>>num;
    for(int i=0;i<num;i++) {
        cout<<"Enter index of element:";
        cin>>index;
        deleteElement(&head,index);
    }
    displayElement(head);
    return 0;
}