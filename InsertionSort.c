#include <stdio.h>

void display(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        int curr = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > curr) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
    printf("The final array after sorting is\n");
    display(arr, len);
}

int main() {
    int arr[100];
    int len;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &len);
    printf("Enter the elements in the array\n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nHere is the initial array\n");
    display(arr, len);
    insertionSort(arr, len);
    return 0;
}
