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

// Insertion 1 : Insert in beginning
struct Node *insertAtBeginning(struct Node *head) {
    int data;
    struct Node *ptr = new struct Node;
    cout<<"Enter the element to be inserted:";
    cin>>data;
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

//Insertion 2 : Insert in given index
struct Node *insertAtIndex(struct Node *head) {
    int data,index;
    struct Node *ptr = new struct Node;
    struct Node *p = head;
    cout<<"Enter the element to be inserted:";
    cin>>data;
    cout<<"Enter the index of the element:";
    cin>>index;
    int i = 0;
    while(i!=index-1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

//Insertion 3 : Insert in the end
struct Node *insertAtEnd(struct Node *head) {
    int data;
    struct Node *ptr = new struct Node;
    struct Node *p = head;
    cout<<"Enter the element to be inserted:";
    cin>>data;
    while(p->next!=NULL) {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

//Deletion 1 : Delete in the beginning
struct Node *deleteAtBeginning(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

//Deletion 2 : Delete at the given index
struct Node *deleteAtIndex(struct Node *head) {
    int index;
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    cout<<"Enter the index of the element:";
    cin>>index;
    for (int i = 0; i < index-1; i++)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = ptr2->next;
    delete ptr2;
    return head;
}

//Deletion 3 : Delete at the end
struct Node *deleteAtEnd(struct Node *head) {
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    while (ptr2->next!=NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = NULL;
    delete ptr2;
    return head;
}

int main() {
    int choice;
    struct Node *head = new struct Node;
    struct Node *second = new struct Node;
    struct Node *third = new struct Node;
    struct Node *fourth = new struct Node;
    struct Node *fifth = new struct Node;
    struct Node *sixth = new struct Node;

    head->data = 12;
    head->next = second;

    second->data = 13;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 21;
    fourth->next = fifth;

    fifth->data = 25;
    fifth->next = sixth;
    
    sixth->data = 34;
    sixth->next = NULL;
    
    do
    {
        cout<<"\nSelect a linked list option:\n1.Traversal\n2.Insertion\n3.Deletion\n4.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Displaying Elements...";
            displayElement(head);
            break;

        case 2:
            int opt;
            cout<<"\nSelect insertion operation:\n1.Insert at Beginning\n2.Insert at Index\n3.Insert at End\n";
            cout<<"Enter your choice:";
            cin>>opt;
            switch (opt)
            {
            case 1:
                insertAtBeginning(head);
                cout<<"Element inserted successfully...";
                break;
            
            case 2:
                insertAtIndex(head);
                cout<<"Element inserted successfully...";
                break;
            
            case 3:
                insertAtEnd(head);
                cout<<"Element inserted successfully...";
                break;
            }
            break;

        case 3:
            int select;
            cout<<"\nSelect deletion operation:\n1.Delete at Beginning\n2.Delete at Index\n3.Delete at End\n";
            cout<<"Enter your choice:";
            cin>>select;
            switch (select)
            {
            case 1:
                deleteAtBeginning(head);
                cout<<"Element deleted successfully...";
                break;
            
            case 2:
                deleteAtIndex(head);
                cout<<"Element deleted successfully...";
                break;
            
            case 3:
                deleteAtEnd(head);
                cout<<"Element deleted successfully...";
                break;
            }
            break;
        }
    } while (choice!=4);
    return 0;
}