#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int max = INT_MIN, min = INT_MAX;
	string lock, unlock; 
	for(int i = 0; i < n; i++){
		int h1, m1, s1, h2, m2, s2;
		string t;
		cin >> t;
		scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
		int in = h1*3600 + m1*60 + s1;
		int out = h2*3600 + m2*60 + s2;
		if(in < min){
			min = in;
			unlock = t;
		}
		if(out > max){
			max = out;
			lock = t;
		}
	}
	
	cout << unlock << " " <<lock;
	 
	
	return 0;
}
