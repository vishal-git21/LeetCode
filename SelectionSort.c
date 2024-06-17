#include <stdio.h>

void display(int *arr,int length){
    for(int i = 0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void selectionsort(int *arr, int length) {
    int min;
    for(int i = 0;i < length-1;i++){
        min = i;
        for(int j = i+1;j<length;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(i == min){
        }
        else{
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
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
    selectionsort(arr,length);
    
    return 0;
}
