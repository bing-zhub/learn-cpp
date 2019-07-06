#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110; 

int n, m;
// g -> 图, d -> 到起点的距离
int g[N][N], d[N][N];

int bfs(){
    queue<PII> q;

    memset(d, -1, sizeof d);
    d[0][0] = 0; // 到起点距离为0
    q.push({0, 0});  // 以(0,0)作为起点

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (!q.empty()){
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++ ){
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n 
                && y >= 0 && y < m // 在范围内 
                && g[x][y] == 0 && d[x][y] == -1){ // 是空地且没有走过
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }

    return d[n - 1][m - 1];
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}