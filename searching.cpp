#include<iostream>
using namespace std;

//Traversal
void display_elements(int array[],int size) {
    cout<<"Display function working...\n";
    for (int i = 0; i<size; i++)
    {
        cout<<array[i]<<"\n";
    }
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

int main() {
    int size,choice;
    cout<<"Enter the size of the array:";
    cin>>size;
    int arr[size];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    }
    do {
        cout<<"\nSelect an operation:\n1.Linear Search\n2.Binary Search\n3.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            linearSearch(arr,size);
            break;
        
        case 2:
            binarySearch(arr,size);
            break;
        }
    } while(choice!=3);
}