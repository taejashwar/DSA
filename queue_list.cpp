#include<iostream>
using namespace std;

//Creating queue using linked list
struct Node {
    int data;
    Node *next;
};

//Initializing queue
Node *front = NULL;
Node *rear = NULL;

void disp_elements() {
    if(front==NULL && rear==NULL) {
        cout<<"Queue is empty..."<<endl;
    }
    else {
        Node *ptr = front;
        while(ptr!=NULL) {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
    }
}

//Enqueue operation
void enqueue(int element) {
    Node *ptr = new Node();
    ptr->data = element;
    ptr->next = NULL;
    if(front==NULL) {
        front = ptr;
        rear = ptr;
    }
    else {
        rear->next = ptr;
        rear = ptr;
    }
    cout<<"Element "<<element<<" inserted to queue successfully..."<<endl;
}

//Dequeue operation
void dequeue() {
    if(front==NULL && rear==NULL) {
        cout<<"Queue Underflow... Cannot remove element"<<endl;
        return;
    }
    else if(front==rear) {
        free(front);
        front = rear = NULL;
    }
    else {
        Node *ptr = front;
        front = front->next;
        free(ptr);
    }
    cout<<"Element removed successfully..."<<endl;
}

int main() {
    int choice, element;
    do {
        cout<<"\nSelect a queue operation:\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"Enter the element to be inserted in the queue:";
                cin>>element;
                enqueue(element);
                break;
            
            case 2:
                dequeue();
                break;
            
            case 3:
                disp_elements();
                break;
        }
    } while(choice!=4);

    return 0;
}