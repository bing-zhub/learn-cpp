//
// Created by 朱兵 on 2019/8/25.
//

#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>

using namespace std;

typedef struct  btNode{
    char data;
    btNode* lChild;
    btNode* rChild;
    btNode(char x) : data(x), lChild(NULL), rChild(NULL) {}
} BTNode;

void preOrderNonRecursion(BTNode *bt);
void inOrderNonRecursion(BTNode *bt);
void postOrderNonRecursion(BTNode *bt);
void preOrder(BTNode *bt);
void inOrder(BTNode *bt);
void postOrder(BTNode *bt);
void levelTr(BTNode *bt);
int getDepth(BTNode *bt);
void search(BTNode *t, BTNode *&tar, char key);
int getMaxWidth(BTNode *bt);
int countNodes(BTNode *bt);
int countLeafs(BTNode *bt);
int search(string arr, int k, int l, int r);

// 由字符串创建完全二叉树
BTNode *createTree(string a, int index);

// 由先序遍历和中序遍历创建二叉树
BTNode *createTreeByPreAndIn(string pre, string in, int l1, int r1, int l2, int r2);

// 由后序遍历和中序遍历创建二叉树
BTNode *createTreeByPostAndIn(string post, string in, int l1, int r1, int l2, int r2);

// 由层序遍历和中序遍历创建二叉树
BTNode *createTreeByLevelAndIn(string level, string in, int n, int l, int r);

void getSubLevel(char subLevel[], string level, string in, int n, int l, int r);


int main(){
    string a = "ABCDEFG";


    // 创建二叉树
    BTNode *t = createTree(a, 0);

    // 非递归先序遍历
    cout << "--- 非递归先序遍历 ---" << endl;
    preOrderNonRecursion(t);

    // 先序遍历
    cout << "--- 先序遍历 ---" <<endl;
    preOrder(t);
    cout << endl;

    // 非递归中序遍历
    cout << "--- 非递归中序遍历 ---" << endl;
    inOrderNonRecursion(t);

    // 中序遍历
    cout << "--- 中序遍历 ---" <<endl;
    inOrder(t);
    cout << endl;

    // 非递归后序遍历
    cout << "--- 非递归后序遍历 ---" << endl;
    postOrderNonRecursion(t);

    // 后序遍历
    cout << "--- 后序遍历 ---" <<endl;
    postOrder(t);
    cout << endl;

    // 层序遍历
    cout << "--- 层序遍历 ---" << endl;
    levelTr(t);

    // 根据先序遍历和中序遍历确定二叉树
    BTNode *preAndIn = createTreeByPreAndIn("ABDECFG", "DBEAFCG", 0, 6, 0, 6);

    // 根据后序遍历和中序遍历确定二叉树
    BTNode *postAndIn = createTreeByPostAndIn("DEBFGCA","DBEAFCG", 0, 6, 0, 6);

    // 获取树的高度
    cout << "--- 获取树的高度 ---" << endl;
    cout << getDepth(t) << endl;

    cout << "--- 搜索 ---" << endl;
    BTNode *tar;
    search(t, tar, 'C');
    cout << tar->lChild->data << endl; // 应为F

    cout << "--- 获取树的宽度 ---" << endl;
    cout << getMaxWidth(t) << endl;

    cout << "--- 节点计数 --- " << endl;
    cout << countNodes(t) << endl;

    cout << "--- 叶节点计数 --- " << endl;
    cout << countLeafs(t) << endl;



    return 0;
}

BTNode *createTree(string a, int index){
    if(index > a.size() || a[index] == '\0') return NULL;

    BTNode *t = (BTNode *)malloc(sizeof(BTNode));
    t->data = a[index];
    t->lChild = createTree(a, 2 * index + 1);
    t->rChild = createTree(a, 2 * index + 2);

    return t;
}

BTNode *createTreeByPreAndIn(string pre, string in, int l1, int r1, int l2, int r2){
    if(l1> r1) return NULL;


    auto s = new BTNode(pre[l1]);

    int i = l2;
    for(;i <= r2; i++) if(in[i] == pre[l1]) break;
    int len = i - l2;
    s->lChild = createTreeByPreAndIn(pre, in, l1+1, l1+len, l2, i-1);
    s->rChild = createTreeByPreAndIn(pre, in, l1+len+1, r1, i+1, r2);
    return s;
}

BTNode *createTreeByPostAndIn(string post, string in, int l1, int r1, int l2, int r2){
    if(l1>r1) return NULL;

    BTNode *s = (BTNode *)malloc(sizeof(BTNode));
    s->lChild = s->rChild = NULL;
    s->data = post[r1];

    int i = l2;
    for(;i <= r2; i++) if(in[i] == post[r1]) break;
    s->lChild = createTreeByPostAndIn(post, in, l1, l1+i-l2-1, l2, i-1);
    s->rChild = createTreeByPostAndIn(post, in, l1+i-l2, r1-1, i+1, r2);

    return s;
}

