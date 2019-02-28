#include <bits/stdc++.h>
using namespace std;

int score[100001] = {0};
int main(){
	int n;
	scanf("%d", &n);

	
	for(int i = 0; i < n ; i++){
		int id,grade;
		scanf("%d%d",&id, &grade);
		score[id] += grade;
	}
	
	int maxi = -1, maxg = -1;
	for(int i = 1; i <= n; i++){
		if(score[i] > maxg){
			maxi = i;
			maxg = score[i];
		}
	}
	
	printf("%d %d", maxi, maxg);
	return 0;
}
