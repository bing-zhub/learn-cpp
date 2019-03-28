#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {2, 3, 5, 7, 8, 9, 12, 21};
    int i=0, j=7;
    int x = 14;
    while(i<j){
        if(arr[i] + arr[j] == x){
            cout << arr[i++] << " " << arr[j--] << endl;
        }else if(arr[i] + arr[j] < x){
            i++;
        }else{
            j--;
        }
    }

    return 0;
}