BTNode *createTreeByLevelAndIn(string level, string in, int n, int l, int r){
    if(l>r) return NULL;

    BTNode *s = (BTNode *)malloc(sizeof(BTNode));
    s->lChild = s->rChild = NULL;
    s->data = level[0];

    int i = search(in, level[0], l, r);

    int ln = i - l; char lLevel[ln];
    int rn = r - i; char rLevel[rn];

    getSubLevel(lLevel, level, in, n, l, i - 1);
    getSubLevel(rLevel, level, in, n, i+1, r);

    s->lChild = createTreeByLevelAndIn(rLevel, in, ln, l, i-1);
    s->rChild = createTreeByLevelAndIn(rLevel, in, rn, i+1, r);

    return s;
}

int getMaxWidth(BTNode *bt){
    if(!bt) return 0;

    queue<BTNode *> q;
    BTNode *p = NULL;
    q.push(bt);
    unsigned long max = 0;
    while(!q.empty()){
        max = q.size()>max?q.size():max;
        p = q.front();
        q.pop();
        if(p->lChild) q.push(p->lChild);
        if(p->rChild) q.push(p->rChild);
    }
    return max;
}

int countNodes(BTNode *bt){
    if(!bt) return 0;

    int n1, n2;
    n1 = countNodes(bt->lChild);
    n2 = countNodes(bt->rChild);
    return n1 + n2 + 1;
}

int countLeafs(BTNode *bt){
    if(!bt->lChild && !bt->rChild) return 1;

    int n1, n2;

    n1 = countLeafs(bt->lChild);
    n2 = countLeafs(bt->rChild);

    return n1+n2;
}

void search(BTNode *t, BTNode *&tar, char key){
    if(!t) return ;

    if(t->data == key) tar = t;
    else{
        search(t->lChild, tar, key);
        if(!tar) search(t->rChild, tar, key); // 剪枝
    }
}

int getDepth(BTNode *bt){
    if(!bt) return 0;

    int ld = 0, rd = 0;
    ld = getDepth(bt->lChild);
    rd = getDepth(bt->rChild);

    return max(rd, ld) + 1;
}

void preOrderNonRecursion(BTNode *bt){
    if(!bt) return;

    stack<BTNode *> s;
    BTNode *p = NULL;
    s.push(bt);
    while (!s.empty()){
        p = s.top();
        s.pop();
        cout << p->data << " ";
        if(p->rChild) s.push(p->rChild);
        if(p->lChild) s.push(p->lChild);
    }
    cout << endl;
}

void inOrderNonRecursion(BTNode *bt){
    if(!bt) return;

    BTNode *p = bt;
    stack<BTNode *> s;
    while(!s.empty() || p){
        while(p){
            s.push(p);
            p = p->lChild;
        }
        if(!s.empty()){
            p = s.top();
            s.pop();
            cout << p->data << " ";
            p = p->rChild;
        }
    }
    cout << endl;
}

void postOrderNonRecursion(BTNode *bt){
    if(!bt) return ;

    stack<char> rev;
    stack<BTNode *> sup;

    sup.push(bt);
    while(!sup.empty()){
        BTNode *p = sup.top();
        rev.push(p->data);
        sup.pop();
        if(p->lChild) sup.push(p->lChild);
        if(p->rChild) sup.push(p->rChild);
    }

    while(!rev.empty()){
        cout << rev.top() << " ";
        rev.pop();
    }

    cout << endl;

}

void preOrder(BTNode *bt){
    if(!bt) return;

    cout << bt->data << " ";
    preOrder(bt->lChild);
    preOrder(bt->rChild);
}

void inOrder(BTNode *bt){
    if(!bt) return;

    inOrder(bt->lChild);
    cout << bt->data << " ";
    inOrder(bt->rChild);
}

void postOrder(BTNode *bt){
    if(!bt) return;

    postOrder(bt->lChild);
    postOrder(bt->rChild);
    cout << bt->data << " ";
}

void levelTr(BTNode *bt){
    if(!bt) return;

    queue<BTNode *> q;
    BTNode *p = NULL;
    q.push(bt);
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout << p->data << " ";
        if(p->lChild) q.push(p->lChild);
        if(p->rChild) q.push(p->rChild);
    }
    cout << endl;
}

int search(string arr, int k, int l, int r){
    for(int i = l; i <= r; i++) if(arr[i] == k) return i;
    return -1;
}

void getSubLevel(char subLevel[], string level, string in, int n, int l, int r){
    int k = 0;
    for(int i = 0; i < n; i++)
        if(search(in, level[i], l, r) != -1)
            subLevel[k++] = level[i];
}
