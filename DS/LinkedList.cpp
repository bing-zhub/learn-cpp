#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct LNode {
    ElementType data;
    LNode *next;
} LNode;

// 尾插法创建链表
void createListR(LNode *&C, int a[], int n);

// 头插法创建链表
void createListF(LNode *&C, int a[], int n);

// 输出链表
void printList(LNode *c);

// 合并链表
void merge(LNode *a, LNode *b, LNode *&c);

// 查找并删除链表
int findAndDelete(LNode *c, int x);

LNode * _find(LNode *c, int x);

// 逆置链表
void reverse(LNode *l, LNode *r);

int main(){
    int arrA[] = {1, 3 ,5 ,7 ,9};
    int arrB[] = {2, 4, 6, 8, 10};
    LNode *a,*b, *c;

    cout << "--- 头插法建立单链表 ---" << endl;
    createListF(a, arrA, 5);
    printList(a);

    cout << "--- 尾插法建立双链表 ---" << endl;
    createListR(a, arrA, 5);
    printList(a);

    cout << "--- 删除指定元素 ---" << endl;
    findAndDelete(a, 3);
    printList(a);

    cout << "--- 合并有序数列 ---" << endl;
    createListF(a, arrA, 5);
    createListF(b, arrB, 5);
    merge(a, b, c);
    printList(c);

    cout << "--- 逆置数列 ---" << endl;
    reverse(c, _find(c, 1));
    printList(a);

    return 0;
}

void createListR(LNode *&C, int a[], int n){
    C = (LNode *)malloc(sizeof(LNode));

    LNode *p = C;

    for(int i = 0; i < n; i++){
        LNode *t = (LNode *)malloc(sizeof(LNode));
        t->data = a[i];
        p->next = t;
        p = t;
    }

    p->next = NULL;
}
//void createListR(LNode *&C, int a[], int n){
//    C = (LNode *)malloc(sizeof(LNode));
//    LNode *r = C;
//    for(int i = 0; i < n; i++){
//        LNode *t = (LNode *)malloc(sizeof(LNode));
//        t->data = a[i];
//        r->next = t;
//        r = r->next;
//    }
//    r->next = nullptr;
//}

void createListF(LNode *&C, int a[], int n){
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;

    for(int i = 0; i < n; i++){
        LNode *t = (LNode *)malloc(sizeof(LNode));
        t->data = a[i];
        t->next = C->next;
        C->next = t;
    }
}
//void createListF(LNode *&C, int a[], int n){
//    C = (LNode *)malloc(sizeof(LNode));
//    C->next = nullptr;
//    for(int i = 0; i < n; i++){
//        LNode *t = (LNode *)malloc(sizeof(LNode));
//        t->data = a[i];
//        t->next = C->next;
//        C->next = t;
//    }
//}

void printList(LNode *c){
    LNode *p = c->next;

    while(p){
        cout << p->data  << " ";
        p = p->next;
    }

    cout << endl;
}
//void printList(LNode *c){
//    LNode *p = c->next;
//    while(p){
//        cout << p->data << " ";
//        p = p->next;
//    }
//    cout << endl;
//}

int findAndDelete(LNode *c, int x){
    LNode *p = c;
    while(p->next){
        if(p->next->data == x)
            break;
        p = p->next;
    }

    if(p && p->next){
        LNode *q = p->next;
        p->next = q->next;
        free(q);
        return 1;
    }else{
        return 0;
    }

}
//int findAndDelete(LNode *c, int x){
//    LNode *p = c;
//    while(p->next){
//        if(p->next->data == x){
//            break;
//        }
//        p = p->next;
//    }
//    if(p && p->next!= nullptr){
//        LNode *q = p->next;
//        p->next = p->next->next;
//        free(q);
//        return 1;
//    } else return 0;
//}

LNode * _find(LNode *c, int x){
    LNode *p = c->next;

    while(p){
        if(p->data==x) break;
        p = p->next;
    }

    return p;
}

// C相当与对a进行拷贝
void merge(LNode *a, LNode *b, LNode *&c){
    LNode *p = a->next, *q = b->next, *r;
    c = a;
    c->next = NULL;
    r = c;
    while(p&&q){
        if(p->data >= q->data){
            r->next = p;
            r = p;
            p = p->next;
        }else{
            r->next = q;
            r = q;
            q = q->next;
        }
    }

    if(p) r->next = p;
    if(q) r->next = q;
}
//void merge(LNode *a, LNode *b, LNode *&c){
//    LNode *p = a->next, *q = b->next, *r;
//    c = a;
//    c->next = nullptr;
//    r = c;
//    while(q && p){
//        if(p->data >= q->data){
//            r->next = p;
//            p = p->next;
//            r = r->next;
//        }else{
//            r->next = q;
//            q = q->next;
//            r = r->next;
//        }
//    }
//    r->next = nullptr;
//    if(p) r->next = p;
//    if(q) r->next = q;
//}

void reverse(LNode *l, LNode *r){
    LNode *p = l->next;
    while(p!=r){
        l->next = p->next;
        p->next = r->next;
        r->next = p;
        p = l->next;
    }
}