#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x){
    int mid;
    while(l<=r){
        mid = l + ((r-l)>>1);
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid] > x){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[10] = {0, 789, 1, 121, 2, 451, 123, 9, 7, 231};
    sort(arr, arr+10);
    for(int i = 0; i < 10; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << binarySearch(arr, 0, 9, 7);
    return 0;
}