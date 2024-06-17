#include <stdio.h>

int binarysearch(int *arr, int start, int end, int value) {
    if (start > end) {
        return -1; 
    }

    int mid = start + (end - start) / 2; 

    if (arr[mid] == value) {
        return mid;  // Element found at mid
    } else if (arr[mid] > value) {
        return binarysearch(arr, start, mid - 1, value); 
    } else {
        return binarysearch(arr, mid + 1, end, value);
    }
}

int main() {
    int length;
    int arr[100];
    int val;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);
    
    printf("Enter %d elements in sorted order:\n", length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element you want to search for: ");
    scanf("%d", &val);
    
    int res = binarysearch(arr, 0, length - 1, val);
    
    if (res != -1) {
        printf("Element found at index: %d\n", res);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
