#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *for_link;
    struct Node *back_link;
};

//Traversal
void traverse(struct Node *ptr) {
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->for_link;
    }
    
}

//Inserion 2 : Insert at given index
struct Node *insertAtIndex(struct Node *head,int data,int index) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node *p = head;
    for (int i = 0; i < index-1; i++)
    {
        p = p->for_link;
    }
    ptr->for_link = p->for_link;
    p->for_link->back_link = ptr;
    ptr->back_link = p;
    p->for_link = ptr;
    return head;
}

//Deletion 2 : Delete the given index
struct Node *deleteAtIndex(struct Node *head,int index) {
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->for_link;
    for (int i = 0; i < index-1; i++)
    {
        ptr1 = ptr1->for_link;
        ptr2 = ptr2->for_link;
    }
    ptr1->for_link = ptr2->for_link;
    ptr2->for_link->back_link = ptr1;
    free(ptr2);
    return head;
    
}

int main() {
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 5;
    head->for_link = second;
    head->back_link = NULL;

    second->data = 11;
    second->for_link = third;
    second->back_link = head;

    third->data = 17;
    third->for_link = fourth;
    third->back_link = second;
    
    fourth->data = 23;
    fourth->for_link = fifth;
    fourth->back_link = third;

    fifth->data = 28;
    fifth->for_link = NULL;
    fifth->back_link = fourth;
    
    //printf("Befor insertion...\n");
    printf("Before Deletion..\n");
    traverse(head);
    //printf("After insertion...\n");
    //insertAtIndex(head,15,2);
    printf("After Deletion..\n");
    deleteAtIndex(head,3);
    traverse(head);
    return 0;
}
