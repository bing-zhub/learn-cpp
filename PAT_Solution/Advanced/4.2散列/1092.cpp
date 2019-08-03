#include <iostream>
using namespace std;

int beads[128];

int main(){
  string s1, s2;
  cin >> s1 >> s2;
  for(int i = 0; i < s1.size(); i++) beads[s1[i]] ++;
  
  int diff = 0;
  for(int i = 0; i < s2.size(); i++){
    if(beads[s2[i]]>0){
      beads[s2[i]] --;
    }else{
      diff ++;
    }
  }
  if(diff>0) cout << "No " << diff;
  else cout << "Yes " << s1.size() - s2.size();
  return 0;
}