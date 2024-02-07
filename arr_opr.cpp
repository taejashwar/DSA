#include<iostream>
using namespace std;

//Input elements in array
void input_elements(int size,int array[]) {
    cout<<"Enter elements: \n";
    for (int i = 0; i<size; i++)
    {
        cin>>array[i];
    }
    
}

//Traversal
void display_elements(int array[],int size) {
    cout<<"Display function working...\n";
    for (int i = 0; i<size; i++)
    {
        cout<<array[i]<<"\n";
    }
    
}

//Insertion
void insert_element(int array[],int size) {
    cout<<"Insert funtion working...\n";
    int element, index;
    cout<<"Enter the element to be inserted: ";
    cin>>element;
    cout<<"Enter the index value where the element is to be inserted: ";
    cin>>index;
    for (int i = size-1; i>=index; i--)
    {
        array[i+1] = array[i];
    }
    array[index] = element;
    cout<<"Element inserted successfully\n";
}

//Linear Search
int linearSearch(int array[],int size) {
    cout<<"Linear Search working...\n";
    int element;
    cout<<"Enter the element to be linear searched:";
    cin>>element;
    for (int i=0;i<size;i++) {
        if(array[i] == element) {
            cout<<"Element found at index "<<i;
        }
    }
    return -1;
}

//Binary Search
int binarySearch(int array[],int size) {
    cout<<"Binary Search working...\n";
    int element,low,mid,high;
    cout<<"Enter the element to be binary searched:";
    cin>>element;
    low = 0;
    high = size-1;
    while(low<=high) {
        mid = (low+high)/2;
        if(array[mid]==element) {
            cout<<"Element was found at index "<<mid;
        }
        if(array[mid]<element) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}

//Deletion
void delete_element(int array[],int size) {
    cout<<"Delete function working...\n";
    int index;
    cout<<"Enter the index of the element to be deleted:";
    cin>>index;
    for (int i = index; i<size; i++) {
        array[i] = array[i+1];
    }
    cout<<"Element deleted successfully...";
}

int main() {
    int arr[50] = {};
    int capacity = 50;
    int size,choice;
    cout<<"Enter the size of the array: ";
    cin>>size;
    do {
        cout<<"\nSelect array operation:\n1.Input Elements\n2.Traversal\n3.Insertion\n4.Linear Search\n5.Binary Search\n6.Deletion\n7.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
            case 1:
            input_elements(size,arr);
            break;
            case 2:
            display_elements(arr,size);
            break;
            case 3:
            insert_element(arr,size);
            size+=1;
            break;
            case 4:
            linearSearch(arr,size);
            break;
            case 5:
            binarySearch(arr,size);
            break;
            case 6:
            delete_element(arr,size);
            size-=1;
            break;
        }
    } while (choice!=7);
    return 0;
}