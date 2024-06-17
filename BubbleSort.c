#include <stdio.h>

void display(int *arr,int length){
    for(int i = 0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int bubblesort(int *arr, int length) {
    for(int i = 0;i < length-1;i++){
        for(int j = 0;j<length-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    display(arr,length);
}

int main() {
    int length;
    int arr[100];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);
    
    for (int i = 0; i < length; i++) {
        printf("Enter the element\n");
        scanf("%d", &arr[i]);
    }
    printf("Array Before Sorting\n");
    display(arr,length);
    printf("Array After Sorting\n");
    bubblesort(arr,length);
    
    return 0;
}
