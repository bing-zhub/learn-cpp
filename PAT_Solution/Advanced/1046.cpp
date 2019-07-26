#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m, q, sum;
int dist[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int t;
		scanf("%d", &t);
		dist[i] = dist[i-1] + t;
		sum += t; 
	}
	scanf("%d", &q);
	while(q--){
		int a, b;
		scanf("%d%d", &a, &b);
		int t = abs(dist[a-1] - dist[b-1]);
		printf("%d\n", min(sum - t, t));
	}
	return 0;
}