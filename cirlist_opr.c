#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display_elements(struct Node *head) {
    struct Node *ptr = head;
    do
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);  
}

//Insertion 1 : Insert at beginning
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next!=head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
    
}

//Insertion 2 : Insert at given index
struct Node *insertAtIndex(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    for (int i = 0;i!=index-1;i++)
    {
       p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

//Insertion 3 : Insert at end
struct Node *insertAtEnd(struct Node *head,int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    while (p->next!=head)
    {
        p = p->next;
    }
    ptr->next = head;
    p->next = ptr;
    return head;
}

//Insertion 4 : Insert at the given node
struct Node *insertAtNode(struct Node *head,struct Node *prevNode,int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

//Deletion 1 : Delete at beginning
struct Node *deleteAtBeginning(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//Deletion 2 : Delete at given index
struct Node *deleteAtIndex(struct Node *head, int index) {
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    for (int i = 0; i < index-1; i++)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = ptr2->next;
    free(ptr2);
    return head;
}

//Deletion 3 : Delete at end
struct Node *deleteAtEnd(struct Node *head) {

}

//Deletion 4 : Delete the given value
struct Node *deleteAtVal(struct Node *head,int val) {
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    while(ptr1->data!=val && ptr2->next!=head) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr2->data == val)
    {
        ptr1->next = ptr2->next;
        free(ptr2);
    }
    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 78;
    head->next = second;

    second->data = 81;
    second->next = third;

    third->data = 93;
    third->next = fourth;

    fourth->data = 99;
    fourth->next = fifth;

    fifth->data = 101;
    fifth->next = head;
    
    //printf("Before insertion...\n");
    printf("Befre deletion...\n");
    display_elements(head);
    //printf("After insertion...\n");
    //head = insertAtBeginning(head,64);
    //head = insertAtIndex(head,83,3);
    //head = insertAtEnd(head,109);
    //head = insertAtNode(head,fourth,105);
    printf("After deletion...\n");
    //head = deleteAtBeginning(head);
    //head = deleteAtIndex(head,3);
    //head = deleteAtEnd(head);
    head = deleteAtVal(head,81);
    display_elements(head);
    return 0;
}