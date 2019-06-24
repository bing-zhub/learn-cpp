## STL
1. vector
变长数组(动态变化), 倍增
2. string
字符串, `substr()`, `c_str()`
3. queue
队列, `push()`,`front()`, `pop()`
4. priority_queue
优先队列, `push()`,`pop()`, `top()`
5. stack
栈, `push()`, `top()`, `pop()`
6. deque
双端队列
7. set, map, multiset, multimap
基于平衡二叉树(红黑树), 动态维护有序序列
8. unordered_set, unordered_map, unordered_multiset
哈希表unordered_multimap
9. bitset 压位

### vector
``` C++
// 定义
vector<int> a;
vector<int> a(10);
vector<int> a(10, 3);

// 大小 o(1)
a.size();

// 是否为空 o(1)
a.empty();

// 清空
a.clear();

// 返回第一个
a.front();

// 返回最后一个
a.back();

// 向尾部追加一个
a.push_back();

// 尾部弹出
a.pop_back();

// 迭代器
a.begin();

// 最后一个数的后面
a.end();

// 遍历
for(int i = 0; i < a.size(); i++) cout << a[i] << ' ';

for(auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';

for(auto x : a) cout << x << ' ';

// 支持比较 字典序 a<b
vector a(4,3), b(4,5);

```
自动边长, 系统为某一个程序分配空间时, 所需时间基于本上与空间大小无关, 与申请次数有关.
32 -> 64 原有元素拷贝到新vector中

### pair
``` C++
// 定义
pair<int, string> p;

// 第一个元素
p.first

// 第二个元素
p.second

// 可以比较 first为第一关键字 second为第二关键字

// 创建
p = make_pair(10, "bing");
// 或
p = {10, "bing"};
```

### string
