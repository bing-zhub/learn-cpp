#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l1, int r1, int l2, int r2){
    int i = l1, j = l2;
    int temp[100], index = 0;
    
    while(i <= r1 && j <= r2){
        if(arr[i] <= arr[j]){
            temp[index++] = arr[i++];
        }else{
            temp[index++] = arr[j++];
        }
    }

    while(i<=r1) temp[index++] = arr[i++];

    while(j<=r2) temp[index++] = arr[j++];

    for(i = 0; i < index; i++) arr[l1+i] = temp[i];
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, mid+1, r);
    }
}


int main(){
    int arr[] = {1, 6, 2, 5, 4, 3};
    mergeSort(arr, 0, 3);
    for(int i =0; i < 6; i++){
        cout << arr[i] << " ";
    }
    return 0;
}