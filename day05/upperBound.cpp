#include <bits/stdc++.h>

using namespace std;

int upperBound(int arr[], int l, int r, int x){
    int mid;
    while(l < r){
        mid = l + ((r-l)>>1);
        if(arr[mid] > x)
            r = mid;
        else
            l = mid + 1; 
    }
    return l;
}

int lowerBound(int arr[], int l, int r, int x){
    int mid;
    while(l<r){
        mid = l + ((r-l)>>1);
        if(arr[mid]>=x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main(){
    int arr[7] = {12 ,13 ,15, 46, 46, 91, 20};
    cout << "lower_bound: " << lowerBound(arr, 0, 6, 46) << endl; 
    cout << "upper_bound: " << upperBound(arr, 0, 6, 46) << endl;
    cout << "has " << upperBound(arr, 0, 6, 46) - lowerBound(arr, 0, 6, 46) << " 46";

    return 0;
}