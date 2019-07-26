#include <iostream>
using namespace std;

int n, m_l_g = 0x3f3f3f3f, f_h_g;
string m_l_id, m_l_n, f_h_id, f_h_n;

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    string name; char g;
    cin >> name >> g;
    if(g == 'M'){
      string id;
      int grade;
      cin >> id >> grade;
      if(grade < m_l_g){
        m_l_g = grade;
        m_l_id = id;
        m_l_n = name;
      }
    }else{
      string id;
      int grade;
      cin >> id >> grade;
      if(grade > f_h_g){
        f_h_g = grade;
        f_h_id = id;
        f_h_n = name;
      }
    }
  }
  if(f_h_g == 0 ) cout << "Absent" << endl; else cout << f_h_n << " " << f_h_id << endl;
  if(m_l_g == 0x3f3f3f3f ) cout << "Absent" << endl; else cout << m_l_n << " " << m_l_id << endl;
  if(f_h_g == 0 || m_l_g == 0x3f3f3f3f) cout << "NA"; else cout << abs(m_l_g - f_h_g);
  return 0;
}
