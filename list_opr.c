#include<stdio.h>
#include<stdlib.h>

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
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Insertion 1 : Insert in beginning
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

//Insertion 2 : Insert in given index
struct Node *insertAtIndex(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
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
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    while(p->next!=NULL) {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

//Insertion 4 : Insert in the given node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

//Deletion 1 : Delete in the beginning
struct Node *deleteAtBeginning(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//Deletion 2 : Delete at the given index
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
    free(ptr2);
    return head;
}

//Deletion 4 : Delete at the given value
struct Node *deleteAtValue(struct Node *head, int val) {
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    while (ptr2->data!=val && ptr2->next!=NULL)
    {
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
    struct Node *sixth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node)); 
    sixth = (struct Node*)malloc(sizeof(struct Node));

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
    
    //printf("Before insertion...\n");
    printf("Before deletion...\n");
    displayElement(head);
    //head = insertAtBeginning(head,7);
    //head = insertAtIndex(head,23,4);
    head = insertAtEnd(head,40);
    //head = insertAfterNode(head,third,19);
    //printf("After insertion...\n");
    //head = deleteAtBeginning(head);
    //head = deleteAtIndex(head,4);
    //head = deleteAtEnd(head);
    //head = deleteAtValue(head,13);
    printf("After deletion...\n");
    displayElement(head);
    return 0;
}