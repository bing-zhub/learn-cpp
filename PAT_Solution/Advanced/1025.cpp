#include <bits/stdc++.h>
using namespace std;

struct node {
	long long id;
	int score, local, localRank, finalRank;
};

int n, m, cnt;

bool cmp(node a, node b){
	return a.score != b.score ? a.score > b.score : a.id < b.id;
}

vector<node> res;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &m);
		vector<node> tmp(m);
		for(int j = 0; j < m; j++) {
			cin >> tmp[j].id >> tmp[j].score;
			cnt++;
			tmp[j].local = i;
		}
		sort(tmp.begin(), tmp.end(), cmp);
		tmp[0].localRank = 1;
		res.push_back(tmp[0]);
		for(int k = 1; k < m; k++){
			tmp[k].localRank = k + 1;
			if(tmp[k].score == tmp[k-1].score) tmp[k].localRank = tmp[k-1].localRank;
			res.push_back(tmp[k]);
		}
	}
	sort(res.begin(), res.end(), cmp);
	res[0].finalRank = 1;
	for(int i = 1; i < res.size(); i++){
		res[i].finalRank = i + 1;
		if(res[i].score == res[i-1].score) res[i].finalRank = res[i-1].finalRank;
	}
	printf("%d", cnt);
	for(int i = 0; i < res.size(); i++){
		printf("\n%ld %d %d %d", res[i].id, res[i].finalRank, res[i].local, res[i].localRank);
	}
	return 0;
}