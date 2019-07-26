#include <iostream>
using namespace std;

int signIn = 0x3f3f3f3f, signOut, n;
string in, out;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		string t;
		int hi, mi, si, ho, mo, so;
		cin >> t;
		scanf("%d:%d:%d %d:%d:%d", &hi, &mi, &si, &ho, &mo, &so);
		int inTime = hi * 3600 + mi * 60 + si;
		int outTime = ho * 3600 + mo * 60 + so;
		if(inTime < signIn) signIn = inTime, in = t;
		if(outTime > signOut) signOut = outTime, out = t;
	}
	cout << in << ' ' << out;
	return 0;
}