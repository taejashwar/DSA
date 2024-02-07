#include<iostream>
using namespace std;

//Queue
struct queue {
    int size, front, rear;
    int *arr;
};

//Traversal
void disp_elements(struct queue *ptr) {
    int i;
    if(ptr->front == ptr->rear) {
        cout<<"Queue is empty..."<<endl;
    }
    else {
        cout<<"Queue elements:"<<endl;
        for (i = ptr->front; i < ptr->rear; i++)
        {
            cout<<"\n"<<ptr->arr[i];
        } 
    }
}

//Enqueue operation
void enqueue(struct queue *ptr, int element) {
    if(ptr->size==ptr->rear) {
        cout<<"Queue Overflow... Cannot insert "<<element<<" to the queue"<<endl;
    }
    else {
        ptr->arr[ptr->rear] = element;
        ptr->rear++;
        cout<<"Element "<<element<<" inserted to queue successfully..."<<endl;
    }
}

//Dequeue operation
void dequeue(struct queue *ptr) {
    if(ptr->front==ptr->rear) {
        cout<<"Queue underflow...Cannot remove the element"<<endl;
    }
    else {
        for (int i = 0; i < ptr->rear-1; i++)
        {
            ptr->arr[i] = ptr->arr[i+1];
        }
        ptr->rear--;
        cout<<"Element removed successfully..."<<endl;
    }
}

int main() {
    int size, element, choice;
    struct queue *qp = new struct queue;
    cout<<"Enter the size of the queue:";
    cin>>size;
    qp->size = size;
    qp->front = 0;
    qp->rear = 0;
    qp->arr = new int;
    do {
        cout<<"\nSelect a queue operation:\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the element to be inserted:";
            cin>>element;
            enqueue(qp,element);
            break;
        
        case 2:
            dequeue(qp);
            break;

        case 3:
            disp_elements(qp);
            break;
        
        }
    } while(choice!=4);
    return 0;
}