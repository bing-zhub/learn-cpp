#include <bits/stdc++.h>

using namespace std;
bool condition;

int findElementInAnOrderSequence(int arr[], int l, int r, int x){
    int mid;
    while(l < r){
        mid = l + ((r-l)>>1);
        if(condition)
            r = mid;
        else
            l = mid + 1; 
    }
    return l;
}

int main(){
    int arr[7] = {12 ,13 ,15, 46, 46, 91, 20}; 
    cout << "upper_bound: " << findElementInAnOrderSequence(arr, 0, 6, 46) << endl;

    return 0;
}