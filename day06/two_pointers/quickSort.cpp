#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r){
    int temp = a[l];
    while(l < r){
        while(l<r && a[r] > temp) r--;
        a[l] = a[r];
        while(l<r && a[l] < temp) l++;
        a[r] = a[l];
    }
    a[l] = temp;
    return l;
}

void quickSort(int arr[], int l, int r){
    if(l<r){
        int pos = partition(arr, l, r);
        quickSort(arr, l, pos-1);
        quickSort(arr, pos+1, r);
    }
}

int main(){
    int arr[] = {1, 3, 5, 2, 4, 9, 7, 8, 0, 6};
    quickSort(arr, 0, 9);
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    return 0;
}