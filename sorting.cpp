#include<iostream>
using namespace std;

void disp_elements(int arr[], int size) {
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[], int size) {
    for(int i=1; i<size; i++) {
        int key = arr[i];
        int j = i-1;
        while(key<arr[j] && j>=0) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size) {
    for(int i=0;i<size-1;i++) {
        int min_index = i;
        for(int j=i+1;j<size;j++) {
            if(arr[j]<arr[min_index]) {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
    }
}

int main() {
    int size, choice;
    cout<<"Enter the size of the array:";
    cin>>size;
    int arr[size];
    cout<<"\nEnter elements:"<<endl;
    for(int i=0;i<size;i++) {
        cout<<"Array["<<i<<"]:";
        cin>>arr[i];
    }
    do {
        cout<<"Select an operation:\n1.Insertion Sort\n2.Selection Sort\n3.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice) {
            case 1:
                insertionSort(arr, size);
                disp_elements(arr,size);
                break;
            case 2:
                selectionSort(arr, size);
                disp_elements(arr, size);
                break;
        } 
    } while(choice!=3);
    return 0;
}