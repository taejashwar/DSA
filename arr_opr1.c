#include<stdio.h>

//Input elements in array
void input_elements(int size,int array[]) {
    printf("Enter elements: \n");
    for (int i = 0; i<size; i++)
    {
        scanf("%d",&array[i]);
    }
    
}

//Traversal
void display_elements(int array[],int size) {
    printf("Display function working...\n");
    for (int i = 0; i<size; i++)
    {
        printf("%d\n",array[i]);
    }
    
}

//Insertion
void insert_element(int array[],int size) {
    printf("Insert funtion working...\n");
    int element, index;
    printf("Enter the element to be inserted: ");
    scanf("%d",&element);
    printf("Enter the index value where the element is to be inserted: ");
    scanf("%d",&index);
    for (int i = size-1; i>=index; i--)
    {
        array[i+1] = array[i];
    }
    array[index] = element;
    printf("Element inserted successfully\n");
}

//Linear Search
int linearSearch(int array[],int size) {
    printf("Linear Search working...\n");
    int element;
    printf("Enter the element to be linear searched:");
    scanf("%d",&element);
    for (int i=0;i<size;i++) {
        if(array[i] == element) {
            printf("Element found at index %d",i);
        }
    }
    return -1;
}

//Binary Search
int binarySearch(int array[],int size) {
    printf("Binary Search working...\n");
    int element,low,mid,high;
    printf("Enter the element to be binary searched:");
    scanf("%d",&element);
    low = 0;
    high = size-1;
    while(low<=high) {
        mid = (low+high)/2;
        if(array[mid]==element) {
            printf("Element was found at index %d",mid);
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
    printf("Delete function working...\n");
    int index;
    printf("Enter the index of the element to be deleted:");
    scanf("%d",&index);
    for (int i = index; i<size; i++) {
        array[i] = array[i+1];
    }
    printf("Element deleted successfully...");
}

int main() {
    int arr[50] = {};
    int capacity = 50;
    int size,choice;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    do {
        printf("\nSelect array operation:\n1.Input Elements\n2.Traversal\n3.Insertion\n4.Linear Search\n5.Binary Search\n6.Deletion\n7.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
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
            default:
            printf("Invalid Input");
            break;
        }
    } while (choice!=7);
    return 0;
}
