#include <bits/stdc++.h>
using namespace std;

int main(){
	int col;
	char c;
	cin >> col >> c;
	int row = col%2 ? col/2 + 1:col/2;
	
	for(int i = 0; i < col; i++)
		cout<<c;
	
	cout <<endl;
	
	for(int i = 0; i < row-2; i++){
		for(int j = 0; j < col; j++){
			if(j==0 || j==col-1)
				cout << c;
			else
				cout << " ";
		}
		cout << endl;
	}
	
	for(int i = 0; i < col; i++)
		cout<<c;
	
	return 0;
}
