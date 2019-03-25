#include <bits/stdc++.h>
using namespace std;

int main(){
    multimap<string, int> map;
    map.insert(make_pair("a", 1));
    map.insert(make_pair("a", 2));
    map.insert(make_pair("a", 3));
    map.insert(make_pair("b", 1));
    map.insert(make_pair("b", 2));
    map.insert(make_pair("b", 3));

    multimap<string, int>::iterator i1 = map.lower_bound("a");
    cout << "a lower_bound: " <<i1->first <<" " << i1->second << endl;
    i1 = map.upper_bound("a");
    cout << "a upper_bound: " <<i1->first <<" " << i1->second << endl;
    
    multimap<string, int>::iterator i2 = map.lower_bound("b");
    cout << "b upper_bound: " <<i2->first <<" " << i2->second << endl;
    i2 = map.upper_bound("b");
    cout << "b upper_bound: " <<i2->first <<" " << i2->second << endl;

    return 0;
}