// Implement a List using Array and develop functions to perform insertion, deletion and linear search operations.
#include<stdio.h>
#include<stdbool.h>
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertion(int arr[], int n, int element, int capacity, int index) {
    if(n>=capacity) {
        printf("Array is full. Cannot insert.\n");
    }
    for(int i=n-1; i>=index; i--) {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
}
void deletion(int arr[], int n, int index) {
    for(int i=index; i<n-1; i++) {
        arr[i]=arr[i+1];
    }
}
bool linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(key==arr[i]) {
            return i;
        } 
    }
    printf("Not found\n"); 
}
void peformOperations(int arr[], int n, int key, int choice, int element, int capacity, int index) {
    switch(choice) {
        case 1 :
        printf("Enter the index where you want to insert an element : ");
        scanf("%d", &index);
        printf("Enter the element to insert :\n");
        scanf("%d", &element);
        printf("The resultant array is :\n");
        insertion(arr, n, element, capacity, index);
        n+=1;
        display(arr, n);
        break;
        case 2 : 
        printf("Enter the index to delete an element : ");
        scanf("%d", &index);
        printf("The array after deletion is :\n");
        deletion(arr, n, index);
        n-=1;
        display(arr, n);
        break;
        case 3 :
        printf("Enter the element to search : ");
        scanf("%d", &key);
        if(linearSearch(arr, n, key)) {
            printf("Found\n");
        }
        break;
        default :
        printf("Invalid choice.\n");
    }
}
int main() {
    int n, arr[1000], key, choice, element, capacity=1000, index;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    printf("Enter %d elements :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The array before any operation is :\n");
    display(arr, n);
    printf("Enter 1 for insertion\n2 for deletion\n3 for linear search : ");
    scanf("%d", &choice);
    peformOperations(arr, n, key, choice, element, capacity, index);
    return 0; 
}
