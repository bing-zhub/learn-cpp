#include <iostream>
#include <cstring>
using namespace std;
const int N = 55;
int decks[N], shuffles[N], backup[N], rep;
char map[5] = {'S', 'H', 'C', 'D', 'J'}; 
int main(){
	for(int i = 1; i < N; i++) decks[i] = i;
	scanf("%d", &rep);
	for(int i = 1; i < N; i++) scanf("%d", &shuffles[i]);
	for(int i = 0; i < rep; i++){
		memcpy(backup, decks, sizeof decks);
		for(int j = 1; j <= N; j++){
			decks[shuffles[j]] = backup[j];
		}
	}
	for(int i = 1; i < N; i++){
		if(i!=1) printf(" "); 
		decks[i] --;
		printf("%c%d",map[decks[i]/13], decks[i]%13+1);
	}
	return 0;
}