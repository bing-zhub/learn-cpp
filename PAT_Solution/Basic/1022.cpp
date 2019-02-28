#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,n;
	cin >> a >> b >> n;
	int ans[31]; 
	a+=b;
	int num = 0;
	do {
		ans[num++] = a%n;
		a/=n;
	} while(a>0);
	
	for(int i = num -1; i > -1; i--){
		cout << ans[i];
	}
	 
	return 0;
}
