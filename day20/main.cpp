#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

int n, m;
const int N = 110;

int d[N][N], g[N][N];
// 记录路径
PII Prev[N][N];

int bfs(){
    queue<PII> q;
    
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    q.push({0, 0});
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++){
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] == 0){
                d[x][y] = d[t.first][t.second] + 1;
                // 记录路径
                Prev[x][y] = t;
                q.push({x, y});
            }
        }
    }

    // 记录路径    
    // for(int x = n -1, y = m - 1; x || y;){
    //     cout << x << ' ' << y << ' ' << endl;
    //     auto t = Prev[x][y];
    //     x = t.first;
    //     y = t.second;
    // }
    
    return d[n-1][m-1];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
            
    cout << bfs() << endl;
    return 0;
}