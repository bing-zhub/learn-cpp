#include <bits/stdc++.h>
using namespace std;

int main(){
	char ans[90][90];
	int nums = 0;
	while(scanf("%s", &ans[nums])!=EOF){
		nums++;
	}
	
	
	for(int i = nums - 1; i > -1; i--){
		cout << ans[i];
		if(i > 0)
			cout << " ";
	}
	
	return 0;
}
