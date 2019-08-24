#include <iostream>
using namespace std;

const int M = 1e5+10;

typedef struct {
  int length;
  int data[M];
} SqList;

void insert(SqList &s ,int x){
  s.data[s.length++] = x;
}

void printList(SqList &s){
  for(int i = 0; i < s.length; i++) cout << s.data[i] << " ";
  cout << endl;
}

// l -> 左端点; r -> 右端点; n -> 交换个数;
void reverse(SqList &s, int l, int r, int n){
  for(int i = l, j = r; i < l + n && i < j; i++, j--){
    swap(s.data[i], s.data[j]);
  }
}

void shift(SqList &s, int p){
  reverse(s, 0, p-1, p);
  reverse(s, p, s.length-1, s.length-1-p);
  reverse(s, 0, s.length-1, s.length);
}


// 重点记忆
void _delete(SqList &s, int l, int r){
  int delta = r - l + 1;
  for(int i = r + 1; i < s.length; i++){
    s.data[i-delta] = s.data[i];
  }
  s.length -= delta;
}

// 参考AcWing 快速排序
void partition(SqList &s){
  int x = s.data[0], i = -1, j = s.length;
  while(i<j){
    do i++; while(s.data[i] < x);
    do j--; while(s.data[j] > x);
    if(i<j) swap(s.data[i], s.data[j]);
  }
}

int main(){
  SqList l;
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  cout << "--- 插入元素 ---" << endl;
  for(int i = 0; i < 10; i++) insert(l, arr[i]);
  printList(l);

  cout << "--- 反转 ---" << endl;
  reverse(l, 0, l.length - 1, l.length);
  printList(l);

  cout << "--- 左移 ---" << endl;
  shift(l, 10);
  printList(l);

  cout << "--- 删除 ---" << endl;
  _delete(l, 1, 4);
  printList(l);

  cout << "--- 划分 ---" << endl;
  partition(l);
  printList(l);

  return 0;
}