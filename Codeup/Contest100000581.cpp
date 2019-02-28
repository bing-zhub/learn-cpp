#include <bits/stdc++.h>
using namespace std;
struct Student{
	int id;
	char name[8];
	int score;
} stu[100000];

bool cmp1(Student a, Student b){
	return a.id < b.id;
}

bool cmp2(Student a, Student b){
	return strcmp(a.name, b.name) < 0;
}

bool cmp3(Student a, Student b){
	if(a.score != b.score)
		return a.score < b.score;
	else
		return a.id < b.id;
}

int main(){
	int index = 0;
	while(1){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n==0)
			break;
		
		for(int i = 0; i < n; i++){
			scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].score);
		}
		
		switch(m){
			case 1:
				sort(stu, stu+n, cmp1);
				break;
			case 2:
				sort(stu, stu+n, cmp2);
				break;
			case 3:
				sort(stu, stu+n, cmp3);
				break;		
		}
		printf("Case %d:\n", ++index);
		for(int i = 0; i < n;i++){
			printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
		}
		
	}
	return 0;
}
