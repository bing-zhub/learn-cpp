#include <bits/stdc++.h>
using namespace std;

int merge(int a[], int b[], int c[], int an, int bn){
    int i = 0, j = 0, index = 0;
    while(i < an && j < bn){
        if(a[i] < b[j]){
            c[index++] = a[i++];
        }else{
            c[index++] = b[j++];
        }
    }
    while(i<an){
        c[index++] = a[i++];
    }
    while(j<bn){
        c[index++] = b[j++];
    }
    return index;
}

int main(){
    int a[] = {1,2,3,4};
    int b[] = {6,7,8,9};
    int c[10] = {0};
    cout << merge(a, b, c, 4, 4) << endl; 
    for(int i =0; i < 8; i++){
        cout << c[i] << " ";
    }
    

    return 0;
}