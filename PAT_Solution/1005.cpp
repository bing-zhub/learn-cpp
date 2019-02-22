#include <bits/stdc++.h>
using namespace std;

int main(){
	string in;
	cin >> in;
	int sum = 0;
	for(int i = 0; i < in.length(); i++)
		sum += in[i] - '0';
	
	in = to_string(sum);
	string mapping[10] = {"zero","one", "two","three","four","five","six","seven","eight","nine"};
	cout << mapping[in[0] - '0'];
	for(int i = 1; i < in.length(); i++){
		cout << " " << mapping[in[i]-'0']; 
	}
	return 0;
}
