#include <stdio.h>

void display(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1],R[n2];
    for(int i = 0;i<n1;i++){
        L[i] = arr[left+i];
    }
    for(int j = 0;j<n2;j++){
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0,j = 0,k = left;
    
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int *arr ,int left,int right){
    if(left < right){
        int mid = left + (right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
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
    mergeSort(arr, 0,len-1);
    printf("\nHere is the final array\n");
    display(arr, len);
    return 0;
}
