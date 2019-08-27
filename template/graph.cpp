//
// Created by Öì±ø on 2019/8/26.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 10;

typedef struct ArcNode {
    int adjV;
    ArcNode* nextArc;
} ArcNode;

typedef struct {
    char data;
    ArcNode* firstArc;
} VNode;

typedef struct {
    VNode adjList[maxSize];
    int n, e;
} AGraph;

bool visit[maxSize];

AGraph createGraph(vector<char> nodes, vector<pair<int, int>> edges){
    AGraph g;
    g.n = nodes.size();
    g.e = edges.size();
    for(int i = 0; i < nodes.size(); i++){
        g.adjList[i].firstArc = NULL;
        g.adjList[i].data = nodes[i];
    }
    for(int i = 0; i < edges.size(); i++){
        ArcNode *q = (ArcNode*)malloc(sizeof(ArcNode));
        q->nextArc = NULL;
        q->adjV = edges[i].second;
        ArcNode *start = g.adjList[edges[i].first].firstArc;
        if(start){
            q->nextArc = start;
            g.adjList[edges[i].first].firstArc = q;
        }else{
            g.adjList[edges[i].first].firstArc = q;
        }
    }
    return g;
}

void DFS(AGraph *g, int v){
    visit[v] = true;
    cout << g->adjList[v].data << " ";
    ArcNode *a =  g->adjList[v].firstArc;
    while(a){
        if(!visit[a->adjV])
            DFS(g, a->adjV);
        a=a->nextArc;
    }
}
//void DFS(AGraph *g, int v){
//    // vÊÇÆðµã
//    visit[v] = true;
//    cout << g->adjList[v].data << " ";
//    ArcNode* q = g->adjList[v].firstArc;
//    while(q){
//        if(!visit[q->adjV])
//            DFS(g, q->adjV);
//        q = q->nextArc;
//    }
//}

void BFS(AGraph *g, int v, bool visit[maxSize]){
    queue<int> q;
    q.push(v);
    visit[v] = true;
    cout << g->adjList[v].data << " ";
    while(!q.empty()){
        int j = q.front();
        q.pop();
        ArcNode *arc =  g->adjList[j].firstArc;
        while(arc){
            if(!visit[arc->adjV]){
                visit[arc->adjV] = true;
                cout << g->adjList[arc->adjV].data << " ";
                q.push(arc->adjV);
            }
            arc = arc->nextArc;
        }
    }

}
//void BFS(AGraph *g, int v, bool visit[maxSize]){
//    ArcNode *p;
//    queue<int> que;
//    cout << g->adjList[v].data << " ";
//    que.push(v);
//    visit[v] = true;
//    while(!que.empty()){
//        int j = que.front();
//        que.pop();
//        p = g->adjList[j].firstArc;
//        while(p){
//            if(!visit[p->adjV]){
//                cout << g->adjList[p->adjV].data << " ";
//                visit[p->adjV] = true;
//                que.push(p->adjV);
//            }
//            p=p->nextArc;
//        }
//    }
//    cout << endl;
//}

int main(){
    char arr[5] = {'A', 'B', 'C', 'D', 'E'};
    vector<char> nodes(arr, (arr + sizeof(arr)/ sizeof(char)));
    int edgesArr[5][2] = {{0,1}, {0,2}, {0,3}, {2,3}, {3,4}};
    vector<pair<int, int>> edges;
    for(int i = 0; i < 5; i++){
        pair<int, int> t;
        t.first = edgesArr[i][0];
        t.second = edgesArr[i][1];
        edges.push_back(t);
    }
    AGraph g = createGraph(nodes, edges);
    DFS(&g, 0);
    cout << endl;
    memset(visit, false, sizeof(visit));
    BFS(&g, 0, visit);
    return 0;
}